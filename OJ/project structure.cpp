#include <conio.h>
#include <iostream>
using namespace std;

void deal_with_input()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		cout << ch;//�˴�����ӡ������Ҫ���������Ĳ�ͬ������ͬ�Ĵ��� 
	}
}

void display()
{
	system("cls");//clear the screen
	//��ӡ��ʾ����Ϣ 
 } 
int count = 0;
int main()
{
	init();
	display();
	while(1)
	{
		deal_with_input();
		count = count + 1;
		if (count == ONE_SECOND)
		{
			deal_with_timer();
			count = 0;
		}
	}
	return 0;
 }
