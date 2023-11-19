#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace_e(char* str)
{
    int len = strlen(str);
    char chr[200]; 
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'e')
        {
            chr[j++] = 'e';
            chr[j++] = 'f';
        }
        else
        {
            chr[j++] = str[i];
        }
    }

    chr[j] = '\0';

    printf("\nChuoi thay the : %s", chr);
}

int main()
{
    char chuoi[100] = "fresher embedded";
    
	replace_e(chuoi);


    return 0;
}
