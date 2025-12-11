#include<stdio.h>
int is_leap_year(int year)
{
    if(year%4==0&&year%100!=0)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int year;
    scanf("%d",&year);
    is_leap_year(year);
    return 0;
}
