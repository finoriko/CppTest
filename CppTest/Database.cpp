#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
namespace Records
{
	Employee& Records::Database::addEmployee(const std::string& firstName, const std::string& lastName)
	{
		Employee theEmployee(firstName, lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Records::Database::getEmployee(int emplyeeNumber)
	{
		for (auto& employee : mEmployees)
		{
			if (employee.getEmployeeNumber() == emplyeeNumber)
			{
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	Employee& Records::Database::getEmployee(const std::string& firstName, const std::string& lastName)
	{
		for (auto& employee : mEmployees)
		{
			if (employee.getFirstName() == firstName && employee.getLastName()==lastName)
			{
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	void Records::Database::displayAll() const
	{
		for (const auto& employee : mEmployees)
		{
			employee.display();
		}
	}

	void Records::Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees)
		{
			if (employee.isHired())
			{
				employee.display();
			}
		}
	}

	void Records::Database::displayFormer() const
	{
		for (const auto& employee : mEmployees)
		{
			if (!employee.isHired())
			{
				employee.display();
			}
		}
	}
}


