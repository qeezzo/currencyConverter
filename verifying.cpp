#include "modules.h"
#include <string>
#include <fstream>

bool verifying(string& currency)
{
	for(int i{}; i< currency.length(); i++){

		// verifying incorrect symbols
		if (!(currency[i] >= 'a' && currency[i] <= 'z') && !(currency[i] >= 'A' && currency[i] <= 'Z')){
			cout << "Error : incorrect input data : not even a letter!" << endl;
			return false;
		}
	}


	ifstream abb("abbreviations.txt");

	string line;

	if (currency.length() != 3){
		cout << "Error : abbreviation must be in 3 latin symbs" << endl;
		return false;
	}

	if (abb.is_open()){
		while (getline(abb, line)){
			if (line[0] == currency[0] &&
				line[1] == currency[1] &&
				line[2] == currency[2])
				return true;
		}
	}
	
	abb.close();

	cout << "Error : incorect input data" << endl; 

	return false;
}
