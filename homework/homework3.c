#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int i;
    char dig[20];

    printf("Digite Numeros: ");gets(dig);

    if(dig[0] == '[' || dig[0] == '(' || dig[0] == '"'){
        for(i = 0; i < strlen(dig); i++){
            printf("%c",dig[i]);
        }
       }
    else{
        for(i = 0; i < strlen(dig); i++){
            dig[i] = 'X';
     }
        for(i = 0;i<strlen(dig); i++){
            printf("%c",dig[i]);
     }
    }
    printf("\n");
    system("pause");
    return 0;
}
