#include<stdio.h>

int main(){
    int n,e,i,j;
    printf("Enter no. of vertices and edges: ");
    scanf("%d %d", &n, &e);
    int u[20], v[20], w[20];
    for(i = 0 ; i < e ; i++){
        printf("Src Dest Cost - ");
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    for(i = 0 ; i < e; i++){
        for(j = 0 ; j < e - i - 1; j++){
            if (w[j] > w[j  + 1]){
                int t = w[j]; w[j] = w[j + 1]; w[j + 1] = t;
                t = u[j]; u[j] = u[j + 1]; u[j + 1] = t;
                t = v[j]; v[j] = v[j + 1]; v[j + 1] = t;
            }
        }
    }
    int parent[20];
    for (i = 0 ; i < n ; i++)
        parent[i] = i;
    int total = 0, count = 0;
    i = 0;
    while(count < n - 1 &&  i < e){
        int a = u[i];
        int b = v[i];
        while (parent[a] != a) parent[a] = a;
        while (parent[b] != b) parent[b] = b;
        if(a != b){
            printf("%d - %d - %d\n", u[i], v[i], w[i]);
            total += w[i];
            count += 1;
        }
        i++;
    }
}