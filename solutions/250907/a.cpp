#include<bits/stdc++.h>
using namespace std;
int t,s;
const int N=1e5+10;
int pt[N],upt[N],pass[N],pospass[N];
bool pas[28];
int pl[28];
string team[N];
vector<string> chm;
int st=1,cnt=0;
struct re{
    int status,st,id;
};
struct line
{
    int pa,subtim;
};
void ups(line &m,line ne)
{
    if(m.pa<ne.pa||(m.pa==ne.pa&&m.subtim>ne.subtim))
        m=ne;
    return;
}
vector<re> record[N];
bool cmpr(re a,re b)
{
    return a.st>b.st;
}
int main()
{
    cin>>t;
    while(t--)
    {
        map<string,int>mp;
        st=cnt;
        cin>>s;
        for(int i=1;i<=s;i++)
        {
            string na,po,re;
            int tim;
            cin>>na>>po>>tim>>re;
            int stu=0;
            if(mp[na]==0)
            {
                mp[na]=cnt;
                team[cnt]=na;
                cnt++;
            }
            if(re[0]=='R') stu=1;
            else if(re[0]=='A') stu=2;
            else stu=3;
            record[mp[na]].push_back({stu,tim,(po[0]-'A')});
        }
        line cpl={0,0};
        for(int i=st;i<cnt;i++)
        {
            memset(pl,0,sizeof(pl));
            memset(pas,0,sizeof(pas));
            sort(record[i].begin(),record[i].end(),cmpr);
            for(auto p:record[i])
            {
                if(p.status==1)
                {
                    pl[p.id]++;
                }
                else if(p.status==2)
                {
                    if(!pas[p.id])
                    {
                        pas[p.id]=true;
                        pt[i]+=p.st+pl[p.id]*20;
                        upt[i]+=p.st+pl[p.id]*20;
                        pass[i]++;pospass[i]++;
                    }
                }
                else
                {
                    if(!pas[p.id])
                    {
                        pas[p.id]=true;
                        pospass[i]++;
                        upt[i]+=p.st+pl[p.id]*20;
                        pospass[i]++;
                    }
                }
            }
            line temp={pass[i],pt[i]};
            ups(cpl,temp);
        }
        chm.clear();
        for(int i=st;i<cnt;i++)
        {
            if(pospass[i]>cpl.pa||(pospass[i]==cpl.pa&&upt[i]<=cpl.subtim))
            {
                chm.push_back(team[i]);
            }
        }
        for(int i=0;i<int(chm.size());i++)
        {
            cout<<chm[i]<<(i==int(chm.size())-1?'\n':' ');
        }
    }
    return 0;
}