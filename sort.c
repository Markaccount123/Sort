#include "Sort.h"
//�ڲ������ܵ�ʱ���ӡ�Ǻ����ĵģ���������ȡ����
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int* a, int n)
{
	assert(a);
	//�ѵ�һ������������ģ�Ȼ���ú�������ݺ͵�һ�����ݱȽϲ���
	for (int i = 0; i < n - 1; ++i)
	{
		//���԰��κ�һ�����򶼷ֽ⿪��Ϊ������������������Ĺ�����˼������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) //�����tmp�͵�һ��ֵ��Ƚϻ���С�Ļ����ٴ��ƶ�end�ͻᷢ�����Ѿ���-1��λ���ˣ�˵�������ɺ����е�Ԫ�ض��ȽϹ���
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
		//�����������������ֿ��ܣ���һ������tmp��ʱ����end�½Ǳ����ڵ�Ԫ�أ�break����
		//�ڶ��־���whileѭ������end�Ѿ�����-1��λ�ã���Ҳ���Ǳȵ�һ��ֵ��ҪС��
		a[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int* a, int n)
{
	//gapԽ�������Ŀ죬���Ǿͱ�ĺܲ�������
	int gap = n;
	//���������ɼ��Ϊgap�������������δ���ǳ����ɣ��ǳ���NB
	//��������ǵ�˼��������Ϊ��ȥ�ź�ɫ��������ɫ�������ɫ�Ĺ��̣�Ҳ����д����forѭ��ȥ����ÿһ����ɫ��һ��
	//���ǹ��̲�����������
	//���Ѷ���ͬʱ����һ������������ˣ�Ҳ��������û��һ������ȥ�ź�ɫ���ڵ���������ɫ�����������ɫ��һ��ֱ������ɫ��ĵ�һ��
	//�����n-gap�������Ϊ�����gap�����һ���У����һ��ֵ��ǰһ��ֵ����ͽ�����

	//gap >1 ����Ԥ����
	while (gap > 1)
	{
		//���������ѡ���gapֵ�أ�
		gap = gap / 3 + 1; //��֤�����һ��һ��ʱ1,��3Ϊ��ѵ�һ��ѡ��ۺ���������3Ϊgap��Ϊ���������������ŵ�
		//�����һ��gap==1��ʱ�����ֱ�Ӳ�������
		//����Ϊ3����
		for (int i = 0; i < n - gap; ++i)
		{
			//�μ�����д���Ǽ��Ϊgap��һ����
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
			//�������Ǳ�����������Ҿͷ�����end�ĺ���
			//���Ƿ�����ĵ�һ��λ�ô�
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
//ֱ��ѡ������
//����һ��ͬʱѡ����С��������������Ȼ�����С������������ĵ�һ��λ�ã��ٰ�������������������һ��λ��
//��������ͬʱ������������ĳ��ȣ������ͻ��ֱ��ѡ��������ٶȿ�һ��
void SelectSort(int* a, int n)
{
	assert(a);
	//����һ�����ҵ��Ǹ���С�����±�Ȼ������һ��λ�õ�Ԫ�ػ���λ�ã�Ȼ�������ҵ��������±�������һ��λ�õ�������
	//���˵���ҵ���С����ֱ�ӷ����˵�һ��λ�ã���ô���һ��λ��ԭ����Ԫ�ؾͱ���ѡ�������С���������ˣ�
	//������ԭ������С���ĵط�������С�����Ǹ�ֵ
	int begin = 0, end = n - 1;
	while (begin < end) 
	{
		//��[begin,end]֮���ҳ���С������������±�
		int mini, maxi;
		mini = maxi = begin;
		//��һ���������֮��Ϳ����ҳ�����һ���������Ǹ������±����С���Ǹ�����С��
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
		//�������ﻹ��һ�����������ĵ�һ��λ�÷ŵľ��������������ֵ����������һ��λ�÷ŵľ������������Сֵ��ʱ��
		//��һ��λ�õ��±�Ϊmaxi,�������һ��λ�õ��±�Ϊmini,Ȼ�󽻻��������һ����һ�ν������ֻ����ˣ��൱��û�н���
		//begin��maxi��λ���غ���,�������һ�ν���������ֵҲ����������
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


//���������������Ҫ����ʲô�ѣ���������Ҫ�������
// ������ 
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//������Ӧ���ҵ����������нϴ����һ��
		if (child+1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		//Ȼ��͸��ױȽϣ�������Ӵ󣬾�Ҫ�͸��׽��н���
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		//��Ҫ������̵�����ȥ
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* a, int n)
{
	//���ڶ�������˵�����ȸ�������飬����Ҫ�ȱ�֤��������������������ѵ��ص�ģ���ѵĻ������������������ѵ��ص�
	//��Ҫ�ӵ�����һ����ΪҶ�ӽ�㴦��ʼ���е�����һֱ��������,����ͱ�֤�������������Ǵ�ѵ��ص�
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

//ð������
//��һ�ֽ����������ǰһ�����ڵڶ�����������ֱ�����������������һ��λ��ֹͣ
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0) //��������黹ʣ��һ����ʱ��Ͳ���Ҫ�ټ���ð����
	{
		int exchange = 0; //��������exchange��������ǳ������������������鱾����������ģ���ʱ���ڶ�������鲻�ϵĽ���ð�ݵĹ��̾ͻ��˷�
		//������ʱ�䣬����һ���������������������鷢��ð�ݾ͸�������Ϊ1��Ϊ0��ʱ��˵��û�з���ð�ݵĹ��̣�Ҳ���Ǳ������������
		//�����һ��ð�ݵĴ���
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
			//Ҫ����������ǴӺ�������ǰ�����̣�һ������break˵����һ�������ˣ�Ҳ������ð�ݽ�����
			//˵��û�з���������Ҳ������һ���Ѿ��������ˣ�����Ҫ��ð����
			break;
		}
		end--;
	}
}

//ѡ ����� �м�� ���ұߵ��������Ƚϣ�ѡ�����������λ��
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

//����д��ֻ����ѡ��һ��K����������������Ľ��
//hoare����  Ҳ������ָ�뷨
int PartSort1(int* a, int begin, int end)
{
	//ѡ�����ʵ���λ��
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	int keyIndex = end;
	while (begin < end)
	{
		//����beginȥ�Ҵ���K��ֵ
		while (begin<end && a[begin] <= a[keyIndex])
		{
			++begin;
		}

		//����endȥ�ұ�KС��ֵ����ʱ�����ﻹҪ��end��������������Ȼbegin��end���ڲ�ѭ����ʱ��ʹ���ˣ�����������ֹͣ
		while (begin<end && a[end] >= a[keyIndex])
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	//��ʱ���begin��end��ͬһ��λ����(ѡbegin���Ǻ�end����һ����)���ڽ���
	Swap(&a[begin], &a[keyIndex]);

	//��ʱ���begin��end��ͣ����λ�þ���K����ȷλ��
	return begin;
}


//�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	//ѡ�����ʵ���λ��
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	//�ʼ�Ŀ�
	int key = a[end];
	while (begin < end)
	{
		//��beginȥ�Ҵ���K��ֵ ,  
		//����ֵ��ע��ľ���һ��Ҫ��=����Ϊ��begin���ߵ����Ǹ��������ʱ�����keyֵ��ȣ�Ҫô������ߣ�Ҫô�����ұ߶�����
		//�����㲻�ӣ��ͻ������ѭ��
		while(begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[end] = a[begin];

		//��endȥ�ұ�KС��ֵ
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
	}
	//�ߵ�����˵��begin��end �����ˣ��������K��ֵ
	a[begin] = key;
	return begin;
	
}

//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	
	int prev = begin - 1;
	int cur = begin;
	int keyIndex = end;
	while (cur <= end) //�������ȡ��=����Ϊ�൱��������һ��ѭ��ֹͣ��ʱ��cur�պ���end��λ�ã�ֱ�ӽ����������Ҿ��ò�ȥ���ȽϺ����
	{
		//��curȥ��С��K��ֵ ,������ᷢ���е�ʱ�����cur��prev��ͬһ��λ�ã����Կ��Բ����ǽ���
		if (a[cur] < a[keyIndex] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		//��a[cur]��a[keyIndex]С��ʱ��ͣ��++��prev֮��curҪ��++
		//��a[cur]��a[keyIndex]���ʱ��ֱ��++cur�������ڵ���˵������Ҫ����++cur�Ĳ����ģ����Կ���ֱ�Ӻϲ�
		++cur;	
	}
	Swap(&a[++prev], &a[keyIndex]);
	return prev;
}

//����
void QuickSort(int* a, int left, int right)
{
	assert(a);
	//if (left < right) //�����ڵ�ʱ�򶼿��Բ������ˣ���Ϊ��ʱ��ʣ��һ��ֵ��
	//{
	//	int div = PartSort(a, left, right);
	//	//�ݹ���ȥ
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
		//�ݹ���ȥ
		//[left, div - 1] div [div+1,right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//����С��10������ʱ�򣬲���ʹ�õݹ飬���Ǹ���ֱ�Ӳ���ķ���
		//Ȼ����������Ҫ��������鷶Χ������������ģ������Ǵ�ʱ�ݹ鵽ĳһ�����������
		InsertSort(a + left, right - left + 1);
	}
}
//
////���ŵķǵݹ�
//void QuickSortNonR(int* a, int left, int right)
//{
//	Stack st;
//	StackInit(&st);
//
//	//������������
//	//��ô����ʱ��ͻ��ȳ����ڳ���
//	StackPush(&st, right);
//	StackPush(&st, left);
//	while (!StackEmpty(&st))
//	{
//		int begin = StackTop(&st);
//		StackPop(&st);
//		int end = StackTop(&st);
//		StackPop(&st);
//		//��ʱ�൱�������õ����������[begin,end]
//		//�Ƚ��д����䵥����
//		int div = PartSort3(a, begin, end);
//		//[begin,div-1] div [div+1,end]
//		//ԭ���Ƕ�[begin,div-1] ��[div+1,end]���еݹ�Ĳ�������������˼·���䵫������ջ��ʵ��
//		//����Ϊ�˺��������Ŷ�������ǰ�������˼�룬ѡ����������������������ջ�Ժ�Ϳ����ȶ������������в���
//		//���ұ�
//		if (div + 1 < end)//������һ������ʱ����൱�������ˣ�������ջ��
//		{
//			StackPush(&st, end);
//			StackPush(&st, div+1);
//		}
//		//�����
//		if (begin < div - 1) 
//		{
//			StackPush(&st, div-1);
//			StackPush(&st, begin);
//		}
//	}
//	StackDestory(&st);
//}


//����֮����Ҫ��tmp����Ϊ��Ҫ��֤��ÿ��
void _MergeSort(int* a,int left,int right,int* tmp)
{
	if (left >= right) //����ֳɲ��ɷָ���Ӳ��ֵ�ʱ��Ϳ����ˣ�Ҳ����ֻʣ��һ��Ԫ�أ�
		return;
	//����Ӧ�÷ֳ�����
	int mid = (left + right) / 2;
	//[left,mid] [mid+1,right] ���������ֱ�Ӻϲ�����������û������������
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1,right, tmp);

	//�鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1; //��һ����Ϊ���ܱ���һ�£��÷ŵ�tmp��������ĺ�ԭ��λ��һ��
	while (begin1 <= end1 && begin2 <= end2)// ��Ϊ�����Ǳ���������Ҫ��=
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//��ʱ˵����һ�����Ѿ�������
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2<= end2)
		tmp[index++] = a[begin2++];

	//�ѹ鲢�õ������ڿ�����ȥ
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}

}
//�鲢����
void MergeSort(int* a, int n)
{
	assert(a);
	//����鲢�Ĺ��̶��ǽ����������ٵ�һ��οռ������в�����
	int* tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a,0,n-1,tmp);
	free(tmp);
}

//�鲢�����������������
void MergeArr(int* a,int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1; 
	while (begin1 <= end1 && begin2 <= end2)// ��Ϊ�����Ǳ���������Ҫ��=
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//��ʱ˵����һ�����Ѿ�������
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	//�ѹ鲢�õ������ڿ�����ȥ
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
//��ᷢ�֣�������δ������ɿ��ܴ���Խ�������ģ���Ϊ���ÿ�������õ���������ܹ���˫�ɶԣ�����Ҳ�п�����ߵ���ȥ���ұߵ���鲢��ʱ��
//�ұߵ���Ͳ����ڣ�����˵��6������ʱ�򣬵�һ��鲢��û������ģ�����2��2���鲢��ʱ��ͻ����Խ�������
//void MergeSortNonR(int* a, int n)
//{
//	assert(a);
//
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	//����ȥ�������gap���������ǺܺõĹ鲢��
//	int gap = 1;
//	while (gap <= n/2)
//	{
//		for (int i = 0; i < n; i += 2 * gap) //��������i���ƣ������������ȥ�ϲ��������
//		{
//			//��ʱ�ȴ�һ��һ���鲢��ʼ˼��������Ϊ[i,i+gap),[i+gap,i+2*gap) ������
//			//����Ϊ�˺������˼����ʽ����һ������ʹ�ñ������һЩ[i,i+gap-1],[i+gap,i+2*gap-1]
//			MergeArr(a, i, i + gap - 1, i + gap, i + 2 * gap - 1, tmp);  //��ֻ�Ǻϲ��˵�һ���͵ڶ�����
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}

//�鲢�ķǵݹ�
void MergeSortNonR(int* a, int n)
{
	assert(a);

	int* tmp = (int*)malloc(sizeof(int) * n);
	//����ȥ�������gap���������ǺܺõĹ鲢��
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap) //��������i���ƣ������������ȥ�ϲ��������
		{
			//��ʱ�ȴ�һ��һ���鲢��ʼ˼��������Ϊ[i,i+gap),[i+gap,i+2*gap) ������
			//����Ϊ�˺������˼����ʽ����һ������ʹ�ñ������һЩ[i,i+gap-1],[i+gap,i+2*gap-1]
			int begin1 = i,end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//��Կ��ܻ�Խ��������ȥ�жϱ߽�
			//1.�ϲ�ʱֻ�е�һ��,�ǾͲ���Ҫ�ϲ���
			if (begin2 >= n)
				break;
			//2.�ϲ�ʱ�ڶ���ֻ�в������ݣ���Ҫ����end2�߽�
			if (end2 >= n)
				end2 = n - 1;
			MergeArr(a, begin1,end1,begin2,end2, tmp);  //��ֻ�Ǻϲ��˵�һ���͵ڶ�����
		}
		gap *= 2;
	}
	free(tmp);
}