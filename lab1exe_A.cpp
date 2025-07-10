/*
 *  lab1exe_A.cpp
 *  ENSF 694 Lab 1, exercise A
 *  Created by Mahmood Moussavi
 *  Completed by: John Zhou
 */

#include <iostream>
#include <cmath>

using namespace std;

const double G = 9.8; /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    double velocity;

    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;

    if (!cin) // means if cin failed to read
    {
        cout << "Invlid input. Bye...\n";
        exit(1);
    }

    while (velocity < 0)
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if (!cin)
        {
            cout << "Invlid input. Bye...";
            exit(1);
        }
    }
    create_table(velocity);

    return 0;
}

double degree_to_radian(double d)
/*
 * REQUIRES:
 *   - angle 'd' in degrees
 *
 * PROMISES:
 *   - Returns the corresponding angle in radians.
 */
{

    return d * PI / 180.0;
}

double Projectile_travel_time(double a, double v)
/*
 * REQUIRES:
 *   - a (angle) in degrees
 *   - v (velocity) in m/s (v > 0).
 *
 * PROMISES:
 *   - Returns the time of flight for the projectile
 *     Formula: time = (v^2 * sin(2 * a)) / g
 */

{
    double radian = degree_to_radian(a);
    return v * v * sin(2 * radian) / G;
};
double Projectile_travel_distance(double a, double v)
/*
 * REQUIRES:
 *   - a (angle) in degrees
 *   - v (velocity) in m/s (v > 0).
 *
 * PROMISES:
 *   - Returns the horizontal distance the projectile will travel
 *     Formula: distance = (2 * v * sin(a)) / g
 */
{
    double radian = degree_to_radian(a);
    return 2 * v * sin(radian) / G;
};

void create_table(double v)
/*
 * REQUIRES:
 *   - velocity 'v' > 0.
 *
 * PROMISES:
 *   - Prints a table showing the time of flight and distance for projectile for each angle from 0° to 90°, at the given velocity.
 */
{
    cout << "Angle\t\tt\t\td\n";
    cout << " (deg)\t\t(sec)\t\t(m)\n";
    for (int a = 0; a <= 90; a += 5)
    {
        double time = Projectile_travel_time(a, v);
        double distance = Projectile_travel_distance(a, v);
        cout << a << "\t\t" << time << "\t\t" << distance << "\n";
    }
}