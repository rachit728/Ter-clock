#include <time.h>

/*
* t_buffer stands for time buffer, it shows time like 2:07PM
* d_buffer stands for date buffer, it shows date like Monday, July 20
*/

#define TIME_FORMAT "%I:%M %p"
#define DATE_FORMAT "%A, %B %d"

void clock_display(char* t_buffer, size_t t_buf_size,
                char* d_buffer, size_t d_buf_size){
    time_t t;
    struct tm *local_time;
    
    t = time(NULL);
    local_time = localtime(&t);

    strftime(t_buffer, t_buf_size, TIME_FORMAT, local_time);
    strftime(d_buffer, d_buf_size, DATE_FORMAT, local_time);
}