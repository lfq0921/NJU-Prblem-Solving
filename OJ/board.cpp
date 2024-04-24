#include<bits/stdc++.h>
using namespace std;
//һЩ����
//ŷ������������ɸ������

//�����㷨
//��������
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//ð��������ǰ�ÿһ��������һ����ѭ���͵�ͷ

//����
int part(int* r, int low, int hight)  //���ֺ���
{
	int i = low, j = hight, pivot = r[low]; //��׼Ԫ��
	while (i < j)
	{
		while (i<j && r[j]>pivot) //��������ʼ��һ�� С�ڵ��� pivot����ֵ
		{
			j--;
		}
		if (i < j)
		{
			swap(r[i++], r[j]);  //r[i]��r[j]������ i �����ƶ�һλ
		}
		while (i < j && r[i] <= pivot) //�������ҿ�ʼ��һ�� ���� pivot����ֵ
		{
			i++;
		}
		if (i < j)
		{
			swap(r[i], r[j--]);  //r[i]��r[j]������ i �����ƶ�һλ
		}
	}
	return i;  //�������ջ�����ɺ��׼Ԫ�����ڵ�λ��
}
void Quicksort(int* r, int low, int hight)
{
	int mid;
	if (low < hight)
	{
		mid = part(r, low, hight);  // ���ػ�׼Ԫ��λ��
		Quicksort(r, low, mid - 1); // ������ݹ��������
		Quicksort(r, mid+1, hight); // ������ݹ��������
	}
}
int main()
{
	int a[10001];
	int  N;
	cout << "������Ҫ��������ݵĸ����� " << endl;
	cin >> N;
	cout << "������Ҫ��������ݣ� " << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	Quicksort(a, 0, N - 1);
	cout << "����������Ϊ�� " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
} 
 
//�鲢����
/* Merge sort in C++ */
#include <cstdio>
#include <iostream>
 
using namespace std;
 
// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
 
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;
 
	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}
 
// Recursive function to sort an array of integers.
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing.
 
	mid = n/2;  // find the mid index.
 
	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = new int[mid];
	R = new int [n - mid];
 
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
 
	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
	// the delete operations is very important
	delete [] R;
	delete [] L;
}
 
int main() {
	/* Code to test the MergeSort function. */
 
	int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.
	int i,numberOfElements;
 
	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes.
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g
	numberOfElements = sizeof(A)/sizeof(A[0]);
 
	// Calling merge sort to sort the array.
	MergeSort(A,numberOfElements);
 
	//printing all elements in the array once its sorted.
	for(i = 0;i < numberOfElements;i++)
	   cout << " " << A[i];
	return 0;
}

 

int main()
{
	return 0;
}
