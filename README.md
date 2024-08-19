#Why does curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); work in main(), but
curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WebAPI_Caller::WriteCallback); does not work when
its wrapped inside a class?
