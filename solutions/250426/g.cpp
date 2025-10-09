#include<bits/stdc++.h>

using namespace std;

vector<int> sums(int k, vector<int> x, int pri_sum,int pri_i){
	int n=x.size();
	vector<int> sum,new_sum;
	if(k==0){
		sum.push_back(pri_sum);
		return sum;
	}
	for(int i=pri_i;i<=n-k;i++){
		new_sum=sums(k-1,x,pri_sum+x[i],i+1);
		sum.insert(sum.end(),new_sum.begin(),new_sum.end());
	}
	return sum;
}

vector<int> generatePrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main(){
    vector<int> primes = generatePrimes(10000);
    //for(int i:primes)cerr<<i<<endl;
	int n,k;
	cin>>n>>k;
	vector<int> x;
	int y;
	for(int i=0;i<n;i++){
		cin>>y;
		x.push_back(y);
	}
	vector<int> sum=sums(k,x,0,0);
	int ans=0,flag;
	for(int i:sum){
		flag=1;
		for(int j:primes){
			if(j*j>i){
				break;
			}
			if(i%j==0){
				flag=0;
				break;
			}
		}
		ans+=flag;
		//cerr<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}