#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <MemberCollection.h>

enum menu
{
    MainMenu,
    StaffMenu,
    MemberMenu,
    ExitProgram
};
menu current_menu;

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

void PrintInt(int int_to_print)
{
    std::cout << std::to_string(int_to_print) << std::endl;
}

void GetLinePrompt(std::string to_display, std::string *result)
{
    std::cout << to_display;
    getline(std::cin, *result);
}

bool IsDigit(char ch)
{
    return isdigit(static_cast<unsigned char>(ch));
}

int ToInt(char c)
{
    return c - 48;
}

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