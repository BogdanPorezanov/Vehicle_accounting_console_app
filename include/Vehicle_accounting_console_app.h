#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vehicle.h"

class Parse_consol
{
public:
	Parse_consol();
	//Parse_consol(std::vector<Vehicle>);
	~Parse_consol();
	void run();
private:
	//std::vector<std::string> Acceptable_types_of_vehicles = { "Car", "car", "Boat", "boat", "Airplane", "airplane", "Spaceship", "spaceship" };
	std::vector<Vehicle> Table;

	std::fstream fs;
	
	bool Checking_correct_number_input(std::string, int&);
	bool Checking_correct_number_short(std::string, int&);
	bool Checking_correct_number_short(int&);
	bool Checking_correct_types_of_vehicles(int&);
	void Displaying_table_header();

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
