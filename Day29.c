#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Fibonacci number: 0\n");
        return 0;
    }
    if (n == 1) {
        printf("Fibonacci number: 1\n");
        return 0;
    }

    // Use an array to store Fibonacci numbers up to n
    unsigned long long fib[1001]; // Enough for n <= 1000
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibonacci number: %llu\n", fib[n]);
    return 0;
}
