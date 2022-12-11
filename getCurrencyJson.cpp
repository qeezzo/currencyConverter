#include "modules.h"
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string getCurrencyJson(char url[])
{
	CURL *curl = curl_easy_init();

	CURLcode response;

	string readBuffer;

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		response = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}


	return readBuffer;
}
