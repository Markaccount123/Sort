#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
//#include"Stack.h"
//打印
void PrintArray(int* a, int n);

//直接插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

// 堆排序 
void AdjustDwon(int* a, int n, int root); 
void HeapSort(int* a, int n);

// 冒泡排序 
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a, int left, int right);

//快排的非递归
void QuickSortNonR(int* a, int left, int right);

//归并排序
void MergeSort(int* a, int n);


void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp);
//归并的非递归
void MergeSortNonR(int* a, int n)