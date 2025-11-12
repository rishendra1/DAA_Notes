#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int mice[] = {4, -3, 3};
    int holes[] = {4, 0, 5};
    int n = 3;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mice[j] > mice[j + 1]) {
                int temp = mice[j];
                mice[j] = mice[j + 1];
                mice[j + 1] = temp;
            }
            if (holes[j] > holes[j + 1]) {
                int temp = holes[j];
                holes[j] = holes[j + 1];
                holes[j + 1] = temp;
            }
        }
    }
    int distance[3];
    for (int i = 0; i < n; i++) {
        distance[i] = abs(mice[i] - holes[i]);
    }
    int big = distance[0];
    for (int i = 1; i < n; i++) {
        if (distance[i] > big) {
            big = distance[i];
        }
    }
    printf("Ans: %d\n", big);
    return 0;
}
