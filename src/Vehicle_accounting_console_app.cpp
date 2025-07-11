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
			std::cout << "Invalid command number\n";
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

bool Parse_consol::Checking_correct_number_short(int &value)
{
	std::string Console_input;
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

void Parse_consol::Displaying_table_header()
{
	std::cout << "ID\t"
		<< "Type\t\t"
		<< "Brand\t\t"
		<< "Model\t\t"
		<< "Year\t" // Year of release
		<< "Weight\t"
		<< "Add field 1\t"
		<< "Add field 2\t\n";
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
		Table.push_back(std::make_unique<Car>(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Number_of_owners, last_Mileage));
		break;
	case 2:
		int last_Displacement;
		int last_Propeller_immersion_depth;
		while (Checking_correct_number_input("Enter the displacement\n", last_Displacement)) {};
		while (Checking_correct_number_input("Enter the propeller immersion depth\n", last_Propeller_immersion_depth)) {};
		Table.push_back(std::make_unique<Boat>(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Displacement, last_Propeller_immersion_depth));
		break;
	case 3:
		int last_Cargo_capacity;
		int last_Wingspan;
		while (Checking_correct_number_input("Enter the cargo capacity\n", last_Cargo_capacity)) {};
		while (Checking_correct_number_input("Enter the wingspan\n", last_Wingspan)) {};
		Table.push_back(std::make_unique<Airplane>(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Cargo_capacity, last_Wingspan));
		break;
	case 4:
		std::string last_Fuel_type;
		int last_Hyperjump_range;
		std::cout << "Enter the fuel type\n";
		std::cin >> last_Fuel_type;
		while (Checking_correct_number_input("Enter the hyperjump range\n", last_Hyperjump_range)) {};
		Table.push_back(std::make_unique<Spaceship>(last_Brand, last_Model, last_Year_of_release, last_Weight, last_Fuel_type, last_Hyperjump_range));
		break;
	}
	std::cout << "Record was created with ID:" << Table[0]->Get_id_counter() << std::endl;
	return false;
}

bool Parse_consol::Editing() // Command 2
{
	std::cout << "Enter \'-\' to skip the field\n";
	int id_value;
	while (Checking_correct_number_input("Enter ID vehicle\n", id_value)) {};
	for (auto &el : Table)
	{
		if (el->Get_id() == id_value)
		{
			el->Edit();
			std::cout << "Record was edited successfully\n";
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
		if ((*i)->Get_id() == id_value)
		{
			if ((*i)->Get_id() == (*i)->Get_id_counter())
			{
				(*i)->Set_id_counter((*i)->Get_id_counter() - 1);
			}
			Table.erase(i);
			std::cout << "Record was deleted successfully\n";
			return false;
		}
	}
	std::cout << "Vehicle with this ID does not exist!\n";
	return true;
}

bool Parse_consol::Display_with_sorting() // Command 4
{
	if (Table.empty())
	{
		std::cout << "There are no records here\n"; 
		return true;
	}
	int Field_number;
	std::cout << "Enter the sort field\n";
	std::cout << " 1.ID\n"
		<< " 2.Type\n"
		<< " 3.Brand\n"
		<< " 4.Model\n"
		<< " 5.Year of release\n"
		<< " 6.Weight\n"
		<< " 7.Number of owners\n"
		<< " 8.Mileage\n"
		<< " 9.Displacement\n"
		<< " 10.Propeller immersion depth\n"
		<< " 11.Cargo capacity\n"
		<< " 12.Wingspan\n"
		<< " 13.Fuel type\n"
		<< " 14.Hyperjump range\n";
	while (Checking_correct_number_short(Field_number)) {};
	Displaying_table_header();
	switch (Field_number)
	{
	case 1:
		std::sort(Table.begin(), Table.end(), [](auto& a, auto& b) { return (a->Get_id() < b->Get_id()); });
		break;
	case 2:
		std::sort(Table.begin(), Table.end(), [](auto& a, auto& b) { return (a->Get_Type() < b->Get_Type()); });
		break;
	case 3:
		std::sort(Table.begin(), Table.end(), [](auto& a, auto& b) { return (a->Get_Brand() < b->Get_Brand()); });
		break;
	case 4:
		std::sort(Table.begin(), Table.end(), [](auto& a, auto& b) { return (a->Get_Model() < b->Get_Model()); });
		break;
	case 5:
		std::sort(Table.begin(), Table.end(), [](auto& a, auto& b) { return (a->Get_Year_of_release() < b->Get_Year_of_release()); });
		break;
	case 6:
		std::sort(Table.begin(), Table.end(), [](auto& a, auto& b) { return (a->Get_Weight() < b->Get_Weight()); });
		break;
	case 7:
		std::sort(Table.begin(), Table.end(), [=](auto& a, auto& b) { 
			if (a->Get_Type() == "Car")
			{
				if (b->Get_Type() == "Car")
				{
					return (a->Get_Field_1_int() < b->Get_Field_1_int());
				}
				return true;
			}
			else
			{
				return false;
			}
			
			});
		break;
	default:
		break;
	}
	for (auto& el : Table)
	{
		el->Display();
	}
	return false;
}

bool Parse_consol::Search() // Command 5
{
	int Field_number;
	int count = 0;
	std::cout << "Enter the search field\n";
	std::cout << " 1.ID\n"
		<< " 2.Type\n"
		<< " 3.Brand\n"
		<< " 4.Model\n"
		<< " 5.Year of release\n"
		<< " 6.Weight\n"
		<< " 7.Number of owners\n"
		<< " 8.Mileage\n"
		<< " 9.Displacement\n"
		<< " 10.Propeller immersion depth\n"
		<< " 11.Cargo capacity\n"
		<< " 12.Wingspan\n"
		<< " 13.Fuel type\n"
		<< " 14.Hyperjump range\n";
	while (Checking_correct_number_short(Field_number)) {};
	int Field_value_int;
	std::string Field_value_string;
	// позже поправлю
	/*switch (Field_number)
	{
	case 1:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el->Get_id() == Field_value_int)
			{
				++count;
				if (count == 1)
				{
					Displaying_table_header();
				}
				el->Edit();
			}
		}
		break;
	case 2:
		std::cout << "Enter the type of vehicle\n";
		std::cout << " 1.Car\n"
			<< " 2.Boat\n"
			<< " 3.Airplane\n"
			<< " 4.Spaceship\n";
		while (Checking_correct_types_of_vehicles(Field_value_int)) {};
		switch (Field_value_int)
		{
		case 1:
			Field_value_string = "Car";
			break;
		case 2:
			Field_value_string = "Boat";
			break;
		case 3:
			Field_value_string = "Airplane";
			break;
		case 4:
			Field_value_string = "Spaceship";
			break;
		default:
			break;
		}
		for (auto el : Table)
		{
			if (el.Get_Type() == Field_value_string)
			{
				++count;
				if (count == 1)
				{
					Displaying_table_header();
				}
				el.Edit();
			}
		}
		break;
	case 3:
		std::cout << "Enter value\n";
		std::cin >> Field_value_string;
		for (auto el : Table)
		{
			if (el.Get_Brand() == Field_value_string)
			{
				++count;
				if (count == 1)
				{
					Displaying_table_header();
				}
				el.Edit();
			}
		}
		break;
	case 4:
		std::cout << "Enter value\n";
		std::cin >> Field_value_string;
		for (auto el : Table)
		{
			if (el.Get_Model() == Field_value_string)
			{
				++count;
				if (count == 1)
				{
					Displaying_table_header();
				}
				el.Edit();
			}
		}
		break;
	case 5:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Year_of_release() == Field_value_int)
			{
				++count;
				if (count == 1)
				{
					Displaying_table_header();
				}
				el.Edit();
			}
		}
		break;
	case 6:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Weight() == Field_value_int)
			{
				++count;
				if (count == 1)
				{
					Displaying_table_header();
				}
				el.Edit();
			}
		}
		break;
	case 7:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Car")
			{
				if (el.Get_Field_1_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 8:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Car")
			{
				if (el.Get_Field_2_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 9:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Boat")
			{
				if (el.Get_Field_1_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 10:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Boat")
			{
				if (el.Get_Field_2_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 11:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Airplane")
			{
				if (el.Get_Field_1_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 12:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Airplane")
			{
				if (el.Get_Field_2_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 13:
		std::cout << "Enter value\n";
		std::cin >> Field_value_string;
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Spaceship")
			{
				if (el.Get_Field_1_string() == Field_value_string)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	case 14:
		while (Checking_correct_number_input("Enter value\n", Field_value_int)) {};
		for (auto& el : Table)
		{
			if (el.Get_Type() == "Spaceship")
			{
				if (el.Get_Field_1_int() == Field_value_int)
				{
					++count;
					if (count == 1)
					{
						Displaying_table_header();
					}
					el.Edit();
				}
			}
		}
		break;
	default:
		std::cout << "Invalid number\n";
		break;
	}*/
	if (count == 0)
	{
		std::cout << "There are no fields with this value\n";
	}
	return false;
}

int Parse_consol::Save() // Command 6
{
	if (Table.size() == 0)
	{
		std::cout << "There are no records to save in this table\n";
		return 2;
	}
	std::string path;
	std::cout << "Specify the path to the save file: ";
	std::cin >> path;
	fs.open(path, std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "File creation error\n";
		fs.close();
		return 1;
	}
	fs << Table.size() << "\n";
	std::sort(Table.begin(), Table.end(), [](auto &a, auto &b) {return (a->Get_id()) < (b->Get_id()); });
	for (auto &el : Table)
	{
		fs << el->String_to_save() << "\n";
	}
	fs.close();
	std::cout << "Save is successful\n";
	return 0;
}

int Parse_consol::Load() // Command 7
{
	std::string path;
	std::cout << "Specify the path to the load file: ";
	std::cin >> path;
	fs.open(path, std::fstream::in);
	if (!fs.is_open())
	{
		std::cout << "File open error\n";
		fs.close();
		return 1;
	}
	std::string line;
	std::getline(fs, line);
	int size;
	try
	{
		size = std::stoi(line);
	}
	catch (const std::exception&)
	{
		std::cout << "Incorrect data in the file being opened\n";
		return 2;
	}
	Table.clear();
	Table.reserve(size);
	
	int last_id = 0;
	std::string last_Type;
	std::string last_Brand;
	std::string last_Model;
	int last_Year_of_release;
	int last_Weight;

	while (std::getline(fs, line))
	{
		try
		{
			last_id = std::stoi(strtok(line.data(), ";"));
			last_Brand = strtok(nullptr, ";");
			last_Model = strtok(nullptr, ";");
			last_Year_of_release = std::stoi(strtok(nullptr, ";"));
			last_Weight = std::stoi(strtok(nullptr, ";"));
			last_Type = strtok(nullptr, ";");
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect data in the file being opened\n";
			return 2;
		}
		if (last_Type == "Car")
		{
			int last_Number_of_owners;
			int last_Mileage;
			try
			{
				last_Number_of_owners = std::stoi(strtok(nullptr, ";"));;
				last_Mileage = std::stoi(strtok(nullptr, ";"));;
			}
			catch (const std::exception&)
			{
				std::cout << "Incorrect data in the file being opened\n";
				return 2;
			}
			Table.push_back(std::make_unique<Car>(last_id, last_Brand, last_Model, last_Year_of_release, last_Weight, last_Number_of_owners, last_Mileage));
		}
		else if (last_Type == "Boat")
		{
			int last_Displacement;
			int last_Propeller_immersion_depth;
			try
			{
				last_Displacement = std::stoi(strtok(nullptr, ";"));;
				last_Propeller_immersion_depth = std::stoi(strtok(nullptr, ";"));;
			}
			catch (const std::exception&)
			{
				std::cout << "Incorrect data in the file being opened\n";
				return 2;
			}
			Table.push_back(std::make_unique<Boat>(last_id, last_Brand, last_Model, last_Year_of_release, last_Weight, last_Displacement, last_Propeller_immersion_depth));
		}
		else if (last_Type == "Airplane")
		{
			int last_Cargo_capacity;
			int last_Wingspan;
			try
			{
				last_Cargo_capacity = std::stoi(strtok(nullptr, ";"));;
				last_Wingspan = std::stoi(strtok(nullptr, ";"));;
			}
			catch (const std::exception&)
			{
				std::cout << "Incorrect data in the file being opened\n";
				return 2;
			}
			Table.push_back(std::make_unique<Airplane>(last_id, last_Brand, last_Model, last_Year_of_release, last_Weight, last_Cargo_capacity, last_Wingspan));
		}
		else if (last_Type == "Spaceship")
		{
			std::string last_Fuel_type = strtok(nullptr, ";");;
			int last_Hyperjump_range;
			try
			{
				last_Hyperjump_range = std::stoi(strtok(nullptr, ";"));;
			}
			catch (const std::exception&)
			{
				std::cout << "Incorrect data in the file being opened\n";
				return 2;
			}
			Table.push_back(std::make_unique<Spaceship>(last_id, last_Brand, last_Model, last_Year_of_release, last_Weight, last_Fuel_type, last_Hyperjump_range));
		}
		else
		{
			std::cout << "Incorrect data in the file being opened\n";
			return 2;
		}
	}
	Table[0]->Set_id_counter(last_id);
	fs.close();
	std::cout << "Load is successful\n";
	return 0;
}



