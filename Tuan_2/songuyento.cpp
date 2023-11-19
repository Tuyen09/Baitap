#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int snt = 0;
    int _snt;
    printf("Nhap so nguyen to: ");
    scanf("%u", &snt);

    if (snt == 2)
    {
        _snt = 1;
    }
    else
    {
        _snt = 1;
        for (int i = 2; i <= sqrt(snt); i++)
        {
            if (snt % i == 0)
            {
                _snt = 0;
                break;
            }
        }
    }

    if (_snt == 1)
    {
        printf("\n%d la so nguyen to", snt); 
    }
    
    else
    {
        printf("\n%d khong phai so nguyen to", snt);
    }
    
    int _j;
    printf("\nCac so nguyen to nho hon %u : \n", snt);
    for (int j = 2; j < snt; j++)
    {
        _j = 1;
        for (int k = 2; k <= sqrt(j); k++)
        {
            if (j % k == 0)
            {
                _j = 0;
                break;
            }
        }
        if (_j)
            printf("%u, ", j);
    }

    return 0;
}

