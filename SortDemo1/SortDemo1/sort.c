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


//�ж��û�������Ƿ�������
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
//���ַ�������ת��Ϊ����
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
	int x = 1;//���Ƹ�ʮ��ǧλ��
	for (int o = 0; o < i; o++)
	{
		ret += arr[o] * x;
		x *= 10;
	}

	return ret;
}
//�����Ҫ���е�����ĺ���
void putNumberToFile(int num)
{
	FILE* fp;
	delate();//ÿ��������ļ��ڵ������������µ�
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
//����ļ�������
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
//�����ݴ��ļ��ж���
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

//���ļ��л�ȡ����
int getdataNumber(int*judge)
{
	char option[100];
	int dataNumber = 0;
	*judge = 0;
	while (1)
	{
		printf("Please choose how many numbers do you want to create��\n");
		printf("1.10000\n");
		printf("2.50000\n");
		printf("3.200000\n");
		printf("4.100������x100k��\n");
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
		//������������ɺ������˵�
		if (*judge == 1||*judge==2)
		{
			break;
		}
	}
	return dataNumber;
}
//��������
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
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int* temp ,int begin, int mid, int end)
{
	
	int i = begin, j = mid + 1, k = begin;
	//�Ƚ����򲢽�ֵ�����м����temp
	while (i <= mid && j <= end)
		temp[k++] = a[i] < a[j] ? a[i++] : a[j++];
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	//���м���������д洢��ֵ����ԭʼ����
	for (i = begin; i <= end; i++)
		a[i] = temp[i];

};


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a,int *temp,int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;//ע��Խ��
	MergeSort(a, temp, begin, mid);
	MergeSort(a, temp, mid + 1, end);
	MergeArray(a, temp, begin, mid, end);

};
//�ɵ��õĹ鲢����
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
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
// *  @description : �������򣨷ǵݹ�棩
// *  @param       : ����ָ��a�����鳤��size
// */
//void QuickSort(int* a, int size);
//
//
///**
// *  @name        : void QuickSort(int *a, int begin, int end)
// *  @description : �������������ţ�
// *  @param       : ����ָ��a���������begin�������յ�end
// */
//int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max)
{
	//������������
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
//�ҵ������е����ֵ
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
		//����Ͱ
		for (i = 0; i < size; i++)
		{
			bucket[a[i] / base % 10]++;
		}
		//�ۼƣ�����ȷ�����ݴ�ŵ�index
		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];

		}
		//��ʱ�����t
		for (i = size-1; i >= 0; i--)
		{
			t[bucket[a[i] / base % 10]-1] = a[i];
			bucket[a[i] / base % 10]--;
		}	
		//��t���鸳ֵ��a����
		for (i = 0; i < size; i++)
		{
			a[i] = t[i];
		}		
		base = base * 10;

		
	}

};


///**
// *  @name        : void ColorSort(int *a,int size)
// *  @description : ��ɫ����
// *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
// */
//void ColorSort(int* a, int size);
//
//
///**
// *  @name        : ����
// *  @description : ��һ�������������ҵ���K��/С����
// *  @param       : ����ָ��a�����鳤��size
// */

	
		

