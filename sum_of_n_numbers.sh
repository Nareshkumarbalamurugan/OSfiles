echo "How many numbers do you want to enter:"
read n
sum=0
for((i=0;i<n;i++))
do
	echo "Enter a number:"
	read number
	((sum+=number))
done

echo "Sum of the given numbers is $sum"

