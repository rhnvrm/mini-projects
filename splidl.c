#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_func(void *ptr, size_t size, size_t nmemb, FILE *stream);

char RANGES[10][50] = {"0-9999", "10000-19999", "20000-29999", "30000-39999", "40000-49999", "50000-59999", "60000-69999", "70000-79999", "80000-89999", "90000-99999"};
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
        //double file_size = 0;

        char file_name[] = "file.pi";
        for(int i = 48; i < 48 + 10; i++){
          file_name[6] = (char)i; //printf("%s", file_name);
          outfile = fopen(file_name, "w");
          printf ( "downloading part %d from the url %s\n", i -48, url );
          curl_easy_setopt(curl, CURLOPT_URL, url);
          curl_easy_setopt(curl, CURLOPT_RANGE, RANGES[i-48]);
          printf("\nRANGE: %s\n", RANGES[i-48] );
          /*curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &file_size);
          printf("\n%lf bytes will be downloaded.\n", file_size);*/
          curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
          curl_easy_setopt(curl, CURLOPT_WRITEDATA, outfile);
          curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);

          res = curl_easy_perform(curl);
          fclose(outfile);
        }
        
    
        curl_easy_cleanup(curl);

        // https://dl.google.com/dl/android/studio/ide-zips/1.1.0/android-studio-ide-135.1740770-linux.zip
        // 26.3 http://nbsadminassist.com/wp-content/uploads/2013/10/Google_wordmark.gif 
        // 56.1 https://pandodaily.files.wordpress.com/2014/03/google-in-bed-w-mercenaries-n-military-e1395865855795.jpg
        //print the bytes downloaded

       
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
    printf("\nDownload of '%s' completed with '%s'", save, curl_easy_strerror(DownloadURL(url, save)));
    
}
