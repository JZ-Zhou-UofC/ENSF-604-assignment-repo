// lab3Clock.h
// ENSF 694 Summer 2025 LAB 3 - EXERCISE C
// Created by: John Zhou

#ifndef lab3_exe_C_Cplx
#define lab3_exe_C_Cplx
/* The following class definition represnets Complex Numbers and contains two
 * private data members called realM (the real part of a complex number),
 * and imagM (the imaginary part of a complex number).
 */

class Clock
{
public:
    Clock();
    // PROMISES: initializes the real part and the imaginary part of a complex number
    // with zero.

    Clock(int s);
    // PROMISES: initializes the real part and the imaginary part of a complex number
    // with the supplied values by r, and i, respectively.
    Clock(int hours, int minutes, int seconds);
    // PROMISES: initializes the real part and the imaginary part of a complex number
    // with the supplied values by r, and i, respectively.

    // Getter functions (const because they don't modify the object)
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    int get_time_in_seconds() const;
    // Setter functions (with validation)
    void set_hour(int h);
    void set_minute(int m);
    void set_second(int s);
    void increment();
    void decrement();
    void add_seconds(int s);
    // Setter function for setting time (hour, minute, second)
    void set_time(int h, int m, int s);

private:
    int hour;
    int minute;
    int second;
    int hms_to_sec() const;
    void sec_to_hms(int s);
};
#endif
