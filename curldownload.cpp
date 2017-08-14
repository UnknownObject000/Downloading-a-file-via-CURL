/*

* Download a file from url and overwrite the current one 
* My GitHub: https://github.com/thejimmster

*/

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include "curl\curl.h"
#include <iostream>
#include <string>
#pragma comment (lib, "libcurl.lib")
#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "wldap32.lib") 
size_t writefile(void *ptr, size_t size, size_t n, FILE *file)
{
	size_t written = fwrite(ptr, size, n, file);
	return written;
}
int main()
{
	CURL *curl = curl_easy_init();
	CURLcode ccode;
	char url[] = "http://localhost/program.exe";
	FILE *outputfile;
	if (curl)
	{
		outputfile = fopen("program.exe", "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefile);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputfile);
		ccode = curl_easy_perform(curl);
		fclose(outputfile);
	}
	return 0;
}
