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


Car::Car(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Car::~Car()
{
}

Boat::Boat(std::string Brand, std::string Model, int Year_of_release, int Weight, int Displacement, int Propeller_immersion_depth) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Displacement = Displacement;
	this->Propeller_immersion_depth = Propeller_immersion_depth;
}

Boat::~Boat()
{
}

Airplane::Airplane(std::string Brand, std::string Model, int Year_of_release, int Weight, int Cargo_capacity, int Wingspan) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Cargo_capacity = Cargo_capacity;
	this->Wingspan = Wingspan;
}

Airplane::~Airplane()
{
}

Spaceship::Spaceship(std::string Brand, std::string Model, int Year_of_release, int Weight, std::string Fuel_type, int Hyperjump_range) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Fuel_type = Fuel_type;
	this->Hyperjump_range = Hyperjump_range;
}

Spaceship::~Spaceship()
{
}
