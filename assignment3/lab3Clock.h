// lab3Clock.h
// ENSF 694 Summer 2025 LAB 3 - EXERCISE C
// Created by: John Zhou

#ifndef lab3_exe_C_Cplx
#define lab3_exe_C_Cplx
/* The following class definition represents a clock and contains three
 * private data members called hour, minute, and second.
 */

class Clock
{
public:
    // Default constructor
    Clock();
    /* PROMISES: Initializes the clock with default values (00:00:00). */

    Clock(int s);
    /* PROMISES: Initializes the clock based on the total number of seconds (since 00:00:00).
       REQUIRES: s to be a non-negative integer representing the total seconds. */

    Clock(int hours, int minutes, int seconds);
    /* PROMISES: Initializes the clock with the given hours, minutes, and seconds.
       REQUIRES: hours (0-23), minutes (0-59), and seconds (0-59). If out of range, resets to 00:00:00. */

    int get_hour() const;
    /* PROMISES: Returns the current hour of the clock (0-23). */

    int get_minute() const;
    /* PROMISES: Returns the current minute of the clock (0-59). */

    int get_second() const;
    /* PROMISES: Returns the current second of the clock (0-59). */

    int get_time_in_seconds() const;
    /* PROMISES: Returns the current time in seconds since 00:00:00. */

    void set_hour(int h);
    /* REQUIRES: h to be in the range of 0 to 23.
       PROMISES: Sets the hour of the clock to the specified value (0-23). */

    void set_minute(int m);
    /* REQUIRES: m to be in the range of 0 to 59.
       PROMISES: Sets the minute of the clock to the specified value (0-59). */

    void set_second(int s);
    /* REQUIRES: s to be in the range of 0 to 59.
       PROMISES: Sets the second of the clock to the specified value (0-59). */

    void increment();
    /* PROMISES: Increments the clock by one second, updating the time accordingly. */

    void decrement();
    /* PROMISES: Decrements the clock by one second, updating the time accordingly. */

    void add_seconds(int s);
    /* REQUIRES: s to be a non-negative integer. If negative, prints an error message.
       PROMISES: Adds the specified number of seconds to the clock. If the total exceeds 24 hours, it wraps around. */
    void set_time(int h, int m, int s);
private:
    int hour;
    int minute;
    int second;

    // Converts the time to seconds
    int hms_to_sec() const;
    /* PROMISES: Converts the current hour, minute, and second into total seconds. */

    // Converts seconds to hour, minute, second format
    void sec_to_hms(int s);
    /* REQUIRES: s to be a non-negative integer representing total seconds.
       PROMISES: Converts the given total seconds to hour, minute, and second format. */
};

#endif
