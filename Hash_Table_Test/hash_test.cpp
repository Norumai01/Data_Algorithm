#include <iostream>
#include <unordered_map>

using namespace std;

void printFreq(string s, string t) {
    unordered_map<char, int> map;
    // For most frequency chars identifier.
    unordered_map<char, int> temp;
    
    // Inserting into map.
    for (int i = 0; i<s.size(); i++) {
        map[s[i]]++;
    }
    
    // Finding the most frequent chars in the strings.
    int count = 0;
    char character;
    for (auto& x: map) {
        if (x.second > count) {
            count = x.second;
            character = x.first;
        }
    }
    cout << character << "->" << count << endl;
    
    // Printing out the frequency of each chars' elements
/*    for (auto& x: map) {
        cout << x.first << "->" << x.second << endl;
    }*/
}


int main() {
	string s = "anagram";
	string t = "nagaram";

    printFreq(s, t);
}