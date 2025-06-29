#include "Vehicle_accounting_console_app.h"


//int Vehicle::id_counter = 0;

int main()
{
	std::vector<Vehicle> vector;
	Parse_consol parser(vector);
	//Parse_consol parser;
	parser.run();
	return 0;
}

Parse_consol::Parse_consol(std::vector<Vehicle> vector)
{
	this->vector_ptr = &vector;
}

Parse_consol::~Parse_consol()
{
}

void Parse_consol::run()
{
	while (1)
	{
		std::string in;
		std::cout << "List of possible commands:\n 1.Creation\n 2.Editing\n 3.Deletion\n " <<
			"4.Displaying the entire list sorted by the selected field\n " <<
			"5.Search by selected field\n 6.Save all entries to a file\n " <<
			"7.Download all recordings from a file\n\nEnter the command number:" << std::endl; // Список доступных команд
		std::cin >> in;
		int In_number;
		try
		{
			In_number = std::stoi(in);
		}
		catch (const std::exception&)
		{
			std::cout << "invalid command number\n";
			continue;
		}
		switch (In_number)
		{
		case 1: // Создание
			if (Command_1())
			{


			}
			break;
		case 2: // Редактирование
			if (Command_2())
			{

			}
			break;
		case 3: // Удаление
			if (Command_3())
			{

			}
			break;
		case 4: // Отображение всего списка с сортировкой по выбранному полю
			if (Command_4())
			{

			}
			break;
		case 5: // Поиск по выбранному полю
			if (Command_5())
			{

			}
			break;
		case 6: // Сохранение всех записей в файл
			if (Command_6())
			{

			}
			break;
		case 7: // Загрузка всех записей из файла
			if (Command_7())
			{

			}
			break;
		default:
			std::cout << "invalid command number\n";
			break;
		}
	}
}

bool Parse_consol::Checking_correct_number_input(std::string console_out, int &value)
{
	std::string Console_input;
	std::cout << console_out;
	std::cin >> Console_input;
	try
	{
		value = std::stoi(Console_input);
	}
	catch (const std::exception&)
	{
		std::cout << "Number input error\n";
		return true;
	}
	return false;
}

bool Parse_consol::Checking_correct_types_of_vehicles(std::string &last_Type)
{
	std::string Console_input;
	std::cin >> Console_input;
	for (const auto &el: Acceptable_types_of_vehicles)
	{
		if (Console_input == el)
		{
			last_Type = Console_input;
			return false;
		}
	}
	std::cout << "Such a vehicle is not provided in this table, enter another one\n";
	return true;
}

bool Parse_consol::Command_1()
{
	std::string last_Type;
	std::string last_Brand;
	std::string last_Model;
	int last_Year_of_release;
	int last_Weight;
	
	std::cout << "Enter the type of vehicle\n";
	while (Checking_correct_types_of_vehicles(last_Type)) {};
	std::cout << "Enter the brand\n";
	std::cin >> last_Brand;
	std::cout << "Enter the model\n";
	std::cin >> last_Model;
	while (Checking_correct_number_input("Enter the year of release\n", last_Year_of_release)) {};
	while (Checking_correct_number_input("Enter the weight\n", last_Weight)) {};

	return false;
}

bool Parse_consol::Command_2()
{
	return false;
}

bool Parse_consol::Command_3()
{
	return false;
}

bool Parse_consol::Command_4()
{
	return false;
}

bool Parse_consol::Command_5()
{
	return false;
}

int Parse_consol::Command_6()
{
	return 0;
}

int Parse_consol::Command_7()
{
	return 0;
}

//Vehicle::Vehicle(std::string Brand, std::string Model, int Year_of_release, int Weight)
//{
//	this->id = ++(this->id_counter);
//	this->Brand = Brand;
//	this->Model = Model;
//	this->Year_of_release = Year_of_release;
//	this->Weight = Weight;
//}
//
//Vehicle::~Vehicle()
//{
//}
//
//Car::Car(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(Brand, Model, Year_of_release, Weight)
//{
//	this->Type = "car";
//	this->Number_of_owners = Number_of_owners;
//	this->Mileage = Mileage;
//}
//
//Car::~Car()
//{
//}


