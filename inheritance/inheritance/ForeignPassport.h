#pragma once
#include "Passport.h"
class FPassport : public Passport
{
public:
	FPassport(PIB pib, char sex, Date bDate, Date eDate, Date iDate, String nationality, String authority, String iNum, String pNum, String VISAS) : 
		Passport(pib, sex, bDate, eDate, iDate, nationality, authority, iNum), passportNum(pNum), VISAS(VISAS) {};
	void Show() const;
private:
	String passportNum;
	String VISAS;
};

void FPassport::Show() const
{
	Passport::Show();
	cout << "passport number: " << passportNum << endl;
	cout << "VISAS: " << VISAS << endl;
}
