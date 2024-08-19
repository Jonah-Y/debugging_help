#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <WebAPI_Caller.h>
#include <curl/curl.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode result;
    string readBuffer;

        curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "HTTP request failed\n");
        return EXIT_FAILURE;
    }

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    
    // perform options
    result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
        return EXIT_FAILURE;
    }

    // Print result to show it works
    cout << readBuffer;

    curl_easy_cleanup(curl);

    WebAPI_Caller API_Caller;
    string result = API_Caller.call_Google();
    cout << result << endl;

    return 0;
}

