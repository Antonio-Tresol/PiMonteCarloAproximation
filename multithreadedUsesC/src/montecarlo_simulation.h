// Copyright 2023 Antonio Badilla Olivas <anthonny.badilla@ucr.ac.cr>.
#include <limits.h>
#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef M_PI_H
#define M_PI_H

typedef long double float64_t;
/// @brief Generates a random float64_t number between 0 and 1
/// @return float64_t random number
float64_t random_float64();
/// @brief Aproximates the value of Pi using the montecarlo method
/// @param sample_points
void pi_aprox_using_montecarlo(int64_t sample_points);

#endif