#include "clock.h"
#include "UI/UI_render.h"
#include "platform/sys_plat.c"

int main(){
  while(true){
    char time_buffer[20];
    char date_buffer[20];

    time_display(time_buffer, sizeof(time_buffer), 
                date_buffer, sizeof(date_buffer));


    puts(time_buffer);
    Variable template[] = {
      {"time", time_buffer},
      {"date", date_buffer},
      {"charge", "87"}, 
      {"status", "Connected"},
    };
    
    render(template, (sizeof(template)/sizeof(template[0])));
    plat_sleep(10);
    clrscr();
  }
  return 0;
}