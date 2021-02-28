#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
//#include"Stack.h"
//��ӡ
void PrintArray(int* a, int n);

//ֱ�Ӳ�������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

// ������ 
void AdjustDwon(int* a, int n, int root); 
void HeapSort(int* a, int n);

// ð������ 
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);

//���ŵķǵݹ�
void QuickSortNonR(int* a, int left, int right);

//�鲢����
void MergeSort(int* a, int n);


void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp);
//�鲢�ķǵݹ�
void MergeSortNonR(int* a, int n)