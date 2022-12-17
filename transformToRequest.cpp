#include "modules.h"
#include <cstring>

string transformToRequest(string& currency)
{
	string url {"https://www.nbrb.by/api/exrates/rates/" + currency + "?parammode=2"};

	return url;
}
