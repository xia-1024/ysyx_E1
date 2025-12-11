#include <stdio.h>
#include <math.h> // 使用 ceil 必须包含此头文件

int main() {
    int x, n;
    double result;

    // 测试用例1: x=17, n=4，预期结果5.0
    x = 17;
    n = 4;
    result = ceil((double)x / n);
    printf("Ceiling(%d / %d) = %lf\n", x, n, result);
    // 如果你需要一个整数结果，可以进行强制类型转换
    printf("As integer: %d\n", (int)result);

    printf("\n");

    // 测试用例2: x=16, n=4，预期结果4.0
    x = 16;
    n = 4;
    result = ceil((double)x / n);
    printf("Ceiling(%d / %d) = %lf\n", x, n, result);
    printf("As integer: %d\n", (int)result);

    printf("\n");

    // 测试用例3: x=5, n=3，预期结果2.0
    x = 5;
    n = 3;
    result = ceil((double)x / n);
    printf("Ceiling(%d / %d) = %lf\n", x, n, result);
    printf("As integer: %d\n", (int)result);

    return 0;
}
