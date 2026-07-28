/* This file is used for switching the mode of ter-clock to timer mode
*  This source filoe is the starting point of timer_main.c
*/

int timer_main(void){
    int seconds, hours, minutes = 0;
    printf("\n Seconds:");
    scanf("%d", &seconds);

    printf("\n Hours:");
    scanf("%d", &hours);

    printf("\n Minutes:");
    scanf("%d", &minutes);
    clrscr();

    while(true){
        char timer_buffer[20];

        timer_display(seconds, hours, minutes, timer_buffer);

        Variable template[] = { 
            {"timer", timer_buffer},  
            {"status", "Connected"}, 
        };

        render(template, (sizeof(template)/sizeof(template[0])));

        sleep(1);
        if(seconds <= 0){
            if(minutes <= 0){
                
                if (hours > 0){
                    --hours;
                    minutes = 60;
                }
            }

            if(minutes > 0){
                --minutes;
                seconds = 60;
            }

        }

        if(seconds <= 0){
            //Here, it means that the time is up and we should close the timer.
            break;
        }


        --seconds;
        clrscr();
    }
    
    return 0;
}