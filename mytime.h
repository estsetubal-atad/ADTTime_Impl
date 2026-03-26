/**
 * @file mytime.h
 * @author your name (you@domain.com)
 * @brief Specification of ADT Time
 * @version 0.1
 * @date 2025-03-24
 * 
 * The name is chosen not to collide with system module <time.h>.
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#define TIME_OK       0    /**< Operation completed successfully */
#define TIME_NULL     1    /**< Null pointer received */
#define TIME_INVALID  2    /**< Invalid time values provided */

/** @brief Opaque structure representing a time (hour, minute, second). */
struct time;
typedef struct time* PtTime;


/**
 * @brief Creates a new Time instance set to "00:00:00".
 *
 * @return A pointer to a new Time instance, or NULL if there is no memory.
 */
PtTime timeCreate();

/**
 * @brief Destroys a Time instance and sets the pointer to NULL.
 * 
 * @param ptT Address of the Time pointer.
 * @return TIME_OK if destroyed successfully, TIME_NULL if input is NULL.
 */
int timeDestroy(PtTime *ptT);

/**
 * @brief Retrieves the hour component of a Time instance.
 * 
 * @param t Pointer to a Time instance.
 * @param hour [out] Address to store the hour value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeGetHour(PtTime t, int *hour);

/**
 * @brief Retrieves the minute component of a Time instance.
 * 
 * @param t Pointer to a Time instance.
 * @param minute [out] Address to store the minute value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeGetMinute(PtTime t, int *minute);

/**
 * @brief Retrieves the second component of a Time instance.
 * 
 * @param t Pointer to a Time instance.
 * @param second [out] Address to store the second value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeGetSecond(PtTime t, int *second);

/**
 * @brief Sets a time with the given hour, minute, and second.
 * 
 * Valid values:
 * - 0 ≤ hour < 24
 * - 0 ≤ minute < 60
 * - 0 ≤ second < 60
 * 
 * @param t Pointer to a Time instance.
 * @param hour Hour value.
 * @param minute Minute value.
 * @param second Second value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL or TIME_INVALID if the any of the time values are invalid.
 */
int timeSet(PtTime t, int hour, int minute, int second);

/**
 * @brief Advances the time by one second.
 * 
 * The time rollsover after "23:59:00", i.e., to "00:00:00"
 * 
 * @param t Pointer to a Time instance.
 * @return int TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeTick(PtTime t);


/**
 * @brief Prints a Time instance to stdout in hh:mm:ss format.
 * 
 * @param t Pointer to a Time instance.
 */
void timePrint(PtTime t);
