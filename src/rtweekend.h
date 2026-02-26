#ifndef RTWEEKEND_H
#define RTWEEKEN_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std Usings
using std::make_shared;
using std::shared_ptr;

// Constants
const double INF = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

// Random Number Genereration -> [0,1)
inline double random_double() {
    // Returns a random real [0,1)
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Return random real [min,max)
    return min + (max-min)*random_double();
}

// Common Headers
#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif