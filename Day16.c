#include <stdio.h>


long long gcd(long long a, long long b) {
    while(b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b; 
}

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", lcm(n, m));
    return 0;
}
