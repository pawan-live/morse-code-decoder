/* This program gets a string as input and
*  displays it in morse code.
*  https://github.com/pawan-live/morse-code-decoder
*/

#include <stdio.h>
#include <string.h>
#include "morseCode.h"
int getCharType(char character);
const char* getMorseCodeByChar(char);

int main(void) {
	char string[] = {};

	printf("Enter string:\n");
	scanf("%[^\n]", string); //read string with spaces

	//end if '\n'
	if (string[0] == '\n') { 
		return 0; 
	}
	
	//get first character type
	int firstCharType = getCharType(string[0]);

	//if string[0] is a letter get morsecode by character
	while(firstCharType == 1 || firstCharType == 2) {
		for (int i = 0; i < strlen(string); i++) {
			int charType = getCharType(string[i]);
			if (charType == 2) {
				string[i] = string[i] - 32; //convert uppercase to lowercase
			} else if (charType == 4 || charType == 5) {
				continue;
			}
			printf("%s ", getMorseCodeByChar(string[i]));
		}
		puts("");
		break;
	}

  return 0;
}

/* Function returns following values based on 
*  character type input
*  number 0 - 9     --> 0
*  character A - Z  --> 1
*  character a - z  --> 2
*  [space]          --> 3 (might be used, not needed right now)
*  - or .           --> 4
*  other            --> 5
*/
int getCharType(char character) {
	if (character >= 0 && character < 10){ //numbers 0-9
		return 0; 
	}	else if (character > 64 && character < 91) { //uppercase
		return 1;
	} else if (character > 96 && character < 123) { //lowercase
		return 2;
	} else if (character == 32) {
		return 3;
	} else if (character == 45 || character == 46){ // - or .
		return 4;
	} else {
		return 5;
	}
}