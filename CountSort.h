void CountSort(int* arry, int size)
{
	//找出最大和最小的值，max-min作为开辟空间的大小
	int min = arry[0], max = arry[0];
	for (int i = 0; i < size; ++i)
	{
		if (arry[i] < min)
			min = arry[i];
		if (arry[i] > max)
			max = arry[i];
	}
	int* count = new int[max - min + 1];
	memset(count, 0, (max - min + 1)*sizeof(int));
	//统计数组中出现数字的次数
	for (int i = 0; i < size; ++i)
	{
		++count[arry[i] - min];
	}
	int index = 0;
	//遍历计数数组，只要值不为一，就将数组的下标+min拷贝进原始数组，原始数组已经没用了
	for (int i = 0; i < max - min + 1; ++i)
	{
		while (count[i]--)
		{
			arry[index++] = min + i;
		}
	}
}
