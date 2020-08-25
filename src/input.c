#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 1024
static char input[INPUT_SIZE + 1];
static char input_copy[INPUT_SIZE + 1];

#define ARG_COUNT 16
static char *command[ARG_COUNT];

int get_input();
int parse_input();
int exec_input();

int get_parse_execute()
{
    return (get_input() &&
            parse_input() &&
            exec_input());
}

int get_input()
{
    int len;

    printf("bashtutor> ");

    fgets(input, INPUT_SIZE, stdin);
    len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    strcpy(input_copy, input);

    return 1;
}

int parse_input()
{
    char *parsed, *delim;
    int index;

    index = 0;
    delim = " ";

    parsed = strtok(input_copy, delim);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, delim);
    }

    return 1;
}

int exec_input()
{
    if (strcmp(command[0], "@exit") == 0) {
        return 0;
    }
    if (strcmp(command[0], "@explain") == 0) {
        printf("Explain current info\n\n");
        return 1;
    }
    if (strcmp(command[0], "@next") == 0) {
        printf("Explain next info\n\n");
        return 1;
    }
    if (strcmp(command[0], "@previous") == 0) {
        printf("Explain previous info\n\n");
        return 1;
    }

    system(input);

    return 1;
}