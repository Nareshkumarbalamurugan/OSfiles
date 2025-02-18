#!/bin/bash
read -p "Enter the number of elements: " n
for (( i=0; i<n; i++ ))
do
  read -p "Enter element $((i+1)): " arr[$i]
done

min=${arr[0]}
max=${arr[0]}

for i in "${arr[@]}"
do
  if (( i < min )); then
    min=$i
  fi
  if (( i > max )); then
    max=$i
  fi
done

echo "Min: $min"
echo "Max: $max"

