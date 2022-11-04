#include <stdio.h>
int main()
{
    int money,a;
    double price;
     scanf_s("%d%d", &money,&a);
     if (a<= 12)
     price = money + money * 0.009*a;
     if (a> 12 && a <= 24)
         price = money + money * 0.001 * a;
     else if (a> 24 && a<= 36)
         price = money + money * 0.0011 *a;
     else
         price = money + money * 0.0012 * a;
     printf("%lf", price);
     return 0;
}