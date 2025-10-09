#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,j,k,m,t,n,a[40],b[40],ans,temp,o;
	vector<int> l,r;
	cin>>t;
	for(i=0;i<t;i++){
		l.clear();
		r.clear();
		ans=0;
		cin>>n;
		for(j=0;j<n;j++)cin>>a[j];
		for(j=0;j<n;j++)cin>>b[j];
		for(j=1;j<=n;j++){
			for(k=0;k<n;k++){
				if(a[k]==j){
					break;
				}
				if(b[k]==j){
					if(k+1<j){
						for(m=k;m+1<j;m++){
							l.push_back(2);
							r.push_back(m+1);
							temp=b[m];
							b[m]=b[m+1];
							b[m+1]=temp;
							ans++;
						}
						l.push_back(3);
						r.push_back(j);
						temp=a[j-1];
						a[j-1]=b[j-1];
						b[j-1]=temp;
						ans++;
					}
					else{
						l.push_back(3);
						r.push_back(k+1);
						temp=a[k];
						a[k]=b[k];
						b[k]=temp;
						ans++;
					}
					break;
				}
			}
			for(k;k>=j;k--){
				l.push_back(1);
				r.push_back(k);
				temp=a[k-1];
				a[k-1]=a[k];
				a[k]=temp;
				ans++;
			}
		}
		for(j=n+1;j<=2*n;j++){
			for(k=0;k<n;k++){
				if(b[k]==j){
					break;
				}
			}
			for(k;k>=j-n;k--){
				l.push_back(2);
				r.push_back(k);
				temp=b[k-1];
				b[k-1]=b[k];
				b[k]=temp;
				ans++;
			}
		}
		cout<<ans<<endl;
		for(j=0;j<l.size();j++){
			cout<<l[j]<<" "<<r[j]<<endl;
		}
		for(o=0;o<n;o++)cerr<<a[o]<<" ";
		cerr<<endl;
		for(o=0;o<n;o++)cerr<<b[o]<<" ";
		cerr<<endl;
	}
	return 0;
}