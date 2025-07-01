#pragma once

#include <string>
#include <map>
#include <variant>

class Vehicle
{
public:
	Vehicle(std::string, std::string, int, int); // марка, модель, год выпуска, вес
	~Vehicle();
	int Get_id_counter() { return id_counter; }

protected:
	//std::string Type;
	std::map<std::string, std::variant<std::string, int>> Table_fields;
private:
	static int id_counter;
	
	/*int id;
	std::string Brand;
	std::string Model;
	int Year_of_release;
	int Weight;*/

};

class Car : public Vehicle
{
public:
	Car(std::string, std::string, int, int, int, int); // + число владельцев, пробег
	~Car();
private:
	/*int Number_of_owners;
	int Mileage;*/
};

class Boat : public Vehicle
{
public:
	Boat(std::string, std::string, int, int, int, int); // + водоизмещение, глубина погружения винта
	~Boat();

private:
	/*int Displacement;
	int Propeller_immersion_depth;*/
};

class Airplane : public Vehicle
{
public:
	Airplane(std::string, std::string, int, int, int, int); // + грузоподъёмность, размах крыла
	~Airplane();

private:
	/*int Cargo_capacity;
	int Wingspan;*/
};

class Spaceship : public Vehicle
{
public:
	Spaceship(std::string, std::string, int, int, std::string, int); // + грузоподъёмность, размах крыла
	~Spaceship();

private:
	/*std::string Fuel_type;
	int Hyperjump_range;*/
};
