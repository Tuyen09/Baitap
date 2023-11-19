#include <stdio.h>

int main() {
    
    // UCLL, BCNN
    int a, b;
    printf("Nhap so a: ");
    scanf("%d", &a);
    printf("Nhap so b: ");
    scanf("%d", &b);
    
  
    int ucln = 1; 

    for (int i = 1; i <= a && i <= b; ++i) {
        if (a % i == 0 && b % i == 0) {
            ucln = i; 
        }
    }

    printf("UCLN la: %d\n", ucln);
    int bcnn = 1;
    bcnn = (a*b)/ucln;
	printf("BCNN la: %d\n", bcnn);
	 
	return 0;    
    
}
