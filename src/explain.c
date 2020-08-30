#include <stdio.h>
#include <stdbool.h>

#include "info/chapters.h"

static int progress = 100;
static int chapter_ends[4] = {100, 102, 204, 303};
static int last_info = 303;

void explain()
{
    int chapter, index;
    char *info;

    chapter = progress / 100;
    index = progress % 100;

    switch (chapter) {
        case 1:  info = chapter1[index];    break;
        case 2:  info = chapter2[index];    break;
        case 3:  info = chapter3[index];    break;
        default: info = NULL;               break;
    }

    if (info)
        printf("-----\n%s\n-----\n", info);
    else
        printf("NULL information\n");
}

void jump_next()
{
    int chapter = progress / 100;
    
    if (progress >= last_info) {
        explain();
        return;
    }
    
    if (progress == chapter_ends[chapter]) {
        progress = (chapter + 1) * 100;
        return;
    }
    
    progress++;
}

void jump_previous()
{
    int chapter = progress / 100;

    if (progress % 100 == 0) {
        progress = chapter_ends[chapter - 1];
        return;
    }

    progress--;
}

bool jump_progress(int jmp)
{
    if (jmp <= 0 || jmp > 9999) {
        printf("Invalid jump operation\n");
        return false;   // prevents explain() from being called
    }
    
    if (jmp >= 1 && jmp <= last_info / 100)
        return jump_progress(jmp * 100);

    progress = jmp;
    if (progress < 100)
        progress = 100;
    
    if (progress / 100 > last_info / 100)
        progress = last_info;

    while (progress > chapter_ends[progress / 100])
        progress--;

    return true;    // allows explain() to be called
}
