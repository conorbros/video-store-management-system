#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <utils.h>
#include <Member.h>

bool check_member_details(std::string username, std::string password)
{
    return true;
}

bool login_to_member_menu()
{
        while (true)
    {
        std::cout << "\n===========Staff Login=========" << std::endl;
        std::cout << "Enter username: ";
        std::string input_username;
        std::cin >> input_username;

        std::cout << "Enter password: ";
        std::string input_password;
        std::cin >> input_password;

        if ()
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

void member_menu(){
    std::cout << "===========Member Menu==========" << std::endl;
    std::cout << " 1. Display all movies" << std::endl;
    std::cout << " 2. Borrow a movie DVD" << std::endl;
    std::cout << " 3. Return a movie DVD" << std::endl;
    std::cout << " 4. List current borrowed DVD's" << std::endl;
    std::cout << " 5. Display top 10 most popular movies" << std::endl;
    std::cout << " 0. Return to main menu" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "\nPlease make a selection (1, 2, 3, 4, 5 or 0 to return to main menu): ";

    int valids[] = {1, 2, 3, 4, 5, 0};
    int selection = get_menu_selection(valids, 6);

    if(selection == 0){
        current_menu = MainMenu;
    }

    if(selection == 1){
        // display_all_movies()
    }

    if(selection == 2){
        // borrow a movie 
    }

    if(selection == 3)
    {
        // return_a_movie
    }

    if(selection == 4)
    {
        // list_current_movies
    }

    if(selection == 5)
    {
        // display top 10 most popular movies
    }
}