import serial


def perc(n, d):
    return str(round(n / d, 1)) + '%'


if __name__ == '__main__':
    count = 0
    data = {k: 0 for k in range(4)}
    try:
        ard = serial.Serial('COM5', 115200)
        while True:
            d = int(ard.readline())
            data[d] += 1
            count += 1
            for k, v in data.items():
                print('{}: {}%% ({})'.format(k, round(v / count * 100, 1), v), end='    ')
            print("Total:", count)
    except KeyboardInterrupt:
        pass
