#include <stdio.h>


int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
  
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    int result;
    scanf("%d", &n) ;
    result = fib(n);
    printf("%d\n",result);

    return 0;
}