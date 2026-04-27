#include<bits/stdc++.h>

using namespace std;

vector<int> pattern_next(const string& pattern){
    int m=pattern.size();
    vector<int> next(m,0);
    for(int i=1,j=0;i<m;i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j=next[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
        }
        next[i]=j;
    }
    return next;
}

int kmp(const string& text, const string& pattern,vector<int> next){
    int ans=-1;
    int n=text.size(), m=pattern.size();
    if(n<m) return ans;
    for(int i=0,j=0;i<n;i++){
        while(j>0 && text[i]!=pattern[j]){
            j=next[j-1];
        }
        if(text[i]==pattern[j]){
            j++;
        }
        if(j==m){
            ans=i-m+1;
            break;
        }
    }
    return ans;
}

void solve(){
    vector<__int128> pow10;
    __int128 tmp=1;
    for(int i=0;i<=38;i++){
        pow10.push_back(tmp);
        tmp*=10;
    }
    string n,m;
    __int128 m1;
    cin>>n>>m;
    m1=0;
    for(int i=0;i<m.size();i++){
        m1*=10;
        m1+=(__int128)(m[i]-'0');
    }
    vector<__int128> n1;
    __int128 base=10000000000000000000LL;
    base*=base;
    for(int i=n.size()-1;i>=0;i-=38){
        __int128 a=0;
        for(int j=min(38,i+1)-1;j>=0;j--){
            a*=10;
            a+=(__int128)(n[i-j]-'0');
        }
        n1.push_back(a);
    }
    n1[0]+=1;
    for(int i=1;i<n1.size();i++){
        if(n1[i-1]/base==0){
            break;
        }
        n1[i]+=n1[i-1]/base;
        n1[i-1]%=base;
    }

    // case 1 mod case
    __int128 ans1;
    __int128 mod=0;
    __int128 mod10=1;
    for(int i=n.size()-1;i>=0;i--){
        mod+=(__int128)(n[i]-'0')*mod10;
        mod%=m1;
        mod10*=10;
        mod10%=m1;
    }
    ans1=m1-mod;
    if(mod==0){
        ans1=m1;
    }

    vector<__int128> n2;//max n
    for(auto i:n1){
        n2.push_back(i);
    }
    n2[0]+=ans1-1;
    for(int i=1;i<n2.size();i++){
        if(n2[i-1]/base==0){
            break;
        }
        n2[i]+=n2[i-1]/base;
        n2[i-1]%=base;
    }

    //case 2 last 2*m digital m
    vector<__int128> n3;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<2;j++){
            n3.clear();
            for(auto i:n1){
                n3.push_back(i);
            }
            n3[0]/=pow10[i+(int)m.size()];
            n3[0]+=j;
            n3[0]*=pow10[i+(int)m.size()];
            n3[0]+=m1*pow10[i];
            if(n3[0]>=n1[0]){
                ans1=min(n3[0]-n1[0]+1,ans1);
                break;
            }
        }
    }

    //case3 kmp
    string m2="",m3="",n4="";
    __int128 m4=m1;
    while(m4!=0){
        m2+=(char)(m4%10)+'0';
        m4/=10;
    }
    m4=m1-1;
    while(m4!=0){
        m3+=(char)(m4%10)+'0';
        m4/=10;
    }
    int flag=0;
    for(int i=0;i<m3.size();i++){
        if(m3[i]!='9'){
            flag=1;
            break;
        }
    }
    if(flag==0){
        m3+='0';
    }
    for(int i=0;i<n1.size();i++){
        string tmp="";
        __int128 m4=n1[i];
        while(m4!=0){
            tmp+=(char)(m4%10)+'0';
            m4/=10;
        }
        while((int)tmp.size()!=38 && i!=n1.size()-1){
            tmp+='0';
        }
        n4+=tmp;
    }
    int x2=kmp(n4,m2,pattern_next(m2));
    if(x2!=-1){
        ans1=1;
    }

    n1[0]+=ans1-1;
    for(int i=1;i<n1.size();i++){
        if(n1[i-1]/base==0){
            break;
        }
        n1[i]+=n1[i-1]/base;
        n1[i-1]%=base;
    }

    if(ans1>1){
        int x1=kmp(n4,m3,pattern_next(m3));
        if(x1!=-1){
            int i=0;
            for(;i<x1;i++){
                n4[i]='0';
            }
            for(;i<x1+m2.size();i++){
                n4[i]=m2[i-x1];
            }
            vector<__int128> n5;
            for(int i=0;i<n4.size();i+=38){
                __int128 a=0;
                for(int j=min(38,(int)n4.size()-i)-1;j>=0;j--){
                    a*=10;
                    a+=(__int128)(n4[i+j]-'0');
                }
                n5.push_back(a);
            }


            int flag1=0;
            for(int i=n1.size()-1;i>=0;i--){
                if(n1[i]<n5[i]){
                    break;
                }
                if(n1[i]>n5[i]){
                    flag1=1;
                    break;
                }
            }
            if(flag1==1){
                n1.clear();
                for(auto i:n5){
                    n1.push_back(i);
                }
            }
        }
    }

    for(int i=n1.size()-1;i>=0;i--){
        //if(n1.size()==0 && )

        if(i==n1.size()-1){
            __int128 x=n1[i];
            vector<int> v;
            while(x){
                v.push_back(x%10);
                x/=10;
            }
            for(int j=v.size()-1;j>=0;j--){
                cout << v[j];
            }
        }else{
            __int128 x=n1[i];
            vector<int> v;
            while(x){
                v.push_back(x%10);
                x/=10;
            }
            for(int j=0;j<38-((int)v.size());j++) cout << 0;
            for(int j=v.size()-1;j>=0;j--){
                cout << v[j];
            }
        }
    }
    cout<<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}