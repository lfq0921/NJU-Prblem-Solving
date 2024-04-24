#include <bits/stdc++.h>
using namespace std;
const int MaxN = 505;
const int MaxC = 1003;
const int MaxM = 5e5 + 5;
const int PoolSize = MaxN * MaxC + MaxM;
struct ListItem;//����֮�����һ������ΪList��struct
typedef ListItem Li; //��ListItem����һ������Li
//�ڸ����䶨��֮ǰ��ֻ��������ʹ����ָ��
int c[MaxC];
int Index = 0;

Li *Head[MaxN], *Tail[MaxN];//

struct ListItem {//���в����ñ���
	int Index;
	/*���Ӹ�������ݳ�Ա��ʵ����ĿҪ��*/
	/*�������ָ����ʵ�����������*/
	int value;
	bool exist;
	struct ListItem *prev;
	struct ListItem *next;
	int num;
	
}Pool[PoolSize];//�ڴ�أ�����Ƶ�������ڴ浼��Ч�ʽ���

struct Lists
{
	ListItem *head;
	ListItem *tail;
};
Lists lists[MaxN];

ListItem *GetNewListItem() {//��������������������һ���µı���
	//��̬����ֻ���ʼ��1�Σ�auto��ʾ�Զ�ƥ�����ͣ���ҪC++11�����ϡ��������Ϊ�б�Ҫ���԰Ѹþ�̬�ֲ�������Ϊȫ�ֱ���
	//������Index����һ����/�ṹ������ݳ�Ա����ôɾ��auto��static����int
	++Index;
	Li * NewOne = &Pool[Index];
	NewOne->Index = Index;//����ı�źͳص��±���ͬ���ģ�����ֱ��ͨ��Pool[i]���õ���i�ű���, &Pool[i] �� (Pool + i) ��ʾָ���i�ű����ָ��
	//�������Ϊ�б�Ҫ����������������һЩ��ʼ�����룬Ҳ�������ӱ������Ĳ���
	NewOne->value = Index;
	NewOne->exist = true;
	return NewOne;
}
void inserthead(int nid)
{
	Li *node = GetNewListItem();
	node->num = nid;
	if (lists[nid].head == NULL) 
		lists[nid].head = lists[nid].tail = node;
	else 
	{
		int thelast = lists[nid].head->Index;
		Pool[thelast].prev = node;
		node->next = lists[nid].head;
		node->prev = NULL;
		lists[nid].head = node;
	}
}

void inserttail(int nid)
{
	ListItem *node = GetNewListItem();
	node->num = nid;
	if (lists[nid].tail == NULL)
		lists[nid].head = lists[nid].tail = node;
	else 
	{
		int thelast = lists[nid].tail->Index;
		Pool[thelast].next = node;
		node->prev = lists[nid].tail;
		node->next = NULL;
		lists[nid].tail = node;
	}
}

void deleteItem(int id)
{
	if((id > Index) || (id <= 0) || !(Pool[id].exist) ) 
		return;
	else 
	{ 
		Pool[id].exist = false;
		if (Pool[id].next != NULL) Pool[id].next->prev = Pool[id].prev;
		if (Pool[id].prev != NULL) Pool[id].prev->next = Pool[id].next;
		if ((Pool[id].next == NULL) && (Pool[id].prev != NULL)) lists[Pool[id].num].tail = Pool[id].prev;
		if ((Pool[id].prev == NULL) && (Pool[id].next != NULL)) lists[Pool[id].num].head = Pool[id].next;
		if ((Pool[id].prev == NULL) && (Pool[id].next == NULL)) lists[Pool[id].num].tail = lists[Pool[id].num].head =NULL;
		return; 
	}
}

void change(int id, int x)
{
	
	if(!(Pool[id].exist)) return;
	else Pool[id].value = x;
}

void printnode(int id)
{
	if(!(Pool[id].exist)) printf("NULL ");
	else printf("%d ",Pool[id].value);
}

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		for (int j = 1; j <= c[i]; j++){
			inserttail(i);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int opt;
		scanf("%d", &opt);
		int a;
		if(opt == 1)
		{
			scanf("%d", &a); 
			if (!Pool[a].exist) printf("NULL NULL NULL\n");
			else{
			if (Pool[a].prev != NULL) printnode(Pool[a].prev->Index);
			else printf("NULL ");
			printnode(a);
			if (Pool[a].next != NULL) printnode(Pool[a].next->Index);
			else printf("NULL ");
			printf("\n");
			}
		}
		if (opt == 2)
		{
			scanf("%d", &a);
			deleteItem(a);
		}
		if (opt == 3)
		{
			scanf("%d", &a);
			inserthead(a);
		}
		if (opt == 4)
		{
			scanf("%d", &a);
			inserttail(a);
		}
		if (opt == 5)
		{
			int what;
			scanf("%d %d", &a, &what);
			change(a, what);
		}
	}
	return 0;
}
