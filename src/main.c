#include "global.h"

#include "clock_src/clock_main.c"
#include "timer_src/timer_main.c"

bool argument_parser(char* find_text, int argc, char* argv[]){
    //i = 1 becuase first element is the executable name.
    //This saves a negligible amount of CPU resources

    for (int i = 1; i < argc; i++){
        if(strcmp(argv[i], find_text) == 0){
            return true;
        }
        printf("%s\n", argv[i]);
    }
    return false;
}

int main(int argc, char* argv[]){
    if(argument_parser("--clock", argc, argv)){
        return clock_main();
    } else if (argument_parser("--timer", argc, argv)){
        return timer_main();
    } else{
        printf("Invalid argument, terminating Ter-clock");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}