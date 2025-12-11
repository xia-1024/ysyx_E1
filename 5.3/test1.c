#include <stdio.h>
#include <stdlib.h>  

// 递归函数：求两个正整数的最大公约数（欧几里得算法）
int gcd(int a, int b) {
    // 递归终止条件：a能被b整除，返回b
    if (a % b == 0) {
        return b;
    }
    // 递归递推：问题规模缩小为求 b 和 a%b 的最大公约数
    else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;
    int result;
    scanf("%d%d", &num1,&num2) ;
    result = gcd(num1, num2);
    printf("%d\n",result);
    return 0;
}