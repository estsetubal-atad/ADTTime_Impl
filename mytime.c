#include <stdio.h>
#include <stdlib.h>
#include "mytime.h"

typedef struct time {    
   // TODO
} Time;


PtTime timeCreate() {
    
    // TODO

    return NULL;
}

int timeDestroy(PtTime *ptT) {
    if (ptT == NULL || *ptT == NULL) return TIME_NULL;
    
    free(*ptT);
    *ptT = NULL;

    return TIME_OK;
}

int timeGetHour(PtTime t, int *hour) {
    
    // TODO

    return TIME_OK;
}

int timeGetMinute(PtTime t, int *minute) {
    
    // TODO
    
    return TIME_OK;
}

int timeGetSecond(PtTime t, int *second) {
    
    // TODO
    
    return TIME_OK;
}

int timeSet(PtTime t, int hour, int minute, int second) {
    
    // TODO
    
    return TIME_OK;
}

int timeTick(PtTime t) {
    
    // TODO
    
    return TIME_OK;
}

void timePrint(PtTime t) {
    // TODO: Print in hh:mm:ss format
}
