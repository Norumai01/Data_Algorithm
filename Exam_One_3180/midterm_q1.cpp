// For an input string of words, find the most frequently occuring word. In case of ties, report any one of them. 
// Your algorithm should be O(n) time where n is the number of words in the string
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;


string findWord(vector<string>& tokens);
 
int main() {
	string line = "I felt happy because I saw the others were happy and because I knew I should feel happy but I wasn’t really happy";
	
	// Convert string to a vector of words
	char delimiter = ' ';
	string token;
	istringstream tokenStream(line);
	vector<string> tokens;
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}	
	cout << "The most frequently occuring word is: " << findWord(tokens) << endl;
	
}

string findWord(vector<string>& tokens) {
	// Your code here
	unordered_map<string,int> wordTable;
	int count = 0;
	string freqWord;

	// Inserting each words and, if multiples appear, add on to their counter.
	for (int i = 0; i < tokens.size(); i++) {
		wordTable[tokens[i]]++; 
	}

	// Goes through the map, if word's counter is greater than the current count...
	// Then the word becomes the new frequent word.
	for (auto& x: wordTable) {
		if (x.second > count) {
			count = x.second;
			freqWord = x.first;
		}
	}
	return freqWord;
}


