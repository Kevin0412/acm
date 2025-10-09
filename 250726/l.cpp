#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,i;
    string chart[1003];
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>chart[i];
    } 
    for(i=n-1;i>0;i--){
    	if(chart[i][0]=='1' & chart[i-1][1]=='1'){
    		chart[i][1]='1';
    		chart[i-1][1]='0';
    	}else if(chart[i][1]=='1' & chart[i-1][0]=='1'){
    		chart[i][0]='1';
    		chart[i-1][0]='0';
    	}
    	if(chart[i][2]=='1' & chart[i-1][3]=='1'){
    		chart[i][3]='1';
    		chart[i-1][3]='0';
    	}else if(chart[i][3]=='1' & chart[i-1][2]=='1'){
    		chart[i][2]='1';
    		chart[i-1][2]='0';
    	}
    }
    for(i=0;i<n;i++)cout<<chart[i]<<endl;
    return 0;
}