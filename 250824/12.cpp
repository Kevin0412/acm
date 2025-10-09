#include<bits/stdc++.h>
using namespace std;

int a[1000][1000],b[4][100][100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int n,m,q;
    
    cin>>n>>m>>q;
    
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		a[i][j]=0;
    	}
    }
    
    for(int i=0;i<m;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<m;j++){
    		if(s[j]=='#'){
    			b[0][i][j]=1;
    		}else{
    			b[0][i][j]=0;
    		}
    	}
    }
    
    for(int k=1;k<4;k++){
    	for(int i=0;i<m;i++){
    		for(int j=0;j<m;j++){
    			b[k][i][j]=b[k-1][m-j-1][i];
    		}
    	}
    }
    
    int bk=0;
    for(int k=0;k<q;k++){
    	int opt,x,y;
    	cin>>opt;
    	if(opt==1){
    		bk++;
    		bk%=4;
    	}else{
    		cin>>x>>y;
    		for(int i=0;i<m;i++){
	    		for(int j=0;j<m;j++){
	    			a[x+i-1][y+j-1]+=b[bk][i][j];
	    		}
	    	}
    	}
    }
    
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<"\n";
    }
	
	return 0;
}