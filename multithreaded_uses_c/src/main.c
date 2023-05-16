// Copyright 2023 Antonio Badilla Olivas <anthonny.badilla@ucr.ac.cr>.
#include "montecarlo_simulation.h"

int main() {
  int sample_points = 100000;
  printf("Enter the number of sample points: ");
  scanf("%d", &sample_points);
  pi_aprox_using_montecarlo(sample_points);
}