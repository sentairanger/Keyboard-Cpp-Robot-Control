# Keyboard-Cpp-Robot-Control
This project uses C++ for robot control.

## Getting started

To get started be sure to install pigpio and ncurses. Pigpio can be downloaded from [this](https://abyz.me.uk/rpi/pigpio/download.html) link. Follow the instructions on the link. Also you can install ncurses by going into the directory of this repository and first run `sudo apt install libncurses5-dev` and then run the command `g++ -Wall -pthread -o key-robot key-robot.cpp -lncurses -lpigpio -lrt` to compile the program. Then run with `sudo ./key-robot` as pigpio requires root privileges. Then use your keyboard to control the direction of your robot.
