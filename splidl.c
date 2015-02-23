#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

size_t write_func(void *ptr, size_t size, size_t nmemb, FILE *stream);

CURLcode DownloadURL(char* url, const char* file);

//callback function for libcurl
size_t write_func(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
     return fwrite(ptr, size, nmemb, stream);
}

CURLcode DownloadURL(char* url, const char* file){
    CURL *curl;
    CURLcode res;
    FILE *outfile;
    curl = curl_easy_init();
    if(curl)
    {
        double file_size = 0;
        //curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &file_size);
        //printf("\n%lf bytes will be downloaded.\n", file_size);
        
        outfile = fopen(file, "w");
        printf ( "downloading the url %s\n", url );
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_RANGE, "0-2999");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, outfile);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(outfile);
        // http://aff.apk4fun.com/go.php?url=http%3A%2F%2Fwww11.zippyshare.com%2Fv%2F8881145%2Ffile.html
        //print the bytes downloaded

        curl_easy_getinfo(curl,CURLINFO_SIZE_DOWNLOAD,&file_size);
        printf("\n%lf bytes were downloaded.", file_size);
        
    }
    return res;
}



int main(void)
{
  
    /* TODO: Automate this save variable*/
    char url[1000];
    char save[255];
    
    printf("url: ");
    scanf("%s", url);
    printf("\nsave as: ");
    scanf("%s", save);
    
    //download the file and print if any error occured
    printf("\nDownload completed with '%s'", curl_easy_strerror(DownloadURL(url, save)));
    
}
