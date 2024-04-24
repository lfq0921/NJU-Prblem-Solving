#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e5 + 5;
int n, m;//���������� 
int n1, m1;
int timer;//dfsʱ��� 
int stac[N], top;//ջ 
int deg[N] = { 0 };//�½�ͼ�Ķ� 
int dfn[N] = { 0 }, low[N] = { 0 }; 
bool instack[N];//�Ƿ���ջ�� 
int cnt = 0;//ǿ��ͨ��������
int represent[N] = { 0 };//��һ������������ 
long long Max = 0;
long long dis[N] = { 0 };
vector<pair<int, int>> e[N], e1[N];
vector<int> inhuan;
bool jinhuan[N] = { 0 };

void tarjan(int x)
{
	dfn[x] = low[x] = ++timer;//��ʱ���
	//��ջ 
	stac[++top] = x;
	instack[x] = 1;
	/*----------------------����---------------------*/ 
	for(int i = 0; i < e[x].size(); i++)//����ÿһ���� 
	{
		int y = e[x][i].first;
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(instack[y]) low[x] = min(low[x],dfn[y]);
	}
	/*---------------------------------------------*/
	if(dfn[x] == low[x])
	{
		int y;
		//�ҵ�һ��ǿ��ͨ���� 
		cnt++;  
		do  
		{  
			//��ջ
			y=stac[top--];  
			instack[y] = 0;  
			represent[y] = x;//���㸳ֵ���ڵ�ǿ��ͨ�������  
		}while(x != y);  
	} 
	return;
}

void toposort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if(represent[i] == i && !deg[i]) q.push(i);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int sz = e1[x].size();
		for (int i = 0; i < sz; i++)
		{
			int y = e1[x][i].first;
			int z = e1[x][i].second;
			deg[y]--;
			dis[y] = max(dis[y], dis[x] + z);
			if (dis[y] > Max) Max = dis[y];
			if (deg[e1[x][i].first] == 0) q.push(e1[x][i].first);
		}
	}
 }

int main()
{
	timer = 0;
	top = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++)//�����µ�ͼ 
	{
		int rep = represent[i];
		if (rep == i) n1++;
		int sz = e[i].size();
		for (int j = 0; j < sz; j++)
		{
			if (represent[i] != represent[e[i][j].first]) 
			{
				deg[e[i][j].first]++; //ͳ��ÿ��������
				e1[rep].push_back(e[i][j]);//����ͼ 
			}
			else
			{
				jinhuan[i] = 1;
				jinhuan[e[i][j].first] = 1;
			}
		} 
	}
	toposort();//����������Ϊdp˳��
	for (int i = 1; i <= n; i++)
	if (jinhuan[i]) inhuan.push_back(i);
	sort(inhuan.begin(), inhuan.end());
	int sz = inhuan.size();
	for (int i = 0; i < sz; i++)
	printf("%d ", inhuan[i]);
	printf("\n%lld", Max);
	return 0;
}

