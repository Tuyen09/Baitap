#include <stdio.h>


int main() {

    long long fib_sequence[70];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    for (int i = 2; i < 70; ++i) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    printf("70 so dau cua day fibonacci la:\n");
    for (int i = 0; i < 70; ++i) {
        printf("%lld ", fib_sequence[i]);
    }
    printf("\n");
    
    
   
	 
	return 0;    
    
}
