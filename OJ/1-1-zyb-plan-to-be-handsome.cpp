#include<iostream>
#include<algorithm>
#include<cmath>
#include <string.h>
using namespace std;
//typedef __int128 int128;
int value[505];
long long f[505][505], sum;
int m, n;

/*long long find_Max(int x, int begin, int end, int time)
{
	if (time > m) return 0;
	//if (b[x][time] != -1) return b[x][time];
	long long choice1 = (a[x][begin] * a[x][begin] * a[x][begin]) * time * time + find_Max(x, begin + 1, end, time + 1);
	printf("(%d, %d, %d, %d) choice1 = %lld\n", x, begin, end, time, choice1);
	long long choice2 = (a[x][end] * a[x][end] * a[x][end]) * time * time + find_Max(x, begin, end - 1, time + 1);
	printf("(%d, %d, %d, %d) choice2 = %lld\n", x, begin, end, time, choice2);
	long long choice3 = 0;
	b[x][time] = max(choice1, choice2);
	b[x][time] = b[x][time] > choice3 ? b[x][time] : choice3;
	printf("b[%d][%d] = %lld\n", x, time, b[x][time]);
	return b[x][time];
}*/ 

int main()
{
	cin >> n >> m;long long ans = 0;
	while(n--)
	{
		memset(f, 0, sizeof f);
		for (int i = 1; i <= m; i++)
			scanf("%d", &value[i]);
			
		for (int i = 1; i <= m; i++)
		{
			for (int j = m; j >= i; j++)	
			{
				long long left = f[i - 1][j] + (value[i - 1] * value[i - 1] * value[i - 1] * (m - j + i - 1) * (m - j + i - 1));
                long long right = f[i][j + 1] + (value[j + 1] * value[j + 1] * value[j + 1] * (m - j + i - 1) * (m - j + i - 1));
                f[i][j] = left;                //����f[]����һ��ʼȫ����ֵΪ0���������f[i-1][j]��f[i][j+1]���Ǹ���������maxȡ0���𰸾Ͳ����ˡ���Ҫ�ȸ�һ��ֵ��
                f[i][j] = max(right, f[i][j]); //��̬�滮״̬����
                // f[i][j] = max(f[i-1][j]+value[i-1]*����^2,f[i][j+1]+value[j+1]*����^2)

                if (i == 1 && j != m) //����ֻ��ѡ�ұߣ������ұ�ֵΪ���������
                    f[i][j] = right;
                else if (j == m) //����ֻ��ѡ��ߣ��������ֵΪ���������
                    f[i][j] = left;
			}
		}
		long long maxn = f[1][m];
        for (int i = 1; i <= m; i++) //���䴦��f[i][i] �����һ�ε�ֵ����
            f[i][i] = max(f[i][i], (f[i][i] + (value[i] * value[i] * value[i] * m * m)));

        for (int i = 1; i <= m; i++) //�������Ĵ�һ����һ������f[i][j]���Ա���һ��Ѱ�����ֵ��Ϊ���д�
            for (int j = m; j >= i; j--)
                maxn = max(f[i][j], maxn);
        ans += maxn; //�����еĴ���Ӽ�Ϊ���մ�
	}
	
	cout << ans;		
	/*sum = 0;
	for(int i = 1; i <= n; i++)
	{
		printf("this is %d turn\n", i);
		sum += find_Max(i, 1, m, 1);
		
	}
	printf("%lld", sum);
	return 0;*/
}
