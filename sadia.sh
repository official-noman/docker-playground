#!/bin/bash

#read -p"your nationality" nationality
#echo "hello, $nationality!"

#$echo "this is a line of text">output.txt

folder_name=$1

if [ -z "$folder_name" ]; then
	echo "Error: Please provide a folder name"
	exit 1
fi



if [ -d "$folder_name" ]; then
	echo "folder exists"
else
	mkdir "$folder_name"
	echo "Folder create done"
fi

