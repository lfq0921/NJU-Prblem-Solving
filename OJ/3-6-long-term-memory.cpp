#include<bits/stdc++.h>
using namespace std;
int k,ans;
int a[3205];
bool cmp(int a1, int b1)
{
	return a1 >= b1;
}
int main()
{
	scanf("%d", &k);
	ans = 0;
	while (k--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		
		bool flag = 1;
		ans = 0;
		for(int i = 1; i < n; i++)
		{  
			sort(a + i, a + n + 1, cmp);// �ӵ�i��Ԫ�ؿ�ʼ�ǵ������� 
			/*for (int t = i; t <= n; t++)
			{
				printf("%d ", a[t]);
			}
			printf("\n");*/
			
			int j;
			if(a[i] > n - i) 
			{
				flag = 0;
				j = i + a[i] + 1;
			}//����i��Ԫ��+arr[i]��ֵ����ԭ���鳤�ȣ���ô�������
			for(j = i + 1; j <= i + a[i]; j++)
				{  
					a[j]--;  
					if(a[j] < 0) 
					{
						flag = 0; 
						j = i + a[i] + 1;
					} 
				}  
				if (!flag) break; 
		}
		if (flag) ans += 1;
	}
	printf("%d", ans);
	return 0;
 } 
