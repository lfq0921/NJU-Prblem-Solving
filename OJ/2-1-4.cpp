#include<iostream>
using namespace std;
struct node
{
	struct node* next[26];
	bool isend;
};
node *newnode()
{
	node *thenew = new node;
	for (int i = 0; i <= 25; i++)
	{
		thenew->next[i] = NULL;
		thenew->isend = false;	
	}
	return thenew;
}
void search(node *root, string str) 
{
    node *cur = root;
    int i = 0;
    for(i = 0; str[i] /* �ȼ���str[i] != '\0'*/ ; ++i) 
    {
    	cur = cur->next[str[i] - 'a'];//�л�����Ӧ���ߵ�����
    	if(cur == NULL) //�ߵ��˿ս��
		{
        cout << "NO" << endl;
            return;
        } 
    } 
    if (cur != NULL && cur->isend)//�ǿ���Ϊĳ�����ʵĽ�β
	cout << "YES" << endl; 
	else cout << "NO" << endl;
	return;
} 
void insert(node *root, string str)
{
	int i = 0; 
    node *cur = root; 
    for(i = 0; str[i] /* �ȼ���str[i] != '\0'*/ ; ++i)
	{
		if (!cur->next[str[i] - 'a'])
		{
			cur->next[str[i] - 'a'] = newnode();
		}
		if(str[i + 1] == '\0')
		{
			cur->next[str[i] - 'a']->isend = true;
		}
		
		else cur = cur->next[str[i] - 'a'];
	 }
	 return;
}
int main()
{
	int n;
	cin >> n;
	node *ROOT = newnode();
	while (n--)
	{
		char opt;
		string str;
		cin >> opt >> str;
		switch(opt)
		{
			case 'I':insert(ROOT, str); break;
			case 'S':search(ROOT, str); 
		}
	}
	return 0;
 } 
