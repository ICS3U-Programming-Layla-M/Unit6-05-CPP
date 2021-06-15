// Copyright (c) 2021 Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: June 15, 2021
// This program asks the user to enter different marks and then calculates the
// average

#include <math.h>
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <iterator>

float calcAverage(std::list<int> listOfMarks) {
    // calculates the average of the sum of every number
    // in a list and returns it
    // returns -1 if the list is empty
    int sum = 0;
    float average = -1;

    // calculate the sum of the numbers in the list
    for (int number : listOfMarks) {
        sum += number;
    }

    if (listOfMarks.size() == 0) {
        // error message if list is empty
        throw std::runtime_error(" Cannot calculate the average of \
an empty list.");
    } else {
        // calculate the average of the list
        int size = listOfMarks.size();
        average = static_cast<float>(sum) / static_cast<float>(size);
    }

    return average;
}


int main() {
    // declare variables
    std::list<int> markList;
    std::string userMarkString, listString = "", numberString;
    int userMarkInt, counter = 0, number;
    float userMarkFloat, userAverage;

    // display greeting
    std::cout << "This program calculates the average of different marks.\n";
    std::cout << "\n";

    while (true) {
        // ask the user to enter marks
        std::cout << "Enter a mark between 0 to 100 (enter '-1' to stop): ";
        std::cin >> userMarkString;

        try {
            // convert from string to int
            userMarkInt = std::stoi(userMarkString);

            // convert from string to float
            userMarkFloat = std::stof(userMarkString);

            if (userMarkInt == -1) {
                // break if the user enters -1
                break;
            } else if (userMarkInt < 0 || userMarkInt > 100) {
                // error message if mark is out of range
                std::cout << userMarkInt << " is not between 0 and 100, ";
                std::cout << "try again.\n";
            } else if (userMarkFloat != userMarkInt) {
                // error message if mark is a decimal
                std::cout << userMarkString << " is not a whole number, ";
                std::cout << "try again.\n";
            } else {
                // add mark to list
                markList.push_back(userMarkInt);
            }
        } catch (std::invalid_argument) {
            // error message if mark is not a number
            std::cout << userMarkString << " is not a whole number, ";
            std::cout << "try again.\n";
        }
    }

    std::cout << "\n";

    try {
        // call calcAverage function
        userAverage = calcAverage(markList);
        userAverage = round(userAverage);

        // display the list the same way as in Python
        auto iter = markList.begin();
        auto iterEnd = (++markList.rbegin()).base();
        std::cout << "For the list of marks: [";
        while (iter != markList.end()) {
            if (iter == iterEnd) {
                number = *iter;
                std::cout << number << "]\n";
                break;
            } else {
                number = *iter;
                std::cout << number << ", ";
                iter++;
            }
        }

        // display the average
        std::cout << "The average is: " << userAverage << ".\n";
    } catch (std::runtime_error& e) {
        // error message if list is empty
        std::cout << "Exception occured."
                  << e.what();
    }
}
