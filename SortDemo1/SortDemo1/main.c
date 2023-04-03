
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
int getdataNumber(int*judge);
int* createArray(int dataNumber);
void readFile(int dataNumber, int dataArray[]);
int FindMax(int* a, int size);
void menu();

void insertSort(int* a, int n);
void MergeArray(int* a, int* temp, int begin, int mid, int end);
void MergeSort(int* a, int* temp, int begin, int end);
void mergeSort(int* a, int size);
void QuickSort_Recursion(int* a, int begin, int end);
void CountSort(int* a, int size, int max);
void RadixCountSort(int* a, int size);

void main(void)
{
	menu();
	return;
}

void menu()
{
	int flag = 0;
	int b = 0;
	int* judge = &b;
	while (1)
	{
		while (1)
		{
			flag = 0;
			printf("Please choose the number:\n");
			printf("1.insertSort\n");
			printf("2.MergeSort\n");
			printf("3.QuickSort_Recursion\n");
			printf("4.CountSort\n");
			printf("5.RadixCountSort\n");
			scanf_s("%d", &flag);
			while (getchar() != '\n');
			if (flag < 1 || flag>5)
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
		int get = getdataNumber(judge);
		if (*judge == 1)
		{
			int* a = (int*)malloc(sizeof(int) * get);
			a = createArray(get);
		
			if (flag == 1)
			{
				insertSort(a, get);
				for (int i = 0; i < get; i++)
				{
					printf("%d\t", a[i]);
				}
				printf("\n");
			}
			else if (flag == 2)
			{
				mergeSort(a, get);
				for (int i = 0; i < get; i++)
				{
					printf("%d\t", a[i]);
				}
				printf("\n");
			}
			else if (flag == 3)
			{
				clock_t start = clock();
				QuickSort_Recursion(a, 0, get - 1);
				clock_t diff = clock() - start;
				printf("cost-time:%d ms\nshow the data for you:\n", diff);
				for (int i = 0; i < get; i++)
				{
					printf("%d\t", a[i]);
				}
				printf("\n");
				system("pause");
			}
			else if (flag == 4)
			{
				CountSort(a, get, FindMax(a, get));
				for (int i = 0; i < get; i++)
				{
					printf("%d\t", a[i]);
				}
				printf("\n");
				system("pause");
			}
			else if (flag == 5)
			{

				RadixCountSort(a, get);
				for (int i = 0; i < get; i++)
				{
					printf("%d\t", a[i]);
				}
				printf("\n");
				system("pause");
			}
		}
		else if (*judge == 2)
		{
			int* a = (int*)malloc(sizeof(int) * get);


			if (flag == 1)
			{
				for (int i = 0; i < 100000; i++)
				{
					putNumberToFile(100);
					a = createArray(get);
					insertSort(a, get);
					for (int i = 0; i < get; i++)
					{
						printf("%d\t", a[i]);
					}
					printf("\n-------------------------\n");
				}
			}
			else if (flag == 2)
			{
				for (int i = 0; i < 100000; i++)
				{
					putNumberToFile(100);
					a = createArray(get);
					mergeSort(a, get);
					for (int i = 0; i < get; i++)
					{
						printf("%d\t", a[i]);
					}
					printf("\n-------------------------\n");
				}
			}
			else if (flag == 3)
			{
				clock_t start = clock();
				for (int i = 0; i < 100000; i++)
				{
					putNumberToFile(100);
					a = createArray(get);
				QuickSort_Recursion(a, 0, get - 1);
				printf("show the data for you:\n");
				for (int i = 0; i < get; i++)
				{
					printf("%d\t", a[i]);
				}
				printf("\n-------------------------\n");
				}
				clock_t diff = clock() - start;
				printf("cost-time:%d ms\n", diff);
				
			}
			else if (flag == 4)
			{
				clock_t start = clock();
				for (int i = 0; i < 100000; i++)
				{
					putNumberToFile(100);
					a = createArray(get);
					CountSort(a, get, FindMax(a, get));
					printf("show the data for you:\n");
					for (int i = 0; i < get; i++)
					{
						printf("%d\t", a[i]);
					}
					printf("\n-------------------------\n");
				}
				clock_t diff = clock() - start;
				printf("cost-time:%d ms\n", diff);
			}
			else if (flag == 5)
			{
				clock_t start = clock();
				for (int i = 0; i < 100000; i++)
				{
					putNumberToFile(100);
					a = createArray(get);
					RadixCountSort(a, get);
					for (int i = 0; i < get; i++)
					{
						printf("%d\t", a[i]);
					}
					printf("\n-------------------------\n");
				}
				clock_t diff = clock() - start;
				printf("cost-time:%d ms\n", diff);
			}
		}
		
		
	}
	
}