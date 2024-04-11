#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <iomanip>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::string> generators = {"minstd_rand", "mt19937", "mt19937_64", "ranlux48_base", "ranlux48", "knuth_b"};
    std::vector<double> generation_times(generators.size());

    for (size_t i = 0; i < generators.size(); ++i) {
        std::uniform_real_distribution<double> distribution(0.0, 10.0);

        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; ++j) {
            double random_number = distribution(gen);
        }
        auto end = std::chrono::high_resolution_clock::now();
        generation_times[i] = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << generators[i] << ": " << generation_times[i] << " ms" << std::endl;
    }
    return 0;
}
