//LSD法  适合位数少的排序(此程序排不了含有负数的序列)
void RadixSort(int* arry, int size)
{
	int time = 1;
	int radix = 10;
	//统计最大的位数
	for (int i = 0; i < size; ++i)
	{
		if (arry[i] > radix)
		{
			time++;
			radix *= 10;
		}
	}
	int* count = new int[10];
	int* bucket = new int[size];
	radix = 1;
	//控制排序的次数，从低位排到高位
	for (int i = 0; i < time; ++i)
	{
		memset(count, 0, 10 * sizeof(int));
		memset(bucket, 0, size * sizeof(int));
		for (int j = 0; j < size; ++j)
		{
			//统计每个桶中有多少个数据
			++count[(arry[j]/radix) % 10];
		}
		for (int k = 1; k < 10; ++k)
		{
			count[k] = count[k] + count[k - 1];
		}
		for (int k = 0; k < size; ++k)
		{
			int index = count[(arry[k] / radix) % 10 - 1];
			while (bucket[index] != 0)
			{
				index++;
				if (index >= size)
				{
					index = 0;
				}
			}
			bucket[index] = arry[k];
		}
		for (int k = 0; k < size; ++k)
		{
			arry[k] = bucket[k];
		}
		radix *= 10;
	}
}
