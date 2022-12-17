#include <iostream>
#include "getCurrencyJson.h"

using namespace std;

struct Currency {

	string name;
	int scale;
	string date;
	double rate;
};

string inputCurrency();

void jsonParcer(Currency&, string);

bool verifying(string&);

unsigned inputSum();

string transformToRequest(string&);

long double calcSumOut(Currency&, Currency&, unsigned&);
