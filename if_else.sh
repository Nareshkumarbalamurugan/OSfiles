echo "enter a number:"
read n 
if [ $((n%2)) -eq 0 ];then
	echo "given number is even"
else
	echo "given number is odd"
fi
