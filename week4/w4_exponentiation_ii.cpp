#include<iostream>
using namespace std;
long long int pw(long long int b,long long int c,long long int x){
    if(c==0) return 1;
    if(c%2==0){
        long long int t=pw(b,c/2,x);
        return ((t%x)*(t%x))%x;
    }
    else{
        long long int t=pw(b,(c-1)/2,x);
        t=t%x;
        return (((t*t)%x)*(b%x))%x;
    }
}
int main(){
    int n;
    long long a,b,c;
    cin>>n;
    long long Mod=1e9+7;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        long long int x=pw(b,c,Mod-1);
        cout<<pw(a,x,Mod)<<endl;
    }
}