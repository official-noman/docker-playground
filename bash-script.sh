#!/bin/bash

echo "hello from bash file"

echo "todays date is $(date)"

# variable
name="Noman"
age=22

if [ $age -gt 21 ]; then
	echo "ur an adult & u can get married"
else
	echo "papa wil ........"
fi

read -p "do u wanna get married?" question
read -p "justify your ans" answer

echo "$question $answer"

#for loop
stdnt=(a,ab.mj,ki)
for st in "${stdnt[@]}"; do
	echo "std: $stdnt"
done


