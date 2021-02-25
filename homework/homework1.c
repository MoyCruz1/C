#include <stdio.h>
#include <string.h>
#define MAX 1000
#define IN 1
#define OUT 0

int main()
{

	int i, l, n, m;
	char input [MAX];
	char output [MAX];

	printf("Escribir texto HTML: ");
	gets(input);
	l= strlen(input);
	n= OUT;
	printf(output);

	for (i=0; i<l ; ++i){

		if (input [i] == '<')
		n = IN;
		if (input [i] == '>')
		n = OUT;
		if( n == OUT)
		output[i] = input[i];

		if (output[i] == '>' )
		printf("%c" , output[i]);
	}
}
