//
// Created by richard on 12/21/22.
//

#include "kostka.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kostka(int *hracX)
{
    int hod;
    srand(time(NULL));
    hod = rand() % 6 + 1;
    *hracX +=hod;
    return hod;
}