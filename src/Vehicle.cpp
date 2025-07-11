#include "Vehicle.h"

int Vehicle::id_counter = 0;

Vehicle::Vehicle(std::string Brand, std::string Model, int Year_of_release, int Weight)
{
	this->id = ++(this->id_counter);
	this->Brand = Brand;
	this->Model = Model;
	this->Year_of_release = Year_of_release;
	this->Weight = Weight;
}

Vehicle::Vehicle(int id, std::string Brand, std::string Model, int Year_of_release, int Weight)
{
	this->id = id;
	this->Brand = Brand;
	this->Model = Model;
	this->Year_of_release = Year_of_release;
	this->Weight = Weight;
}

Vehicle::~Vehicle()
{
}

const void Vehicle::Display()
{
	std::cout << Brand << "\t\t"
		<< Model << "\t\t"
		<< Year_of_release << "\t"
		<< Weight << "\t";
}

void Vehicle::Edit()
{
	while (Edit_string("Enter the brand\n", this->Brand)) {};
	while (Edit_string("Enter the model\n", this->Model)) {};
	while (Edit_number("Enter the year of release\n", this->Year_of_release)) {};
	while (Edit_number("Enter the weight\n", this->Weight)) {};
}

const std::string Vehicle::String_to_save()
{
	std::string value_to_save = std::to_string(id); value_to_save.append(Dividing_symbol);
	value_to_save.append(Brand); value_to_save.append(Dividing_symbol);
	value_to_save.append(Model); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Year_of_release)); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Weight)); value_to_save.append(Dividing_symbol);
	return value_to_save;
}

bool Vehicle::Edit_string(std::string console_out, std::string &value)
{
	std::string Console_input;
	std::cout << console_out;
	std::cin >> Console_input;
	if (Console_input == "-")
	{
		return false;
	}
	else
	{
		value = Console_input;
		return false;
	}
}

bool Vehicle::Edit_number(std::string console_out, int & value)
{
	std::string Console_input;
	std::cout << console_out;
	std::cin >> Console_input;
	if (Console_input == "-")
	{
		return false;
	}
	else
	{
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
}

Car::Car(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Car::Car(int id, std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(id, Brand, Model, Year_of_release, Weight)
{
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Car::~Car()
{
}

const void Car::Display()
{
	std::cout << id << "\t"
		<< "Car\t\t";
	Vehicle::Display();
	std::cout << Number_of_owners << "\t"
		<< Mileage << "\t\n";
}

void Car::Edit()
{
	Vehicle::Edit();
	while (Edit_number("Enter the number of owners\n", this->Number_of_owners)) {};
	while (Edit_number("Enter the mileage\n", this->Mileage)) {};
}

const std::string Car::String_to_save()
{
	std::string value_to_save = Vehicle::String_to_save();
	value_to_save.append("Car"); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Number_of_owners)); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Mileage)); value_to_save.append(Dividing_symbol);
	return value_to_save;
}

Boat::Boat(std::string Brand, std::string Model, int Year_of_release, int Weight, int Displacement, int Propeller_immersion_depth) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Displacement = Displacement;
	this->Propeller_immersion_depth = Propeller_immersion_depth;
}

Boat::Boat(int id, std::string Brand, std::string Model, int Year_of_release, int Weight, int Displacement, int Propeller_immersion_depth) :Vehicle(id, Brand, Model, Year_of_release, Weight)
{
	this->Displacement = Displacement;
	this->Propeller_immersion_depth = Propeller_immersion_depth;
}

Boat::~Boat()
{
}

const void Boat::Display()
{
	std::cout << id << "\t"
		<< "Boat\t\t";
	Vehicle::Display();
	std::cout << Displacement << "\t"
		<< Propeller_immersion_depth << "\t\n";
}

void Boat::Edit()
{
	Vehicle::Edit();
	while (Edit_number("Enter the number of displacement\n", this->Displacement)) {};
	while (Edit_number("Enter the propeller immersion depth\n", this->Propeller_immersion_depth)) {};
}

const std::string Boat::String_to_save()
{
	std::string value_to_save = Vehicle::String_to_save();
	value_to_save.append("Boat"); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Displacement)); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Propeller_immersion_depth)); value_to_save.append(Dividing_symbol);
	return value_to_save;
}

Airplane::Airplane(std::string Brand, std::string Model, int Year_of_release, int Weight, int Cargo_capacity, int Wingspan) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Cargo_capacity = Cargo_capacity;
	this->Wingspan = Wingspan;
}

Airplane::Airplane(int id, std::string Brand, std::string Model, int Year_of_release, int Weight, int Cargo_capacity, int Wingspan) :Vehicle(id, Brand, Model, Year_of_release, Weight)
{
	this->Cargo_capacity = Cargo_capacity;
	this->Wingspan = Wingspan;
}

Airplane::~Airplane()
{
}

const void Airplane::Display()
{
	std::cout << id << "\t"
		<< "Airplane\t";
	Vehicle::Display();
	std::cout << Cargo_capacity << "\t"
		<< Wingspan << "\t\n";
}

void Airplane::Edit()
{
	Vehicle::Edit();
	while (Edit_number("Enter the cargo capacity\n", this->Cargo_capacity)) {};
	while (Edit_number("Enter the wingspan\n", this->Wingspan)) {};
}

const std::string Airplane::String_to_save()
{
	std::string value_to_save = Vehicle::String_to_save();
	value_to_save.append("Airplane"); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Cargo_capacity)); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Wingspan)); value_to_save.append(Dividing_symbol);
	return value_to_save;
}

Spaceship::Spaceship(std::string Brand, std::string Model, int Year_of_release, int Weight, std::string Fuel_type, int Hyperjump_range) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Fuel_type = Fuel_type;
	this->Hyperjump_range = Hyperjump_range;
}

Spaceship::Spaceship(int id, std::string Brand, std::string Model, int Year_of_release, int Weight, std::string Fuel_type, int Hyperjump_range) :Vehicle(id, Brand, Model, Year_of_release, Weight)
{
	this->Fuel_type = Fuel_type;
	this->Hyperjump_range = Hyperjump_range;
}

Spaceship::~Spaceship()
{
}

const void Spaceship::Display()
{
	std::cout << id << "\t"
		<< "Spaceship\t";
	Vehicle::Display();
	std::cout << Fuel_type << "\t"
		<< Hyperjump_range << "\t\n";
}

void Spaceship::Edit()
{
	Vehicle::Edit();
	while (Edit_string("Enter the fuel type\n", this->Fuel_type)) {};
	while (Edit_number("Enter the hyperjump range\n", this->Hyperjump_range)) {};
}

const std::string Spaceship::String_to_save()
{
	std::string value_to_save = Vehicle::String_to_save();
	value_to_save.append("Spaceship"); value_to_save.append(Dividing_symbol);
	value_to_save.append(Fuel_type); value_to_save.append(Dividing_symbol);
	value_to_save.append(std::to_string(Hyperjump_range)); value_to_save.append(Dividing_symbol);
	return value_to_save;
}
