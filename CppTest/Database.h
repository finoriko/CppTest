#pragma once
#include <iostream>
#include <vector>
#include "Empolyee.h"

namespace Records
{
	const int kFirstEmployeeNumber = 1000;
	class Database
	{
	public:
		Employee& addEmployee(const std::string& firstName,const std::string& lastName);
		Employee& getEmployee(int emplyeeNumber);
		Employee& getEmployee(const std::string& firstName, const std::string& lastName);
		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber = kFirstEmployeeNumber;
	};
}