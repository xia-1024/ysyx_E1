#include<stdio.h>
#include<string.h>


int main()
{
	int a[100] = {1,2,3,5,7,9};
	int b[100];
	memcpy(b,a,sizeof(a));
	for(int i = 0; i < 6; i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
