#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <utils.h>
#include <Member.h>

bool member_logged_in = false;

/**
 * @brief Writes the member menu to the screen
 * 
 */
void WriteMemberMenu()
{
    std::cout << "===========Member Menu==========" << std::endl;
    std::cout << " 1. Display all movies" << std::endl;
    std::cout << " 2. Borrow a movie DVD" << std::endl;
    std::cout << " 3. Return a movie DVD" << std::endl;
    std::cout << " 4. List current borrowed DVD's" << std::endl;
    std::cout << " 5. Display top 10 most popular movies" << std::endl;
    std::cout << " 0. Return to main menu" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "\nPlease make a selection (1, 2, 3, 4, 5 or 0 to return to main menu): ";
}
