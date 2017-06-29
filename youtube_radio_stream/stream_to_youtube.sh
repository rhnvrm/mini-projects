#! /bin/bash

VBR="2500k"                                    
FPS="30"                                      
QUAL="ultrafast"                                
YOUTUBE_URL="rtmp://a.rtmp.youtube.com/live2"  

SOURCE_V="gif/wolfchilderenloopmp41.gif"
SOURCE_A="list.txt"
KEY="xxxx-xxxx-yyyy-yyyy" 


ffmpeg \
-re -f concat -safe 0 -i $SOURCE_A \
-ignore_loop 0 -i $SOURCE_V \
-vcodec libx264 -pix_fmt yuv420p -preset $QUAL -b:v $VBR \
-acodec libmp3lame -ar 44100 \
-threads 0 -bufsize 512k \
-f flv $YOUTUBE_URL/$KEY > stream_log.txt&