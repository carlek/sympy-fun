#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate r2
long double calculate_r2(int R, int h) {
    long double numerator = 2.0 * R * h * (R + h + sqrt(R * R - h * h));
    long double denominator = 2.0 * R * R + 4.0 * R * h + 2.0 * R * sqrt(R * R - h * h) + 3.0 * h * h + 4.0 * h * sqrt(R * R - h * h);
    return numerator / denominator;
}

// Function to calculate r1
long double calculate_r1(int R, int h) {
    return sqrt(2) * sqrt(R) * sqrt(R + h) - R - h;
}

int main() {
    for (int R = 1; R <= 2025; ++R) {
        for (int h = 1; h <= 2025; ++h) {
            long double r2 = calculate_r2(R, h);
            if (r2 != 0 & floor(r2) == r2) { // Check if r2 is an integer
                long double r1 = calculate_r1(R, h);
                if (r1 !=0 & floor(r1) == r1) { // Check if r1 is an integer
                    cout << "R: " << R << ", h: " << h << ", r1: " << (int)r1 << ", r2: " << (int)r2 << endl;
                }
            }
        }
    }
    return 0;
}
