#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int len=str.length();
        int odd0=0,odd1=0,odd2=0,even0=0,even1=0,even2=0;
        for(int i=0;i<len;i++)
        {
        	if(i%2==0){
        		if(str[i]=='0'){
        			odd0++;
        		}else if(str[i]=='1'){
        			odd1++;
        		}else if(str[i]=='2'){
        			odd2++;
        		}
        	}else{
        		if(str[i]=='0'){
        			even0++;
        		}else if(str[i]=='1'){
        			even1++;
        		}else if(str[i]=='2'){
        			even2++;
        		}
        	}
        }
        if(odd0>even0){
        	if(odd0-even0<=even2){
        		even2-=odd0-even0;
        		even0=odd0;
        	}else{
        		even0+=even2;
        		even2=0;
        	}
        }else{
        	if(even0-odd0<=odd2){
        		odd2-=even0-odd0;
        		odd0=even0;
        	}else{
        		odd0+=odd2;
        		odd2=0;
        	}
        }
        if(odd1>even1){
        	if(odd1-even1<=even2){
        		even2-=odd1-even1;
        		even1=odd1;
        	}else{
        		even1+=even2;
        		even2=0;
        	}
        }else{
        	if(even1-odd1<=odd2){
        		odd2-=even1-odd1;
        		odd1=even1;
        	}else{
        		odd1+=odd2;
        		odd2=0;
        	}
        }
        cout<<abs(odd0-even0)+abs(odd1-even1)+abs(odd2-even2)<<"\n"
    }
    return 0;
}