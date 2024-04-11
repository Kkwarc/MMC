#include <iostream>
#include <fstream>
#include <cmath>
#include <tuple>
#include <vector>

class BasicMultiGenerator {
public:
    int a;
    int c;
    int m;
    BasicMultiGenerator(int a, int c, int m) {
        this->a = a;
        this->c = c;
        this->m = m;
    }

    double generate_single_value(int prev_value) {
        double result = fmod(a * prev_value + c, m-1);
        return result;
    }

    std::vector<double> generate_multiple_values(int amount) {
        int x = 1;
        std::vector<double> values;
        for (int i = 0; i < amount; i++) {
            double result = generate_single_value(x);
            values.push_back(result);
            x = static_cast<int>(result);
        }
        return values;
    }

    void save_to_file(const std::vector<double>& values, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (double value : values) {
                file << value << "\n";
            }
            file.close();
            std::cout << "Values saved to file: " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
};

int main() {
    BasicMultiGenerator rng_1(17, 0, pow(2, 13));
    BasicMultiGenerator rng_2(58, 0, pow(2, 13));
    std::vector<double> values_1 = rng_1.generate_multiple_values(2500);
    std::vector<double> values_2 = rng_2.generate_multiple_values(2500);
    rng_1.save_to_file(values_1, "rng_a17_random_numbers.txt");
    rng_1.save_to_file(values_2, "rng_a58_random_numbers.txt");
    return 0;
}

