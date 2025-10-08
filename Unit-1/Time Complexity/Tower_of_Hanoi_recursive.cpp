#include<iostream>

using namespace std;

void Tower_of_Hanoi(int n,char s,char m,char d){
if(n > 0) {
        Tower_of_Hanoi(n - 1,s,d,m);
        cout<<"Moving disc "<<n<<" from "<<s<<" to "<<d<<"\n";
        Tower_of_Hanoi(n - 1,m,s,d);
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    Tower_of_Hanoi(n,'A','B','C');
}