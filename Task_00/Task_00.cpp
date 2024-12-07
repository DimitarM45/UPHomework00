#include <iostream>
#include <ctime>

constexpr unsigned short MIN_DAY_VALUE = 1;
constexpr unsigned short MAX_DAY_VALUE = 31;

constexpr unsigned short MIN_MONTH_VALUE = 1;
constexpr unsigned short MAX_MONTH_VALUE = 12;

constexpr unsigned short MIN_YEAR_VALUE = 1900;
constexpr unsigned short MAX_YEAR_VALUE = 2100;

int main()
{
	unsigned short day, month, year;

	std::cin >> day;
	std::cin >> month;
	std::cin >> year;

	bool isDayValid = day >= MIN_DAY_VALUE && day <= MAX_DAY_VALUE;
	bool isMonthValid = month >= MIN_MONTH_VALUE && month <= MAX_MONTH_VALUE;
	bool isYearValid = year >= MIN_YEAR_VALUE && year <= MAX_YEAR_VALUE;

	while (!isDayValid && !isMonthValid && !isYearValid)
	{
		std::cout << "Make sure days are between " << MIN_DAY_VALUE << " and " << MAX_DAY_VALUE;
		std::cout << "Make sure days are between " << MIN_DAY_VALUE << " and " << MAX_DAY_VALUE;
		std::cout << "Make sure days are between " << MIN_DAY_VALUE << " and " << MAX_DAY_VALUE;
	}

	struct tm date;

	date.tm_mday = day;
	date.tm_mon = month;
	date.tm_year = year;

	
}