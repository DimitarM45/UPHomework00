#include <iostream>

constexpr unsigned short MAX_ARR_CAPACITY = 20;

unsigned short getDigits(unsigned long long number)
{
	unsigned long long tempNumber = number;

	unsigned short digits = 0;

	while (tempNumber != 0)
	{
		digits++;

		tempNumber /= 10;
	}

	return digits;
}

void populateArray(int arr[MAX_ARR_CAPACITY], unsigned short size, unsigned long long number)
{
	int index = 0;

	while (number)
	{
		arr[index++] = number % 10;

		number /= 10;
	}
}

void reverseArray(int arr[MAX_ARR_CAPACITY], unsigned short size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int tempNum = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tempNum;
	}
}

unsigned short buildString(char str[MAX_ARR_CAPACITY], const int numberArr[MAX_ARR_CAPACITY], unsigned short numberArrSize)
{
	unsigned short index = 0;

	const char alphabetStart = 'a' - 1;

	for (int i = 0; i < numberArrSize - 1; i += 2)
	{
		unsigned short currNumber = (numberArr[i] * 10) + numberArr[i + 1];

		if (currNumber > 26)
		{
			unsigned short firstDigit = currNumber / 10;

			unsigned short secondDigit = currNumber % 10;

			str[index++] = (char)(firstDigit + alphabetStart);
			str[index++] = secondDigit != 0 ? (char)(secondDigit + alphabetStart) : '.';
		}
		else if (currNumber < 10)
		{
			str[index++] = '.';
			str[index++] = (char)(currNumber + alphabetStart);
		}
		else
		{
			str[index++] = (char)(currNumber + alphabetStart);
		}
	}

	if (numberArrSize % 2 != 0)
	{
		str[index++] = (char)(numberArr[numberArrSize - 1] + alphabetStart);
	}

	return index;
}

void printString(char str[MAX_ARR_CAPACITY], unsigned short size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << str[i];
	}
}

int main()
{
	unsigned long long number;
	std::cin >> number;

	char str[MAX_ARR_CAPACITY];

	int numberArr[MAX_ARR_CAPACITY];

	unsigned short digits = getDigits(number);

	populateArray(numberArr, digits, number);

	reverseArray(numberArr, digits);
	
	unsigned short strSize = buildString(str, numberArr, digits);

	printString(str, strSize);
}