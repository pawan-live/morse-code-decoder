#include <stdio.h>
#include <string.h>
#include "morseCode.h"
int getCharType(char character);
const char* getMorseCodeByChar(char);

int main(void) {
	char string[] = {}; //for input

  printf("Enter string:\n");
	scanf("%[^\n]", string); //read with spaces
	
	//get first character type
	int result = getCharType(string[0]);

	//get morsecode by character
	for (int i = 0; i < strlen(string); i++) {
		int charType = getCharType(string[i]);
		if (charType == 2) {
			string[i] = string[i] - 32;
		} else if (charType == 3) {
			continue;
		}
		printf("%s ", getMorseCodeByChar(string[i]));
	}

  return 0;
}

/* Function returns following values based on 
*  character type input
*  number 0 - 9     --> 0
*  character A - Z  --> 1
*  character a - z  --> 2
*  other            --> 3
*/
int getCharType(char character) {
	if (character >= 0 && character < 10){ //numbers 0-9
		return 0; 
	}	else if (character > 64 && character < 91) { //uppercase
		return 1;
	} else if (character > 96 && character < 123) { //lowercase
		return 2;
	} else {
		return 3;
	}
}