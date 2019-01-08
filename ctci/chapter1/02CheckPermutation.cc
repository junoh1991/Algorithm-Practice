// Given two strings, write a method to decide if one is a permutation of the other.

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>


using namespace std;

// Assumption. The inputs are only small-case string
int isPermutation(string a, string b){
	static int charMap[26];

	
	if (a.size() != b.size())
		return false;

	for (int i = 0; i < a.size(); i++){
		charMap[a[i]-'a']++;
	}

	for (int i = 0; i < b.size(); i++){
		charMap[b[i]-'a']--;
	}

	for (int i = 0; i < 26; i++){
		if (charMap[i] != 0)
			return false;
	}

	return true;
}

int main(){
	string input1 = "abcdaa";
	string input2 = "badcaa";


	int ans = isPermutation(input1, input2);
	
	printf("ans %d \n", ans);

}
