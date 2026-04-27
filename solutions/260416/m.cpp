#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,r,a;
    cin>>n>>m>>r>>a;
    double PI=3.141592653586793;
    vector<pair<int,int>> polyline(n+1),exhibit(m);
    for(int i=0;i<n;i++){
        cin>>polyline[i].first>>polyline[i].second;
    }
    polyline[n]=polyline[0];
    for(int i=0;i<m;i++){
        cin>>exhibit[i].first>>exhibit[i].second;
    }
    vector<double> ans(m+1,0.0);
    for(int i=0;i<n;i++){
        complex<double> z1,z2;
        z1=(complex<double>)polyline[i].first+(complex<double>)polyline[i].second*1i;
        z2=(complex<double>)polyline[i+1].first+(complex<double>)polyline[i+1].second*1i;
        complex<double> l=z2-z1;
        complex<double> l1=abs(l)/l;
        double x1=abs(l);
        vector<pair<double,int>> points;
        points.push_back({0.0,0});
        points.push_back({x1,0});
        for(int j=0;j<m;j++){
            complex<double> z3=(complex<double>)exhibit[j].first+(complex<double>)exhibit[j].second*1i;
            z3-=z1;
            z3*=l1;
            if(abs(z3.imag())>=(double)r){
                continue;
            }
            double x2=z3.real()-sqrt((double)r*(double)r-z3.imag()*z3.imag());
            if(x2>=x1){
                continue;
            }
            double x3=z3.real();
            if(a!=90){
                x3-=abs(z3.imag())/tan((double)a/180.0*PI);
            }
            if(x3<=0.0){
                continue;
            }
            if(x3<=x2){
                continue;
            }
            if(x2<=0.0){
                points.push_back({0.0,1});
            }else{
                points.push_back({x2,1});
            }
            if(x3>=x1){
                points.push_back({x1,-1});
            }else{
                points.push_back({x3,-1});
            }
        }
        sort(points.begin(),points.end(),[](auto p1,auto p2){
            if(p1.first==p2.first){
                return p1.second>p2.second;
            }
            return p1.first<p2.first;
        });
        int k=0;
        double prev=0.0,curr=0.0;
        for(auto i:points){
            curr=i.first;
            ans[k]+=curr-prev;
            k+=i.second;
            prev=curr;
        }
    }
    for(auto i:ans){
        printf("%.18lf\n",i);
    }
}