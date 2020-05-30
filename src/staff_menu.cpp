#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <utils.h>
#include <Member.h>
#include <Movie.h>

/**
 * @brief Staff menu login details
 * 
 */
const std::string staffUsername = "staff";
const std::string staffPassword = "today123";
bool staff_logged_in = false;

/**
 * @brief Log the user into the staff menu
 * 
 */
void LoginToStaffMenu()
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

        if (input_password != staffPassword || input_username != staffUsername)
        {
            std::cout << "Login details are incorrect. Try again? (Y/N): ";
            if (!GetYesOrNo())
            {
                staff_logged_in = false;
                break;
            }
        }
        else
        {
            staff_logged_in = true;
            break;
        }
    }
    std::cout << std::endl;
}

/**
 * @brief Writes the staff menu to the output
 * 
 */
void WriteStaffMenu()
{
    std::cout << "===========Staff Menu==========" << std::endl;
    std::cout << " 1. Add a new movie DVD" << std::endl;
    std::cout << " 2. Remove a movie DVD" << std::endl;
    std::cout << " 3. Register a new Member" << std::endl;
    std::cout << " 4. Find a registered member's phone number" << std::endl;
    std::cout << " 0. Return to main menu" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "\nPlease make a selection (1, 2, 3, 4 or 0 to return to main menu): ";
}

/**
 * @brief Get a genre from a list of possible selections
 * 
 * @return std::string the selected genre
 */
std::string GetGenre()
{
    std::cout << "Select the genre" << std::endl;
    std::cout << " 1. Drama" << std::endl;
    std::cout << " 2. Adventure" << std::endl;
    std::cout << " 3. Family" << std::endl;
    std::cout << " 4. Action" << std::endl;
    std::cout << " 5. Sci-Fi" << std::endl;
    std::cout << " 6. Comedy" << std::endl;
    std::cout << " 7. Thriller" << std::endl;
    std::cout << " 8. Other" << std::endl;
    std::cout << "Make selection (1-8): ";

    int valids[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int selection = GetMenuSelection(valids, 8);

    if (selection == 1)
        return "Drama";
    if (selection == 2)
        return "Adventure";
    if (selection == 3)
        return "Family";
    if (selection == 4)
        return "Action";
    if (selection == 5)
        return "Sci-Fi";
    if (selection == 6)
        return "Comedy";
    if (selection == 7)
        return "Thriller";
    if (selection == 8)
        return "Other";

    throw std::invalid_argument("Invalid selection");
}

/**
 * @brief Get a classification from a list of possible selections
 * 
 * @return std::string the selected classifications
 */
std::string GetClassification()
{
    std::cout << "Select the classification: " << std::endl;
    std::cout << " 1. General (G)" << std::endl;
    std::cout << " 2. Parental Guidance (PG)" << std::endl;
    std::cout << " 3. Mature (M15+)" << std::endl;
    std::cout << " 4. Mature Accompanied (MA15+)" << std::endl;
    std::cout << "Make selection (1-4): ";

    int valids[] = {1, 2, 3, 4};
    int selection = GetMenuSelection(valids, 4);

    if (selection == 1)
        return "General (G)";
    if (selection == 2)
        return "Parental Guidance (PG)";
    if (selection == 3)
        return "Mature (M15+)";
    if (selection == 4)
        return "Mature Accompanied (MA15+)";

    throw std::invalid_argument("Invalid selection");
}

/**
 * @brief Gets a new movie from the user
 * 
 * @param title the title for the new movie
 * @return Movie* Pointer to the new movie object
 */
Movie *GetNewMovie(std::string title)
{
    bool valid = false;

    std::string director;
    GetLinePrompt("Enter the director(s): ", &director);

    std::string starring;
    GetLinePrompt("Enter the starring actor(s): ", &starring);

    std::string duration;
    while (!valid)
    {
        GetLinePrompt("Enter movie duration (minutes): ", &duration);
        if (!IsStringNumbersOnly(duration))
        {
            std::cout << "Bad entry. Enter minutes in numbers only." << std::endl;
        }
        else
        {
            valid = true;
        }
    }

    valid = false;
    std::string release_year;
    while (!valid)
    {
        GetLinePrompt("Enter the release date (year): ", &release_year);
        if (!IsStringNumbersOnly(release_year))
        {
            std::cout << "Bad entry. Enter release year in numbers only." << std::endl;
        }
        else if (release_year.length() != 4)
        {
            std::cout << "Bad entry. Year must be four digits." << std::endl;
        }
        else
        {
            valid = true;
        }
    }

    std::string genre = GetGenre();
    std::string classification = GetClassification();

    int copies;
    std::cout << "Enter the number of copies you wish to add: ";
    valid = false;
    while (!valid)
    {
        std::cin >> copies;
        if (std::cin.fail())
        {
            std::cout << "You must enter copies as a number." << std::endl;
            valid = false;
        }
        else
        {
            valid = true;
        }
    }

    Movie *movie = new Movie(title, director, starring, duration, genre, classification, release_year, copies);
    return movie;
}