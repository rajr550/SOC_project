#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<int> a(n);
    map<long long,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        long long target1=x-a[i];
        for(int j=i+1;j<n;j++){
            long long target2=target1-a[j];
            if(m.count(target2)){
                cout << m[target1] + 1 << " " <<m[target2] + 1 << " "  << j + 1 << endl;
                return 0;
            }
            m[a[j]]=j;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}


