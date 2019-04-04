#include<iostream>
#include<cmath>

struct BOOK
{
	char Name[1024];
	char Author[1024];
	char Publishing[1024];
	char Genre[1024];
	int Year;
};
typedef BOOK(&BOOKS)[10];
const int Size = 10;
void Create_books(BOOKS&);

int main()
{
	BOOK books[Size] = {};

	system("pause");
	return 0;
}

void Create_books(BOOKS& books)
{
	for (int i = 0; i < Size; i++)
	{
		books[i] = { "Unknown name", "Unknown author", "Unknown publishing", "Inknown genre" };
		strcpy(books[i].Name, "");
	}
}









/*#include<iostream>
#include<cmath>

struct washing_machine
{
	char Firm[1024];
	char Color[1024];
	float Width;
	float Length;
	float Height;
	float Power;
	float Spin_speed;
	float Heating_temperature;
};

int main()
{
	washing_machine A = { "Bork", "Red", 50.0f, 30.0f, 100.0f, 1000.0f, 800.0, 40.0f };
		std::cout << "\t\t\tWashing machine parameters" << std::endl << "\tFirm - " << A.Firm << std::endl << 
		"\tColor - " << A.Color << std::endl << "\tWidth - " << A.Width << std::endl << "\tLength - " << 
		A.Length << std::endl << "\tHeight - " << A.Height << std::endl << "\tPower - " << A.Power << std::endl <<
		"\tSpin speed - " << A.Spin_speed << std::endl << "\tHeating temperature - " << A.Heating_temperature << std::endl << std::endl;

	system("pause");
	return 0;
}
*/
