/***********************************************************************
 *  Project Reference <<TODO>>
 *
 *  DESCRIPTION
 *      <<TODO>> Tells you what the code in the file does.
 *
 *  REFERENCES
 *      <<TODO>> Requirements Specification
 *      <<TODO>> Software Specification
 ***********************************************************************/

#if !defined(INC_<<TODO>>_H)
#define INC_<<TODO>>_H

/*=====================================================================*
    Required Header Files

    GUIDANCE:
    Only those headers required to make this file compileable are included
    here. Headers needed by the associated .c file(s) are included in the
    appropriate section of those .c file(s).

    RATIONALE:
    This keeps the complexity of the inclusion dependency graph low which
    leads to:
        (a) faster compilation times (and other activities that depend on
            the inclusion dependencies)
        (b) better understanding of the impact of changes

    EXAMPLES:
    #include <limits.h>
    #include "modulename_helperfile.h"
    #include "module_a/module_a.h"
        ^-- This assumes the include path settings allow this to resolve
            appropriately
 *=====================================================================*/
#include <stdint.h>

/*=====================================================================*
    Public Defines

    GUIDANCE:
    This section contains only those macro definitions that are part of an
    API (public or internal) of this module. All other macro definitions belong
    in an associated .c file. Note that if you are using a unit test harness,
    you may find it useful for some macro defintions to be here (if this header
    defines the public API for the unit under test).

    Macro names must start with MODULENAME_

    RATIONALE:
    This follows best practices in data-hiding and encapsulation.

    EXAMPLES:
    #define MODULENAME_MAX_CLIENTS      (4u)
 *=====================================================================*/
/* None */

/*=====================================================================*
    Public Data Types

    GUIDANCE:
    This section contains those only data type defintions that are part of an
    API (public or internal) of this module. All other data type definitions
    belong in an associated .c file.

    Type names must start with modulename_

    RATIONALE:
    This follows best practices in data-hiding and encapsulation.

    EXAMPLES:
    typedef enum modulename_thing_t
    {
        MODULENAME_THING_0,
        MODULENAME_THING_1,
        MODULENAME_THING_COUNT
    } modulename_thing_t;

    typedef struct modulename_data_t
    {
        uint32_t count;
        const char *str;
    } modulename_data_t;
 *=====================================================================*/
/* None */

/*=====================================================================*
    Public Data

    GUIDANCE:
    Global variables may only be used under exceptional circumstances.
    Access to module data must be done through a function-based API unless
    it is not possible to do so due to a more important, competing constraint
    (e.g. resource limitation, 3rd party module interface).

    In order to gently nudge you in the direction of this best practice,
    this 'Public Data' section is NOT PRESENT in template.c. If you must
    use public data, add this section between the 'Private Defines'
    and 'Private Data Types' section of template.c. The rationale for this
    positioning is that client's access into publicly-defined data
    should be limited in scope so as to minimize the amount of API-breakage
    that can occur if the declaration (in this header) or definition
    (in the .c file) of the public data changes.

    Global variable names must start with modulename_

    Lastly, if public data is a necessity, opaque pointers and appropriate
    storage class modifiers (i.e. const) must be used in its defintion in
    order to ensure that users of the exposed public data cannot access and/or
    modify (accidentally or intentionally) any "private" data members that may
    be part of the publicly-exposed data.

    RATIONALE:
    This follows the best practice of minimizing the use of global variables.
    It allows the module implemenatation to change substantially without
    affecting the module interface.
 *=====================================================================*/
/* REMOVE THIS SECTION IF NO PUBLIC DATA IS DEFINED */

/*=====================================================================*
    Public Functions

    GUIDANCE:
    This section contains only those function definitions that are part of an
    API (public or internal) of this module. All other function definitions
    belong in an associated .c file and must be delcared 'static'.

    Headers must be supplied for these function defintions describing what
    the function does (but how it works), its input and output parameters,
    and its return value (if appropriate).

    RATIONALE:
    This follows best practices in data-hiding and encapsulation. It allows
    the module implemenatation to change substantially without affecting the
    module interface.

    EXAMPLES:
    See the coding standards or style guidelines for your project.
 *=====================================================================*/
/*---------------------------------------------------------------------*
 *  NAME
 *      universe_galaxy_system_planet_verb
 *
 *  DESCRIPTION
 *      <<TODO>> Description of the function in as much detail as is necessary
 *      for the caller of the function. As much as possible, this should be
 *      agnostic of any aspect of the function's implementation. This allows
 *      the implementation to change, if needed, without modifying the API
 *      without changing the externally-visible behaviour and associated tests.
 *
 *      This should include:
 *          - Pre-conditions to be satisfied before the function can be called
 *          - Post-conditions that must be satisfied when the function returns
 *          - Description of any constraints, limitations, or unusual aspects
 *            of the function the caller must be aware of, such as:
 *              - blocking/non-blocking behaviour
 *              - side-effects
 *              - MT-safety
 *              - required calling context or periodicity
 *
 *      Enclose parameter names referenced in the description in single quotes.
 *
 *  RETURNS
 *      <<TODO>> Describe what data the function returns
 *---------------------------------------------------------------------*/

#endif /* !defined(INC_<<TODO>>_H) */
