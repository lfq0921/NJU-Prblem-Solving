struct cmp
{
	bool operator () (point A, pointB)
	{
		return A.dis > B.dis;
	}
};//���ȶ����д�ṹ�� 
