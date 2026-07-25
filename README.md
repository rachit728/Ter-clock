Ter-clock is a terminal based clock that aims for memory efficiency and CPU-friendliness.
It is an open-source tool with no dependencies and can be setup up in a few time.
It is made by 'mcro' for Hack Club's YSWS project but is freqently being updated for efficiency and features

## Update
# Current version: v0.1
1. Support template based cutomization for clock interface.
2. Uses syscalls for sleep and clearing screen.
3. String substitution for template engine

## How to use template engine
To use the template engine of 'Ter-clock', we have to compile the clock to a binary and put a file named 'clock.txt' inside the project directory. It must contain the following placeholder because if these place holders and not found, the template engine will fail at string subtitution:
1. (time) : Displays current time in "Hour:Minute PM/AM" format
2. (date) : Displays current date in "Day, Month Date " format
3. (status): Displays the status for the of Wifi-connection (Under construction)
