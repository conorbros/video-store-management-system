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

MemberCollection member_collection;

bool is_digit(char ch)
{
    return isdigit(static_cast<unsigned char>(ch));
}

int to_int(char c)
{
    return c - 48;
}

bool is_menu_input_valid(char x, int valid_inputs[], int length)
{
    if (!is_digit(x))
    {
        return false;
    }

    int n = to_int(x);
    for (int i = 0; i < length; i++)
    {
        if (valid_inputs[i] == n)
        {
            return true;
        }
    };
    return false;
}

std::string selection_array_to_string(int array[], int length)
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
            trail = ":";
        }

        result += std::to_string(array[i]) + trail;
    }
    return result;
}

bool get_y_or_n()
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

int get_menu_selection(int valid_inputs[], int length)
{
    std::string error_message = "Bad entry. Enter " + selection_array_to_string(valid_inputs, length);
    char n;
    std::cin >> n;
    while (!is_digit(n) || !is_menu_input_valid(n, valid_inputs, length))
    {
        std::cout << error_message;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> n;
    }
    return to_int(n);
}