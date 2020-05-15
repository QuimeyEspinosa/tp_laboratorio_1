#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getString(char str[], int limitChar, char message[], char messageError[])
{
    printf("%s", message);
    fflush(stdin);
    fgets(str, limitChar, stdin);
    str[strlen(str)-1] = '\0';
    while(strlen(str) >= limitChar - 2 || strlen(str) == 0)
    {
        printf("%s", messageError);
        fflush(stdin);
        fgets(str, limitChar, stdin);
        str[strlen(str)-1] = '\0';
    }
}

void strLwr(char str[])
{
    int i = 0;

    while (str[i] != '\0')
	{
    	if (str[i] >= 'A' && str[i] <= 'Z') {
        	str[i] = str[i] + 32;
    	}
      	i++;
	}
}
