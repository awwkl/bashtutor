#include <stdio.h>
#include <stdlib.h>

#include "misc.h"
#include "input.h"

int main()
{
    start_program();

    while (get_parse_execute());

    exit_program();
}
