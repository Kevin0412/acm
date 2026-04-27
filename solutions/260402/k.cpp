#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T-->0){
        int n;
        cin >> n;
        vector<int> v0,v1,v2,v3;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            x %= 4;
            if(x==0){
                v0.push_back(i);
            }else if(x==1){
                v1.push_back(i);
            }else if(x==2){
                v2.push_back(i);
            }else{
                v3.push_back(i);
            }
        }

        int a=v1.size(),b=v2.size(),c=v3.size();
        if(abs(c-a)-2*b>2){
            cout << -1 << "\n";
        }else{
            for(int i=0;i<v0.size();i++) cout << v0[i] << " ";
            
            if(a>c){
                int d=a-c;
                while(v2.size() && d>0){
                    cout << v2.back() << " ";
                    v2.pop_back();
                    cout << v1.back() << " ";
                    v1.pop_back();
                    cout << v1.back() << " ";
                    v1.pop_back();
                    d -= 2;
                }
            }

            if(c>a){
                int d=c-a;
                while(v2.size() && d>0){
                    cout << v3.back() << " ";
                    v3.pop_back();
                    cout << v3.back() << " ";
                    v3.pop_back();
                    cout << v2.back() << " ";
                    v2.pop_back();
                    d -= 2;
                }
            }

            for(int i=0;i<v2.size();i++) cout << v2[i] << " ";

            for(int i=0;i<v1.size();i++){
                cout << v3[i] << " ";
                cout << v1[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}