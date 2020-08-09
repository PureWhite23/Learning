#include <iostream>
using namespace std;

void bubble(int *a,int length);
void printArray(int *a, int length);

int main() 
{
	int arr[] = {1, 5, 4, 3, 9, 7, 2, 6, 81, 22};
	int length = sizeof(arr) / sizeof(arr[0]);

	bubble(arr,length);
	printArray(arr,length);

	system("pause");
	return 0;
}

void bubble(int *a,int length)
{
	int tmp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void printArray(int *a,int length)
{
	for (int k = 0; k < length; k++)
	{
		cout << a[k] << " ";
	}
}