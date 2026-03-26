#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "mytime.h"

int main() {
    PtTime t = timeCreate();
    timePrint(t);  // "00:00:00"

    int errorCode = timeSet(t, 14, 30, 45);
    if( errorCode != TIME_OK ) {
        printf("An error occured: %d\n", errorCode);
    } else {
        timePrint(t);  // "14:30:45"
    }

    timeTick(t);
    timePrint(t);  // "14:30:46"

    int h, m, s;      
    timeGetHour(t, &h);
    timeGetMinute(t, &m);
    timeGetSecond(t, &s);

    printf("%d hours, %d minutes and %d seconds.\n", h, m, s); 
    
    timeDestroy(&t);

    return EXIT_SUCCESS;
}
