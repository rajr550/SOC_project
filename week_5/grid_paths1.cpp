#include<iostream>
#include<vector>
using namespace std;
int MOD=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    if (grid[n - 1][n - 1] != '*') dp[n - 1][n - 1] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if (grid[i][j] == '*') continue;
            if(j+1<n && grid[i][j+1]!='*')
            dp[i][j]=(dp[i][j]+dp[i][j+1])%MOD;
            if(i+1<n && grid[i+1][j]!='*')
            dp[i][j]=(dp[i][j]+dp[i+1][j])%MOD;
        }
    }
    cout<<dp[0][0];
}
