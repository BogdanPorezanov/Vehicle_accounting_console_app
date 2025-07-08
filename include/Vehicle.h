#pragma once

#include <iostream>
#include <string>

class Vehicle
{
public:
	Vehicle(std::string, std::string, int, int); // марка, модель, год выпуска, вес
	~Vehicle();

	//virtual std::string Get_Type() { return " "; };
	const int Get_id() { return id; }
	const int Get_id_counter() { return id_counter; }
	const virtual std::string Get_Type() = 0;
	const std::string Get_Brand() { return Brand; }
	const std::string Get_Model() { return Model; }
	const int Get_Year_of_release() { return Year_of_release; }
	const int Get_Weight() { return Weight; }
	const virtual int Get_Field_1_int() = 0;
	const virtual int Get_Field_2_int() = 0;
	const virtual std::string Get_Field_1_string() = 0;

	void Set_id_counter(int value) { this->id_counter = value; }

	const virtual void Display();
	virtual void Edit();
	const virtual std::string String_to_save();

protected:
	bool Edit_string(std::string, std::string&);
	bool Edit_number(std::string, int&);

	int id;
	std::string Brand;
	std::string Model;
	int Year_of_release;
	int Weight;

	std::string Dividing_symbol = ";";
private:
	static int id_counter;

	

};

class Car : public Vehicle
{
public:
	Car(std::string, std::string, int, int, int, int); // + число владельцев, пробег
	~Car();

	const std::string Get_Type() override { return "Car"; }
	int Get_Number_of_owners() { return Number_of_owners; }
	int Get_Mileage() { return Mileage; }
	const int Get_Field_1_int() override { return Number_of_owners; };
	const int Get_Field_2_int() override { return Mileage; };
	const virtual std::string Get_Field_1_string() override { return " "; };

	const void Display() override;
	void Edit() override;
	const std::string String_to_save() override;

private:
	int Number_of_owners;
	int Mileage;
};

class Boat : public Vehicle
{
public:
	Boat(std::string, std::string, int, int, int, int); // + водоизмещение, глубина погружения винта
	~Boat();

	const std::string Get_Type() override { return "Boat"; }
	int Get_Displacement() { return Displacement; }
	int Get_Propeller_immersion_depth() { return Propeller_immersion_depth; }
	const int Get_Field_1_int() override { return Displacement; };
	const int Get_Field_2_int() override { return Propeller_immersion_depth; };
	const virtual std::string Get_Field_1_string() override { return " "; };

	const void Display() override;
	void Edit() override;
	const std::string String_to_save() override;

private:
	int Displacement;
	int Propeller_immersion_depth;
};

class Airplane : public Vehicle
{
public:
	Airplane(std::string, std::string, int, int, int, int); // + грузоподъёмность, размах крыла
	~Airplane();

	const std::string Get_Type() override { return "Airplane"; }
	int Get_Cargo_capacity() { return Cargo_capacity; }
	int Get_Wingspan() { return Wingspan; }
	const int Get_Field_1_int() override { return Cargo_capacity; };
	const int Get_Field_2_int() override { return Wingspan; };
	const virtual std::string Get_Field_1_string() override { return " "; };

	const void Display() override;
	void Edit() override;
	const std::string String_to_save() override;

private:
	int Cargo_capacity;
	int Wingspan;
};

class Spaceship : public Vehicle
{
public:
	Spaceship(std::string, std::string, int, int, std::string, int); // + грузоподъёмность, размах крыла
	~Spaceship();

	const std::string Get_Type() override { return "Spaceship"; }
	std::string Get_Fuel_type() { return Fuel_type; }
	int Get_Hyperjump_range() { return Hyperjump_range; }
	const std::string Get_Field_1_string() override { return Fuel_type; };
	const int Get_Field_1_int() override { return 0; };
	const int Get_Field_2_int() override { return Hyperjump_range; };

	const void Display() override;
	void Edit() override;
	const std::string String_to_save() override;

private:
	std::string Fuel_type;
	int Hyperjump_range;
};
