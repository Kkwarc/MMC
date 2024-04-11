#include <chrono>
#include <iostream>
#include <gsl/gsl_rng.h>

int main() {
    const gsl_rng_type **t, **t0;
    t0 = gsl_rng_types_setup();

    for (t = t0; *t != 0; t++) {
        gsl_rng *gen = gsl_rng_alloc(*t);
        gsl_rng_set(gen, 12345);

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000000; i++) {
            gsl_rng_uniform(gen);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        gsl_rng_free(gen);

        std::cout << (*t)->name << ": " << static_cast<double>(duration) / 1000000.0 << " us" << std::endl;
    }

    return 0;
}
