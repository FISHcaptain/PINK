//统计字符
#include<stdio.h>
void f(char a[100])
{
    int i = 0;
    int p = 0, q = 0, m = 0, n = 0;
    // "\r" "\n" 是否会结束gets_s的输入
    while (a[i] != '\0')
    {
        if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
        {
            p++;
        }
        else if (a[i] == ' ')
        {
            q++;
        }
        else if (a[i] >= '0' && a[i] <= '9')
        {
            m++;
        }
        else
        {
            n++;
        }
        i++;
    }
    printf("%d\n%d\n%d\n%d", p, q, m, n);
}
int main()
{
    char a[100];
    // 多余了，删除
    int p=0, q=0, m=0, n=0;
    gets_s(a);
    f(a);
    return 0;
}
