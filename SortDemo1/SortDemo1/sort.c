#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

void putNumberToFile(int num);
void delate();
int JudgeInt(char string[]);
int TranslateInt(char string[]);
int getdataNumber(int *judge);
int* createArray(int dataNumber);
void readFile(int dataNumber, int dataArray[]);
int FindMax(int* a, int size);

void insertSort(int* a, int n);
void MergeArray(int* a, int* temp, int begin, int mid, int end);
void MergeSort(int* a, int* temp, int begin, int end);
void mergeSort(int* a, int size);
void QuickSort_Recursion(int* a, int begin, int end);
void CountSort(int* a, int size, int max);
void RadixCountSort(int* a, int size);


//判断用户输入的是否是整数
int JudgeInt(char string[])
{

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] < '0' || (string[i] > '9'))
		{
			return 0;
		}
	}
	return 1;
}
//将字符串内容转化为整型
int TranslateInt(char string[])
{
	int arr[100] = { 0 };
	int ret = 0;
	int i = 0;
	int j;
	for (i = 0, j = strlen(string); i < strlen(string); i++, j--)
	{
		arr[j - 1] = string[i] - 48;
	}
	int x = 1;//控制个十百千位数
	for (int o = 0; o < i; o++)
	{
		ret += arr[o] * x;
		x *= 10;
	}

	return ret;
}
//获得需要排列的数组的函数
void putNumberToFile(int num)
{
	FILE* fp;
	delate();//每次先清空文件内的数据再生成新的
	if ((fp = fopen("data.txt", "a+")) == NULL)
	{
		printf("cannot open this file");
		exit(0);
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d\n", rand());
	}

	printf("Finish creating\n");
	fclose(fp);
}
//清空文件内数据
void delate()
{
	FILE* fp;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("cannot open this file");
		exit(0);
	}
	fclose(fp);
}
//将数据从文件中读出
void readFile(int dataNumber, int dataArray[])
{
	FILE* fp;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("cannot open this file");
		exit(0);
	}
	for (int i = 0; i < dataNumber; i++)
	{
		fscanf(fp, "%d", &dataArray[i]);

	}
	fclose(fp);

}

//在文件中获取数字
int getdataNumber(int*judge)
{
	char option[100];
	int dataNumber = 0;
	*judge = 0;
	while (1)
	{
		printf("Please choose how many numbers do you want to create：\n");
		printf("1.10000\n");
		printf("2.50000\n");
		printf("3.200000\n");
		printf("4.100个数据x100k次\n");
		gets_s(option, 100);
		if (JudgeInt(option))
		{
			int choice = TranslateInt(option);
			switch (choice)
			{
			case 1:
				dataNumber = 10000;
				putNumberToFile(dataNumber);
				*judge = 1;
				break;
			case 2:
				dataNumber = 50000;
				putNumberToFile(dataNumber);
				*judge = 1;
				break;
			case 3:
				dataNumber = 200000;
				putNumberToFile(dataNumber);
				*judge = 1;
				break;
			case 4:
				dataNumber = 100;
				*judge = 2;
				break;
			default:
				printf("Please give me the right number.");
				break;
			}
		}
		else
		{
			printf("Please give me the right number.");
		}
		//当数据生成完成后，跳出菜单
		if (*judge == 1||*judge==2)
		{
			break;
		}
	}
	return dataNumber;
}
//创建数组
//int* createArray(int dataNumber)
//{
//	if (dataNumber == 10000)
//	{
//		int dataArray[10000] = { 0 };
//		readFile(dataNumber,dataArray);
//		return dataArray;
//	}
//	if (dataNumber == 50000)
//	{
//		int dataArray[50000] = { 0 }; 
//		readFile(dataNumber, dataArray); 
//		return dataArray;
//	}
//	if (dataNumber == 200000)
//	{
//		int dataArray[200000] = { 0 };
//		readFile(dataNumber, dataArray);
//		return dataArray;
//	}
//	
//}
int* createArray(int dataNumber)
{
	if (dataNumber == 10000)
	{
		int* dataArray = (int*)malloc(sizeof(int) * dataNumber);
		for (int i = 0; i < dataNumber; i++)
		{
			dataArray[i] = 0;
		}
		
		readFile(dataNumber, dataArray);
		return dataArray;
	}
	if (dataNumber == 50000)
	{
		int* dataArray = (int*)malloc(sizeof(int) * dataNumber);
		for (int i = 0; i < dataNumber; i++)
		{
			dataArray[i] = 0;
		}
		
		readFile(dataNumber, dataArray);
		return dataArray;
	}
	if (dataNumber == 200000)
	{
		int* dataArray = (int*)malloc(sizeof(int) * dataNumber);
		for (int i = 0; i < dataNumber; i++)
		{
			dataArray[i] = 0;
		}
		
		readFile(dataNumber, dataArray);
		return dataArray;
	}
	if (dataNumber == 100)
	{
		int* dataArray = (int*)malloc(sizeof(int) * dataNumber);
		for (int i = 0; i < dataNumber; i++)
		{
			dataArray[i] = 0;
		}

		readFile(dataNumber, dataArray);
		return dataArray;
	}

}



/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n)
{
	clock_t start = clock();
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > key)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	clock_t diff = clock() - start;
	printf("cost-time:%d ms\nshow the data for you:\n", diff);
	/*system("pause");*/
};


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int* temp ,int begin, int mid, int end)
{
	
	int i = begin, j = mid + 1, k = begin;
	//比较排序并将值赋给中间变量temp
	while (i <= mid && j <= end)
		temp[k++] = a[i] < a[j] ? a[i++] : a[j++];
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	//将中间变量数组中存储的值赋给原始数组
	for (i = begin; i <= end; i++)
		a[i] = temp[i];

};


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a,int *temp,int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;//注意越界
	MergeSort(a, temp, begin, mid);
	MergeSort(a, temp, mid + 1, end);
	MergeArray(a, temp, begin, mid, end);

};
//可调用的归并排序
void mergeSort(int* a, int size)
{
	
	int* temp = (int*)malloc(sizeof(int) * size);
	assert(temp);
	clock_t start = clock();
	MergeSort(a, temp, 0, size - 1);
	clock_t diff = clock() - start;
	printf("cost-time:%d ms\nshow the data for you:\n", diff);
	/*system("pause");*/
	free(temp);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	

	if (begin >= end)
		return;
	int i = begin, j = end;
	int pivot = a[i];
	while (i < j)
	{
		while (i < j && a[j] >= pivot)
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= pivot)
			i++;
		a[j] = a[i];
	}
	a[i] = pivot;
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);

	
};

//
///**
// *  @name        : void QuickSort(int *a,int size)
// *  @description : 快速排序（非递归版）
// *  @param       : 数组指针a，数组长度size
// */
//void QuickSort(int* a, int size);
//
//
///**
// *  @name        : void QuickSort(int *a, int begin, int end)
// *  @description : 快速排序（枢轴存放）
// *  @param       : 数组指针a，数组起点begin，数组终点end
// */
//int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max)
{
	//创建计数数组
	int* count = (int*)malloc(sizeof(int) * (max+1));
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		count[a[i]]++;
	}
	for (int i = 0,j=0; i <= max; i++)
	{
		while (count[i]--)
			a[j++] = i;
	}
	
};
//找到数组中的最大值
int FindMax(int* a,int size)
{
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	
	int base = 1;
	int max = FindMax(a, size);
	int i;
	int* t = (int*)malloc(sizeof(int) * size);
	while (max / base >0)
	{
		int bucket[10] = { 0 };
		//计数桶
		for (i = 0; i < size; i++)
		{
			bucket[a[i] / base % 10]++;
		}
		//累计，用于确定数据存放的index
		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];

		}
		//临时存放在t
		for (i = size-1; i >= 0; i--)
		{
			t[bucket[a[i] / base % 10]-1] = a[i];
			bucket[a[i] / base % 10]--;
		}	
		//将t数组赋值到a数组
		for (i = 0; i < size; i++)
		{
			a[i] = t[i];
		}		
		base = base * 10;

		
	}

};


///**
// *  @name        : void ColorSort(int *a,int size)
// *  @description : 颜色排序
// *  @param       : 数组指针a（只含0，1，2元素），数组长度size
// */
//void ColorSort(int* a, int size);
//
//
///**
// *  @name        : 自拟
// *  @description : 在一个无序序列中找到第K大/小的数
// *  @param       : 数组指针a，数组长度size
// */

	
		

