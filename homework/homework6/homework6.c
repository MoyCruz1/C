#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

char linea[MAX];

char ins[MAX];

int main()
{
	int c, i;
	node* n = NULL;
	node* arbol = NULL;
	char user_account[MAX];
	char access_code[MAX];
	char temp1[MAX]; 
	char temp2[MAX];

	while((convert_to_line(user_account, access_code)) != EOF ) {
		if (strstr(ins, "add")) {
			i = 0;
			while (i != '\t') {
				temp1[i] = user_account[i];
				temp2[i] = access_code[i];
				i++;
			}

			n = insert(temp1, temp2, arbol, 0);
			if (arbol == NULL) {
				arbol = n;
			}
		} else if (strstr(ins, "del")) {
			del(arbol, user_account, access_code);
		} else {
			show(arbol, '+');
		}
	}
	return 0;
}

//based on Hectormtz work
