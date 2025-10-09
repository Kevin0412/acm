#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int a=0,i,k=s.length()%2;
    for(i=0;i<s.length();i++){
        if(s[i]=='H'){
            a+=k;
            a%=2;
        }
        k++;
        k%=2;
    }
    if(a){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
    return 0;
}