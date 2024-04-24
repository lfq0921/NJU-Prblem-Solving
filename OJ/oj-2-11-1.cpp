/**
 * �������� ��C/C++���ԣ�
 * ��ʵ���·��������ȽϺ�����C99�е�qsort������������ǩ���뺬����·�ע�ͺ�
 * https://en.cppreference.com/w/c/algorithm/qsort��
 * �㲻���޸�main������ʵ�ֺ��������в���ʹ���κο⺯����
 * */
#include <stdio.h>

/**
 * Sorts the given array pointed to by ptr in ascending order.
 * The array contains count elements of size bytes.
 * Function pointed to by comp is used for object comparison.
 * 1. ptr - pointer to the array to sort
 * 2. count - number of element in the array
 * 3. size - size of each element in the array in bytes
 * 4. comp - comparison function which returns a negative integer
 * value if the first argument is less than the second, a positive integer value
 * if the first argument is greater than the second and zero if the arguments
 * are equal. The function must not modify the objects passed to it and must
 * return consistent results when called for the same objects, regardless of
 * their positions in the array. * */
 
 /**
 * ������� ptr ��ָ��ĸ��������������
 * ���������С�ֽڵļ���Ԫ�ء�
 * comp ��ָ��Ĺ������ڶ���Ƚϡ�
 * 1.ptr - ָ��Ҫ����������ָ��
 * 2.count - ������Ԫ�ص�����
 * 3.size - ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
 * 4.comp - ���ظ������ıȽϺ���
 * ֵ �����һ������С�ڵڶ�����������Ϊ������ֵ
 * �����һ���������ڵڶ����������������Ϊ��
 * ��ȡ��ú��������޸Ĵ��ݸ����Ķ��󣬲��ұ���
 * ��Ϊ��ͬ�������ʱ����һ�µĽ������������
 * �����������е�λ�á�* */
 
void mySwap(void *a, void *b, size_t size)
{
	char *pa = (char *)a; 
	char *pb = (char *)b;
	for (int i = 0; i < size; i++) 
	{
		char tmp = *(pa + i);
		*(pa + i) = *(pa + i);
		*(pa + i) = tmp;
	}
	return ;
}

void qsort(void *ptr, size_t count, size_t size,
           int (*comp)(const void *, const void *))
{
	if(count <= 1) return;
	int l = 0; 
	int r = count - 1;
	while (l < r)
	{
		while ((l < r) && comp((char*)ptr + r * size, (char*)ptr) >= 0) r--;
		while ((l < r) && comp((char*)ptr + r * size, (char*)ptr) >= 0) l++;
		if (l < r) mySwap ((char*)ptr + l * size, (char*)ptr + r * size, size);
	}
	mySwap((char*)ptr, (char*)ptr + l * size, size);
	qsort((char*)ptr, l, size, comp);
	qsort((char*)ptr + (l + 1) * size, count - l - 1, size, comp);
	return;
 } 
/**
 * Return a negative value if the integer a points to is smaller than that of b.
 * Return a positive value if the integer a points to is larger than that of b.
 * Return zero if the integers a and b point to are equal.
 * */
int less(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b) return -1;
	if (*(int *)a == *(int *)b) return 0;
	if (*(int *)a > *(int *)b) return 1;
}
/**
 * Return a negative value if the real number (double) a points to is larger
 * than that of b. Return a positive value if the real number (double) a points
 * to is smaller than that of b. Return zero if the real number (double) a and b
 * point to are equal.
 * */
int greater(const void *a, const void *b)
{
	if (*(double *)a > *(double*)b) return -1;
	if (*(double *)a == *(double*)b) return 0;
	if (*(double *)a < *(double*)b) return 1;
}

int a[100005] = {};
double b[100005] = {};

int main() {
  int T = 0;
  scanf("%d", &T);
  while (T--) {
    int i = 0, type = 0, n = 0;
    scanf("%d%d", &type, &n);
    if (type == 1) {
      for (i = 0; i < n; ++i) {
        scanf("%d", a + i);
      }
      qsort(a, n, sizeof(int), less);
      for (i = 0; i < n; ++i) {
        printf("%d ", a[i]);
      }
      printf("\n");
    } else {
      for (i = 0; i < n; ++i) {
        scanf("%lf", b + i);
      }
      qsort(b, n, sizeof(double), greater);
      for (i = 0; i < n; ++i) {
        printf("%.3lf ", b[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
