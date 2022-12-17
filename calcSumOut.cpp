#include "modules.h"

long double calcSumOut(Currency& curIn, Currency& curOut, unsigned &sum)
{
	long double sumOut{};

	sumOut = sum * ((curIn.rate * curOut.scale) / (curOut.rate * curIn.scale));

	return sumOut;
}
