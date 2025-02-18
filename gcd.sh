#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter second number: " num2

while (( num2 != 0 ))
do
  temp=$num2
  num2=$(( num1 % num2 ))
  num1=$temp
done

echo "GCD: $num1"

