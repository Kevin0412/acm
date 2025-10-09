#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
bool is_prime[MAXN + 1];
vector<int> primes;

void euler_sieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        // 用已得到的素数 primes[j] 去筛
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = false;
            // 关键：保证每个合数只被最小质因子筛掉
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main(){
    euler_sieve(1000);

    for(auto i:primes){
        cout<<i<<",";
    }
    cout<<endl;
}

