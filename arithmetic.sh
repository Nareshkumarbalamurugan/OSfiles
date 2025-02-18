while true;
do
	echo "Arithmetic operations menu"
	echo "1.Addition"
	echo "2.Subraction"
	echo "3.Multiplication"
	echo "4.Division"
	echo "5.Modulus"
	echo "6.Exit"
	echo "--------------------------"
	echo "Enter your choice(1-6):"
	read choice
	if [ "$choice" -eq 6 ]; then
		echo "Exiting the program"
		break
	fi

	echo "Enter the first number:"
	read a
	echo "Enter the second number:"
	read b


	case $choice in
		1)
			echo "Addition:$((a+b))"
			;;
		2)
			echo "Subraction:$((a-b))"
			;;
		3)
			echo "multiplication:$((a*b))"
			;;
		4)
			if [ "$b" -ne 0 ]; then
			echo "division:$((a/b))"
			else
			echo "Multiplication by 0 is not allowed"
			fi
			;;
		5)
			if [ "$b" -ne 0 ]; then
				echo "Modulus:$((a%b))"
			else
				echo "Modulus by 0 is not allowed"
			fi
			;;
		*)
			echo "Invalid option please enter from the given option"
			;;
		esac
done
