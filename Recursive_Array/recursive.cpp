// Want to create an recursive function that do a sum of an array.

#include <iostream>
#include <vector>

int sumArrayRec(std::vector<int>& vec) {
    if (vec.size() == 1) {
        return vec.at(vec.size()-1);
    }
    else {
        int sum = vec.at(vec.size()-1);
        vec.pop_back();
        sumArrayRec(vec);
        return sum; 
    }
}

int sumArrayIter(std::vector<int>& vec) {
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
    std::cout << "Recursive: " << sumArrayRec(vec) << std::endl;
    // Testing Iterative Function...
    std::cout << "Iterative: " << sumArrayIter(vec) << std::endl;
    return EXIT_SUCCESS;
}