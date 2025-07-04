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

Vehicle::~Vehicle()
{
}

void Vehicle::Display()
{
	std::cout << id << "\t"
		<< Brand << "\t"
		<< Model << "\t"
		<< Year_of_release << "\t"
		<< Weight << "\t";
}

//void Vehicle::Edit(std::string Brand, std::string Model, int Year_of_release, int Weight)
//{
//	this->Brand = Brand;
//	this->Model = Model;
//	this->Year_of_release = Year_of_release;
//	this->Weight = Weight;
//}


Car::Car(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Car::~Car()
{
}

void Car::Display()
{
	std::cout << id << "\t"
		<< "Car\t";
	Vehicle::Display();
	std::cout << Number_of_owners << "\t"
		<< Mileage << "\t";
}

void Car::Edit(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage)
{
	this->Brand = Brand;
	this->Model = Model;
	this->Year_of_release = Year_of_release;
	this->Weight = Weight;
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Boat::Boat(std::string Brand, std::string Model, int Year_of_release, int Weight, int Displacement, int Propeller_immersion_depth) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Displacement = Displacement;
	this->Propeller_immersion_depth = Propeller_immersion_depth;
}

Boat::~Boat()
{
}

void Boat::Display()
{
	std::cout << id << "\t"
		<< "Boat\t";
	Vehicle::Display();
	std::cout << Displacement << "\t"
		<< Propeller_immersion_depth << "\t";
}

void Boat::Edit(std::string Brand, std::string Model, int Year_of_release, int Weight, int Displacement, int Propeller_immersion_depth)
{
	this->Brand = Brand;
	this->Model = Model;
	this->Year_of_release = Year_of_release;
	this->Weight = Weight;
	this->Displacement = Displacement;
	this->Propeller_immersion_depth = Propeller_immersion_depth;
}

Airplane::Airplane(std::string Brand, std::string Model, int Year_of_release, int Weight, int Cargo_capacity, int Wingspan) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Cargo_capacity = Cargo_capacity;
	this->Wingspan = Wingspan;
}

Airplane::~Airplane()
{
}

void Airplane::Display()
{
	std::cout << id << "\t"
		<< "Airplane\t";
	Vehicle::Display();
	std::cout << Cargo_capacity << "\t"
		<< Wingspan << "\t";
}

void Airplane::Edit(std::string Brand, std::string Model, int Year_of_release, int Weight, int Cargo_capacity, int Wingspan)
{
	this->Brand = Brand;
	this->Model = Model;
	this->Year_of_release = Year_of_release;
	this->Weight = Weight;
	this->Cargo_capacity = Cargo_capacity;
	this->Wingspan = Wingspan;
}

Spaceship::Spaceship(std::string Brand, std::string Model, int Year_of_release, int Weight, std::string Fuel_type, int Hyperjump_range) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Fuel_type = Fuel_type;
	this->Hyperjump_range = Hyperjump_range;
}

Spaceship::~Spaceship()
{
}

void Spaceship::Display()
{
	std::cout << id << "\t"
		<< "Spaceship\t";
	Vehicle::Display();
	std::cout << Fuel_type << "\t"
		<< Hyperjump_range << "\t";
}

void Spaceship::Edit(std::string Brand, std::string Model, int Year_of_release, int Weight, std::string Fuel_type, int Hyperjump_range)
{
	this->Brand = Brand;
	this->Model = Model;
	this->Year_of_release = Year_of_release;
	this->Weight = Weight;
	this->Fuel_type = Fuel_type;
	this->Hyperjump_range = Hyperjump_range;
}
