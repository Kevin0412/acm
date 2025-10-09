#include<bits/stdc++.h>

using namespace std;

int time_string_to_minutes(const std::string& time_str) {
    int hours = 0, minutes = 0, seconds = 0;
    double fractional_seconds = 0.0;
    char colon1, colon2, dot;
    
    std::istringstream iss(time_str);
    iss >> hours >> colon1 >> minutes >> colon2 >> seconds;
    
    // 检查分隔符有效性
    if (colon1 != ':' || colon2 != ':') {
        throw std::invalid_argument("Invalid time format");
    }
    
    // 处理毫秒部分
    if (iss.peek() == '.') {
        iss >> dot; // 读取点号
        std::string frac_str;
        while (std::isdigit(iss.peek())) {
            frac_str += static_cast<char>(iss.get());
        }
        fractional_seconds = std::stod("0." + frac_str);
    }
    
    return hours * 60 + minutes;
}


struct {
	int first_solve[26];
	int fail[26];
	int penalty;
	int solved;
} teams[100005];

int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int k,n,i,j;
	int t,rank1,rank2;
	string time_str,p,r;
	cin>>k>>n;
	for(i=0;i<=k;i++){
		for(j=0;j<26;j++){
			teams[i].first_solve[j]=-1;
			teams[i].fail[j]=0;
		}
		teams[i].penalty=0;
		teams[i].solved=0;
	}
	while(n--){
		cin>>time_str>>t>>p>>r;
		rank2=0;
		if(t==0){
			if(r=="AC"){
				if(teams[0].first_solve[p[0]-'A']<0){
					rank1=1;
					rank2=1;
					for(i=1;i<=k;i++){
						if(teams[i].solved>teams[0].solved){
							rank1++;
						}else if(teams[i].solved==teams[0].solved & teams[i].penalty<teams[0].penalty){
							rank1++;
						}
						//cerr<<i<<" "<<teams[i].solved<<endl;
					}
				}
			}
		}
		if(r=="AC"){
			if(teams[t].first_solve[p[0]-'A']<0){
				teams[t].first_solve[p[0]-'A']=time_string_to_minutes(time_str);
				teams[t].solved++;
				teams[t].penalty+=teams[t].first_solve[p[0]-'A']+20*teams[t].fail[p[0]-'A'];
			}
		}else{
			if(teams[t].first_solve[p[0]-'A']<0){
				teams[t].fail[p[0]-'A']++;
			}
		}
		if(rank2){
			for(i=1;i<=k;i++){
				if(teams[i].solved>teams[0].solved){
					rank2++;
				}else if(teams[i].solved==teams[0].solved & teams[i].penalty<teams[0].penalty){
					rank2++;
				}
			}
			cout<<time_str<<" "<<p<<" #"<<rank1<<" -> #"<<rank2<<endl;
		}
	}
	return 0;
}