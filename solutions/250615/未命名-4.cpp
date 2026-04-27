#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    char a[100001],b[]="matiji";
    cin>>a;
    int i,j=0,c=0;
    for(i=0;i<100001;i++){
        if(a[i]==b[j]){
            j++;
        }else{
            i-=j;
            j=0;
        }
        if(j==6){
            j=0;
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}