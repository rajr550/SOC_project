#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n-1];
    int freq[n]={};
    for(int i:a){
        cin>>i;
        freq[i-1]++;
    }
    for(int i=0;i<n;i++){
        if(!freq[i]){
            cout<<i+1;
        }
    }
}
