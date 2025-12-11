#include <stdio.h>
#include <stdlib.h>  
void diamond(int n, char sym) {
    // 确保n为奇数（避免菱形变形）
    if (n % 2 == 0) {
        n++;
    }
    int mid = n / 2;  // 中间行的索引（从0开始）
    
    // 遍历每一行
    for (int i = 0; i < n; i++) {
        // 1. 计算当前行前置的制表符数量
        int space_num = abs(i - mid);
        // 打印前置制表符
        for (int j = 0; j < space_num; j++) {
            printf("\t");
        }
        
        // 2. 计算当前行的符号数量
        int sym_num = 1 + 2 * (mid - space_num);
        // 打印符号（符号之间用制表符分隔）
        for (int j = 0; j < sym_num; j++) {
            printf("%c", sym);
            // 最后一个符号后不打印制表符
            if (j != sym_num - 1) {
                printf("\t");
            }
        }
        printf("\n");
    }
}
int main() {
	int x;
	char fuh;

	scanf("%d\n",&x);
	
	scanf(" %c",&fuh);
	diamond(x, fuh);
    	return 0;
}
