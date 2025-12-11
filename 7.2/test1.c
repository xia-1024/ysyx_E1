#include <stdio.h>
#include <math.h>

struct complex_struct {
    double x, y;
};

double real_part(struct complex_struct z)
{
    return z.x;
}

double img_part(struct complex_struct z)
{
    return z.y;
}

double magnitude(struct complex_struct z)
{
    return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)
{
    return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y)
{
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
    struct complex_struct z;
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_img(real_part(z1) + real_part(z2),
                  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_img(real_part(z1) - real_part(z2),
                  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_ang(magnitude(z1) * magnitude(z2),
                 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_ang(magnitude(z1) / magnitude(z2),
                 angle(z1) - angle(z2));
}

/* 打印复数的函数 */
void print_complex(struct complex_struct z)
{
    double real = real_part(z);
    double imag = img_part(z);
    
    /* 处理实部为0且虚部为0的情况 */
    if (fabs(real) < 1e-10 && fabs(imag) < 1e-10) {
        printf("0.0\n");
        return;
    }
    
    /* 处理实部不为0的情况 */
    if (fabs(real) >= 1e-10) {
        printf("%.1f", real);
        
        /* 处理虚部 */
        if (fabs(imag) >= 1e-10) {
            if (imag > 0) {
                printf("+%.1fi", imag);
            } else {
                printf("%.1fi", imag);  /* imag为负，自带负号 */
            }
        }
        printf("\n");
    } 
    /* 实部为0，只有虚部 */
    else {
        printf("%.1fi\n", imag);
    }
}

int main(void)
{
    /* 测试各种情况的复数 */
    struct complex_struct z1 = make_from_real_img(1.0, 0.0);
    struct complex_struct z2 = make_from_real_img(0.0, -2.0);
    struct complex_struct z3 = make_from_real_img(-1.0, 2.0);
    struct complex_struct z4 = make_from_real_img(1.0, -2.0);
    struct complex_struct z5 = make_from_real_img(0.0, 0.0);
    struct complex_struct z6 = make_from_real_img(3.0, 4.0);
    
    printf("测试打印函数：\n");
    printf("z1 = "); print_complex(z1);  /* 1.0 */
    printf("z2 = "); print_complex(z2);  /* -2.0i */
    printf("z3 = "); print_complex(z3);  /* -1.0+2.0i */
    printf("z4 = "); print_complex(z4);  /* 1.0-2.0i */
    printf("z5 = "); print_complex(z5);  /* 0.0 */
    printf("z6 = "); print_complex(z6);  /* 3.0+4.0i */
    
    /* 测试复数运算 */
    printf("\n测试复数运算：\n");
    
    struct complex_struct sum = add_complex(z3, z4);
    printf("(-1.0+2.0i) + (1.0-2.0i) = ");
    print_complex(sum);
    
    struct complex_struct diff = sub_complex(z3, z4);
    printf("(-1.0+2.0i) - (1.0-2.0i) = ");
    print_complex(diff);
    
    struct complex_struct prod = mul_complex(z6, z6);
    printf("(3.0+4.0i) * (3.0+4.0i) = ");
    print_complex(prod);
    
    struct complex_struct quot = div_complex(z6, make_from_real_img(2.0, 0.0));
    printf("(3.0+4.0i) / 2.0 = ");
    print_complex(quot);
    
    return 0;
}
