#include <bits/stdc++.h>
using namespace std;
namespace MyQueue {
	const int MaxSize = 5e5 + 10; //�ڵ�������ҵ��C���У������ʹ�øÿ�ܣ����Ҳ����޸ı�������Ҳ�������κη�ʽ��ȥ�������Ӷ��е�����
	struct queue {
		int item[MaxSize], //�洢Ԫ�ص����� 
		limit, //��������
		head, //�����±�
		tail; //��β�±�
		int headReturn = 0;
		int tailReturn = 0;
		//������Ҫ��ʵ��һ��ѭ�����ÿռ�Ķ���
		//�㲢����Ҫ�����������ݳ�Ա��Ҳ����Ҫ��item��д��Ƕ���Ԫ�ص����ݣ�Ҳ����Ҫȫ�ֱ�������ʲô��̬�ֲ��������ܹ�ʵ�����¼�������
		//��������벻����ô�������������������ݳ�Ա��ȫ�ֱ���, �������������Ӷ�������
		void init(int n) {//��ʼ��Ϊһ����������Ϊlimit�Ķ���
			for (int i = 0; i < n; i++)
			{
				item[i] = 0;
			} 
			limit = n;
			head = 0;
			tail = 0;
		}
		bool empty() {//̽���Ƿ����Ϊ��
			if (((tail - head) == 0) && (tailReturn == headReturn)) return true;
			else return false;
		}
		bool full() {//̽������Ƿ�Ϊ��
			int tail1;
			if ((tail <= head) && (tailReturn > headReturn)) tail1 = tail + limit;
			else tail1 = tail;
			if ((tail1 - head) == (limit)){
				return true;
			}
			else {
				return false;
			}
		}
		void insert(int value) {//�ڶ�β����һ��Ԫ��
				item[tail] = value;
				tail++;
				if (tail >= limit) {
					tail -= limit;
					tailReturn++;
				}
				
			}
		
		int pop() {//�������ף�����ԭ���Ķ��׵�Ԫ����Ϊ����ֵ
			if (!empty())
			{
				int temp = item[head];
				item[head] = 0;
				if(!empty()) 
				{
					head++;
				}
				if (head >= limit) {
					head -= limit;
					headReturn++;
				}
				return temp;
			}
		}

	};
}
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	using MyQueue::queue;
	queue q;
	q.init(n);
	while (m--) {
		int op, x;
		cin >> op;
		if (op == 1) {
			cin >> x;
			if (!q.full()) {
				q.insert(x);
			}
		} else {
			if (!q.empty()) {
				cout << q.pop() << endl;
			}
		}
	}
	return 0;
}
