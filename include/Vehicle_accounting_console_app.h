#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"

class Parse_consol
{
public:
	Parse_consol(std::vector<Vehicle>);
	~Parse_consol();
	void run();
private:
	std::vector<std::string> Acceptable_types_of_vehicles = { "Car", "car", "Boat", "boat", "Airplane", "airplane", "Spaceship", "spaceship" };
	std::vector<Vehicle>* vector_ptr;
	
	bool Checking_correct_number_input(std::string, int&);
	bool Checking_correct_types_of_vehicles(std::string&);

	// Command 1
	bool Creation();
	// Command 2
	bool Editing();
	// Command 3
	bool Deletion();
	// Command 4
	bool Display_with_sorting();
	// Command 5
	bool Search();
	// Command 6
	int Save();
	// Command 7
	int Load();
};

//class Vehicle
//{
//public:
//	Vehicle(std::string, std::string, int, int); // марка, модель, год выпуска, вес
//	~Vehicle();
//	int Get_id() { return id; }
//	int Get_id_counter() { return id_counter; }
//
//protected:
//	std::string Type;
//private:
//	static int id_counter;
//
//	int id;
//	std::string Brand;
//	std::string Model;
//	int Year_of_release;
//	int Weight;
//
//};
//
//class Car : public Vehicle
//{
//public:
//	Car(std::string, std::string, int, int, int, int); // + число владельцев, пробег
//	~Car();
//private:
//	int Number_of_owners;
//	int Mileage;
//};