#include<iostream>
using namespace std;
typedef long long ll;
int divisors(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(i!= n/i) 
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cout<<divisors(x)<<endl;
    }
}
