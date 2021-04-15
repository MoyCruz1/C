#include <stdlib.h>
#include <stdio.h>

int nums[26];
int saveN[10];
int pos = 0;

int GetSetNumByChar(char s, int num, int getNum, int setNum, char nextS);
int ValidateGetSet(int idx, int num, int getNum, int setNum, char nextS);//guardar o colocar
int CasesCalculator(char character);

int main()
	
{
    int c, isOverwrite, countInto; //variables
    char s;
    char text[100];//amplitud

    printf("Type the variables needed, example: 'a = 1', to finish press 2 times 'enter': \n");
    isOverwrite = 0;
    countInto = 0;
    while (text[0] || isOverwrite)//ciclo variables necesarias
    {
        gets(text);
        if (text[0])
        {
            countInto = 0; //sin letra es enter
            char letter, nextChar;
            int number;
            letter = text[0];//variable en x1
            nextChar = text[2]; //sig. variable en x3
            
            char numText[10]; 
            int i, j, isNum;
            j = 0;
            isNum = 0;
            for(i = 0; text[i]; i++)//contado
		    
            {
                if (text[i] == '=')//si encuentra un "=" da paso a:
                {
                    i = i + 2; // posiciones x+2
                    isNum = 1; //true
                }
                if (isNum)
                {
                    numText[j] = text[i]; 
                    j++;
                }
            }
            number = atoi(numText); //conversión a enteros
        isOverwrite = GetSetNumByChar(letter, number, 0, 1, nextChar);
        for(i = 0; numText[i]; i++)
        {
            numText[i] = ' '; //reset
            }
    }
        else //
        {
            countInto++; 
            if(countInto == 2)
            {
                isOverwrite = 0;
            }
        }
    }
    printf("Now this is the calculator\n");
    printf("Write variables in the form Polaca inverse, Example: a b +\n");
    //Calculadora
    while ((c = getchar()) != EOF)
    {
        s = (char)c;
        CasesCalculator(s);
    }
    return 0;
}

int GetSetNumByChar(char s, int num, int getNum, int setNum, char nextS)
{
    switch(s){ //casos abecedario
        case 'A':
        case 'a':
            return ValidateGetSet(0, num, getNum, setNum, nextS);
        
        case 'B':
        case 'b':
            return ValidateGetSet(1, num, getNum, setNum, nextS);
            
        case 'C':
        case 'c':
            return ValidateGetSet(2, num, getNum, setNum, nextS);
        
        case 'D':
        case 'd':
            return ValidateGetSet(3,num, getNum, setNum, nextS);
        
        case 'E':
        case 'e':
            return ValidateGetSet(4, num, getNum, setNum, nextS);
        
        case 'F':
        case 'f':
            return ValidateGetSet(5, num, getNum, setNum, nextS);
        
        case 'G':
        case 'g':
            return ValidateGetSet(6, num, getNum, setNum, nextS);
        
        case 'H':
        case 'h':
            return ValidateGetSet(7, num, getNum, setNum, nextS);
        
        case 'I':
        case 'i':
            return ValidateGetSet(8, num, getNum, setNum, nextS);
        
        case 'J':
        case 'j':
            return ValidateGetSet(9, num, getNum, setNum, nextS);
        
        case 'K':
        case 'k':
            return ValidateGetSet(10, num, getNum, setNum, nextS);
        
        case 'L':
        case 'l':
            return ValidateGetSet(11, num, getNum, setNum, nextS);
        
        case 'M':
        case 'm':
            return ValidateGetSet(12, num, getNum, setNum, nextS);
        
        case 'N':
        case 'n':
            return ValidateGetSet(13, num, getNum, setNum, nextS);
        
        case 'O':
        case 'o':
            return ValidateGetSet(14, num, getNum, setNum, nextS);
        
        case 'P':
        case 'p':
            return ValidateGetSet(15, num, getNum, setNum, nextS);
        
        case 'Q':
        case 'q':
            return ValidateGetSet(16, num, getNum, setNum, nextS);
        
        case 'R':
        case 'r':
            return ValidateGetSet(17, num, getNum, setNum, nextS);
        
        case 'S':
        case 's':
            return ValidateGetSet(18, num, getNum, setNum, nextS);
        
        case 'T':
        case 't':
            return ValidateGetSet(19, num, getNum, setNum, nextS);
        
        case 'U':
        case 'u':
            return ValidateGetSet(20, num, getNum, setNum, nextS);
        
        case 'V':
        case 'v':
            return ValidateGetSet(21, num, getNum, setNum, nextS);
        
        case 'W':
        case 'w':
            return ValidateGetSet(22, num, getNum, setNum, nextS);
        
        case 'X':
        case 'x':
            return ValidateGetSet(23, num, getNum, setNum, nextS);
        
        case 'Y':
        case 'y':
            return ValidateGetSet(24, num, getNum, setNum, nextS);
            
        case 'Z':
        case 'z':
            return ValidateGetSet(25, num, getNum, setNum, nextS);
            
      default:
       printf("Without variable, type it");
        break;
    }
    return 0;
}

int ValidateGetSet(int idx, int num, int getNum, int setNum, char nextS)
{
    if(setNum)
    {
        
        if(nextS == ':')
        {
            //con : se guarda
            nums[idx] = num;
        }
        else if (nums[idx])
        {
            //aviso de sobreescripción 
            printf("Are you sure to rewrite? 1 for yes or 0 for no\n");
            int save;
            scanf ("%d", &save);
            if (save)//si es verdadero reemplaza
            {
                nums[idx] = num;
            }
            return 1;
        }
        else
        {
            //sin dato, guarda
            nums[idx] = num;
        }
    }
    if (getNum) //guardar un numero
    {
        return nums[idx];
    }
    return 0;
}

int CasesCalculator(char character) //polaca inverse casos
{
    switch(character)
    {
        case '+': //según la suma, últimas 2 x
            saveN[pos - 2] = saveN[pos - 2] + saveN[pos - 1];
            pos = pos - 1;
            break;
        case '-':
            saveN[pos - 2] = saveN[pos - 2] - saveN[pos - 1];
            pos = pos - 1;
            break;
        case '*':
            saveN[pos - 2] = saveN[pos - 2] * saveN[pos - 1];
            pos = pos - 1;
            break;
        case '/':
            saveN[pos - 2] = saveN[pos - 2] / saveN[pos - 1];
            pos = pos - 1;
            break;
        case ' ': //nada
            break;
        case '\n': //da resultado de última x
            printf("result = %d\n", saveN[0]);
            pos = 0; //reset x
            break;
        default:
        //cuando sean letras
        saveN[pos] = GetSetNumByChar(character, 0, 1, 0, '\0');
        pos++;
        break;
    }
    return 0;
}

//basado en el de mi compañero Braian Sotelo
