'''#include<bits/stdc++.h>
using namespace std;
int t;
double a,b,c,d,e,f,ppm;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>ppm;
        cin>>a>>b>>c>>d>>e>>f;
        double acc=(a+b+2.0*c/3.0+d/3.0+e/6.0)/(a+b+c+d+e+f);
        double ppu=((320.0*a+300.0*b+200.0*c+100.0*d+50.0*e)-(320.0*(a+b+c+d+e+f))*0.8)*5*ppm;
        double ppl=320.0*(a+b+c+d+e+f);
        acc*=100;
        cout<<std::fixed<<std::setprecision(2)<<acc<<"% "<<int(max(ppu/ppl+0.5,0.0))<<'\n';
    }
    return 0;
}'''

t=int(input())
for _ in range(t):
    ppm=int(input())
    g=input().split(" ")
    a=int(g[0])
    b=int(g[1])
    c=int(g[2])
    d=int(g[3])
    e=int(g[4])
    f=int(g[5])
    acc_1=a+b+2.0*c/3.0+d/3.0+e/6.0
    acc_2=a+b+c+d+e+f
    ppu=((320*a+300*b+200*c+100*d+50*e)-256*(a+b+c+d+e+f))*5*ppm;
    ppl=320*(a+b+c+d+e+f)
    acc_1*=100
    print("{:.2f}% {}".format(round(acc_1/acc_2,2),max(round(ppu/ppl),0)))