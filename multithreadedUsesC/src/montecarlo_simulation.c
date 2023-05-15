#include "montecarlo_simulation.h"

float64_t random_float64() {
  float64_t random_uint = drand48();
  return random_uint;
}

void pi_aprox_using_montecarlo(int64_t sample_points) {
  // to stores X and Y coordinates of a random point
  float64_t x = 0.0;
  float64_t y = 0.0;
  // to store distance of a random
  // point from origin
  float64_t distance = 0.0;

  // Stores number of points inside circle
  int64_t inside_circle = 0;

  // Stores number of points inside square
  int64_t inside_square = 0;

  int64_t i = 0;

// use omp to parallelize the for loop here we use reduction to sum the number
// of points inside the circle and the square
#pragma omp parallel firstprivate(x, y, distance, i) \
    reduction(+ : inside_circle, inside_square)
  {  // NOLINT
    srand48(time(NULL));
    // Generates random points
    for (i = 0; i < sample_points; i++) {
      // Finds random X co-ordinate
      x = random_float64();
      // Finds random X co-ordinate
      y = random_float64();
      // computes the distance of point (x, y) from origin
      distance = ((x * x) + (y * y));
      // If d is less than or equal to 1
      if (distance <= 1) {
        // Increment inside_circle by 1
        inside_circle++;
      }
      // Increment inside_square by 1
      inside_square++;
    }
  }
  // Stores the estimated value of PI
  float64_t pi = 4.0 * ((float64_t)inside_circle / (float64_t)(inside_square));
  printf("aproximation of Pi = %Lf\n", pi);
}