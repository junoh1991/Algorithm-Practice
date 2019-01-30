#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void string_reverse1(char *string){
	int size = strlen(string);
	char temp;
	
	for (int i = 0; i < size/2; ++i){
		temp = string[i];
		string[i] = string[size - 1 - i];
		string[size - 1 - i] = temp;
	}
}

char *string_reverse2(const char *string){
	int size = strlen(string);
	char *ans = (char*) malloc(size + 1);

	int i;
	for (i = 0; i < size; ++i){
		ans[i] = string[size - i - 1];
	}
	ans[i] = '\0';
	return ans;
}


int main(){
	char test1[] = "Hello World!";
	char* test2 = "Hello World!";

	string_reverse1(test1);
	printf("%s\n", test1);


	test2 = string_reverse2(test2);
	printf("%s\n", test2);
	free(test2);

}
