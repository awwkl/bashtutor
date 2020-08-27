#include <stdio.h>
#include <stdbool.h>

#include "info/chapters.h"

static int progress = 100;
static int end_of_chapter_1 = 102;
static int end_of_chapter_2 = 204;
static int end_of_chapter_3 = 303;
static int last_chapter = 3;
static int last_info = 303;

void explain()
{
    int chapter, index;
    char *info;

    chapter = progress / 100;
    index = progress % 100;

    if (chapter == 1)
        info = chapter1[index];
    if (chapter == 2)
        info = chapter2[index];
    if (chapter == 3)
        info = chapter3[index];

    printf("%s\n", info);
}

void jump_next()
{
    if (progress == last_info) {
        explain();
        return;
    }
    
    if (progress == end_of_chapter_1 || progress == end_of_chapter_2 ||
        progress == end_of_chapter_3) 
        {
        progress = (progress / 100) * 100 + 100;
        return;
    }
    
    progress++;
}

void jump_previous()
{
    if (progress == 100) {
        return;
    } else if (progress == 200) {
        progress = end_of_chapter_1;
    } else if (progress == 300) {
        progress = end_of_chapter_2;
    } else if (progress == 400) {
        progress = end_of_chapter_3;
    }

    progress--;
}

bool jump_progress(int jmp)
{
    if (jmp < 10) {
        return jump_progress(jmp * 100);
    }

    if (jmp < 100 || jmp > 100 * (last_chapter + 1)) {
        printf("Invalid operation: Jump to out of max range\n");
        return false;
    }

    if ((jmp > end_of_chapter_1 && jmp < 200) ||
        (jmp > end_of_chapter_2 && jmp < 300) ||
        (jmp > end_of_chapter_3 && jmp < 400)) 
    {
        printf("Invalid operation: Jump to invalid ranges in chapter\n");
        return false;
    }

    progress = jmp;
    return true;
}
