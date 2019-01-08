// There are three types of edits that can be performed on strings: insert a chracter,
// remove a chracter, or replace a chracter. Given two strings, write a function to check
// if they are one edit (or zero edits) away.
//
// EXAMPLE
// pale,	ple	 ->	 true
// pales, 	pale ->	 true
// pale,	bale ->	 true
// pale, 	bake ->  false


#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

// Assume inputs are small-case letters
int isOneAway(string a, string b){
	int difference = a.size() - b.size();
	if(abs(difference) > 1)
		return false;
	
	
}

int main(){
	string a = "pale";
	string b = "bale";

	int ans = isOneAway(a, b);
	
	cout << ans << endl;

}
