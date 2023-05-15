// Copyright 2023 Antonio Badilla Olivas <anthonny.badilla@ucr.ac.cr>.
// this program computes an aproximation of pi using the monte carlo method

// Import the Rng trait from the rand crate to generate random numbers
use rand::Rng;
use std::io;

fn main() {
    let mut input = String::new();
    println!("Enter the number of points to use for the approximation of pi: ");
    io::stdin().read_line(&mut input).unwrap();
    // Convert the input to an integer
    let total_points: i32 = input.trim().parse().unwrap();
    // Initialize the counter for the number of points inside the circle
    let mut inside_circle: i32 = 0;
    // Create a random number generator
    let mut rng = rand::thread_rng();
    // Iterate from 0 to total_points
    for _ in 0..total_points {
        // Generate a random x-coordinate between 0 and 1
        let x: f64 = rng.gen_range(0.0..1.0);

        // Generate a random y-coordinate between 0 and 1
        let y: f64 = rng.gen_range(0.0..1.0);

        // Calculate the squared Euclidean distance from the origin (0, 0) to the point (x, y)
        let distance = x.powi(2) + y.powi(2);

        // Check if the distance is less than or equal to 1 (meaning the point is inside the circle)
        if distance <= 1.0 {
            // Increment the counter for points inside the circle
            inside_circle += 1;
        }
    }
    // Calculate the approximation of pi using the ratio of points inside the circle to total points, multiplied by 4
    let pi_aproximation = 4.0 * (inside_circle as f64 / total_points as f64);
    // Print the approximation of pi
    println!("pi approximation: {}", pi_aproximation);
}
