/*
Leetcode Problem 242 - Valid Anagram

 Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

NOTE: Your code has to run in O(n) time where n is the number of letters. 
Zero points for any non-O(n) algorithm.
*/

#include <iostream>
#include <unordered_map>

using namespace std;
bool isAnagram(string s, string t);


int main() {
	string s = "anagram";
	string t = "nagaram";
	if (isAnagram(s, t)) cout << "True" << endl;
	else cout << "False" << endl;
	s = "rat";
	t = "car";
	if (isAnagram(s, t)) cout << "True" << endl;
	else cout << "False" << endl;
}

bool isAnagram(string s, string t) {
// Your code here
	unordered_map<char, int> container;

	// Adds char-elements of the string s into the hash table. 
	// If there's a copy, it will add one to the value of the key element. 
	for (int i = 0; i < s.size(); i++) {
		if (container.find(s[i]) == container.end()) {
			container.insert(make_pair(s[i], 1));
		} 
	else {
		    container[s[i]]++;
		}
	}

	// If there an element unmatched from string t, return false.
	// If an element matched, erase key element or decrease by one if multiple.
	for (int i = 0; i < t.size(); i++) {
		if (container.find(t[i]) == container.end()) {
		    return false;
		} 
		else {
		    if (container[t[i]] == 1) {
				container.erase(t[i]);
			}
			else {
				container[t[i]]--;
			}
		}
	}

	// If container empty after all processes, return true. 
	if (container.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
