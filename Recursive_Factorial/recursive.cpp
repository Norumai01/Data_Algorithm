#include <iostream>

int recursiveFactorial(int n) {
    if (n == 0) return 1;
    else return n * recursiveFactorial(n-1);
}

int iterativeFactorial(int n) {
    int prod = 1;
    for (int i = n; i >= 1; i--) {
        prod = prod * i;
    }
    return prod;
}

int main() {
    int val = 5;
    
    // Testing recursive Factorial
    std::cout << "Recursive: " << recursiveFactorial(val) << std::endl;
    // Testing iterative Factorial
    std::cout << "Iterative: " << iterativeFactorial(val) << std::endl;
    return EXIT_SUCCESS;
}