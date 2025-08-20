
#include <stdio.h>

int main() {
    int arr[] = {1, 2, -3, 4, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Subarrays with zero sum:\n");

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];   
            if (sum == 0) {
                printf("(%d, %d)\n", i, j);  
            }
        }
    }

    return 0;
}
