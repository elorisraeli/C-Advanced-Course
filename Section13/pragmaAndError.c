#include <stdio.h>
/*
// pragma = pragmatic information
the declaration is:
#pragma token_name

Options of #pragma calls:

- #pragma GCC dependency
· allows you to check the relative dates of the current file and another file.
· if the other file is more recent than the current file, a warning is issued
· this pragma is useful if the current file is derived from the other file and should be regenerated
Examples:
#pragma GCC dependency "parse.y"
#pragma GCC dependency "/urs/include/time.h" rerun fixincludes

- #pragma GCC poison
· this directive is used to remove an identifier completely from the program 
· sometimes, there is an identifier that you want to remove completely from your
    program, and make sure that it is never used
· to enforce this, you can poison the identifier with this pragma
    its followed by list of identifiers to poison and if any of those identifiers appear
    anywhere in the source after the directive, an error will be displayed by the compiler
Example:
#pragma GCC poison printf sprintf fprintf
sprintf(some_string, "hello"); // will produce an error

- #pragma GCC system_header
· the #pragma GCC system_header tells the compiler to consider the rest of 
    the current include file as a system header
· code that comes before the '#pragma' in the file is not affected
· this pragma takes no arguments
· system headers are header files that come with the OS or compiler
· GCC gives code found in the system headers special treatment
· this pragma can affect the severity of some diagnostic messages
· all warnings are suppressed while GCC is processing a system header
· macros defined in a system header are immune to a few warnings wherever they are expanded 

(#pragma GCC warning, errors, and message)
- #pragma once
· specifies that the header file containing this directive is included only once even if the 
    programmer includes it multiple times during a complication
· works similar to using include guards
· a less portable alternative to using '#ifdef' to guard the contents of header files
    against multiple inclusions

- #pragma GCC warning "message"
· cause the preprocessor to issue a warning diagnostic with the text 'message'
· message contained in the pragma must be a single string literal

- #pragma GCC error "message"
· causes the preprocessor to issue an error with the text 'message'
· message contained in the pragma must be a single string literal

- #pragma message "message"
· print string as a compiler message on complication
· the message is informational only (not a warning or error)


#error directive
· one of the least used but potentially most useful features of the C preprocessor is
    the ANSI specified #error directive
· the #error directive causes the preprocessor to issue an error message that includes
    any text in the directive 
· error message is a sequence of characters separated by spaces
· you do not have to enclose the text in quotes
· the message is optional
Examples:
1)
#if __STDC_VERSION__ != 201112L // should fail if compiler used is an older standard
                                // and succeed when it uses C11
#error Not C11
#endif

run:
gcc test.c
compiler answer:
test.c:8:2:error: #error Not C11
#error Not C11
2)
#ifdef OPTION1
    Do Something
#elif OPTION2
    Do Something
#else
#error ***You must use option 1 or option 2***
#endif

*/

#pragma GCC poison printf

// runs anyway
#pragma GCC warning "hello"
#pragma GCC error "what"
#pragma message "ok"


void main(){

    printf("Hello."); // error appears in running
    #error just annoying you while coding and debugging
}