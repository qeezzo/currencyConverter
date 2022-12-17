#include <iostream>
#include "getCurrencyJson.h"

using namespace std;

struct Currency {

	string name {"Белорусский Рубль"};
	int scale {1};
	string date;
	double rate {1.0};
};

string inputCurrency();

void jsonParcer(Currency&, string);

bool verifying(string&);

unsigned inputSum();

string transformToRequest(string&);

long double calcSumOut(Currency&, Currency&, unsigned&);
