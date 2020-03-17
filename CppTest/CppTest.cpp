// CppTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
	Database employeeDB;
	bool done = false;
	while (!done)
	{
		int selection = displayMenu();
		switch (selection)
		{
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cout << "Unknown command." << endl;
			break;
		}
	}
	return 0;


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employees" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employeess" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> " << endl;
	cin >> selection;
	return selection;
}
void doHire(Database& db)
{
	string firstName;
	string lastName;

	cout << "First name?";
	cin >> firstName;

	cout << "Last name?";
	cin >> lastName;
	db.addEmployee(firstName, lastName);
}

void doFire(Database& db)
{
	int employeeNumber;

	cout << "Employee Number?";
	cin >> employeeNumber;

	try
	{
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " terminated." << endl;
	}
	catch (const std::logic_error& exeception)
	{
		cerr << "Unable to terminate employee: " << exeception.what() << endl;
	}
}

void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;

	cout << "How much of a raise?";
	cin >> raiseAmount;
	try
	{
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error & exeception)
	{
		cerr << "Unable to terminate employee: " << exeception.what() << endl;
	}
}

void doDemote(Database& db)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;

	cout << "How much of a reduce?";
	cin >> raiseAmount;
	try
	{
		Employee& emp = db.getEmployee(employeeNumber);
		emp.demote(raiseAmount);
	}
	catch (const std::logic_error & exeception)
	{
		cerr << "Unable to terminate employee: " << exeception.what() << endl;
	}
}
