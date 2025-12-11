#include<stdio.h>
#include<math.h>
int main()
{
    double x,y;
    scanf("%lf%lf",&x,&y);
    printf("%d %d",(int)ceil(x),(int)floor(y));
    return 0;
}