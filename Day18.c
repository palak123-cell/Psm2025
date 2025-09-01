#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    scanf("%lld", &n);

    int count = 0;
    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i * i == n) count++;     // perfect square
            else count += 2;             // i and n/i
        }
    }
    printf("%d\n", count);
    return 0;
}
