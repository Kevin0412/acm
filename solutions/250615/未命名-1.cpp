#include<bits/stdc++.h> 

using namespace std;

int main() 
{ 
    int i,t,j,n,c,d,flag;
    cin>>t;
    char a[10001],b[10001];
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        c=10001,d=0;
        for(j=0;j<10001;j++){
            if(a[j]=='\0'){
                break;
            }
            if(a[j]!=b[j]){
                c=min(c,j);
                d=j;
            }
        }
        flag=1;
        for(j=0;j<=d-c;j++){
            if(a[c+j]!=b[d-j]){
            	flag=0;
                cout<<"N"<<endl;
                break;
            }
        }
        if(flag) cout<<"Y"<<endl;
    }
    return 0; 
}