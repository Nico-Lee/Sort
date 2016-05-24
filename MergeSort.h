//归并排序单元
void MergeCell(int* arry,int* tmp, int left1, int right1, int left2, int right2)
{
	int index = 0;
	int begin = left1;
	while (left1 <= right1&&left2 <= right2)
	{
		if (arry[left1] < arry[left2])
		{
			tmp[index++] = arry[left1++];
		}
		else
		{
			tmp[index++] = arry[left2++];
		}
	}
	while (left1 > right1&&left2 <= right2)
	{
		tmp[index++] = arry[left2++];
	}
	while (left2 > right2&&left1 <= right1)
	{
		tmp[index++] = arry[left1++];
	}
	for (int i = 0; i < index; ++i)
	{
		arry[begin++] = tmp[i];
	}
}
//归并排序区间
void Merge_(int* arry, int* tmp, int left, int right)
{
	if (left < right)
	{
		int mid = left - (left - right) / 2;
		Merge_(arry, tmp, left, mid);
		Merge_(arry, tmp, mid+1, right);
		MergeCell(arry, tmp, left, mid, mid + 1, right);
	}

}

void MergeSort(int *arry, int size)
{
	int left = 0;
	int right = size - 1;
	int* tmp = new int[size];
	Merge_(arry, tmp, left, right);
	for (int i = 0; i < size; ++i)
	{
		cout << arry[i] << " ";
	}
}
