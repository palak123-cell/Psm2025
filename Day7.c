#include <stdio.h>

int trap(int h[], int n) {
    int l = 0, r = n - 1, lMax = 0, rMax = 0, water = 0;
    while (l < r) {
        if (h[l] < h[r]) {
            lMax = (h[l] > lMax) ? h[l] : lMax;
            water += lMax - h[l];
            l++;
        } else {
            rMax = (h[r] > rMax) ? h[r] : rMax;
            water += rMax - h[r];
            r--;
        }
    }
    return water;
}

int main() {
    int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(h) / sizeof(h[0]);
    printf("%d\n", trap(h, n));
    return 0;
}
