#include <stdio.h>

int main() {
    int n, i;
    printf("Enter size of array (n-1): ");
    scanf("%d", &n);   // here n means size of array (n-1 elements)

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // actual total numbers will be n+1
    int total = n + 1;

    // expected sum of numbers 1 to total
    long long expected_sum = (long long)total * (total + 1) / 2;

    // actual sum of given array
    long long actual_sum = 0;
    for(i = 0; i < n; i++) {
        actual_sum += arr[i];
    }

    // missing number
    long long missing = expected_sum - actual_sum;

    printf("Missing number: %lld\n", missing);

    return 0;
}
