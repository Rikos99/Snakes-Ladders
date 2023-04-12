//
// Created by richard on 1/11/23.
//

#include "snakes-and-ladders.h"
#include <stdio.h>



int snakes(int *hracX, int *hracY, int hrac)
{
    if(*hracX==7 && *hracY==2)
    {
        *hracX = 3;
        *hracY = 2;
        snake(hrac);
    }

    if(*hracX==2 && *hracY==6)
    {
        *hracX=9;
        *hracY=3;
        snake(hrac);
    }

    if(*hracX==7&& *hracY==6)
    {
        *hracX=0;
        *hracY=4;
        snake(hrac);
    }

    if(*hracX==2&& *hracY==7)
    {
        *hracX=2;
        *hracY=3;
        snake(hrac);
    }

    if(*hracX==8&& *hracY==9)
    {
        *hracX=8;
        *hracY=2;
        snake(hrac);
    }

    if(*hracX==5&& *hracY==10)
    {
        *hracX=1;
        *hracY=6;
        snake(hrac);
    }

    if(*hracX==7&& *hracY==10)
    {
        *hracX=9;
        *hracY=8;
        snake(hrac);
    }
}
int ladders(int *hracX, int *hracY, int hrac)
{
    if(*hracX==3 && *hracY==1)
    {
        *hracX = 1;
        *hracY = 3;
        ladder(hrac);
    }
    if(*hracX==8 && *hracY==1)
    {
        *hracX = 10;
        *hracY = 3;
        ladder(hrac);
    }
    if(*hracX==8 && *hracY==6)
    {
        *hracX = 7;
        *hracY = 8;
        ladder(hrac);
    }
    if(*hracX==5 && *hracY==8)
    {
        *hracX = 6;
        *hracY = 9;
        ladder(hrac);
    }
    if(*hracX==10 && *hracY==9)
    {
        *hracX = 1;
        *hracY = 10;
        ladder(hrac);
    }
    if(*hracX==10 && *hracY==8)
    {
        *hracX = 10;
        *hracY = 10;
        ladder(hrac);
    }
    if(*hracX==8 && *hracY==3)
    {
        *hracX = 4;
        *hracY = 9;
        ladder(hrac);
    }




}
void snake(int hrac)
{
    switch(hrac)
    {
        case 1:
            printf("Hrac1: Vstoupili jste na hada.\n");
            break;
        case 2:
            printf("Hrac2: Vstoupili jste na hada.\n");
            break;
    }
}

void ladder(int hrac)
{
    switch(hrac)
    {
        case 1:
            printf("Hrac1: Vstoupili jste na zebrik.\n");
            break;
        case 2:
            printf("Hrac2: Vstoupili jste na zebrik.\n");
            break;
    }
}


