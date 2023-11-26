#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *filegoc, *fileso, *filechu, *filekytu;
    int kytu;

    filegoc = fopen("baigoc.txt", "r");

    if (filegoc == NULL) {
        perror("error");
        return 1;
    }
    
    fileso = fopen("C:\\Users\\Admin\\Desktop\\Baitap\\Tuan_5\\numbers.txt", "w");
    filechu = fopen("C:\\Users\\Admin\\Desktop\\Baitap\\Tuan_5\\letters.txt", "w");
    filekytu = fopen("C:\\Users\\Admin\\Desktop\\Baitap\\Tuan_5\\special_chars.txt", "w");
    

    if (fileso == NULL || filechu == NULL || filekytu == NULL) {
        perror("error");
        fclose(filegoc);
        return 1;
    }

    while ((kytu = fgetc(filegoc)) != EOF) {
        printf("%c", kytu);

        if (isdigit(kytu)) {
            fprintf(fileso, "%c",kytu); 
        } else if (isalpha(kytu)) {
            fprintf(filechu, "%c",kytu); 
        } else if (ispunct(kytu)) {
            fprintf(filekytu, "%c",kytu); 
        }
    }

    fclose(filegoc);
    fclose(fileso);
    fclose(filechu);
    fclose(filekytu);

    printf("Hoan thanh.\n");

    return 0;
}
