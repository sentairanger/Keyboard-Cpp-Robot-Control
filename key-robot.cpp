// Include headers
#include <ncurses.h>
#include <iostream>
#include <pigpio.h>

//g++ -Wall -pthread -o key-robot key-robot.cpp -lncurses -lpigpio -lrt
// Define pins
const uint8_t PIN1 = 13;
const uint8_t PIN2 = 21;
const uint8_t PIN3 = 17;
const uint8_t PIN4 = 27;

// Setup pins

void init() {
  gpioSetMode(PIN1, PI_OUTPUT);
  gpioSetMode(PIN2, PI_OUTPUT);
  gpioSetMode(PIN3, PI_OUTPUT);
  gpioSetMode(PIN4, PI_OUTPUT);
}

// Define directions
void forward() {
  gpioWrite(PIN1, PI_HIGH);
  gpioWrite(PIN2, PI_LOW);
  gpioWrite(PIN3, PI_HIGH);
  gpioWrite(PIN4, PI_LOW);
}

void backward() {
  gpioWrite(PIN1, PI_LOW);
  gpioWrite(PIN2, PI_HIGH);
  gpioWrite(PIN3, PI_LOW);
  gpioWrite(PIN4, PI_HIGH);
}

void left() {
  gpioWrite(PIN1, PI_LOW);
  gpioWrite(PIN2, PI_HIGH);
  gpioWrite(PIN3, PI_HIGH);
  gpioWrite(PIN4, PI_LOW);
}

void right() {
  gpioWrite(PIN1, PI_HIGH);
  gpioWrite(PIN2, PI_LOW);
  gpioWrite(PIN3, PI_LOW);
  gpioWrite(PIN4, PI_HIGH);
}

void stop() {
  gpioWrite(PIN1, PI_LOW);
  gpioWrite(PIN2, PI_LOW);
  gpioWrite(PIN3, PI_LOW);
  gpioWrite(PIN4, PI_LOW);

}

// Initialize screen and then allow the user to control the robot
int main() {
  gpioInitialise();
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, true);

  printw("Press 'q' to quit.");
  refresh();

  for (int ch = getch(); ch != 'q'; ch = getch()) {
    switch (ch) {
      case KEY_UP:
        forward();
        break;
      case KEY_DOWN:
        backward();
        break;
      case KEY_LEFT:
        left();
        break;
      case KEY_RIGHT:
        right();
        break;
      case 10:
        stop();
        break;
      default:
        printw("error");
    
    
    
    }
    clrtoeol();
    refresh();
  }

  endwin();
  // Terminate GPIO access when done
  gpioTerminate();
  return 0;
}
