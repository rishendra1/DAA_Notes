#include <stdio.h>

int fact(int x) {
    int f = 1; 
    for (int i = 1; i <= x; i++) {
        f = f * i; 
    }
    return f;
}
int main() {
    int n, r;
    printf("Enter the values for n and r (to calculate nCr): ");
    scanf("%d %d", &n, &r); 
    int result = fact(n) / (fact(r) * fact(n - r));
    printf("The value of nCr is: %d\n", result);
    return 0;
}