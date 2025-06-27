#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int max=0;
    int temp=0;
    char store;
    for(int i=0;i<str.length();i++){
        if(i!=0){
            if(store!=str[i]){
              store=str[i];
              temp=1;
              continue;  
            }
        }
        store=str[i];
        temp++;
        if(temp>max){
            max=temp;
        }
    }
    cout<<max;
}
