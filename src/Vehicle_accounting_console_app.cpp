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
			if (Creation())
			{


			}
			break;
		case 2: // Редактирование
			if (Editing())
			{

			}
			break;
		case 3: // Удаление
			if (Deletion())
			{

			}
			break;
		case 4: // Отображение всего списка с сортировкой по выбранному полю
			if (Display_with_sorting())
			{

			}
			break;
		case 5: // Поиск по выбранному полю
			if (Search())
			{

			}
			break;
		case 6: // Сохранение всех записей в файл
			if (Save())
			{

			}
			break;
		case 7: // Загрузка всех записей из файла
			if (Load())
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
		std::cout << "Invalid number\n";
		return true;
	}
	return false;
}

bool Parse_consol::Checking_correct_number_short(std::string console_in, int& value)
{
	try
	{
		value = std::stoi(console_in);
	}
	catch (const std::exception&)
	{
		std::cout << "Invalid number\n";
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

bool Parse_consol::Creation() // Command 1
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
	if (last_Type == "Car" || last_Type == "car")
	{
		int last_Number_of_owners;
		int last_Mileage;
		while (Checking_correct_number_input("Enter the number_of_owners\n", last_Number_of_owners)) {};
		while (Checking_correct_number_input("Enter the mileage\n", last_Mileage)) {};
		vector_ptr->push_back(Car(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Number_of_owners, last_Mileage));
	}
	else if (last_Type == "Boat" || last_Type == "boat")
	{

	}
	else if (last_Type == "Airplane" || last_Type == "airplane")
	{

	}
	else if (last_Type == "Spaceship" || last_Type == "spaceship")
	{

	}

	/*vector_ptr->push_back(Car(last_Brand, last_Model, last_Year_of_release, last_Weight));*/

	return false;
}

bool Parse_consol::Editing() // Command 2
{
	return false;
}

bool Parse_consol::Deletion() // Command 3
{
	return false;
}

bool Parse_consol::Display_with_sorting() // Command 4
{
	std::cout << "Enter the type of vehicle\n";
	return false;
}

bool Parse_consol::Search() // Command 5
{
	return false;
}

int Parse_consol::Save() // Command 6
{
	return 0;
}

int Parse_consol::Load() // Command 7
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


