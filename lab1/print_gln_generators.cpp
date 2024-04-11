#include <gsl/gsl_rng.h>

int main() {
    const gsl_rng_type **t, **t0;
    t0 = gsl_rng_types_setup();
    for (t = t0; *t != 0; t++) {
        printf("%s\n", (*t)->name);
    }
    return 0;
}
