// Online C compiler to run C program online
#include <stdio.h>


void primeFactorization(long long n) {
    
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }

    
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%lld ", i);
            n /= i;
        }
    }

    
    if (n > 2)
        printf("%lld", n);
}

int main() {
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);

    printf("Prime Factorization: ");
    primeFactorization(n);
    printf("\n");

    return 0;
}
