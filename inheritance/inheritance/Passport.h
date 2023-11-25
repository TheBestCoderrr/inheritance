#pragma once
#include "String.h"
class PIB {
public:
	PIB(String fname, String lname, String sname) : fname(fname), lname(lname), sname(sname) {}
	PIB(const PIB& other) { *this = other; }
	String fname, lname, sname;
	PIB& operator=(const PIB& other) {
		fname = other.fname;
		lname = other.lname;
		sname = other.sname;
		return *this;
	}
};

class Date {
public:
	Date(size_t day, size_t mon, size_t year) : day(day), mon(mon), year(year) {}
	Date(const Date& other) { *this = other; }
	size_t day, mon, year;
	Date& operator=(const Date& other) {
		day = other.day;
		mon = other.mon;
		year = other.year;
		return *this;
	}
};

class Passport
{
public:
	Passport(PIB pib, char sex, Date bDate, Date eDate, Date iDate , String nationality, String authority,  String iNum) : pib(pib), sex(sex), 
		birthDate(bDate), expiryDate(eDate), issueDate(iDate), nationality(nationality), authority(authority), identifyNum(iNum) {};
	void Show() const;
protected:
	PIB pib;
	char sex;
	Date birthDate;
	Date expiryDate;
	Date issueDate;
	String nationality;
	String authority;
	String identifyNum;
};

void Passport::Show() const
{
	cout << "PIB: " << pib.fname << " " << pib.lname << " " << pib.sname << endl;
	cout << "sex: " << sex << endl;
	cout << "Date of Birth: " << birthDate.day << "." << birthDate.mon << "." << birthDate.year << endl;
	cout << "Date of expiry: " << expiryDate.day << "." << expiryDate.mon << "." << expiryDate.year << endl;
	cout << "Date of issue: " << issueDate.day << "." << issueDate.mon << "." << issueDate.year << endl;
	cout << "nationality: " << nationality << endl;
	cout << "authority: " << authority << endl;
	cout << "identify number: " << identifyNum << endl;
}

