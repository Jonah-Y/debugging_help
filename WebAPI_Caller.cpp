#include "WebAPI_Caller.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;

WebAPI_Caller::WebAPI_Caller()
{
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "HTTP request failed. Connect to internet and restart program.\n");
        throw string("HTTP request failed");
    }
}

WebAPI_Caller::~WebAPI_Caller()
{
    curl_easy_cleanup(curl);
}

size_t WebAPI_Caller::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Returns the data from call to https://www.google.com
string WebAPI_Caller::call_Google() {

    string url = "https://www.google.com";

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WebAPI_Caller::WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    
    // perform options
    result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
        // TODO throw exception?
    }

    // Return results to show it works
    return readBuffer;
}