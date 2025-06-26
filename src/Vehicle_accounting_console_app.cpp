#include "Vehicle_accounting_console_app.h"


int Vehicle::id_counter = 0;


int main()
{
	/*Vehicle v("suz", "sem", 1, 2);
	Vehicle vz("suz", "sem", 1, 2);
	Car c("suz", "sem", 1, 2, 3, 4);
	std::cout << vz.Get_id() << std::endl;
	std::cout << c.Get_id() << std::endl;

	std::cout << vz.Get_id_counter() << std::endl;
	std::cout << c.Get_id_counter() << std::endl;

	Car cz("suz", "sem", 1, 2, 3, 4);
	Vehicle vx("suz", "sem", 1, 2);
	std::cout << vx.Get_id_counter() << std::endl;
	std::cout << cz.Get_id_counter() << std::endl;*/

	while (1)
	{
		Parse_console_input();
	}
	
	//return 0;
}

inline void Parse_console_input()
{

}

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
	this->Type_of_vehicle = "car";
	this->Number_of_owners = Number_of_owners;
	this->Mileage = Mileage;
}

Car::~Car()
{
}
