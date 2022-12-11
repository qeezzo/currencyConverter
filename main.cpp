#include <iostream>
#include "modules.h"
using namespace std;

int main() {
	string currencyIn;
	string currencyOut;
	unsigned long int sum;
	int	result;
	
	cout << "from :\t";
	currencyIn = inputCurrency();
	while (!verifying(currencyIn)){
		cout << "Error : incorect input data" << endl; 
		currencyIn = inputCurrency();
	}

	cout << "to   :\t";
	currencyOut = inputCurrency();
	while (!verifying(currencyOut)){
		cout << "Error : incorect input data" << endl; 
		currencyOut = inputCurrency();
	}

	cout << "sum  :\t";
	sum = inputSum();
	while (sum < 0){
		cout << "Error : incorect input data" << endl;

		cout << "sum  :\t";
		sum = inputSum();
	}

	char url[] = "https://www.nbrb.by/api/exrates/rates/USD?parammode=2";
	string currencyJson;
	currencyJson = getCurrencyJson(url);

	cout << "get json : " << currencyJson << endl;

	return 0;
}
