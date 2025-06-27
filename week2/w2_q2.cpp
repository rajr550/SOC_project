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
        long long target=x-a[i];
        if(m.count(target)){
            cout << m[target] + 1 << " " << i + 1 << endl;
            return 0;
        }
        m[a[i]]=i;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}


