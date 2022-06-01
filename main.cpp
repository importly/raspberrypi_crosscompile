#include <iostream>
#include <thread>
#include <stdlib.h>
#include <pigpio.h>

/*

02  -
04 | |  03
17  -
22 | |  15
18  - . 14

*/

int lgpio[8] = {3, 2, 4, 14, 15, 18, 27, 17};
int dgpio[4] = {26, 13, 19, 6};

int states[4][8][2] = {{{3,1}, {2,0}, {4,1}, {17,0}, {22,1}, {15,0}, {18,1}, {14,1}},
                       {{3,1}, {2,0}, {4,0}, {17,0}, {22,1}, {15,0}, {18,0}, {14,0}},
                       {{3,0}, {2,0}, {4,0}, {17,0}, {22,0}, {15,0}, {18,0}, {14,0}},
                       {{3,0}, {2,0}, {4,0}, {17,0}, {22,0}, {15,0}, {18,0}, {14,0}}};


int main(int argc, char *argv[]) {
  if (gpioInitialise() <= 0)
  {
    std::cout << "gpio init fail"
              << "\n";
    return -1;
  };

  for (int i = 0; i < 8; i++)
  {
    gpioSetMode(lgpio[i], PI_OUTPUT);
    gpioWrite(lgpio[i], false);
  }
  for (int i = 0; i < 4; i++)
  {
    gpioSetMode(dgpio[i], PI_OUTPUT);
    gpioWrite(dgpio[i], true);
  }

  bool ledstate = false;
  int numa = 0;
  int numb = 0;

  std::cout << "hello" << "\n";

  while (true)
  {
    int place = numa % 4;
    for (int i = 0; i < 4; i++) {
      if (i != place) {
        gpioWrite(dgpio[i],true);
      }
      gpioWrite(dgpio[place],false);
    }
    for (int i = 0; i < 8; i++) {
      gpioWrite(lgpio[i],states[place][i][1]);
    }
    numa++;
    gpioDelay(2500);
    //   gpioWrite(dgpio[numa%4],ledstate);
    //   for (int i = 0; i < 4; i++) {
    //     if (i != numa%4) {
    //       gpioWrite(dgpio[i],true);
    //     }
    //     gpioWrite(dgpio[numa%4],false);
    //   }

    //   std::cout << numa << " " << numb << " " << ledstate << "\n";

    //   if (numa % 5 == 0) {
    //     numb++;
    //     if (numb % 8 == 0) {
    //       ledstate = !ledstate;
    //     }
    //   }
    //   gpioWrite(lgpio[numb%8],!ledstate);
    //   numa++;
    //   gpioDelay(5000);
    // };
  }
}