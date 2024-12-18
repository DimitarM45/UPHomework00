#include <iostream>

constexpr char DEFAULT_TWEET_START[] = "Traicho tweeted: ";

constexpr unsigned short MAX_INPUT_LENGTH = 1000;
constexpr unsigned short MAX_TWEET_LENGTH = 280;

unsigned short countLetters(const char str[MAX_INPUT_LENGTH])
{
	unsigned short counter = 0;

	for (int i = 0; i < MAX_INPUT_LENGTH; i++)
	{
		counter++;
	}

	return counter;
}

int main()
{
	char inputText[MAX_INPUT_LENGTH];
	std::cin.getline(inputText, MAX_INPUT_LENGTH);

	unsigned short threadIndex = 0;

	for (int i = 0; i < MAX_INPUT_LENGTH; i++)
	{
		if (i > 0)
		{
			std::cout << "--------------------";
		}

		int index = i;

		while (index < MAX_TWEET_LENGTH)
		{
			std::cout << inputText[index];

			index++;
		}

		std::cout << '\n';
		
		if (inputText[index] == ' ')
		{
			index--;
		}
	}
}