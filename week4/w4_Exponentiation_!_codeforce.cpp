#include<iostream>
using namespace std;
int pw(int n){
    if(n==0) return 1;
    if(n%2==0){
        int t=pw(n/2);
        return 1ll*t*t % 10;
    }
    else{
        int t=pw((n-1)/2);
        return 1ll*t*t*1378 % 10;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<pw(n);
}
