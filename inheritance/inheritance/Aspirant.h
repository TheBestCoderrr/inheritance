#pragma once
#include "Student.h"
class Aspirant : public Student
{
public:
	Aspirant() : Student(nullptr, 0), candidateWork(nullptr) {}
	Aspirant(const char* name, size_t age, const char* cWork) : Student(name, age), candidateWork(cWork) {}
	void Show() const;
private:
	String candidateWork;
};

