#include "modules.h"

string inputCurrency() {
	string currency;
	cin >> currency;

	for(int i{}; i< currency.length(); i++){
		if (currency[i] >= 'a' and currency[i] <= 'z')
			currency[i] = currency[i] - 32;

		// verifying incorrect symbols
		else if (!(currency[i] >= 'a' && currency[i] <= 'z') && !(currency[i] >= 'A' && currency[i] <= 'Z')){
			cout << "Error : incorrect input data : not even a letter!" << endl;
			cout << "to   :\t";
			return inputCurrency();
		}
	}

	return currency;
}


unsigned inputSum() {
	unsigned sum{};
	string sumStr{};

	cin >> sumStr;

	for (char* p{&sumStr[0]}; p < sumStr.length() + &sumStr[0]; p++){
		if (!(*p >= '0' && *p <= '9')){
			cout << "Error : incorrect input data : should be a positive number!" << endl;
			cout << "sum  :\t";
			return inputSum();
		}
	}

	sum = stoi(sumStr);

	return sum;
}
