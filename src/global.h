//This file is responsible for reducing the chances of include hell
//It do it by using a concept of including only once and not more than once on multiple file
//This way is not recommended for big projects.

#ifndef GLOBAL_H
#define GLOBAL_H

#define FILENAME "timer.txt"

#include <string.h>
#include "clock_src/clock.h"
#include "timer_src/timer.h"
#include "UI/UI_render.h"
#include "platform/sys_plat.c"

static inline void sleep(size_t seconds);
void clrscr(void);

void clock_display(char* t_buffer, size_t t_buf_size,
                char* d_buffer, size_t d_buf_size);
void timer_display(int seconds, int hours, int minutes, 
                    char* display_text);

void render(Variable macro[], int count);


#endif