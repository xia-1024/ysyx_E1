#include <stdio.h>
#include <stdlib.h>  

int gcd(int a, int b) {
    // 核心优化：b不为0时，持续更新a和b
    while (b != 0) {
        int temp = a % b;  // 暂存余数
        a = b;
        b = temp;
    }
    // 循环结束时，b=0，a即为最大公约数
    return a;
}

int main() {
    int num1, num2;
    int result;
    scanf("%d%d", &num1, &num2);
    result = gcd(num1, num2);
    printf("%d\n", result);
    return 0;
}