#include<iostream>

using namespace std;

int main(){
    int n,i,a[100],target,index;
    cout<<"Enter size: ";
    cin>>n;
    for(i = 0 ; i<n ; i++){
        cout<<"Enter Element: ";
        cin>>a[i];
    }
    cout<<"Enter target value: ";
    cin>>target;
    for(i = 0 ; i<n ; i++){
        if(a[i] == target){
            index = i;
            break;
        }
        else{
            index = -1;
        }
    }
    if(index == -1){
        cout<<"Element does not present.";
    }
    else{
        cout<<"Element is at - "<<index;
    }
}