#include "modules.h"
#include <exception>
#include <string>
#include <fstream>

bool verifying(string& currency)
{
	ifstream abb("abbreviations.txt");

	string line;

	if (currency.length() != 3)
		return false;

	if (abb.is_open()){
		while (getline(abb, line)){
			if (line[0] == currency[0] &&
				line[1] == currency[1] &&
				line[2] == currency[2])
				return true;
		}
	}

	abb.close();

	return false;
}
