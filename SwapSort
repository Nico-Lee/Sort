
void BubbleSort(int* arry, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arry[j] > arry[j + 1])
			{
				swap(arry[j], arry[j + 1]);
			}
		}
	}
}

//冒泡排序第一次优化（设置一个标志）
void BubbleSort(int* arry, int size)
{
	bool swaped = false;
	for (int i = 0; i < size; i++)
	{
		swaped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arry[j] > arry[j + 1])
			{
				swap(arry[j], arry[j + 1]);
				swaped = true;
			}
		}
		if (!swaped)
		{
			break;
		}
	}
}


//冒泡排序第二次优化（去除已经有序的区间）
void BubbleSort(int* arry, int size)
{
	int lastswappos = size-1;
	int lastswappos_temp = size-1;
	for (int i = 0; i < size; i++)
	{
		lastswappos = lastswappos_temp;
		for (int j = 0; j < lastswappos; j++)//每次冒泡到最后一次交换的位置
		{
			if (arry[j] > arry[j + 1])
			{
				swap(arry[j], arry[j + 1]);
				lastswappos_temp = j;
			}
		}
		if (lastswappos==lastswappos_temp)
		{
			break;
		}
	}
}



//快速排序[left,right]
void QuickSort(vector<int> &arry, int left, int right)
{
	if (left >= right)
		return;
	////当待排序区间长度小于13时，插入排序会比快排要快
	//if (right - left < 13)
	//{
	//InsertSort(arry[left], arry[right]);
	//}
	int lflag = left;
	int rflag = right;
	int tmp = arry[left];
	while (lflag < rflag)
	{
		while ((lflag < rflag) && arry[rflag] >= tmp)
		{
			rflag--;
		}
		arry[lflag] = arry[rflag];
		while ((lflag < rflag) && arry[lflag] <= tmp)
		{
			lflag++;
		}
		arry[rflag] = arry[lflag];
	}
	swap(arry[lflag], tmp);
	QuickSort(arry, left, rflag - 1);
	QuickSort(arry, rflag + 1, right);
}


//*********************************************************
//快速排序（挖坑法）[left,right]
void QuickSort(vector<int> &arry, int left, int right)
{
	if (left >= right)
		return;
	////当待排序区间长度小于13时，插入排序会比快排要快
	//if (right - left < 13)
	//{
	//	InsertSort(arry[left], arry[right]);
	//}
	//基数
	int key = arry[right];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && arry[i] < key)
		{
			i++;
		}
		if (i < j)
		{
			arry[j] = arry[i];
			j--;
		}
		while (i<j && arry[j]>key)
		{
			j--;
		}
		if (i < j)
		{
			arry[i] = arry[j];
			i++;
		}
	}
	//除了循环i=j,将key值填入arry[i]或arry[j]。
	arry[i] = key;
	QuickSort(arry, left, i - 1);
	QuickSort(arry, i + 1, right);
}



********************************************
void QuickSort(vector<int> &arry, int left, int right)
{
	递归结束条件
	if (left >= right)
		return;
	int cur = left;
	int prev = cur - 1;
	int key = arry[right];
	while (cur != right)
	{
		if (arry[cur] < key && cur != (++prev))
		{
			swap(arry[cur], arry[prev]);
		}
		cur++;
	}
	swap(arry[++prev],arry[right]);
	QuickSort(arry, left, prev - 1);
	QuickSort(arry, prev + 1, right);
}

//******************************************
//三数取中法（选取left，right，mid中不大不小的那个值作为key，和arry[right]交换）
int FindMidValue(vector<int> &arry, int left, int right)//[p,q]
 {
     int mid= left-( left - right ) / 2;
	 if (arry[left] > arry[mid])
	 {
		 if (arry[mid] > arry[right])
		 {
			 swap(arry[right], arry[mid]);
		 }
		 else if (arry[right] > arry[left])
		 {
			 swap(arry[right], arry[left]);
		 }
	 }
	 else if (arry[left] > arry[right])
	 {
		 swap(arry[right], arry[left]);
	 }
     return arry[right];
 }
void QuickSort(vector<int> &arry, int left, int right)
{
	if (left >= right)
		return;
	int lflag = left;
	int rflag = right;
	int key = FindMidValue(arry, lflag, rflag);
	while (lflag < rflag)
	{
		while (lflag < rflag && arry[lflag] <= key)
		{
			lflag++;
		}
		if (lflag < rflag)
		{
			arry[rflag] = arry[lflag];
			rflag--;
		}
		while (lflag < rflag && arry[rflag] >= key)
		{
			rflag--;
		}
		if (lflag < rflag)
		{
			arry[lflag] = arry[rflag];
			lflag++;
		}
	}
	arry[lflag] = key;
	QuickSort(arry, left, lflag - 1);
	QuickSort(arry, lflag + 1, right);
}
