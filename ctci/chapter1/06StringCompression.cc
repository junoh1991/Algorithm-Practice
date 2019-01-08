// Implement a method to perform basic string compression using the
// counts of repeated characters. For example, the string aabcccccaaa
// would become a2b1c5a3. If the "compressed" string would not become
// smaller than the original string, your method should return the original
// string. You can assume the string has only uppercdase and lowercase(a-z)

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string stringCompression(string a){
	int counter = 1;
	string ans;
	for (int i = 0; i < a.size(); i++){
		if (i == a.size() -1){
			ans = ans + a[i] + to_string(counter);
		}
		else if (a[i] == a[i+1])
			counter++;
		else{
			ans = ans + a[i] + to_string(counter);
			counter = 1;
		}
	}

	if (ans.size() < a.size())
		return ans;
	else
		return a;
}

int main(){
	string input = "abbbcccccc";
	string output = stringCompression(input);

	cout << output<< endl;

}
