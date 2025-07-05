#include "Vehicle_accounting_console_app.h"

//int Vehicle::id_counter = 0;

int main()
{
	//std::vector<Vehicle> vector;
	Parse_consol parser;
	parser.run();
	return 0;
}

Parse_consol::Parse_consol() 
{
}

//Parse_consol::Parse_consol(std::vector<Vehicle> vector)
//{
//	this->vector_ptr = &vector;
//}

Parse_consol::~Parse_consol()
{
}

void Parse_consol::run()
{
	while (1)
	{
		std::string in;
		std::cout << "\nList of possible commands:\n 1.Creation\n 2.Editing\n 3.Deletion\n " <<
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

bool Parse_consol::Checking_correct_number_short(std::string console_in, int &value)
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

bool Parse_consol::Checking_correct_types_of_vehicles(int &last_Type)
{
	std::string Console_input;
	int Check_Type;
	std::cin >> Console_input;
	try
	{
		Check_Type = std::stoi(Console_input);
	}
	catch (const std::exception&)
	{
		std::cout << "Invalid number\n";
		return true;
	}
	if (Check_Type >= 1 && Check_Type <= 4)
	{
		last_Type = Check_Type;
		return false;
	}
	else
	{
		std::cout << "Invalid number\n";
		return true;
	}
	
}

bool Parse_consol::Creation() // Command 1
{
	int last_Type;
	std::string last_Brand;
	std::string last_Model;
	int last_Year_of_release;
	int last_Weight;
	
	std::cout << "Enter the type of vehicle\n";
	std::cout << " 1.Car\n"
		<< " 2.Boat\n"
		<< " 3.Airplane\n"
		<< " 4.Spaceship\n";
	while (Checking_correct_types_of_vehicles(last_Type)) {};
	std::cout << "Enter the brand\n";
	std::cin >> last_Brand;
	std::cout << "Enter the model\n";
	std::cin >> last_Model;
	while (Checking_correct_number_input("Enter the year of release\n", last_Year_of_release)) {};
	while (Checking_correct_number_input("Enter the weight\n", last_Weight)) {};
	switch (last_Type)
	{
	case 1:
		int last_Number_of_owners;
		int last_Mileage;
		while (Checking_correct_number_input("Enter the number of owners\n", last_Number_of_owners)) {};
		while (Checking_correct_number_input("Enter the mileage\n", last_Mileage)) {};
		Table.push_back(Car(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Number_of_owners, last_Mileage));
		break;
	case 2:
		int last_Displacement;
		int last_Propeller_immersion_depth;
		while (Checking_correct_number_input("Enter the displacement\n", last_Displacement)) {};
		while (Checking_correct_number_input("Enter the propeller immersion depth\n", last_Propeller_immersion_depth)) {};
		Table.push_back(Boat(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Displacement, last_Propeller_immersion_depth));
		break;
	case 3:
		int last_Cargo_capacity;
		int last_Wingspan;
		while (Checking_correct_number_input("Enter the cargo capacity\n", last_Cargo_capacity)) {};
		while (Checking_correct_number_input("Enter the wingspan\n", last_Wingspan)) {};
		Table.push_back(Airplane(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Cargo_capacity, last_Wingspan));
		break;
	case 4:
		std::string last_Fuel_type;
		int last_Hyperjump_range;
		std::cout << "Enter the fuel type\n";
		std::cin >> last_Fuel_type;
		while (Checking_correct_number_input("Enter the hyperjump range\n", last_Hyperjump_range)) {};
		Table.push_back(Spaceship(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Fuel_type, last_Hyperjump_range));
		break;
	}
	std::cout << "Record was created with ID:" << Table[0].Get_id_counter() << std::endl;
	return false;
}

bool Parse_consol::Editing() // Command 2
{
	int id_value;
	while (Checking_correct_number_input("Enter ID vehicle\n", id_value)) {};
	for (auto &el : Table)
	{
		if (el.Get_id() == id_value)
		{
			el.Edit();
			return false;
		}
	}
	std::cout << "Vehicle with this ID does not exist!\n";
	return true;
}

bool Parse_consol::Deletion() // Command 3
{
	int id_value;
	while (Checking_correct_number_input("Enter ID vehicle\n", id_value)) {};
	for (auto i = Table.begin(); i != Table.end(); ++i)
	{
		if (i->Get_id() == id_value)
		{
			Table.erase(i);
			return false;
		}
	}
	std::cout << "Vehicle with this ID does not exist!\n";
	return true;
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



