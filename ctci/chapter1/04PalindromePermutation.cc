// Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is a rearragement of letters. The palindrome does not need to be limited
// to just dictionary words.
// 
// EXAMPLE
// Input:	Tact Coa
// Output:  True (permutations: "taco cat", "atco cta", etc


#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string a){
	static int charMap[26];

	for (int i = 0; i< a.size(); i++){
		if (a[i] == ' ')
			continue;

		// If big case, change to a small case
		if (a[i] < 'a'){
			a[i] = a[i] | 0x20;
		}

		charMap[a[i]-'a']++;
	}

	int oddCounter = 0;
	for (int i = 0; i < 26; i++){
		if(charMap[i] % 2 == 1){
			oddCounter++;
			if (oddCounter >1)
				return false;
		}

	}

	return true;
}


int main(){
	string input = "tact Coap";
	printf("%d\n", isPalindrome(input));

}
