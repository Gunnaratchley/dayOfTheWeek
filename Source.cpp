#include <iostream>


int dayOfTheWeek(int y, int m, int d);

std::string getName(int day);

int main()
{
	int day = 0;
	int month = 0;
	int year = 0;
	char choice = 'Y';

	while (choice == 'Y' || choice == 'y')
	{
		std::cout << "Please Enter Year:  " << std::endl;
		std::cin >> year;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Entry!  Please Try Again. \n\nYear:  ";

			std::cin >> year;
		}

		std::cout << "Please Enter Month:  " << std::endl;
		std::cin >> month;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Entry!  Please Try Again. \n\nMonth:  ";

			std::cin >> month;
		}

		std::cout << "Please Enter Day:  " << std::endl;
		std::cin >> day;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Entry!  Please Try Again. \n\nDay:  ";

			std::cin >> day;
		}
		std::cout << std::endl;
		/*std::cout << (dayOfTheWeek(year, month, day)) << std::endl;*/
		std::cout << (getName(dayOfTheWeek(year, month, day)));
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Would you like to choose another date (y/n)? ";
		std::cin >> choice;
		std::cout << std::endl;
		std::cout << std::endl;

		if (choice == 'N' || choice == 'n')
			break;
	}

	std::cout << "Thank you for participating" << std::endl;

	return 0;
}

//day of the week funciton
int dayOfTheWeek(int year, int month, int day)
{
	int t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
	// if the month is less than 3 reduce year by 1
	if (month < 3)
		year -= 1;

	return ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7);

}

// function to return the name of the day
std::string getName(int day)
{
	if (day == 0)
		return ("Sunday");
	if (day == 1)
		return ("Monday");
	if (day == 2)
		return ("Tuesday");
	if (day == 3)
		return ("Wednesday");
	if (day == 4)
		return ("Thursday");
	if (day == 5)
		return ("Friday");
	if (day == 6)
		return ("Saturday");
	if (day < 0 || day > 6)
		return ("Invalid");
}