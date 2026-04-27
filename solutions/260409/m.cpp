#include<bits/stdc++.h>
using namespace std;

vector<long long> cross(vector<long long> va,vector<long long> vb){
    return {va[1]*vb[2]-va[2]*vb[1],va[2]*vb[0]-va[0]*vb[2],va[0]*vb[1]-va[1]*vb[0]};
}

long long dot(vector<long long> va,vector<long long> vb){
    return va[0]*vb[0]+va[1]*vb[1]+va[2]*vb[2];
}

vector<long double> cross(vector<long double> va,vector<long double> vb){
    return {va[1]*vb[2]-va[2]*vb[1],va[2]*vb[0]-va[0]*vb[2],va[0]*vb[1]-va[1]*vb[0]};
}

long double dot(vector<long double> va,vector<long double> vb){
    return va[0]*vb[0]+va[1]*vb[1]+va[2]*vb[2];
}

long double absv(vector<long double> v){
    return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

long double degree(vector<long double> va,vector<long double> vb){
    return acos(max(min(dot(va,vb)/absv(va)/absv(vb),(long double)1.0),(long double)-1.0));
}

void solve(){
    long double r;
    vector<long long> va(3),vb(3),vh(3);
    cin>>r;
    cin>>vh[0]>>vh[1]>>vh[2];
    cin>>va[0]>>va[1]>>va[2];
    cin>>vb[0]>>vb[1]>>vb[2];
    if(dot(va,vh)==0 && dot(vb,vh)==0){
        printf("%.18llf\n",3.141592653589793/2*r);
        return;
    }
    vector<long long> fa=cross(va,vb);
    vector<long double> fad={(long double)fa[0],(long double)fa[1],(long double)fa[2]};
    fad={fad[0]/absv(fad),fad[1]/absv(fad),fad[2]/absv(fad)};
    vector<long double> vad={(long double)va[0],(long double)va[1],(long double)va[2]};
    vector<long double> vbd={(long double)vb[0],(long double)vb[1],(long double)vb[2]};
    vector<long double> vhd={(long double)vh[0],(long double)vh[1],(long double)vh[2]};
    vector<long double> projv={fad[0]*dot(vhd,fad),fad[1]*dot(vhd,fad),fad[2]*dot(vhd,fad)};
    vector<long double> projp={vhd[0]-projv[0],vhd[1]-projv[1],vhd[2]-projv[2]};
    long double dab,dhpa,dhpb;
    dab=degree(vad,vbd);
    dhpa=degree(vad,projp);
    dhpb=degree(vbd,projp);
    if(abs(dhpa+dhpb-dab)<1.0e-8){
        //cout<<r*degree(vhd,projp)<<"\n";
        printf("%.18llf\n",r*degree(vhd,projp));
    }else{
        //cout<<r*min(degree(vhd,vad),degree(vhd,vbd))<<"\n";
        printf("%.18llf\n",r*min(degree(vhd,vad),degree(vhd,vbd)));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}