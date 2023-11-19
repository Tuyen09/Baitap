#include <stdio.h>
#include <string.h>
#include <ctype.h>
void xulychuoi(char *str)
{
    int len;
    int i = 0;
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len = strlen(str);
    }
    char c[100];
    int j = 0;
    for (i = 0; i < len; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' ' && str[i+1] != ' '))
        {
                c[j++] = str[i];
        }
    }
    c[j] = '\0'; 

    printf("Chuoi sau khi xu ly : %s\n", c);
}
void conv(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    
     printf("\nChuoi chuyen doi : %s", str);
}

void string_mirror(char *str)
{
	// In chuoi dao nguoc
    char a[100];
    int len = strlen(str);
    int i;
    for (i = 0; i < len; ++i)
    {
        a[i] = str[len - i - 1];
    }
    a[len] = '\0';
    printf("\nChuoi dao nguoc: %s\n", a);
}

int main()
{
    char chuoi[100];
    printf("Nhap chuoi : ");

    fgets(chuoi, sizeof(chuoi), stdin);
    printf("\nChuoi vua nhap la : %s", chuoi);
	xulychuoi(chuoi);
	conv(chuoi);
	string_mirror(chuoi);


    return 0;
}
