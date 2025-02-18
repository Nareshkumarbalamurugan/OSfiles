#!/bin/bash
odd_even_func(){
	if(( $1 % 2 ==  0 )); then
		echo "$1 is even"
	else
		echo "$1 is odd"
	fi
}

echo "enter a number:"
read num

odd_even_func $num
	

