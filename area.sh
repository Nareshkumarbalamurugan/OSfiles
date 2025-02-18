#!/bin/bash

square_area() {
    area=$(( $1 * $1 ))
    echo "Area of the square is $area"
}

rectangle_area() {
    area=$(( $1 * $2 ))
    echo "Area of the rectangle is $area"
}

triangle_area() {
    area=$(( $1 * $2 / 2 ))
    echo "Area of the triangle is $area"
}

echo "Choose the shape to calculate the area:"
echo "1. Square"
echo "2. Rectangle"
echo "3. Triangle"
read -p "Enter your choice (1/2/3): " choice

case $choice in
    1)
        echo "Enter the side length of the square:"
        read side
        square_area $side
        ;;
    2)
        echo "Enter the length of the rectangle:"
        read length
        echo "Enter the width of the rectangle:"
        read width
        rectangle_area $length $width
        ;;
    3)
        echo "Enter the base of the triangle:"
        read base
        echo "Enter the height of the triangle:"
        read height
        triangle_area $base $height
        ;;
    *)
        echo "Invalid choice, please enter 1, 2, or 3."
        ;;
esac

