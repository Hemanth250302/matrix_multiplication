#include "constants.h"
#include "input_validation.h"
#include <math.h>
#include <iostream>

std::string trimSpaces(std::string &input)
{
    int length = input.size();

    int start = 0;
    while (start < length && isspace(input[start]))
        start++;
    int end = length - 1;
    while (end > start && isspace(input[end]))
        end--;
    return input.substr(start, end - start + 1);
}

bool validateChoice(std::string choice)
{

    bool isValid = false;
    if (choice[0] == 'a' || choice[0] == 'm' || choice[0] == 'e')
    {
        if (choice.size() == 1)

            isValid = true;
    }
    return isValid;
}

double parseIntegralPart(std::string &input, int &index)
{
    double integralPart = 0;
    while (index < input.size() && input[index] != '.')
    {

        if (isdigit(input[index]))
        {
            integralPart = integralPart * 10 + (input[index] - '0');
            index++;
        }
        else
        {
            integralPart = error_invalid_input;
            break;
        }
    }
    return integralPart;
}

double parseDecimalPart(std::string &input, int &index)
{
    double decimalPart = 0.0;
    double multiplicationFactor = 0.1;
    int count = 1;
    while (index < input.size() && input[index] != '.')
    {
        if (isdigit(input[index]))
        {
            decimalPart = decimalPart + (input[index] - '0') * pow(multiplicationFactor, count);
            count++;
            index++;
        }
        else
        {
            decimalPart = error_invalid_input;
            break;
        }
    }
    return decimalPart;
}

double validateFloatInput(std::string &input)
{
    double result = 0;
    int sign = 1;
    double integralPart = 0;
    double decimalPart = 0;

    int index = 0;
    if (input[0] == '-')
    {
        sign = -1;
        index++;
    }
    else if (input[0] == '+')
    {
        index++;
    }
    if (!isdigit(input[index]))
    {
        result = error_invalid_input;
    }
    integralPart = parseIntegralPart(input, index);

    if (input[index] == '.')
    {
        index++;
        decimalPart = parseDecimalPart(input, index);
    }

    if (input[index] == '.')
    {
        decimalPart = error_invalid_input;
    }
    if (integralPart != error_invalid_input && decimalPart != error_invalid_input)
        result = sign * (integralPart + decimalPart);
    else
        result = error_invalid_input;
    return result;
}

int validateIntegerInput(std::string &input)
{
    int result = 0;
    int sign = 1;
    int integralPart = 0;
    int index = 0;
    if (input[index] == '-')
    {
        result = error_invalid_int_input;
    }
    else if (input[0] == '+')
    {
        index++;
    }

    if (!isdigit(input[index]))
    {
        result = error_invalid_int_input;
    }
    integralPart = parseIntegralPart(input, index);
    if (integralPart != error_invalid_input)
    {
        result = sign * integralPart;
    }
    else
        result = error_invalid_input;

    if (input[index] == '.')
    {
        result = error_invalid_int_input;
    }

    return result;
}

int getInput(std::string floatOrInteger)
{
    int result;
    int input1;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        input = trimSpaces(input);
        if (floatOrInteger == "int")
            input1 = validateIntegerInput(input);
        else
            input1 = validateFloatInput(input);
        if (input1 != error_invalid_input && input1 != error_invalid_int_input)
        {
            result = input1;
            break;
        }
        else
        {
            std::cout << "Invalid input!! Enter again:" << '\n';
        }
    }
    return result;
}

std::string getChoice()
{
    std::string choice;
    std::getline(std::cin, choice);
    choice = trimSpaces(choice);
    if (validateChoice(choice))
    {
        if (choice[0] == 'e')
        {
            std::cout << "Exiting from the program" << '\n';
            exit(1);
        }
        choice=choice;
    }
    else
    {
        std::cout << "invalid choice!!! try again" << '\n';
      return getChoice();
    }
    return choice; 
}