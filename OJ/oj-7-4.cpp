#include <bits/stdc++.h>
using namespace std;
namespace MyList {//�����������ǵ�list��STL��list
	const int MaxSize = 2e5 + 1;//��1��ʼ�ã������Ҫn+m�� 
	struct Item {
		int link[2];//link[0]��link[1]��ʾ0�����1�������һ��������±�, ����㺦�����֣����Ըĳ� int left, right;
		//int val; ���ⲻ��Ҫ
	};
	struct list {
		Item item[MaxSize];//���ڴ洢����
		int size;//�ж��ٸ���Ч�ı���
		int cur;//��ǰ������±�
		int idx;//ÿ����+1����Ϊ�±�����±���ʹ��
		void init(int n) {//��ʼ��1��n, ����insertӦ���ܹ���ȷ�����0��ʼ���룬���Կ���ֱ�Ӹ���insert
			/*to do*/ // ����Ҫ�ȰѼ���������ʼ��
			size = 0; 
			idx = 0;
			for (int i = 0; i < n; ++i) insert(), cur = idx;
			cur = 1;
		}
		void erase() {//ɾ��curָ��ı������ϸ�ڼ�����
			//ע��size == 1ʱ
			/*to do*/
			if (size != 0)
			{
				item[item[cur].link[0]].link[1] = item[cur].link[1];
				item[item[cur].link[1]].link[0] = item[cur].link[0];
				cur = item[cur].link[0];
				size--;
			}
		}
		void insert() {//�ڵ�ǰ�����0��������һ��������±�Ϊ++idx ��{���(size == 0) {��ֱ�Ӻ��������λ�ã�������ǰ�±�����Ϊ�±�����±�}}��
			//ע��size == 0ʱ��size == 1ʱ�������ֶ�ģ��һ��Ӧ����ô����
			//���˽�++x��x++������
			/*to do*/
			if (size == 0)
			{
				++idx;
				item[idx].link[0] = idx;
				item[idx].link[1] = idx;
				cur = idx;
				++size;
			}
			else
			{
				++idx;
				item[idx].link[1] = cur;
				item[idx].link[0] = item[cur].link[0];
				item[item[cur].link[0]].link[1] = idx;
				item[cur].link[0] = idx;
				++size;
			}
		
		}
		void move(int cnt, int dir) {//��cur��dir�����ƶ�cnt��������ϸ�ڼ�����
			/*�Ƚ����Ż����õ����ŵ�dir��cnt��size == 0ʱ��Ҫ���Բ���*/
			/*to do*/
			if (size != 0)
			{
				if (cnt < 0) {
					dir = 1 - dir;
					cnt = -cnt;
				}
				int step = cnt % size;
				if (step > (size / 2)) {
					step = size - step;
					dir = 1 - dir;
				}
				for (int i = 1; i <= step; i++)
					cur = item[cur].link[dir];
			}
			
		}
		int getCur() {//ȡ����ǰ������±�
			return size ? cur : -1;
		}

	};
}
int main() {
	using namespace MyList;
	//������ڴ˴�д��using MyList::list; ����using namespace MyList; �����Ͳ���ÿ������list��дMyList::ǰ׺
	//��������using��namespace��������ݺ�����using��namespace��ͻ�����ͽ�ԭ�����������һ����������Ϊ׼
	MyList::list l;
	int op, x, n, m;
	cin >> n;
	l.init(n);
	/*to do*/
	cin >> m;
	for(int i = 1; i <= m; ++i)
	{
		cin >> op;
		switch(op)
		{
			case 0:
				l.erase(); break;
			case 1:
				l.insert(); break;
			case 2:
				cin >> x; l.move(x, 0); break;
			case 3:
				cin >> x; l.move(x, 1); break;
			case 4:
				cout << l.getCur() << endl; break;
		}
	}
	
	return 0;
}
