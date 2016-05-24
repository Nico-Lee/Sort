//Direct insert sort
void InsertSort(int *a, size_t size)
{
	assert(a);
	for (size_t i = 1; i < size; ++i)
	{
		int tmp = a[i];
		size_t j = i;
		while (j > 0 && tmp < a[j - 1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
}


//HellSort
void HellSort(vector<int>& a, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i <size - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > a[end+gap])
			{
				a[end + gap] = a[end];
				a[end] = tmp;
				end -= gap;
			}
		}
	}
