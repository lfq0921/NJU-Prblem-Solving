#include<iostream>
using namespace std;
typedef long long ll;

int qmi(int a,int k,int p)
{
    int res = 1 % p;
    while(k)
    {
        if(k & 1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}
int pi (int n, int m)//����n��/��n-m���� 
{
	ll res = 1;
	for (int i = n - m + 1; i <= n; i++)
		res = (res * (i % 998244353)) % 998244353;
	return res;
 } 
int main()
{
	int n, m, k, c;
	cin >> n >> m >> k >> c;
	int multi = 1;
	int multi2;
	for (int i = 1; i <= n + 1; i++)//���������׳�   n���ͣ�n + 1���� 
	{
		multi = (multi * (i % 998244353)) % 998244353;//(n+1)!
		if (i == n) multi2 = multi;//n!
	}
	if (multi2 < 0)
	multi = qmi(multi, 998244353 - 2, 998244353) % 998244353;//��n+1��������Ԫ 
	multi2 = qmi(multi2, 998244353 - 2, 998244353) % 998244353;// n������Ԫ 
	ll c1 = ((pi(m + n, n + 1) % 998244353) * multi) % 998244353;//����k��������C(m+n, n+1)
	ll c2 = ((pi(m + n - 1, n) % 998244353) * (multi2 % 998244353)) % 998244353;//����c�������� (m+n-1, n)
	ll ans = ((c1 * k) % 998244353+ (c2 * c) % 998244353) % 998244353;//������ 
	cout << ans;
	return 0;
}
