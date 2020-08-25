/***********************************************************************
 *  Project Reference <<TODO>>
 *
 *  DESCRIPTION
 *      <<TODO>> Tells you what the code in the file does or refers to
 *      accompanying header file.
 *
 *  REFERENCES
 *      <<TODO>> Requirements Specification
 *      <<TODO>> Software Specification
 ***********************************************************************/

/*=====================================================================*
    Local Header Files

    GUIDANCE:
    Only those headers local/private to this module should be included
    here. While not required, it is typically the case that these form
    part of an "internal API" for the module (helper routines, etc.) and
    therefore are not exposed as part of the public API of the module. These
    headers should always be included at the same level, or below, of this
    .c file.

    RATIONALE:
    This allows a complex module to be decomposed into files of more
    manageable size which aids in understanding and maintainability. It also
    makes it obvious where this .c file has supporting local/private headers.

    EXAMPLES:
    #include "modulename_helperfile.h"
    #include "modulename_otherhelper.h"
    #include "subdir/modulename_details.h"
        ^-- This assumes 'subdir' is a subdirectory at the same level
            as this .c file.
 *=====================================================================*/
/* None */

/*=====================================================================*
    Interface Header Files

    GUIDANCE:
    The headers defining the public API for another module in the project
    are included here. This may be part of the code under development, or
    the code in a 3rd party library or module. Headers that provide
    system-wide defintions (e.g. compiler/tool-chain related, OS) go
    in a separate section below.

    RATIONALE:
    This makes it obvious where this .c file has dependencies on external
    public APIs within the software being developed.

    EXAMPLES:
    #include "module_a/module_a.h"
        ^-- This assumes the include path settings allow this to resolve
            appropriately
 *=====================================================================*/
/* None */

/*=====================================================================*
    System-wide Header Files

    GUIDANCE:
    The headers providing system-wide defintions (e.g. compiler/tool-chain
    related, OS libraries) are included here. The '<>' inclusion syntax
    must be used.

    RATIONALE:
    This makes it obvious where this .c file has dependencies on the system
    and/or runtime platform.

    EXAMPLES:
    #include <limits.h>
    #include <net/ipv4.h>
 *=====================================================================*/
/* None */

/*=====================================================================*
    Private Defines

    GUIDANCE:
    This section contains only macro definitions that are private to
    this .c file and NOT part of any module API (public or internal).

    Macro names should NOT start with MODULENAME_ in order to make it obvious
    they are private to this .c file.

    RATIONALE:
    This follows best practices in data-hiding and encapsulation. It allows
    the module implemenatation to change substantially without affecting the
    module interface.

    EXAMPLES:
    #define INTERNAL_MAGIC      (0xDEADBEEFuL)

 *=====================================================================*/
/* None */

/*=====================================================================*
    Private Data Types

    GUIDANCE:
    This section should contain only data type defintions that are private
    to this .c file and NOT part of any module API (public or internal).

    Type names should NOT start with modulename_ in order to make it obvious
    they are private to this .c file.

    RATIONALE:
    This follows best practices in data-hiding and encapsulation. It allows
    the module implemenatation to change substantially without affecting the
    module interface.

    EXAMPLES:
    typedef enum special_thing_t
    {
        SPECIAL_THING_0,
        SPECIAL_THING_1,
        SPECIAL_THING_COUNT
    } special_thing_t;

    typedef struct mydata_t
    {
        uint8_t *foo;
        double bar[SPECIAL_THING_COUNT];
    } mydata_t;

 *=====================================================================*/
/* None */

/*=====================================================================*
    Private Function Prototypes

    GUIDANCE:
    This section contains function prototypes (declarations) that are private
    to this .c file. They must be declared 'static'.

    RATIONALE:
    This follows best practices in data-hiding and encapsulation. It allows
    the module implemenatation to change substantially without affecting the
    module interface.

    EXAMPLES:
    static void thing_do(special_thing_t this_thing);
    static bool data_process(const mydata_t * const p_data);
    static bool data_modify(mydata_t * const p_data);
 *=====================================================================*/
/* None */

/*=====================================================================*
    Private Data

    GUIDANCE:
    This section contains definitions of variables private to this module. They
    must be declared 'static'.

    RATIONALE:
    This follows best practices in data-hiding and encapsulation. It allows
    the module implemenatation to change substantially without affecting the
    module interface.

    EXAMPLES:
    static const uint16_t m_default_value = 100u;
    static mydata_t data[MODULENAME_MAX_CLIENTS];
 *=====================================================================*/
/* None */

/*=====================================================================*
    Public Function Implementations

    GUIDANCE:
    This section contains the definition (implementation) of functions public
    to this .c file, so they must be part of an API (public or internal) and
    must have a declaration (prototype) in a module header.

    No function header is required here because it must be present in an
    associated header file due to it being part of an API.

    RATIONALE:
    This follows best practices in data-hiding and encapsulation.

    EXAMPLES:
    See the coding standards or style guidelines for your project.
 *=====================================================================*/

/*---------------------------------------------------------------------*
 *  NAME
 *      universe_galaxy_system_planet_verb
 *
 *  DESCRIPTION
 *      <<TODO>> Description of the function in as much detail as is necessary
 *      for a maintainer of the function. This should only include details of
 *      the implementation that are not obvious from the code & comments within
 *      the function itself. It should not include information that is conveyed
 *      in the associated function header in the module's .h file.
 *
 *      Examples of content to include:
 *          - Discussion of algorithms used and data transformed
 *          - Description of the error handling and recovery (if any)
 *          - Description of any limitations or unusual features that restrict
 *            the performance of the function
 *
 *      Enclose parameter names referenced in the description in single quotes.
 *
 *  RETURNS
 *      <<TODO>> Describe what data the function returns
 *---------------------------------------------------------------------*/
/* Your code goes here */

/*=====================================================================*
    Private Function Implementations

    GUIDANCE:
    This section contains the definition (implementation) of functions private
    to this .c file. Their prototype must be declared in the
    'Private Function Prototypes' section earlier in this file.

    Headers must be supplied for these function defintions describing what
    the function does (but not how it does it, i.e. the details of the
    implementation), its input and output parameters, and its return value
    (if appropriate).

    RATIONALE:
    This follows best practices in data-hiding and encapsulation. It allows
    the module implemenatation to change substantially without affecting the
    module interface.

    EXAMPLES:
    See the coding standards or style guidelines for your project.
 *=====================================================================*/
/* None */
