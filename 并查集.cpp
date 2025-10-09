#include<bits/stdc++.h>
using namespace std;

int a[200001];

int find(int x,int a[]){
	if (a[x] == -1) return x;
	return a[x] = find(a[x], a);  
}


int main(){
	int n,m;
	int z,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=-1;
	}
	for(int i=0;i<m;i++){
		cin>>z>>x>>y;
		if(z==1){
			int r1=find(x,a);
			int r2=find(y,a);
			if (r1!=r2){
				a[r1]=r2;
			}
		}else{
			if(find(x,a)==find(y,a)){
				cout<<"Y"<<endl;
			}else{
				cout<<"N"<<endl;
			}
		}
	}
	
	return 0;
}