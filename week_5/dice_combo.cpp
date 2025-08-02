#include<iostream>
#include<vector>
using namespace std;
int MOD=1e9+7;
int ways(int n, vector<int>& dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int x=0;
    for(int j=1;j<=6;j++){
        x=(x+ways(n-j,dp))%MOD;
    }
    dp[n]=x;
    return x;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<ways(n,dp);
}
