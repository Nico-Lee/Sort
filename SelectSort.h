#pragma once
#include<iostream>
#include<assert.h>
#include"windows.h"
#include"time.h"
using namespace std;
//选择排序和堆排序都属于选择排序


//选择排序
void SelectSort(int* arry, int size)
{
	assert(arry);
	int flag = 0;
	while (flag != size - 1)
	{
		int min = flag;
		for (int i = flag + 1; i < size; i++)
		{
			if (arry[i] < arry[min])
			{
				min = i;
			}
		}
		swap(arry[min], arry[flag]);
		flag++;
	}
}


void testSelectSort()
{
	int arry[] = { 1, 9, 2, 3, 8, 5, 6, 15, 6, 7 };
	int size = sizeof(arry) / sizeof(int);
	cout << size << endl;
	SelectSort(arry, size);
	for (int i = 0; i < size; i++)
	{
		cout << arry[i] << "  ";
	}
}


//堆排序
void AdjustDown(int* a, size_t size, size_t parent)//下调函数
{
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&a[child] < a[child + 1])
			++child;
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, size_t size)
{
	//建堆
	for (int i = (size - 2) / 2; i >= 0; --i)
		//i不能定义为size_t除法会溢出，翻转成一个很大的数
	{
		//从第一个非叶子结点（最后一个叶子结点的父亲）开始下调
		AdjustDown(a, size, i);
	}
	for (size_t i = 0; i < size; ++i)
	{
		swap(a[0], a[size - 1 - i]);
		AdjustDown(a, size - i - 1, 0);
	}
}


void FindMaxK(int N, int K)//找出N个数据中最大的K个数据
{
	int* arryN = new int[N];
	int* maxK = new int[K];
	for (int i = 0; i < N; ++i)
	{
		arryN[i] = (rand() % 100);
	}
	for (int i = 0; i < N; ++i)
	{
		cout << arryN[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < K; i++)
	{
		maxK[i] = arryN[i];
	}
	for (int i = K; i < N; ++i)
	{
		HeapSort(maxK, K);
		maxK[0] = arryN[i];
	}
	for (int i = 0; i < K; ++i)
	{
		cout << maxK[i] << " ";
	}
}
void testHeapSort()
{
	//int arry[] = { 1, 9, 2, 3, 8, 5, 6, 15, 6, 7, 0, -1000 };
	//int size = sizeof(arry) / sizeof(int);
	//HeapSort(arry, size);
	//for (int i = 0; i < size; i++)
	//{
	//	cout << arry[i] << "  ";
	//}
	int N = 10;
	int K = 5;
	FindMaxK(N, K);
}


int main()
{
	testSelectSort();
	return 0;
}
