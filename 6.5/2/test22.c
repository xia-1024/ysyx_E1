#include <stdio.h>
#include <stdlib.h>

void diamond(int n, char sym) {
    if (n % 2 == 0) n++; // 强制奇数行
    int mid = n / 2;
    for (int i = 0; i < n; i++) {
        // 打印前置制表符
        int space_num = abs(i - mid);
        for (int j = 0; j < space_num; j++) printf("\t");
        
        // 打印符号（制表符分隔）
        int sym_num = 1 + 2 * (mid - space_num);
        for (int j = 0; j < sym_num; j++) {
            printf("%c", sym);
            if (j != sym_num - 1) printf("\t");
        }
        printf("\n");
    }
}

int main() {
    int n;
    char sym;

    // 1. 输入菱形行数
    printf("请输入菱形的行数（奇数）：");
    scanf("%d", &n);

    // 2. 输入菱形符号（%c前加空格，跳过前面的回车符）
    printf("请输入构成菱形的符号：");
    scanf(" %c", &sym); // 关键：%c前的空格跳过空白字符

    // 3. 调用函数打印菱形
    diamond(n, sym);

    return 0;
}
