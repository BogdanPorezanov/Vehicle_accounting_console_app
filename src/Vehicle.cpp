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


Car::Car(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	this->Type = "car";
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Car::~Car()
{
}