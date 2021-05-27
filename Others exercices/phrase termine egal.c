#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char string[100], c;
	int i, flag = 0;
	printf ("Saisez une phrase : ");
	gets (string);
	int len = strlen (string);
	for (i=0; i<len; i++) {
		if (string[i] == ' ' || string[i] == ',' || string[i] == '.') {
			c = string[i-1];
			break;
		}	
	}
	for (i=0; i<=len; i++) {
		if (string[i] == ' ' || string[i] == ',' || string[i] == '.' || string[i] == '\0') {
			if (isalpha(string[i-1]) != 0) {
				if (string[i-1] != c) {
					flag = 1;
					break;
				}
			}
		}	
	}
	if (flag == 0)
		printf ("Les lettres finales de phrase est egale");
	else
		printf ("Les letters finales de phrase est n'est pas egale");	
	return 0;
}
