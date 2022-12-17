#include "modules.h"

void jsonParcer(Currency& cur, string json)
{
	for (char* p{&json[0]};  p < &json[0] + json.length(); p++){

		string tmpKey {};
		string tmpValue {};

		// getting key and value from json
		if (*p == '\"'){
			p++;
			// key
			while (*p != '\"'){
				tmpKey += *p;
				p++;
			}
			p += 2;

			// value string
			if (*p == '\"'){
				p++;
				while (*p != '\"'){
					tmpValue += *p;
					p++;
				}
			} else {
				while(*p != ',' && *p != '}'){
					tmpValue += *p;
					++p;
				}
			}

			// write into struct
			if 		(tmpKey == "Date")
				cur.date = tmpValue;
			else if (tmpKey == "Cur_Name"s)
				cur.name = tmpValue;
			else if (tmpKey == "Cur_Scale"s)
				cur.scale = stoi(tmpValue);
			else if (tmpKey == "Cur_OfficialRate"s)
				cur.rate = stod(tmpValue);
		}

	}
}
