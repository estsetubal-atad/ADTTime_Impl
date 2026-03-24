# Time ADT (Impl)

This project implements an Abstract Data Type (ADT) for representing *time*, encapsulating its data structure. 

> [!NOTE]
> This is a C program template generated from:
>
> - <https://github.com/estsetubal-atad/CProgram_Template>


# Exercises

You are provided with an initial specification of the ADT:

```cpp
/* Error codes */
#define TIME_OK       0
#define TIME_NULL     1
#define TIME_INVALID  2

/* Opaque structure and pointer (data type) */ 
struct time;
typedef struct time* PtTime;

/* Operations */
PtTime timeCreate();
int timeDestroy(PtTime *ptT);
int timeGetHour(PtTime t, int *hour);
int timeGetMinute(PtTime t, int *minute);
int timeGetSecond(PtTime t, int *second);
int timeSet(PtTime t, int hour, int minute, int second);
int timeTick(PtTime t);
void timePrint(PtTime t);
```

and a test program:

```cpp
#include "mytime.h"

int main() {
    PtTime t = timeCreate();
    timePrint(t);  // "00:00:00"

    int error = timeSet(t, 14, 30, 45);
    if( error != TIME_OK ) {
        printf("An error occured: %d\n", error);
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
```

## 1 | Implementation 

In `mytime.c`:

1. Choose a representation for the `struct time` data structure to store "time", from the following:

- `int hour, minute, seconds;`, or
- `int totalSeconds;` (elapsed from 00:00:00)
  - :bulb: Each will have advantages/disadvantages in implementing certain operations. Choose wisely! You can check below which other operations you'll be asked to implement.

2. Implement the functions and test the program.

## 2 | Additional operations (1/2)

Add the following operations to the *Time ADT*:

```cpp
/**
 * @brief Adds two Time instances and returns the result.
 * 
 * Addition wraps around at midnight: 24:00:00 -> 00:00:00.
 * 
 * @param t1 First Time operand.
 * @param t2 Second Time operand.
 * @return A new Time instance representing the sum, or NULL if any argument is NULL or there is no memory.
 */
PtTime timeAdd(PtTime t1, PtTime t2);

/**
 * @brief Computes the (absolute) difference between two Time instances.
 * 
 * There are no "negative times".
 * 
 * Example: 
 * 			|12:30:00 - 10:15:30| = 02:14:30
 * 			|10:15:30 - 12:30:00| = 02:14:30
 * 
 * @param t1 First Time operand.
 * @param t2 Second Time operand.
 * @return A new Time instance representing the (absolute) difference, or NULL if any argument is NULL or there is no memory.
 */
PtTime timeDiff(PtTime t1, PtTime t2);
```

## 3 | A problem to solve

🚆 **The Train Ride Problem**

Bruno is taking a train from Setúbal to Lisbon.

- The train departs at **08:47:35**
- It arrives at **09:32:10**

However, the train makes a short stop along the way:

- It pauses for **00:05:20** at a station

🎯 **Your Task**

Using the Time ADT, determine:

👉 How long Bruno actually spent moving on the train (excluding the stop).

## 4 | Additional operations (2/2)

Add the following operations and the *doxygen* documentation to the ADT and test them:

```cpp
int timeToSeconds(PtTime t, int *totalSeconds);
→ Returns the total number of seconds elapsed from "00:00:00"

PtTime timeCreateFrom(int hour, int minute, int second);
→ Creates a new time instance with an inital time set (performs validation of all arguments).
→ In C, we cannot have two functions with the same name

int timeCompare(PtTime t1, PtTime t2);
→ Compares two instances (similar to `strcmp`): returns `<0`, `0` or `>0`.

bool timeEquals(PtTime t1, PtTime t2);
→ Checks if the instances contain the same time.

bool timeSame(PtTime t1, PtTime t2);
→ Checks if the instances are **the same** (same pointer/address).

PtTime timeNow();
→ Returns a new time instance with the current time (use `time.h` helper functions).
```