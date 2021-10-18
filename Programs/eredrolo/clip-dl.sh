#!/bin/sh
echo 'Select download resolution (480/720/1080)'
read -r res
echo 'Enter starting time (hh:mm:ss)'
read -r start
echo 'Enter end time (hh:mm:ss)'
read -r end

url1=$(youtube-dl -gf "bestvideo[height<=$res]/best[height<=$res]" "$1")
url2=$(youtube-dl -gf "bestaudio" "$1")
title=$(youtube-dl -e "$1")

if [ "$url2" != null ] # Check if audio and video files are separate or not
then
         ffmpeg -ss "$start" -to "$end" -i "$url1" -ss "$start" -to "$end" -i "$url2" -c:v libx264 -crf 23 -c:a aac "$HOME/$title - ($start-$end).mp4"
else
         ffmpeg -ss "$start" -to "$end" -i "$url1" -c:v libx264 -crf 23 -c:a aac "$HOME/$title - ($start-$end).mp4"
fi

exit
