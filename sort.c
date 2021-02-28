#include "Sort.h"
//在测试性能的时候打印是很消耗的，所以这里取消掉
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	//把第一个数当成有序的，然后拿后面的数据和第一个数据比较插入
	for (int i = 0; i < n - 1; ++i)
	{
		//可以把任何一种排序都分解开来为单步分析在整合整体的过程来思考问题
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) //当这个tmp和第一个值相比较还是小的话，再次移动end就会发现他已经到-1的位置了，说明他依旧和所有的元素都比较过了
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		//这里跳出来会有两种可能，第一个就是tmp此时大于end下角标所在的元素，break出来
		//第二种就是while循环结束end已经到了-1的位置，（也就是比第一个值还要小）
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	//gap越大，数跳的快，但是就变的很不有序了
	int gap = n;
	//这里就能完成间距为gap组的所有排序，这段代码非常的巧，非常的NB
	//如果是我们的思想总是认为先去排红色下来排蓝色最后排紫色的过程，也就是写三个for循环去控制每一个颜色的一组
	//但是过程并不是这样的
	//他把多组同时进行一次排序就排完了，也就是他并没有一次性先去排红色，在调回来排蓝色，而是排完红色第一个直接排蓝色组的第一个
	//这里的n-gap可以理解为当你的gap分组第一组中，最后一个值往前一个值插入就结束了

	//gap >1 就是预排序
	while (gap > 1)
	{
		//这里如何来选这个gap值呢？
		gap = gap / 3 + 1; //保证了最后一次一定时1,且3为最佳的一个选项，综合下来当以3为gap作为间距来算是最好最优的
		//当最后一次gap==1的时候就是直接插入排序
		//这里为3组排
		for (int i = 0; i < n - gap; ++i)
		{
			//牢记这里写的是间距为gap的一组排
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//不管我是比你大或者相等我就放在你end的后面
			//还是放在你的第一个位置处
			a[end + gap] = tmp;
		}
		// PrintArray(a, n);
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//直接选择排序
//遍历一遍同时选出最小的数和最大的数，然后把最小的数放在数组的第一个位置，再把最大的数放在数组的最后一个位置
//数组两边同时减减缩短数组的长度，这样就会比直接选择排序的速度快一半
void SelectSort(int* a, int n)
{
	assert(a);
	//这里一定是找到那个最小数的下标然后和你第一个位置的元素互换位置，然后我再找到最大的数下标和你最后一个位置的数互换
	//如果说你找到最小的数直接放在了第一个位置，那么你第一个位置原来的元素就被你选的这个最小的数覆盖了，
	//但是你原来放最小数的地方还是最小数的那个值
	int begin = 0, end = n - 1;
	while (begin < end) 
	{
		//在[begin,end]之间找出最小数和最大数的下标
		int mini, maxi;
		mini = maxi = begin;
		//这一组遍历下来之后就可以找出来这一组中最大的那个数的下标和最小的那个数的小标
		for (int i = begin +1 ; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		//但是这里还有一种情况，当你的第一个位置放的就是这个数组的最大值，当你的最后一个位置放的就是你数组的最小值的时候
		//第一个位置的下标为maxi,而你最后一个位置的下标为mini,然后交换，你的下一步再一次交换，又回来了，相当于没有交换
		//begin和maxi的位置重合了,这里进行一次交换你的最大值也给交换走了
		Swap(&a[begin], a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], a[maxi]);
		begin++;
		end--;
	}
}


//考虑清楚你这里需要构建什么堆？升序你需要构建大堆
// 堆排序 
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//首先你应该找到两个孩子中较大的哪一个
		if (child+1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		//然后和父亲比较，如果孩子大，就要和父亲进行交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		//需要这个过程迭代下去
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* a, int n)
{
	//对于堆排序来说，首先给你的数组，你需要先保证他的左右子树都是满足堆的特点的，大堆的话左右子树都得满足大堆的特点
	//需要从倒数第一个不为叶子结点处开始进行调整，一直调整上来,这里就保证了左右子树都是大堆的特点
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}

}

//冒泡排序
//是一种交换排序，如果前一个大于第二个数交换，直到把最大的数换到最后一个位置停止
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0) //当你的数组还剩下一个的时候就不需要再继续冒泡了
	{
		int exchange = 0; //这里引入exchange这个变量非常的厉害，如果你的数组本来就是有序的，此时你在对这个数组不断的进行冒泡的过程就会浪费
		//大量的时间，但是一旦你设置这个，当你的数组发生冒泡就给他设置为1，为0的时候说明没有发生冒泡的过程，也就是本来就是有序的
		//这个是一组冒泡的代码
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] < a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			//要想清楚数组是从后面再往前面缩短，一旦这里break说明这一段有序了，也就整体冒泡结束了
			//说明没有发生交换，也就是这一段已经是有序了，不需要在冒泡了
			break;
		}
		end--;
	}
}

//选 最左边 中间和 最右边的三个数比较，选出这里面的中位数
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else //a[begin] >a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

//这里写的只是你选择一次K遍历整个数组出来的结果
//hoare方法  也叫左右指针法
int PartSort1(int* a, int begin, int end)
{
	//选出合适的中位数
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	int keyIndex = end;
	while (begin < end)
	{
		//先让begin去找大于K的值
		while (begin<end && a[begin] <= a[keyIndex])
		{
			++begin;
		}

		//再让end去找比K小的值，此时在这里还要对end有限制条件，不然begin和end在内部循环的时候就错过了，而不是相遇停止
		while (begin<end && a[end] >= a[keyIndex])
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	//此时你的begin和end在同一个位置了(选begin还是和end都是一样的)，在交换
	Swap(&a[begin], &a[keyIndex]);

	//此时你的begin和end所停留的位置就是K的正确位置
	return begin;
}


//挖坑法
int PartSort2(int* a, int begin, int end)
{
	//选出合适的中位数
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	//最开始的坑
	int key = a[end];
	while (begin < end)
	{
		//让begin去找大于K的值 ,  
		//这里值得注意的就是一定要加=，因为当begin所走到的那个数如果此时和你的key值相等，要么留在左边，要么留在右边都可以
		//但是你不加，就会造成死循环
		while(begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[end] = a[begin];

		//让end去找比K小的值
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
	}
	//走到这里说明begin和end 相遇了，这里放上K的值
	a[begin] = key;
	return begin;
	
}

//前后指针法
int PartSort3(int* a, int begin, int end)
{
	
	int prev = begin - 1;
	int cur = begin;
	int keyIndex = end;
	while (cur <= end) //这里可以取消=，因为相当于你的最后一步循环停止的时候cur刚好在end的位置，直接交换，但是我觉得不去掉比较好理解
	{
		//让cur去找小于K的值 ,但是你会发现有的时候你的cur和prev在同一个位置，所以可以不考虑交换
		if (a[cur] < a[keyIndex] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		//当a[cur]比a[keyIndex]小的时候，停下++完prev之后，cur要在++
		//当a[cur]比a[keyIndex]大的时候，直接++cur，所以宗的来说，都是要进行++cur的操作的，所以可以直接合并
		++cur;	
	}
	Swap(&a[++prev], &a[keyIndex]);
	return prev;
}

//快排
void QuickSort(int* a, int left, int right)
{
	assert(a);
	//if (left < right) //连等于的时候都可以不用排了，因为此时就剩下一个值了
	//{
	//	int div = PartSort(a, left, right);
	//	//递归下去
	//	//[left, div - 1] div [div+1,right]
	//	QuickSort(a, left, div - 1);
	//	QuickSort(a, div + 1, right);
	//}

	if (left >= right)
		return;

	if ((right - left + 1) > 10)
	{
		//int div = PartSort1(a, left, right);
		//int div = PartSort2(a, left, right);
		int div = PartSort3(a, left, right);
		//递归下去
		//[left, div - 1] div [div+1,right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//区间小于10个数的时候，不再使用递归，而是改用直接插入的方法
		//然而你这里需要排序的数组范围，不再是最初的，可能是此时递归到某一层的左右子树
		InsertSort(a + left, right - left + 1);
	}
}
//
////快排的非递归
//void QuickSortNonR(int* a, int left, int right)
//{
//	Stack st;
//	StackInit(&st);
//
//	//先入右在入左
//	//那么出的时候就会先出左在出右
//	StackPush(&st, right);
//	StackPush(&st, left);
//	while (!StackEmpty(&st))
//	{
//		int begin = StackTop(&st);
//		StackPop(&st);
//		int end = StackTop(&st);
//		StackPop(&st);
//		//此时相当于我们拿到这这段区间[begin,end]
//		//先进行大区间单趟排
//		int div = PartSort3(a, begin, end);
//		//[begin,div-1] div [div+1,end]
//		//原来是对[begin,div-1] 和[div+1,end]进行递归的操作，但是现在思路不变但换成用栈来实现
//		//这里为了好理解对照着二叉树的前序遍历的思想，选择了先入右在入左，这样出栈以后就可以先堆最左边区间进行操作
//		//入右边
//		if (div + 1 < end)//当你是一个数的时候就相当于有序了，不再入栈了
//		{
//			StackPush(&st, end);
//			StackPush(&st, div+1);
//		}
//		//入左边
//		if (begin < div - 1) 
//		{
//			StackPush(&st, div-1);
//			StackPush(&st, begin);
//		}
//	}
//	StackDestory(&st);
//}


//这里之所以要给tmp是因为你要保证你每次
void _MergeSort(int* a,int left,int right,int* tmp)
{
	if (left >= right) //把其分成不可分割的子部分的时候就可以了（也就是只剩下一个元素）
		return;
	//首先应该分成两半
	int mid = (left + right) / 2;
	//[left,mid] [mid+1,right] 有序则可以直接合并，现在他们没有序，子问题解决
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1,right, tmp);

	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1; //这一步是为了能保持一致，让放到tmp数组里面的和原先位置一样
	while (begin1 <= end1 && begin2 <= end2)// 因为这里是闭区间所以要加=
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//此时说明有一个组已经走完了
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2<= end2)
		tmp[index++] = a[begin2++];

	//把归并好的数据在拷贝回去
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}

}
//归并排序
void MergeSort(int* a, int n)
{
	assert(a);
	//这里归并的过程都是借助你所开辟的一大段空间来进行操作的
	int* tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a,0,n-1,tmp);
	free(tmp);
}

//归并数组把这个单独拎出来
void MergeArr(int* a,int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1; 
	while (begin1 <= end1 && begin2 <= end2)// 因为这里是闭区间所以要加=
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//此时说明有一个组已经走完了
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	//把归并好的数据在拷贝回去
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
//你会发现，下面这段代码是由可能存在越界的情况的，因为逆置考虑了最好的情况，都能够成双成对，但是也有可有左边的组去和右边的组归并的时候
//右边的组就不存在，比如说有6个数的时候，第一遍归并是没有问题的，但是2个2个归并的时候就会出现越界的问题
//void MergeSortNonR(int* a, int n)
//{
//	assert(a);
//
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	//怎样去控制这个gap，能让他们很好的归并？
//	int gap = 1;
//	while (gap <= n/2)
//	{
//		for (int i = 0; i < n; i += 2 * gap) //这里的这个i控制，就是针对让它去合并后面的组
//		{
//			//此时先从一个一个归并开始思考，区间为[i,i+gap),[i+gap,i+2*gap) 开区间
//			//但是为了和相面的思考方式保持一致这里使用闭区间好一些[i,i+gap-1],[i+gap,i+2*gap-1]
//			MergeArr(a, i, i + gap - 1, i + gap, i + 2 * gap - 1, tmp);  //这只是合并了第一数和第二个数
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}

//归并的非递归
void MergeSortNonR(int* a, int n)
{
	assert(a);

	int* tmp = (int*)malloc(sizeof(int) * n);
	//怎样去控制这个gap，能让他们很好的归并？
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap) //这里的这个i控制，就是针对让它去合并后面的组
		{
			//此时先从一个一个归并开始思考，区间为[i,i+gap),[i+gap,i+2*gap) 开区间
			//但是为了和相面的思考方式保持一致这里使用闭区间好一些[i,i+gap-1],[i+gap,i+2*gap-1]
			int begin1 = i,end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//针对可能会越界的情况，去判断边界
			//1.合并时只有第一组,那就不需要合并了
			if (begin2 >= n)
				break;
			//2.合并时第二组只有部分数据，需要修正end2边界
			if (end2 >= n)
				end2 = n - 1;
			MergeArr(a, begin1,end1,begin2,end2, tmp);  //这只是合并了第一数和第二个数
		}
		gap *= 2;
	}
	free(tmp);
}