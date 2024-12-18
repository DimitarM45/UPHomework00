#include <iostream>
#include <ctime>

constexpr unsigned short MIN_DAY_VALUE = 1;
constexpr unsigned short MAX_DAY_VALUE = 31;

constexpr unsigned short MIN_MONTH_VALUE = 1;
constexpr unsigned short MAX_MONTH_VALUE = 12;

constexpr unsigned short MIN_YEAR_VALUE = 1900;
constexpr unsigned short MAX_YEAR_VALUE = 2100;

constexpr unsigned short MAX_DATE_STR_SIZE = 50;

bool validateDate(const unsigned short day, const unsigned short month, const unsigned short year)
{
	bool isMonthDayValid = false;

	bool isDayValid = day >= MIN_DAY_VALUE && day <= MAX_DAY_VALUE;
	bool isMonthValid = month >= MIN_MONTH_VALUE && month <= MAX_MONTH_VALUE;
	bool isYearValid = year >= MIN_YEAR_VALUE && year <= MAX_YEAR_VALUE;

	return isDayValid && isMonthValid && isYearValid;
}

int main()
{
	unsigned short day, month, year;

	std::cin >> day;
	std::cin >> month;
	std::cin >> year;

	while (!validateDate(day, month, year))
	{
		std::cout << "\nMake sure day is between " << MIN_DAY_VALUE << " and " << MAX_DAY_VALUE << "!\n";
		std::cout << "Make sure month is between " << MIN_MONTH_VALUE << " and " << MAX_MONTH_VALUE << "!\n";
		std::cout << "Make sure year is between " << MIN_YEAR_VALUE << " and " << MAX_YEAR_VALUE << "!\n";
		
		std::cin >> day;
		std::cin >> month;
		std::cin >> year;
	}

	struct tm date;

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_mon = month;
	date.tm_year = year;

	
}