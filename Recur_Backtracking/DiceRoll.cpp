// Prints all possible outcomes of rolling the given
// number of six-sided dice in {#, #, #} format.
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, std::vector<int> vec) {
    for (auto& ele: vec) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    return os;
}

void diceRollHelper(int dice, std::vector<int>& chosen);

void diceRoll(int dice) {
    std::vector<int> chosen;
    diceRollHelper(dice, chosen);
}

void diceRollHelper(int dice, std::vector<int>& chosen) {
    if (dice == 0) {
        std::cout << chosen << std::endl;
    }
    else {
        for (int i = 1; i <= 6; i++) {
            chosen.push_back(i);
            diceRollHelper(dice - 1, chosen);
            chosen.pop_back();
        }
    }
}

int main() {
    diceRoll(2);
    return EXIT_SUCCESS;
}