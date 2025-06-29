#pragma once

#include <string>

class Vehicle
{
public:
	Vehicle(std::string, std::string, int, int); // �����, ������, ��� �������, ���
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
	Car(std::string, std::string, int, int, int, int); // + ����� ����������, ������
	~Car();
private:
	int Number_of_owners;
	int Mileage;
};