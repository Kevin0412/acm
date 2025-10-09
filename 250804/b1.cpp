#include <bits/stdc++.h>
using namespace std; 
#define int long long
using ll = long long;
const int MOD = 1e9 + 7;
// 矩a阵结构体
struct Matrix {
    int n, m; // n: 行数, m: 列数
    vector<vector<ll>> a;
    Matrix(int _n, int _m) : n(_n), m(_m), a(_n + 1, vector<ll>(_m + 1, 0)) {}

    static Matrix identity(int n) {
        Matrix I(n, n);
        for (int i = 1; i <= n; ++i) {
            I.a[i][i] = 1;
        }
        return I;
    }
};
// 矩阵乘法: C = A * B
// 时间复杂度: O(n^3) 或 O(A.n * A.m * B.m)
Matrix operator*(const Matrix& A, const Matrix& B) {
    Matrix C(A.n, B.m);
    for (int i = 1; i <= A.n; ++i) {
        for (int j = 1; j <= B.m; ++j) {
            for (int k = 1; k <= A.m; ++k) {
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
            }
        }
    }
    return C;
}



// 矩阵快速幂: A^p, 时间复杂度: O(n^3 * log p) , A必须是方阵
Matrix power(Matrix A, ll p) {
    Matrix res = Matrix::identity(A.n);
    while (p) {
        if (p & 1) res= res * A;
        A = A * A;
        p >>= 1;
    }
    return res;
}

void solve(){
	ll n;
	cin>>n;
	if(n<=3){
		cout<<1<<endl;
		return;
	}
	Matrix m(3,3);
	m.a[1][2]=1;
	m.a[2][3]=1;
	m.a[3][1]=1;
	m.a[3][3]=1;
	Matrix a(3,1);
	a.a[1][1]=1;
	a.a[2][1]=1;
	a.a[3][1]=1;
	Matrix ans=power(m,n-3)*a;
	cout<<ans.a[3][1]<<endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0); 
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}