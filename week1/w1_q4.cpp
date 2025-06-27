#include<iostream>
using namespace std;
int lucky(int i){
    int big1=0;
    int small1=i%10;
    while(i>0){
        if((i%10)>big1){
            big1=(i%10);
        }
        if((i%10)<small1){
        small1=(i%10);
    }
        i=i/10;
    }
    return big1-small1;
}
int main(){
    int n;
    cin>>n;
    int A[2][n];
    for(int i=0;i<n;i++){
        cin>>A[0][i]>>A[1][i];
    }
    int lucky_number;
    for(int i=0;i<n;i++){
        int max=0;
         int b=A[0][i];
        for(;b<=A[1][i];b++){
            if(A[1][i]<9){
                lucky_number=A[1][i];
                break;
            }
            if((lucky(b))>=max){
                max=lucky(b);
                lucky_number=b;
                if(max==9){
                    break;
                }
            }
        }
        cout<<lucky_number<<endl;
    }
    return 0;
}