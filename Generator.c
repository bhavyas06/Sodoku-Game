#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Generator.h"

int randomGenerator(int num) {
    int n = (int)floor((float)(rand() / (double)RAND_MAX*num+1));
    return n;
}