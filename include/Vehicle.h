#pragma once

#include <iostream>
#include <string>

class Vehicle
{
public:
	Vehicle(std::string, std::string, int, int); // марка, модель, год выпуска, вес
	~Vehicle();

	int Get_id() { return id; }
	int Get_id_counter() { return id_counter; }
	virtual std::string Get_Type() = 0;
	std::string Get_Brand() { return Brand; }
	std::string Get_Model() { return Model; }
	int Get_Year_of_release() { return Year_of_release; }
	int Get_Weight() { return Weight; }

	virtual void Display();

protected:
	//std::string Type;

	int id;
	std::string Brand;
	std::string Model;
	int Year_of_release;
	int Weight;
private:
	static int id_counter;

	

};

class Car : public Vehicle
{
public:
	Car(std::string, std::string, int, int, int, int); // + число владельцев, пробег
	~Car();
	std::string Get_Type() override { return "Car"; }
	int Get_Number_of_owners() { return Number_of_owners; }
	int Get_Mileage() { return Mileage; }

private:
	int Number_of_owners;
	int Mileage;
};

class Boat : public Vehicle
{
public:
	Boat(std::string, std::string, int, int, int, int); // + водоизмещение, глубина погружения винта
	~Boat();
	std::string Get_Type() override { return "Boat"; }
	int Get_Displacement() { return Displacement; }
	int Get_Propeller_immersion_depth() { return Propeller_immersion_depth; }

private:
	int Displacement;
	int Propeller_immersion_depth;
};

class Airplane : public Vehicle
{
public:
	Airplane(std::string, std::string, int, int, int, int); // + грузоподъёмность, размах крыла
	~Airplane();
	std::string Get_Type() override { return "Airplane"; }
	int Get_Cargo_capacity() { return Cargo_capacity; }
	int Get_Wingspan() { return Wingspan; }

private:
	int Cargo_capacity;
	int Wingspan;
};

class Spaceship : public Vehicle
{
public:
	Spaceship(std::string, std::string, int, int, std::string, int); // + грузоподъёмность, размах крыла
	~Spaceship();
	std::string Get_Type() override { return "Spaceship"; }
	std::string Get_Fuel_type() { return Fuel_type; }
	int Get_Hyperjump_range() { return Hyperjump_range; }

private:
	std::string Fuel_type;
	int Hyperjump_range;
};
