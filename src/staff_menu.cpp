#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <utils.h>
#include <Member.h>

std::string STAFF_USERNAME = "staff";
std::string STAFF_PASSWORD = "today123";

bool login_to_staff_menu()
{
    while (true)
    {
        std::cout << "\n===========Staff Login=========" << std::endl;
        std::cout << "Enter staff username: ";
        std::string input_username;
        std::cin >> input_username;

        std::cout << "Enter staff password: ";
        std::string input_password;
        std::cin >> input_password;

        if (input_password != STAFF_PASSWORD || input_username != STAFF_USERNAME)
        {
            std::cout << "Login details are incorrect. Try again? (Y/N): ";
            if (!get_y_or_n())
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
}

void register_new_member()
{
    std::cout << "\n==============New Member=======" << std::endl;
    std::cout << "Enter first name: ";
    std::string first_name;
    std::cin >> first_name;

    std::cout << "Enter last name: ";
    std::string last_name;
    std::cin >> last_name;

    std::cout << "Enter phone number: ";
    std::string phone_number;
    std::cin >> phone_number;

    std::cout << "Enter password: ";
    int password;
    std::cin >> password;

    Member new_member(first_name, last_name, phone_number, password);
}

void staff_menu()
{
    std::cout << "===========Staff Menu==========" << std::endl;
    std::cout << " 1. Add a new movie DVD" << std::endl;
    std::cout << " 2. Remove a movie DVD" << std::endl;
    std::cout << " 3. Register a new Member" << std::endl;
    std::cout << " 4. Find a registered member's phone number" << std::endl;
    std::cout << " 0. Return to main menu" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "\nPlease make a selection (1, 2, 3, 4 or 0 to return to main menu): ";

    int valids[] = {1, 2, 3, 4, 0};
    int selection = get_menu_selection(valids, 5);

    if (selection == 0)
    {
        current_menu = MainMenu;
    }

    if(selection == 1){
        // add_new_movie();
    }

    if(selection == 2){
        // remove_movie();
    }

    if(selection == 3){
        register_new_member();
    }

    if(selection == 4){
        // find_member();
    }
}