#include <iostream>
#include <iomanip>
#include "modules.h"
using namespace std;

int main() {
	string currencyIn;
	string currencyOut;
	unsigned sum;
	int	result;
	
	cout << "from :\t";
	currencyIn = inputCurrency();
	while (!verifying(currencyIn)){
		cout << "from :\t";
		currencyIn = inputCurrency();
	}

	cout << "to   :\t";
	currencyOut = inputCurrency();
	while (!verifying(currencyOut)){
		cout << "to   :\t";
		currencyOut = inputCurrency();
	}

	cout << "sum  :\t";
	sum = inputSum();

	Currency curIn, curOut;
	string urlIn, urlOut; 
	string currencyJsonIn, currencyJsonOut;

	urlIn = transformToRequest(currencyIn);
	urlOut = transformToRequest(currencyOut);

	currencyJsonIn = getCurrencyJson(urlIn);
	currencyJsonOut = getCurrencyJson(urlOut);

	jsonParcer(curIn, currencyJsonIn);
	jsonParcer(curOut, currencyJsonOut);


	//cout << "Name : " << curIn.name << endl;
	//cout << "Rate : " << curIn.rate << endl;
	//cout << "Date : " << curIn.date << endl;
	//cout << "Scle : " << curIn.scale << endl;

	//cout << "Name : " << curOut.name << endl;
	//cout << "Rate : " << curOut.rate << endl;
	//cout << "Date : " << curOut.date << endl;
	//cout << "Scle : " << curOut.scale << endl;

	long double sumOut{};
	sumOut = calcSumOut(curIn, curOut, sum);

	//system("clear");
	cout << endl;

	cout << sum << " " << curIn.name << " > " << curOut.name << endl;
	cout << "=== " << setprecision(4) << fixed << sumOut << " ===" << endl;


	return 0;
}
