#include<iostream>
using namespace std;
int euclid(int n , int m){
    int r;
    while (n % m != 0){
        r = n % m;
        n = m;
        m = r;
    }
    return m;

}
int main(){
    int res;
    res = euclid(48,36);
    cout<<res;
}