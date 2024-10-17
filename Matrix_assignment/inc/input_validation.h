#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>

std::string trimSpaces(std::string &input);
bool validateChoice(std::string choice);
double validateFloatInput(std::string &input);
int validateIntegerInput(std::string &input);
int getInput(std::string floatOrInteger);
std::string getChoice();

#endif
