#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);	//ПРОТОТИП
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

//#define DEBUG_ASSERTION_FAILED_1
//#define DEBUG_ASSERTION_FAILED_2

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;	//Размер массива
#ifdef DEBUG_ASSERTION_FAILED_1
	int* pn = &n;
	delete[] pn;
#endif // DEBUG_ASSERTION_FAILED_1

	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {3, 5, 8};
	FillRand(arr, n);
	Print(arr, n);

	int value;	//Добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);	//ВЫЗОВ
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

#ifdef DEBUG_ASSERTION_FAILED_2
	delete[] buffer;
#endif // DEBUG_ASSERTION_FAILED_2

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//cout << arr[i] << "\t";
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)	//РЕАЛИЗАЦИЯ
{
	//1.создать буферный размер нужного размера(на 1 элемент больше)
	int* buffer = new int[n + 1]{};
	//2/копируем все значения в новый массив
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3 удаляем исходный массив
	delete[] arr;
	//4.подменяем исходный маасив буферным
	arr = buffer;
	//5.добавляем значение в конец массива
	arr[n] = value;
	//6.после того как в массиве добавился элемент ,количество его элементов увеличивается на 1
	n++;

	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* insert(int arr[], int& n, int value, int index)
{
	if (index >= n)return arr;
	int* buffer = new int[n + 1];
	//Часть массива копируем соответственно:
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//Оставшуюся часть массива копируем со смещением:
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* erase(int arr[], int& n, int index)
{
	if (index >= n)return arr;
	int* buffer = new int[--n];
	/*for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i] = arr[i + 1];*/
	int i = 0;
	for (; i < index; i++)
		buffer[i] = arr[i];
	for (; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}