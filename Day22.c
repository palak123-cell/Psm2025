#include <stdio.h>

int firstElement(int arr[], int n, int k) {
    int freq[100001] = {0};  
    
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if(freq[arr[i]] == k) return arr[i];  
    }
    return -1;
}

int main() {
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    
    printf("%d\n", firstElement(arr, n, k));
    return 0;
}
