#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

size_t write_func(void *ptr, size_t size, size_t nmemb, FILE *stream);

void DownloadURL(char* url, const char* file);

//callback function for libcurl
size_t write_func(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
     return fwrite(ptr, size, nmemb, stream);
}

void DownloadURL(char* url, const char* file){
    CURL *curl;
    CURLcode res;
    FILE *outfile;
    curl = curl_easy_init();
    if(curl)
    {
        outfile = fopen(file, "w");
        printf ( "downloading the url %s\n", url );
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, outfile);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(outfile);
    }
}



int main(void)
{
    char *url = "https://github.com/rhnvrm/splidl/archive/master.zip";
    DownloadURL(url, "master.zip");

}
