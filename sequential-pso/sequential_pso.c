#include <api>  // Memphis parallel platform api
#include <stdlib.h>

int fitness(int x, int y, int z) {

    int penalty = 10000;

    int objective_function = 10 * pow((x - 1), 2) + 20 * pow((y - 2), 2) + 30 * pow((z - 3), 2);

    // Constrains (all constrains must be converted into <=0)
    int constrains[2];
    
    constrains[0] = x + y + z - 5;
    constrains[1] = pow(x, 2) + 2 * y - z;

    // defining penalty for each constrain
    int count = sizeof(constrains);
    int constrain_sum = 0;
    for (size_t i = 0; i < count; i++) {
        if (constrains[i] > 0) {
            constrain_sum++;
        }
    }

    return objective_function + penalty * constrain_sum;
}

void main(){

    int lower_bounds[3] = {0, 0, 0};
    int upper_bounds[3] = {10, 10, 10};

    // PSO parameters
    int dimensions = 3;
    int population = 100;
    int inertia_weight = 1;
    // float damping_factor = 0.99; // Memphis supposedely doesn't support floats
    int cognitive_weight = 2;
    int social_weight = 2;
    int min_velocity = -2;
    int max_velocity = 2;
    int error_tolerance = 1;
    int max_iterations = 100;

    /*  PSO initialization  */
    // initializing population
    Echo("Initializing population");
    int particles[population][dimensions];
    int velocity[population][dimensions];
    for (size_t i = 0; i < population; i++) {
        for (size_t j = 0; j < dimensions; j++) {
            particles[i][j] = lower_bounds[j] + rand() % (upper_bounds[j] - lower_bounds[j] + 1);
            velocity[i][j] = min_velocity + rand() % (max_velocity - min_velocity + 1);
        }
    }
    
    // initialize best_position same as positions
    int best_position[population][dimensions] = particles;
    
    // calculate initial fitness
    int fitness_values[population];
    int population_best_position[dimensions];
    int population_best_fitness[100];
    int global_best_position[dimensions];
    int global_best_fitness = 0;
    for (size_t i = 0; i < population; i++) {
        fitness_values[i] = fitness(particles[i][0], particles[i][1], particles[i][2]);
        population_best_fitness[i] = fitness_values[i];
        if (i == 0) {
            global_best_position = particles[0];
            global_best_fitness = fitness_values[0];
        } else if (fitness_values[i] < global_best_fitness) {
            global_best_position = particles[i];
            global_best_fitness = fitness_values[i];
        }
    }

    /*  PSO execution  */
    for (size_t i = 0; i < max_iterations; i++) {

        // Sanity check
        if ((i + 1 % 50) == 0) {
            Echo("Iteration number: ");
            Echo(itoa(i + 1));
        }

        // apply dampening to inertia weight
        // NOT DONE DUE TO MISSING FLOAT SUPPORT IN MEMPHESSIS
        // inertia_weight = inertia_weight * damping_factor;

        // update velocity and position
        for (size_t j = 0; j < population; j++) {
            for (size_t k = 0; k < dimensions; k++) {
                velocity[j][k] = inertia_weight * velocity[j][k] +
                cognitive_weight * rand() % (best_position[j][k] - particles[j][k]) + 
                social_weight * rand() % (global_best_position[k] - particles[j][k]);

                particles[j][k] = particles[j][k] + velocity[j][k];
                
                // clamp position to boundaries
                if (particles[j][k] < lower_bounds[k]) {
                    particles[j][k] = lower_bounds[k];
                } else if (particles[j][k] > upper_bounds[k]) {
                    particles[j][k] = upper_bounds[k];
                }
            }
            // update fitness
            fitness_values[j] = fitness(particles[j][0], particles[j][1], particles[j][2]);

            // update best position
            if (fitness_values[j] < population_best_fitness[j]) {
                best_position[j][0] = particles[j][0];
                best_position[j][1] = particles[j][1];
                best_position[j][2] = particles[j][2];
                population_best_fitness[j] = fitness_values[j];

                // update global best position
                if (fitness_values[j] < global_best_fitness) {
                    global_best_position[0] = particles[j][0];
                    global_best_position[1] = particles[j][1];
                    global_best_position[2] = particles[j][2];
                    global_best_fitness = fitness_values[j];
                }
            }
        }

        // check error tolerance
        if (global_best_fitness <= error_tolerance) {
            Echo("Error tolerance reached.");
            break;
        }
    }
    
    Echo("Best fitness found:");
    Echo(itoa(global_best_fitness));
    Echo("Best position found:");
    Echo(itoa(global_best_position[0]));
    Echo(itoa(global_best_position[1]));
    Echo(itoa(global_best_position[2]));

    // Terminate program
    exit();
}