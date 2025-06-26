#pragma once

#include <iostream>
#include <string>
//#include 

inline void Parse_console_input();

class Vehicle
{
public:
	Vehicle(std::string, std::string, int, int); // марка, модель, год выпуска, вес
	~Vehicle();
	int Get_id() { return id; }
	int Get_id_counter() { return id_counter; }

protected:
	std::string Type_of_vehicle;
private:
	static int id_counter;

	int id;
	std::string Brand;
	std::string Model;
	int Year_of_release;
	int Weight;

};

class Car : public Vehicle
{
public:
	Car(std::string, std::string, int, int, int, int); // + число владельцев, пробег
	~Car();
private:
	int Number_of_owners;
	int Mileage;
};