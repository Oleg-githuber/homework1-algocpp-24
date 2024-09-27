#include <iostream>
#include <clocale>

// Прототипы функций
int enterNumber();
void printArray(int* arr, int arrSize);
int calculateValueOfNumbers(int* arr, int arrSize, int number);

// Точка входа в программу
int main()
{
	setlocale(LC_ALL, "Russian");

    int arr[]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int arrSize = sizeof(arr) / sizeof(int);
	printArray(arr, arrSize);
	int number{ enterNumber() };
	int result{ calculateValueOfNumbers(arr, arrSize, number) };
	std::cout << "\nКоличество элементов в массиве больших, чем " << number << ": " << result << std::endl;

    return EXIT_SUCCESS;
}

/*
* Функция ввода точки отсчёта
*/
int enterNumber()
{
	int number{};
	while (true)
	{
		std::cout << "Введите точку отсчёта: ";
		if (std::cin >> number)
		{
			return number;
		}
		std::cout << "Вы ввели некорректное значение" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}

// Функция нахождения индекса массива
int findIndex(int number, int* arr, int arrSize)
{
	// Переменные для левого, правого и центрального индексов
	int leftIndex{ 0 };
	int rightIndex{ arrSize - 1 };
	int centerIndex{};

	// Если точка отсчёта находится за пределами границ значений
	if (arr[leftIndex] > number)
	{
		return leftIndex - 1;
	}
	if (arr[rightIndex] < number)
	{
		return rightIndex;
	}

	// Нахождение индекса в цикле
	while (leftIndex <= rightIndex)
	{
		centerIndex = (leftIndex + rightIndex) / 2;
		
		// Если между левым и правым элементом нет элементов
		if (rightIndex - leftIndex == 1)
		{
			if (arr[rightIndex] == number)
			{
				return rightIndex;
			}
			return leftIndex;
		}

		// Уменьшение границ поиска
		if (arr[centerIndex] < number)
		{
			leftIndex = centerIndex;
			continue;
		}
		if (arr[centerIndex] > number)
		{
			rightIndex = centerIndex;
			continue;
		}

		// Если попали на нужный элемент
		if (arr[centerIndex] == number)
		{
			if (arr[centerIndex + 1] > number)
			{
				return centerIndex;
			}

			leftIndex = centerIndex;
			//++leftIndex;
			//continue;
		}
	}
	return centerIndex;
}

// Функция вычисления количества элементов больше точки отсчёта
int calculateValueOfNumbers(int* arr, int arrSize, int number)
{
	if ((arr == nullptr) || (arrSize == 0))
	{
		return 0;
	}
	return arrSize - findIndex(number, arr, arrSize) - 1;
}

// Функция вывода массива на экран
void printArray(int* arr, int arrSize)
{
	std::cout << "Массив:\n[";
	for (int index{}; index < arrSize; ++index)
	{
		std::cout << arr[index];
		if (index < (arrSize - 1))
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}