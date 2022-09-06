#include <iostream>

int recursivePower(int n, int m) { 
    if (m == 0) {
        return 1;
    }
    else {
        return n * recursivePower(n,m-1);
    }
    /* 
    Testing Partial Product    // Comment else statement if testing.
    std::cout << "m: " << m << std::endl;
    int prod = n * recursivePower(n,m-1);
    std::cout << "Partial Product: " << prod << endl;
    return prod;
    */
}

int iterativePower(int n, int m) {
    int prod = 1;
    for (int i = 0; i < m; i++) {
        prod *= n;
    }
    return prod;
}

int main() {
    int n = 5;
    int m = 3;
    // Testing Recursive Function...
    std::cout << "Recursive: " << recursivePower(n,m) << std::endl;
    // Testing Iterative Function...
    std::cout << "Iterative: " << iterativePower(n,m) << std::endl;
    return EXIT_SUCCESS;
}