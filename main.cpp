/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
int main()
{
#ifdef LED1
    DigitalIn pressbutton(PC_13);
    BusOut light(/*a*/D10, /*b*/D11, /*c*/D7, /*d*/D6, /*e*/D5, /*f*/D9, /*g*/D8);
#else
#endif

while (true)
{
    if (!pressbutton)
    {
        light[0] = 1;// reset lights
        light[1] = 1;
        light[2] = 1;
        light[3] = 1;
        light[4] = 1;
        light[5] = 1;
        light[6] = 1;
        int number = rand() % 6+1;
        switch(number)
        {
        case 1:
        light[1] = 0; //b
        light[2] = 0; //c
        break;
        case 2:
        light[0] = 0; //a
        light[1] = 0; //b
        light[6] = 0; //g
        light[4] = 0; //e
        light[3] = 0; //d
        break;
        case 3:
        light[0] = 0; //a
        light[1] = 0; //b
        light[6] = 0; //g
        light[2] = 0; //c
        light[3] = 0; //d
        break;
        case 4:
        light[5] = 0; //f
        light[6] = 0; //g
        light[2] = 0; //c
        light[1] = 0; //b
        break;
        case 5:
        light[0] = 0; //a
        light[5] = 0; //f
        light[6] = 0; //g
        light[2] = 0; //c
        light[3] = 0; //d
        break;
        case 6:
        light[0] = 0; //a
        light[5] = 0; //f
        light[6] = 0; //g
        light[4] = 0; //e
        light[3] = 0; //d
        light[2] = 0; //c
        break;
        }
        thread_sleep_for(500);
    }
}
}