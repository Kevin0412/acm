#include <iostream>

using namespace std;

int main(){
    int i,t,c,d,j;
    cin>>t;
    for(i=0;i<t;i++){
        char a[9];
        c=0;
        d=0;
        cin>>a;
        if(a[0]==a[4]){
            cout<<a[0]<<endl;
            continue;
        }
        for(j=0;j<8;j++){
            if(a[j]==a[0]){
                c++;
            }
            if(a[j]==a[4]){
                d++;
            }
        }
        if(c==d){
            cout<<"N"<<endl;
            continue;
        }
        if(c>d){
            cout<<a[0]<<endl;
            continue;
        }
        cout<<a[4]<<endl;
    }
}