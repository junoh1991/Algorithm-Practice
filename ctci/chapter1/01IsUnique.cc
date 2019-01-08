// Is Unique: Implement an algorithm to determine if a string has all unique characters. 
// What if you cannot use additional data structures?

#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

bool charMap[26];

int isUnique(string str){

	for (int i = 0; i < str.size(); i++){
		if (charMap[str[i]] == 1)
			return false;
		else
			charMap[str[i]] = 1;
	}

	return true;
}

int main(){

	string input = "hapy";
	cout << isUnique(input) << endl;
	
	return 0;
}
