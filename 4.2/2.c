#include<stdio.h>

void print(int b)
{
	printf("%d\n",b%10);
	printf("%d\n",b/10%10);
}

int main()
{
	int a;
	scanf("%d",&a);
	print(a);
	return 0;
}
