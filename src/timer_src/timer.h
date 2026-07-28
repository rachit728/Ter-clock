#include <stdio.h>
#include <stdlib.h>

char* int_to_string(int number) {
    // 12 bytes can hold any 32-bit signed integer (up to 10 digits, a minus sign, and '\0')
    int size = 12 * sizeof(char);
    char *result = malloc(size); 


    if (result != NULL) {
        if(number >= 10){
            snprintf(result, size, "%d", number);
        }
        else{
            char temp[12];

            snprintf(result, size, "%d", 0);
            snprintf(temp, 12, "%d", number);
            strcat(result, temp);
        }
    }
    return result; // Remember to free() this memory in the main code later
}

void timer_display(int seconds, int hours, int minutes, 
                    char* display_text){
    char* seconds_text = int_to_string(seconds);
    char* minutes_text = int_to_string(minutes);
    char* hours_text = int_to_string(hours);

    strcpy(display_text, hours_text);
    strcat(display_text, " : ");
    strcat(display_text, minutes_text);
    strcat(display_text, " : ");
    strcat(display_text, seconds_text);

    free(seconds_text);
    free(minutes_text);
    free(hours_text);
}