#!/usr/bin/env bash
#
# Format C/C++ sources under mtg_firmware/ using the repo .clang-format.
#
# Usage:
#   ./format.sh
#   CLANG_FORMAT=clang-format-18 ./format.sh
#
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FIRMWARE="${ROOT}/mtg_firmware"

if [[ -n "${CLANG_FORMAT:-}" ]]; then
    FMT=( "${CLANG_FORMAT}" )
elif command -v clang-format >/dev/null 2>&1; then
    FMT=( clang-format )
elif command -v uvx >/dev/null 2>&1; then
    FMT=( uvx clang-format )
else
    echo "error: clang-format not found (install llvm or set CLANG_FORMAT)" >&2
    exit 1
fi

format_file() {
    local file="$1"
    local assume_name="$2"

    if [[ "${FMT[0]}" == "uvx" ]]; then
        uvx clang-format --style=file:"${ROOT}/.clang-format" \
            --assume-filename="${assume_name}" -i "${file}"
    else
        "${FMT[@]}" --style=file:"${ROOT}/.clang-format" \
            --assume-filename="${assume_name}" -i "${file}"
    fi
}

format_via_stdin() {
    local file="$1"
    local assume_name="$2"
    local tmp

    tmp="$(mktemp)"
    if [[ "${FMT[0]}" == "uvx" ]]; then
        uvx clang-format --style=file:"${ROOT}/.clang-format" \
            --assume-filename="${assume_name}" < "${file}" > "${tmp}"
    else
        "${FMT[@]}" --style=file:"${ROOT}/.clang-format" \
            --assume-filename="${assume_name}" < "${file}" > "${tmp}"
    fi
    mv "${tmp}" "${file}"
}

while IFS= read -r -d '' file; do
    case "${file}" in
        *.c)
            format_file "${file}" "$(basename "${file}")"
            ;;
        *.cpp)
            format_file "${file}" "$(basename "${file}")"
            ;;
        *.h)
            format_file "${file}" "$(basename "${file}")"
            ;;
        *.ino)
            format_via_stdin "${file}" "$(basename "${file%.ino}.cpp")"
            ;;
    esac
done < <(
    find "${FIRMWARE}" -type f \( \
        -name '*.c' -o \
        -name '*.cpp' -o \
        -name '*.h' -o \
        -name '*.ino' \
    \) ! -path '*/templates/*' -print0 | sort -z
)

echo "Formatted sources under ${FIRMWARE} (skipped templates/)"
