#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <MemberCollection.h>

enum Menu
{
    MainMenu,
    StaffMenu,
    MemberMenu,
    ExitProgram
};
Menu current_menu;

/**
 * @brief Gets the user to press 0 to exit
 * 
 */
void ZeroToExit()
{
    std::cout << "Press 0 exit" << std::endl;
    while (true)
    {
        char input;
        std::cin >> input;
        if (input == '0')
            break;
    }
}

/**
 * @brief Checks if a number contains numbers only
 * 
 * @param str the string to check
 * @return true if the string is only numbers
 * @return false if the string is not only numbers
 */
bool IsStringNumbersOnly(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Displays a prompt and returns the user's input
 * 
 * @param to_display prompt to display
 * @param result pointer to return the result
 */
void GetLinePrompt(std::string to_display, std::string *result)
{
    std::cout << to_display;
    getline(std::cin, *result);
}

/**
 * @brief Returns whether a character is a digit or not
 * 
 * @param ch Character to check
 * @return true if the character is a digit
 * @return false if character is not a digit
 */
bool IsDigit(char ch)
{
    return isdigit(static_cast<unsigned char>(ch));
}

/**
 * @brief Converts a char to an int
 * 
 * @param c character to convert to an int
 * @return int converted character
 */
int ToInt(char c)
{
    return c - 48;
}

/**
 * @brief Checks if a menu input value is valid against a list of valid inputs
 * 
 * @param x input to check
 * @param valid_inputs  array of valid input
 * @param length length of the valid inputs array
 * @return true if the input is valid
 * @return false if the input is not valid
 */
bool IsMenuInputValid(char x, int valid_inputs[], int length)
{
    if (!IsDigit(x))
    {
        return false;
    }

    int n = ToInt(x);
    for (int i = 0; i < length; i++)
    {
        if (valid_inputs[i] == n)
        {
            return true;
        }
    };
    return false;
}

/**
 * @brief Converts a selection array to string for displaying in the input
 * 
 * @param array The array to convert to a string
 * @param length The length of the array to convert to a string
 * @return std::string The array converted to a string
 */
std::string SelectionArrayToString(int array[], int length)
{
    std::string result = "";
    for (int i = 0; i < length; i++)
    {
        std::string trail = ", ";
        if (i == length - 2)
        {
            trail = " or ";
        }

        if (i == length - 1)
        {
            trail = ": ";
        }

        result += std::to_string(array[i]) + trail;
    }
    return result;
}

/**
 * @brief Get "Y" or "N" from the user
 * 
 * @return true if Y is inputted
 * @return false if N is inputted
 */
bool GetYesOrNo()
{
    bool valid = false;
    bool result;

    while (!valid)
    {
        std::string input;
        std::cin >> input;

        if (input == "Y" || input == "y")
        {
            result = true;
            break;
        }

        if (input == "N" || input == "n")
        {
            result = false;
            break;
        }

        valid = false;
        std::cout << "You must enter Y or N: ";
    }
    return result;
}

/**
 * @brief Gets a selection
 * 
 * @param valid_inputs 
 * @param length 
 * @return int 
 */
int GetMenuSelection(int valid_inputs[], int length)
{
    std::string error_message = "Bad entry. Enter " + SelectionArrayToString(valid_inputs, length);
    char n;
    std::cin >> n;
    while (!IsDigit(n) || !IsMenuInputValid(n, valid_inputs, length))
    {
        std::cout << error_message;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> n;
    }
    return ToInt(n);
}