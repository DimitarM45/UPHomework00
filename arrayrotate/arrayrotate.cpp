#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int k = 1;

	for (int i = 0; i < k; i++)
	{
		int temp = arr[5 - 1];

		for (int i = 5 - 2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}

		arr[0] = temp;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << ' ';
	}
}