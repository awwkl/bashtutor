#include <stdio.h>
#include <stdlib.h>

#include "misc.h"
#include "explain.h"

void start_program()
{
    load_chapters();

    print_welcome();
    print_chapters();
    print_help();

    printf("\
To begin, enter \"@j 1\" or \"@j 100\" to jump to first chapter   \n\
Subsequently, enter \"@n\" to progress through the lessons           \n\
");
}

void exit_program()
{
    printf("\n\n<-- See you again! -->\n");
    exit(EXIT_SUCCESS);
}

void print_welcome()
{
        printf("\n\
██████╗  █████╗ ███████╗██╗  ██╗████████╗██╗   ██╗████████╗ ██████╗ ██████╗ \n\
██╔══██╗██╔══██╗██╔════╝██║  ██║╚══██╔══╝██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗\n\
██████╔╝███████║███████╗███████║   ██║   ██║   ██║   ██║   ██║   ██║██████╔╝\n\
██╔══██╗██╔══██║╚════██║██╔══██║   ██║   ██║   ██║   ██║   ██║   ██║██╔══██╗\n\
██████╔╝██║  ██║███████║██║  ██║   ██║   ╚██████╔╝   ██║   ╚██████╔╝██║  ██║\n\
╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n\n\
Welcome to bashtutor, an interactive tutorial to learn and practice basic   \n\
Bash commands. You can now learn Bash without leaving the terminal. Enjoy!  \n\
");
}

void print_chapters()
{
    printf("                                        \n\
Chapter List                                        \n\
------------                                        \n\
1) Basic Terminal Keyboard Shortcuts                \n\
2) File and Directory Commands                      \n\
3) Special Characters                               \n\
------------                                        \n\
Enter \"@j N\" or \"@jump N\" to jump to Chapter N  \n\
");
}

void print_help()
{
    printf("                                        \n\
Here are the bashtutor commands:                    \n\
-----                                               \n\
@h, @help           print this message              \n\
@q, @quit, Ctrl-C   quit and exit bashtutor         \n\
-----                                               \n\
@e, @explain        print current explanation again \n\
@n, @next           jump to next explanation        \n\
@p, @previous       jump to previous explanation    \n\
@j xxx, @jump xxx   jump to explanation xxx         \n\n\
");
}
