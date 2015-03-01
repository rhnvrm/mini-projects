/*
 *           
 * 
 *      examples:
 *      //      mb https://dl.google.com/dl/android/studio/ide-zips/1.1.0/android-studio-ide-135.1740770-linux.zip
 *      // 56.1 kb https://pandodaily.files.wordpress.com/2014/03/google-in-bed-w-mercenaries-n-military-e1395865855795.jpg
 *      // 633  kb http://hdwallpaperd.com/wp-content/uploads/wallpaper-photos-61.jpg
 *      
 *      proof of concept example:
 *      // http://mirror.cse.iitk.ac.in/ubuntu/pool/multiverse/v/virtualbox-guest-additions-iso/virtualbox-guest-additions-iso_4.3.10-1_all.deb
 *
 */





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

char RANGES[10][50] = {"0-9999999", "10000000-19999999", "20000000-29999999", "30000000-39999999", "40000000-49999999", "50000000-59999999", "60000000-69999999", "70000000-79999999", "80000000-89999999", "90000000-99999999"};

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
        char file_name[] = "file.pi";
        for(int i = 48; i < 48 + 10; i++){
          file_name[6] = (char)i; //printf("%s", file_name);
          outfile = fopen(file_name, "w");
          printf ( "\nDownloading part %d from the url %s\n", i -48, url );
          curl_easy_setopt(curl, CURLOPT_URL, url);
          curl_easy_setopt(curl, CURLOPT_RANGE, RANGES[i-48]);
          printf("RANGE: %s\n", RANGES[i-48] );

          curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
          curl_easy_setopt(curl, CURLOPT_WRITEDATA, outfile);
          curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);

          res = curl_easy_perform(curl);
          fclose(outfile);
        }
        
        curl_easy_cleanup(curl);     
    }
    return res;
}



int main(void)
{
  
    /* TODO: Automate this save variable*/
    char url[1000];
    char save[500];
    char command[1000] = "cat file.p? > ";
    
    printf("url: ");
    scanf("%s", url);

    //loop for making the save variable
    //--- logic -> from last '/' till \0 = save
    int len = 0, t = 0;    
    for(; url[len] != '\0'; len++){;}
    while(url[len] != '/') len--;
    len++;
    for(; url[len]!= '\0'; len++, t++){
        save[t] = url[len];
    }
    save[t] = '\0';

    //download the file and print if any error occured
    printf("\nDownload of '%s' completed with '%s'", save, curl_easy_strerror(DownloadURL(url, save)));
    system(strcpy(command, save)); // join the files
    system("rm file.p?");
    
}
