#include<bits/stdc++.h>

using namespace std;

double cross(pair<double,double> a,pair<double,double> b,pair<double,double> c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}

double dist(pair<double,double> a,pair<double,double> b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(){
	int i,n;
	cin>>n;
	vector<pair<double,double>> a,b;
	double x,y,ans=0;
	for(i=0;i<n;i++){
		cin>>x>>y;
		a.push_back({x,y});
	}
	sort(a.begin(),a.end(),[](const auto& b,const auto& c){
		if(b.first==c.first)return b.second < c.second;
		return b.first < c.first;
	});
	for(i=0;i<a.size();i++){
		while(b.size()>=2){
			auto top=b.back();
			auto nextTop=b[b.size()-2];
			if(cross(nextTop,top,a[i])>0)break;
			b.pop_back();
		}
		b.push_back(a[i]);
	}
	int lowerSize=b.size();
	for(i=a.size()-2;i>=0;i--){
		while(b.size()>lowerSize){
			auto top=b.back();
			auto nextTop=b[b.size()-2];
			if(cross(nextTop,top,a[i])>0)break;
			b.pop_back();
		}
		b.push_back(a[i]);
	}
	for(i=0;i<b.size()-1;i++){
		ans+=dist(b[i],b[i+1]);
	}
	printf("%.2lf\n",ans);
	return 0;
}