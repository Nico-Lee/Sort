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
//****************************************************
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
