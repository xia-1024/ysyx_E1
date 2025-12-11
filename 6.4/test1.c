#include <stdio.h>

int is_prime(int n)
{
    int i;
    int result = 1;  // 假设是素数
	if(n == 1){
	return 0;}    
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            result = 0;  // 发现能整除，不是素数
        }
    }
    
    return result;
}

int main(void)
{
    int i;
    for (i = 1; i <= 100; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
        // 去掉continue，什么都不做
    }
    return 0;
}
