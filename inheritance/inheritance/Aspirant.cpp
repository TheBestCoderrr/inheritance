#include "Aspirant.h"

void Aspirant::Show() const
{
	Student::Show();
	cout << "Candidate work: " << candidateWork << endl;
}
