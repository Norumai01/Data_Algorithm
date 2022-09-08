// Want to create an recursive function that do a sum of an array.

#include <iostream>
#include <vector>

// sum (1,7,3,4,8) = 3 + sum(1,7) + sum(4,8) --> Binary Recursion
int sumArrayBinary(std::vector<int>& vec, int start, int stop) {
    int mid; 
    if (start > stop) {
        return 0;   // If no elements, return sum is zero.
    }
    else {
        mid = start + (stop - start)/2;
        return vec.at(mid) + sumArrayBinary(vec, start, mid-1) + sumArrayBinary(vec, mid+1, stop);
    }

}

int sumArrayRec(std::vector<int>& vec, int stop) {    // Recursion
    if (stop < 0) {
        return 0;   // If no size, sum is zero.
    }
    else if (stop == 0) {
        return vec.at(stop);    // If one element, the sum is the only element.
    }
    else {
        return vec.at(stop) + sumArrayRec(vec, stop-1);
    }
}

int sumArrayIter(std::vector<int>& vec) {     // Iterative
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum; 
    /*
    // Alternative: Automatically go through the entire loop of the vector. Part of C++ Ver. 2011.
    for (auto& e : vec) {
        sum += e;
    }
    return sum;
    */
}

int main() {
    std::vector<int> vec{1, 7, 3, 4, 8};
    // Testing Recursive Function...
    std::cout << "1st Vector's Recursive: " << sumArrayRec(vec, vec.size()-1) << std::endl;
    // Testing Iterative Function...
    std::cout << "1st Vector's Iterative: " << sumArrayIter(vec) << std::endl;
    // Testing Binary Recursion Function...
    std::cout << "1st Vector's Iterative: " << sumArrayBinary(vec, 0, vec.size()-1) << std::endl;

    std::cout << "\n\n";

    std::vector<int> vec1{1};
    // Testing Recursive Function...
    std::cout << "2nd Vector's Recursive: " << sumArrayRec(vec1, vec1.size()-1) << std::endl;
    // Testing Iterative Function...
    std::cout << "2nd Vector's Iterative: " << sumArrayIter(vec1) << std::endl;
    // Testing Binary Recursion Function...
    std::cout << "2nd Vector's Iterative: " << sumArrayBinary(vec1, 0, vec1.size()-1) << std::endl;

    std::cout << "\n\n";
    
    std::vector<int> vec2{};
    // Testing Recursive Function...
    std::cout << "3rd Vector's Recursive: " << sumArrayRec(vec2, vec2.size()-1) << std::endl;
    // Testing Iterative Function...
    std::cout << "3rd Vector's Iterative: " << sumArrayIter(vec2) << std::endl;
    // Testing Binary Recursion Function...
    std::cout << "3rd Vector's Iterative: " << sumArrayBinary(vec2, 0, vec2.size()-1) << std::endl;

    std::cout << "\n\n";    
    
    std::vector<int> vec3{1, 2, 3, 4, 5, 6, 7, 8};
    // Testing Recursive Function...
    std::cout << "4th Vector's Recursive: " << sumArrayRec(vec3, vec3.size()-1) << std::endl;
    // Testing Iterative Function...
    std::cout << "4th Vector's Iterative: " << sumArrayIter(vec3) << std::endl;
    // Testing Binary Recursion Function...
    std::cout << "4th Vector's Iterative: " << sumArrayBinary(vec3, 0, vec3.size()-1) << std::endl;
    return EXIT_SUCCESS;
}