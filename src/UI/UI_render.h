#include <stdlib.h>
#include "UI_data.h"
#define FILENAME "clock.txt"


void render(Variable macro[], int count){
    char data[200];
    FILE* file = fopen(FILENAME, "r");

    if(file == NULL){
        perror("Error: File is unable to be opened!!\n");
        return;
    }

    while(fgets(data, sizeof(data), file) != NULL ){
        char result[600];

        substitute(data, result, macro, count);

        printf("%s", result);
    }
}