int clock_main(){
  while(true){
    char time_buffer[20];
    char date_buffer[20];

    clock_display(time_buffer, sizeof(time_buffer), 
                date_buffer, sizeof(date_buffer));


    puts(time_buffer);
    Variable template[] = {
      {"time", time_buffer},
      {"date", date_buffer},
      {"status", "Connected"},
    };
    
    render(template, (sizeof(template)/sizeof(template[0])));
    sleep(10);
    clrscr();
  }
  return 0;
}