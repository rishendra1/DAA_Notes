#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    printf("Enter no. of items: ");
    scanf("%d", &n);

    int w[n], p[n];
    float r[n];

    for(i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &w[i]);
        printf("Enter profit of item %d: ", i + 1);
        scanf("%d", &p[i]);
        r[i] = (float)p[i] / w[i];
    }
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(r[j] < r[j + 1]) {
                float tempf = r[j];
                r[j] = r[j + 1];
                r[j + 1] = tempf;

                int tempi = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempi;

                tempi = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempi;
            }
        }
    }
    int capacity;
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    float profit = 0.0;
    i = 0;

    while(capacity > 0 && i < n) {
        if(w[i] <= capacity) {
            capacity -= w[i];
            profit += p[i];
        } else {
            profit += r[i] * capacity;
            capacity = 0;
        }
        i++;
    }
    printf("\nProfit - %.2f\n", profit);
    return 0;
}
