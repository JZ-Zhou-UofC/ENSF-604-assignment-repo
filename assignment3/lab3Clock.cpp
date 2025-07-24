// lab3Clock.cpp
// ENSF 694 Summer 2025 LAB 3 - EXERCISE C
// Created by: John Zhou

#include "lab3Clock.h"
#include <iostream>
using namespace std;

Clock::Clock() : hour(0), minute(0), second(0)
{
}

Clock::Clock(int s)
{
    if (s < 0)
    {
        *this = Clock();
    }
    else
    {
        sec_to_hms(s);
    }
}
Clock::Clock(int h, int m, int s) : hour(h),
                                                    minute(m), second(s)
{
    if (s < 0 || m < 0 || h < 0 || m > 59 || s > 59 || h > 23)
    {
        *this = Clock();
    }
    else
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
}


int Clock::get_hour() const
{
    return hour;
}


int Clock::get_minute() const
{
    return minute;
}

int Clock::get_second() const
{
    return second;
}

int Clock::get_time_in_seconds() const
{
    return hms_to_sec();
}

void Clock::set_hour(int h)
{
    if (h >= 0 && h < 24)
    {
        hour = h;
    }
}


void Clock::set_minute(int m)
{
    if (m >= 0 && m < 60)
    {
        minute = m;
    }
}

void Clock::set_second(int s)
{
    if (s >= 0 && s < 60)
    {
        second = s;
    }
}

void Clock::set_time(int h, int m, int s)
{
    set_hour(h);
    set_minute(m);
    set_second(s);
}

int Clock::hms_to_sec() const
{
    return hour * 3600 + minute * 60 + second;
}

void Clock::sec_to_hms(int s)
{
    int hour = s / 3600; // Calculate hours
    hour = hour % 24;    // Ensure hours are within a 24-hour range

    this->hour = hour;
    this->minute = (s % 3600) / 60;
    this->second = s % 60;
}

void Clock::increment()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
            }
        }
    }
}
void Clock::decrement()
{
    if (hms_to_sec() == 0)
    {
        set_time(23, 59, 59);
    }
    else
    {
        sec_to_hms(hms_to_sec() - 1);
    }
}

void Clock::add_seconds(int s)
{
    if (s < 0)
    {
        cout << "Error: Seconds must be a positive integer" << endl;
        return;
    }

    int total_seconds = hms_to_sec() + s;
    total_seconds = total_seconds % (24 * 60 * 60);
    sec_to_hms(total_seconds);
}
