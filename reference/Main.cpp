#include <iostream>


void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void p_swap(int* pn1, int* pn2) {
	int tmp = *pn1;
	*pn1 = *pn2;
	*pn2 = tmp;
}
void r_swap(int& var1, int& var2) {
	int tmp = var1;
	var1 = var2;
	var2 = tmp;
}
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}
int& rmax(int arr[], const int length) {
	int max_index = 0;
	for (int i = 1; i < length; i++)
		if (arr[i] > arr[max_index])
			max_index = i;
	return arr[max_index]; //возвращаем ссылку на индекс массива
}

template <typename T>
void ref_dbl(T&var1, T&var2);

int* greater_arr(int arr1[], const int length1, int arr2[], const int length2, bool&first);

int main () {
	setlocale(LC_ALL, "Russian");
		int n, m;

		//Ссылки на переменные
		/* Создание и инициализация ссылки
		int& refn = n; //альтернативное имя переменной


		std::cout << "n " << n << std::endl;
		std::cout << "refn = " << refn << std::endl;
		n = 15;
		std::cout << "refn = " << refn << std::endl;
		refn = 42;
		std::cout << "n " << n << std::endl;
		*/

		//Ссылки как пареметры функций
		/*n = 7; m = 15;
		std::cout << "n = " << n << "; m = " << m << ";\n";
		r_swap(n, m); //работает, удобно
		std::cout << "n = " << n << "; m = " << m << ";\n";
		*/

		//Ссылки как результат работы функций
		/*const int size = 5;
		int arr[size]{6, 7, 2, 7, 5};

		print_arr(arr, size);
		std::cout << "Максимум = " << rmax(arr, size) << std::endl;
		rmax(arr, size) = -1; // в максимальное число массива записали значение -1
		print_arr(arr, size);
		*/

		//Задача 1. Квадрат или обнуление 
		/*std::cout << "Задача 1.\nВведите два числа -> ";
		std::cin >> n >> m;
		ref_dbl(n, m);
		std::cout << "n = " << n << std::endl;
		std::cout << "m = " << m << "\n\n";
		*/

		//Задача 2. Указатель на массив
		std::cout << "Задача 2.\nМассив А: ";
		const int sizeA = 5;
		const int sizeB = 6;
		int A[sizeA]{ 2, 3, 6, 6 , 1 };
		int B[sizeB]{ 4, 7, 73, 1, 41, 4 };
		print_arr(A, sizeA);
		std::cout << "Массив В: ";
		print_arr(B, sizeB);
		std::cout << "Длиннейший: ";
		bool f;
		int* pointer = greater_arr(A, sizeA, B, sizeB, f);
		print_arr(pointer, f ? sizeA : sizeB);




		return 0;
}


int* greater_arr(int arr1[], const int length1, int arr2[], const int length2, bool&first) {
	//if (length1 > length2)
		//return arr1;
	return (first = length1 > length2) ? arr1 : arr2; //тернарный оператор 
}


template <typename T>
void ref_dbl(T&var1, T& var2) {
	if (var1 > var2) {
		var1 *= var1; //var1 = pow(var1, 2) // нужно подключить библеотеку
		var2 *= var2; //var2 = pow(var2, 2) 
		return;
	}
	var1 = 0;
	var2 = 0;
}
