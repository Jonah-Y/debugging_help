#include <string>
#include <curl/curl.h>
#ifndef WEBAPI_CALLER_H
#define WEBAPI_CALLER_H

#pragma once

using namespace std;

class WebAPI_Caller
{
private:
    CURL *curl;
    CURLcode result;
    string readBuffer;
    size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

public:
    WebAPI_Caller();
    ~WebAPI_Caller();
    string call_Google();

};

#endif