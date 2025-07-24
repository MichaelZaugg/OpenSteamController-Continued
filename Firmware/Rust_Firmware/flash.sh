#!/bin/bash

echo
echo Please enter Steam Controlller USB Mass Media directory \(e.g. /run/media/username/CRP DISABLD\)

read location

echo
echo Are you sure this is the correct location? \$ $location
echo \[Y / n\]

read confirmation

if [[ "$confirmation" == "Y" || "$confirmation" == "y" || -z "$confirmation" ]]; then
    echo
    dd conv=notrunc oflag=direct bs=512 if=./firmware/firmware.bin of="$location/firmware.bin"
elif [[ "$confirmation" == "N" || "$confirmation" == "n" ]]; then
    exit
else
    echo
    echo "Invalid input: $confirmation"
fi

echo
echo Firmware Successfully Written!