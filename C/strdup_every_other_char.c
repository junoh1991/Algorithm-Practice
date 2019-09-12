#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* strdup_every_other_char(const char* s) {
	int new_size = strlen(s)/2+1;
	if (new_size & 1 == 1)
		new_size++;

	char* res = (char*) malloc(new_size * sizeof(char));
	
	int i;
	int j = 0;
	for (i = 0; i < sizeof(s); i+=2){
		res[j] = s[i];
		j++;
	}
	res[j] = '\0';
	

	return res;
}


int main(){

	char* string = "house";

	char* ans = strdup_every_other_char(string);
	printf("%s\n", ans);
}

