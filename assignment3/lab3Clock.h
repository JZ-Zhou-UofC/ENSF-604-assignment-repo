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
    // PROMISES: Initializes the clock with default values (00:00:00).

    // Constructor that initializes the clock from seconds
    Clock(int s);
    // PROMISES: Initializes the clock based on the total number of seconds (since 00:00:00).
    // REQUIRES: s to be a non-negative integer representing the total seconds.

    // Constructor that initializes the clock from hours, minutes, and seconds
    Clock(int hours, int minutes, int seconds);
    // PROMISES: Initializes the clock with the given hours, minutes, and seconds.
    // REQUIRES: hours (0-23), minutes (0-59), and seconds (0-59). If out of range, resets to 00:00:00.

    // Getter for hour
    int get_hour() const;
    // PROMISES: Returns the current hour of the clock (0-23).

    // Getter for minute
    int get_minute() const;
    // PROMISES: Returns the current minute of the clock (0-59).

    // Getter for second
    int get_second() const;
    // PROMISES: Returns the current second of the clock (0-59).

    // Getter for time in seconds
    int get_time_in_seconds() const;
    // PROMISES: Returns the current time in seconds since 00:00:00.

    // Setter for hour
    void set_hour(int h);
    // PROMISES: Sets the hour of the clock to the specified value (0-23).
    // REQUIRES: h to be in the range of 0 to 23.

    // Setter for minute
    void set_minute(int m);
    // PROMISES: Sets the minute of the clock to the specified value (0-59).
    // REQUIRES: m to be in the range of 0 to 59.

    // Setter for second
    void set_second(int s);
    // PROMISES: Sets the second of the clock to the specified value (0-59).
    // REQUIRES: s to be in the range of 0 to 59.

    // Increments the clock by one second
    void increment();
    // PROMISES: Increments the clock by one second, updating the time accordingly.

    // Decrements the clock by one second
    void decrement();
    // PROMISES: Decrements the clock by one second, updating the time accordingly.

    // Adds a specified number of seconds to the clock
    void add_seconds(int s);
    // PROMISES: Adds the specified number of seconds to the clock. If the total exceeds 24 hours, it wraps around.
    // REQUIRES: s to be a non-negative integer. If negative, prints an error message.

    // Setter to set all time values at once
    void set_time(int h, int m, int s);
    // PROMISES: Sets the hour, minute, and second of the clock to the specified values.
    // REQUIRES: h (0-23), m (0-59), and s (0-59).

private:
    int hour;
    int minute;
    int second;
    
    // Converts the time to seconds
    int hms_to_sec() const;
    // PROMISES: Converts the current hour, minute, and second into total seconds.

    // Converts seconds to hour, minute, second format
    void sec_to_hms(int s);
    // PROMISES: Converts the given total seconds to hour, minute, and second format.
    // REQUIRES: s to be a non-negative integer representing total seconds.
};

#endif
