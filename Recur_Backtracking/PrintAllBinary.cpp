/* Write a recursive function printAllBinary that accepts an
integer number of digits and prints all binary numbers that have
exactly that many digits, in ascending order, one per line. 

https://web.stanford.edu/class/archive/cs/cs106x/cs106x.1192/lectures/Lecture10/Lecture10.pdf
*/

#include <iostream>

void printAllBinaryHelper(int digits, std::string soFar);

void printAllBinary(int numDigits) {
    printAllBinaryHelper(numDigits, "");
}

void printAllBinaryHelper(int digits, std::string soFar) {
    if (digits == 0) {
        std::cout << soFar << std::endl;
} 
    else {
        printAllBinaryHelper(digits - 1, soFar + "0");
        printAllBinaryHelper(digits - 1, soFar + "1");
    }
}

int main() {
    printAllBinary(3);
    return EXIT_SUCCESS;
}