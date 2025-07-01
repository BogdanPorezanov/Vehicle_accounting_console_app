#include "Vehicle.h"

int Vehicle::id_counter = 0;

Vehicle::Vehicle(std::string Brand, std::string Model, int Year_of_release, int Weight)
{
	Table_fields["Id"] = ++(this->id_counter);
	Table_fields["Brand"] = Brand;
	Table_fields["Model"] = Model;
	Table_fields["Year_of_release"] = Year_of_release;
	Table_fields["Weight"] = Weight;
}

Vehicle::~Vehicle()
{
}


Car::Car(std::string Brand, std::string Model, int Year_of_release, int Weight, int Number_of_owners, int Mileage) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	Table_fields["Car"] = "car";
	Table_fields["Number_of_owners"] = Number_of_owners;
	Table_fields["Mileage"] = Mileage;
}

Car::~Car()
{
}

Boat::Boat(std::string Brand, std::string Model, int Year_of_release, int Weight, int Displacement, int Propeller_immersion_depth) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	Table_fields["Boat"] = "boat";
	Table_fields["Displacement"] = Displacement;
	Table_fields["Propeller_immersion_depth"] = Propeller_immersion_depth;
}

Boat::~Boat()
{
}

Airplane::Airplane(std::string Brand, std::string Model, int Year_of_release, int Weight, int Cargo_capacity, int Wingspan) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	Table_fields["Airplane"] = "airplane";
	Table_fields["Cargo_capacity"] = Cargo_capacity;
	Table_fields["Wingspan"] = Wingspan;
}

Airplane::~Airplane()
{
}

Spaceship::Spaceship(std::string Brand, std::string Model, int Year_of_release, int Weight, std::string Fuel_type, int Hyperjump_range) :Vehicle(Brand, Model, Year_of_release, Weight)
{
	Table_fields["Spaceship"] = "spaceship";
	Table_fields["Fuel_type"] = Fuel_type;
	Table_fields["Hyperjump_range"] = Hyperjump_range;
}

Spaceship::~Spaceship()
{
}
