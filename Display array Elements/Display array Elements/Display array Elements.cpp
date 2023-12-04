// Display array Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//jgavina@cnm.edu Jamie Gavina

#include <iostream>
#include <iomanip>

int main() {
    // Course header
    std::cout << "Name: Your Name\n";
    std::cout << "Program Title: DisplayArrayElements\n";
    std::cout << "Program Objective: To practice simple array skills.\n";

    // Declare an array of six doubles
    double arr[6];

    // Ask the user for six floating point numbers
    std::cout << "Enter six floating point numbers separated by commas: ";
    for (int i = 0; i < 6; i++) {
        std::cin >> arr[i];
    }

    // Display the numbers in the array
    std::cout << "The numbers in the array are:\n";
    for (int i = 0; i < 6; i++) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << std::endl;
    }

    // Say goodbye
    std::cout << "Goodbye!\n";

    return 0;
}