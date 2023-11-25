#include "Aspirant.h"
#include "ForeignPassport.h"

int main() {
	srand(time(0));
	Aspirant as("Tom", 21, "Work");
	for (size_t i = 0; i < rand() % 10 + 5; i++)
		as.AddMark(rand() % 12 + 1);
	as.Show();
	cout << endl;
	FPassport passport(PIB("Artem", "Dovzhenko", "Romanovich"), 'M', Date(15, 3, 2010), Date(27, 9, 2026), Date(27, 9, 2022), "UKR", "0470", "0467045-5654", "FH3766523", "No VISA");
	passport.Show();
}