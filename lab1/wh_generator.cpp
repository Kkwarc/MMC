#include <iostream>
#include <fstream>
#include <cmath>
#include <tuple>
#include <vector>

class WichmannHill {
public:
    WichmannHill() {}

    std::tuple<double, double, double, double> generate_single_value(int prev_x_value, int prev_y_value, int prev_z_value) {
        double x = fmod(171 * prev_x_value, 30269);
        double y = fmod(172 * prev_y_value, 30307);
        double z = fmod(170 * prev_z_value, 30323);

        double result = fmod(x / 30269.0 + y / 30307.0 + z / 30323.0, 1.0);
        return std::make_tuple(result, x, y, z);
    }

    std::vector<double> generate_multiple_values(int amount) {
        int x = 1, y = 1, z = 1;
        std::vector<double> values;
        for (int i = 0; i < amount; i++) {
            auto [value, new_x, new_y, new_z] = generate_single_value(x, y, z);
            values.push_back(value);
            x = static_cast<int>(new_x);
            y = static_cast<int>(new_y);
            z = static_cast<int>(new_z);
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
    WichmannHill rng;
    std::vector<double> values = rng.generate_multiple_values(10000);
    rng.save_to_file(values, "wh_random_numbers.txt");
    return 0;
}

