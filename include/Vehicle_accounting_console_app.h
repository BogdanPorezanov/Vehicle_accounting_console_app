#pragma once

#include <iostream>
#include <string>
//#include 

extern std::string Console_input_for_numbers;

inline void Parse_console_input();

bool Checking_for_the_correct_number_input(std::string, int&);

bool Command_1();
bool Command_2();
bool Command_3();
bool Command_4();
bool Command_5();
int Command_6();
int Command_7();

class Vehicle
{
public:
	Vehicle(std::string, std::string, int, int); // марка, модель, год выпуска, вес
	~Vehicle();
	int Get_id() { return id; }
	int Get_id_counter() { return id_counter; }

protected:
	std::string Type;
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