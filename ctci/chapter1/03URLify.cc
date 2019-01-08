// Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional chracters, and that you are givin the "true"
// length of the string.
//
// EXAMPLE
// Input:	"Mr John Smith    ", 13
// Output:  "Mr%20John%20Smith"


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void URLify(char* a, int size){
	int counter = 0;
	int numSpaces = 0;

	// Find how many space exists in the true string
	for (int i = size - 1; i >= 0; i--){
		if (a[i] == ' ')
			numSpaces++;
	}

	// Iterate from the end of the string
	for (int i = size - 1; i >= 0; i--){
		//Find the space chracter
		if (a[i] != ' ')
			counter++;
		else{
			for (int j = i + counter; j > i; j--){
				a[i + j + numSpaces * 2] = a[i + j];
			}
			

			numSpaces--;
			counter = 0;

			a[i + numSpaces*2] = '%';
			a[i + numSpaces*2 + 1] = '2';
			a[i + numSpaces*2 + 2] = '0';
	
			i = i + numSpaces*2 - 1;
			
			if (numSpaces != 0){
				while (a[i] == ' ')
					i--;
			}

		}
	}	

}

int main(){
	char input[] = "Mr John Smith    ";
	URLify(input, 13);
	printf("%s\n", input);
}
