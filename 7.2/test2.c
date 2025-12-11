#include <stdio.h>
#include <stdlib.h>

/* 有理数结构体 */
struct rational {
    int numerator;   /* 分子 */
    int denominator; /* 分母，始终为正数 */
};

/* 辅助函数：求最大公约数（欧几里得算法） */
int gcd(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* 构造有理数并约分 */
struct rational make_rational(int num, int den)
{
    struct rational r;
    
    if (den == 0) {
        fprintf(stderr, "错误：分母不能为0\n");
        exit(EXIT_FAILURE);
    }
    
    /* 保证分母为正，符号由分子表示 */
    if (den < 0) {
        num = -num;
        den = -den;
    }
    
    /* 约分 */
    int g = gcd(num, den);
    r.numerator = num / g;
    r.denominator = den / g;
    
    return r;
}

/* 打印有理数 */
void print_rational(struct rational r)
{
    if (r.denominator == 1) {
        printf("%d\n", r.numerator);
    } else {
        printf("%d/%d\n", r.numerator, r.denominator);
    }
}

/* 有理数加法 */
struct rational add_rational(struct rational a, struct rational b)
{
    int num = a.numerator * b.denominator + b.numerator * a.denominator;
    int den = a.denominator * b.denominator;
    return make_rational(num, den);
}

/* 有理数减法 */
struct rational sub_rational(struct rational a, struct rational b)
{
    int num = a.numerator * b.denominator - b.numerator * a.denominator;
    int den = a.denominator * b.denominator;
    return make_rational(num, den);
}

/* 有理数乘法 */
struct rational mul_rational(struct rational a, struct rational b)
{
    int num = a.numerator * b.numerator;
    int den = a.denominator * b.denominator;
    return make_rational(num, den);
}

/* 有理数除法 */
struct rational div_rational(struct rational a, struct rational b)
{
    /* 除以一个有理数等于乘以它的倒数 */
    if (b.numerator == 0) {
        fprintf(stderr, "错误：除以0\n");
        exit(EXIT_FAILURE);
    }
    
    int num = a.numerator * b.denominator;
    int den = a.denominator * b.numerator;
    return make_rational(num, den);
}

/* 测试函数 */
int main(void)
{
    struct rational a = make_rational(1, 8);   /* a=1/8 */
    struct rational b = make_rational(-1, 8);  /* b=-1/8 */
    
    printf("a = "); print_rational(a);
    printf("b = "); print_rational(b);
    
    printf("a + b = ");
    print_rational(add_rational(a, b));
    
    printf("a - b = ");
    print_rational(sub_rational(a, b));
    
    printf("a * b = ");
    print_rational(mul_rational(a, b));
    
    printf("a / b = ");
    print_rational(div_rational(a, b));
    
    /* 更多测试 */
    printf("\n更多测试：\n");
    
    struct rational c = make_rational(3, 6);  /* 约分后应为1/2 */
    printf("c = "); print_rational(c);
    
    struct rational d = make_rational(4, -8); /* 约分后应为-1/2 */
    printf("d = "); print_rational(d);
    
    printf("c + d = "); print_rational(add_rational(c, d));
    printf("c * d = "); print_rational(mul_rational(c, d));
    
    return 0;
}
