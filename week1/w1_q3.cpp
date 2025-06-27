#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        int v=(n % (2+k));
        if((v%2==0)||(v%k==0)||(((n%2)%k)==0)||(((n%k)%2)==0)){
            cout<<"YES"<<endl;
        }
        else if((n%2==1) && (k%2==0)){
            cout<<"NO"<<endl;
        }
        else if(true){
            bool possible = false;
        for (long long y = 0; y <= n / k; ++y) {
           if ((n - y * k) % 2 == 0) {
             possible = true;
             break;
            }
            }
            if(possible){
                cout<<"YES"<<endl;
            }
            else{
            cout<<"NO"<<endl;
        }
        }
        
        }
    return 0;
}