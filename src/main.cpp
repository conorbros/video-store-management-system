#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <utils.h>
#include <limits>
#include <staff_menu.h>
#include <MemberCollection.h>
#include <MovieCollection.h>
#include <member_menu.h>

MemberCollection member_collection;
MovieCollection movie_collection = MovieCollection();
std::string current_member_username;

Member *GetCurrentMember()
{
   return member_collection.GetMember(current_member_username);
}

void AddDummyData()
{
   Member *new_member = new Member("c", "b", "test street", "123456789", 1234);
   member_collection.RegisterMember(new_member);

   Movie *movie = new Movie("Movie 1", "Director", "Starting", "100", "Drama", "General", "1998", 5, 1);
   movie_collection.InsertMovie(movie);
   movie = new Movie("Movie 2", "Director", "Starting", "100", "Drama", "General", "1998", 5, 2);
   movie_collection.InsertMovie(movie);

   movie = new Movie("Movie 3", "Director", "Starting", "100", "Drama", "General", "1998", 5, 3);
   movie_collection.InsertMovie(movie);

   movie = new Movie("Movie 4", "Director", "Starting", "100", "Drama", "General", "1998", 5, 6);
   movie_collection.InsertMovie(movie);

   movie = new Movie("Movie 5", "Director", "Starting", "100", "Drama", "General", "1998", 5, 5);
   movie_collection.InsertMovie(movie);
}

void LoginToMemberMenu()
{
   while (true)
   {
      std::cout << "\n===========Member Login=========" << std::endl;
      std::cout << "Enter your username (LastNameFirstname): ";
      std::string input_username;
      std::cin >> input_username;

      std::cout << "Enter password: ";
      int input_password;
      std::cin >> input_password;

      if (!member_collection.CheckMemberDetails(input_username, input_password))
      {
         std::cout << "Login details are incorrect. Try again? (Y/N): ";
         if (!GetYesOrNo())
         {
            member_logged_in = false;
            return;
         }
      }
      else
      {
         current_member_username = member_collection.GetMember(input_username)->username;
         member_logged_in = true;
         return;
      }
   }
}

void DisplayAllMovies()
{
   std::cout << std::endl;
   std::cout << "============Display all movies========" << std::endl;
   std::cout << std::endl;
   movie_collection.DisplayMoviesInOrder();
   std::cout << std::endl;

   ZeroToExit();
}

void ReturnMovie()
{
   std::cout << std::endl;
   std::cin.ignore();
   std::cout << "===========Return a movie=============" << std::endl;
   std::string title;
   GetLinePrompt("Enter movie title:", &title);

   Movie *movie = movie_collection.GetMovie(title);
   movie->copies = movie->copies + 1;

   GetCurrentMember()->RemoveMovieFromCurrentMovies(movie);
   std::cout << "You returned " + movie->title << std::endl;
}

void BorrowAMovie()
{
   std::cout << std::endl;

   std::cout << "===========Borrow movie=========" << std::endl;
   std::string title;
   std::cin.ignore();

   bool valid = true;
   do
   {
      GetLinePrompt("Enter movie title:", &title);
      if (!movie_collection.DoesMovieExist(title))
      {
         std::cout << "Movie does not exist in library." << std::endl;
         valid = false;
      }
      else
      {
         valid = true;
      }
   } while (!valid);

   Member *member = GetCurrentMember();
   Movie *movie = movie_collection.GetMovie(title);
   movie->copies = movie->copies - 1;
   member->current_movies.push_back(movie);

   std::cout << "You borrowed " + movie->title << std::endl;
   std::cout << std::endl;
}

void ShowMemberMenu()
{
   WriteMemberMenu();
   int valids[] = {1, 2, 3, 4, 5, 0};
   int selection = GetMenuSelection(valids, 6);

   if (selection == 0)
   {
      current_menu = MainMenu;
   }

   if (selection == 1)
   {
      DisplayAllMovies();
   }

   if (selection == 2)
   {
      BorrowAMovie();
   }

   if (selection == 3)
   {
      ReturnMovie();
   }

   // Print Current movies
   if (selection == 4)
   {
      std::cout << std::endl;
      GetCurrentMember()->PrintCurrentMovies();
      ZeroToExit();
   }

   if (selection == 5)
   {
      // display top 10 most popular movies
   }
}

void RegisterNewMember()
{
   std::cout << "\n==============New Member=======" << std::endl;
   std::cout << "Enter member's first name: ";
   std::string first_name;
   std::cin >> first_name;

   std::cout << "Enter member's last name: ";
   std::string last_name;
   std::cin >> last_name;

   std::cin.ignore();
   std::cin.clear();

   if (member_collection.DoesMemberExist(last_name + first_name))
   {
      std::cout << first_name + " " + last_name + " has already registered." << std::endl;
      ZeroToExit();
   }

   std::cout << "Enter member's address: ";
   std::string address;
   std::cin >> address;

   std::string phone_number;
   bool valid = true;
   do
   {
      std::cout << "Enter member's phone number: ";
      std::cin >> phone_number;
      if (!IsStringNumbersOnly(phone_number))
      {
         std::cout << "Phone number must be numbers only." << std::endl;
         valid = false;
      }
      else
      {
         valid = true;
      }
   } while (!valid);

   std::string password_input;
   valid = true;
   do
   {
      std::cout << "Enter member's password(4 digits): ";
      std::cin >> password_input;

      if (!IsStringNumbersOnly(password_input) || password_input.length() > 4 || password_input.length() < 4)
      {
         std::cout << "Password must be 4 digits." << std::endl;
         valid = false;
      }
      else
      {
         valid = true;
      }

   } while (!valid);
   int password = std::stoi(password_input);

   Member *new_member = new Member(first_name, last_name, address, phone_number, password);

   member_collection.RegisterMember(new_member);
}

void FindMember()
{
   std::cout << "\n==============Find Member=======" << std::endl;

   std::string first_name, last_name, username;

   bool valid = true;
   do
   {
      std::cout << "Enter member's first name: ";
      std::cin >> first_name;

      std::cout << "Enter member's last name: ";
      std::cin >> last_name;
      username = last_name + first_name;

      if (!member_collection.DoesMemberExist(username))
      {
         std::cout << "Member with that username does not exist." << std::endl;
         valid = false;
      }
      else
      {
         valid = true;
      }
   } while (!valid);

   std::string phone_number = member_collection.GetMemberPhoneNumber(username);
   std::cout << first_name + " " + last_name + "Phone number: " + phone_number << std::endl;

   ZeroToExit();
}

void RemoveMovie()
{
   std::cout << "\n==============Remove Movie=======" << std::endl;

   bool valid = true;
   std::string title;
   std::cin.ignore();
   do
   {

      GetLinePrompt("Enter the movie title: ", &title);

      if (!movie_collection.DoesMovieExist(title))
      {
         std::cout << "Movie does not exist in the library." << std::endl;
         valid = false;
      }
      else
      {
         valid = true;
      }
   } while (!valid);

   movie_collection.RemoveMovie(title);
   std::cout << "You have removed " + title << std::endl
             << std::endl;
}

void AddNewMovie()
{
   std::cout << "\n==============Add Movie=======" << std::endl;

   std::string title;
   std::cin.ignore();
   GetLinePrompt("Enter the movie title: ", &title);

   // Check if the movie already exists in the library
   Movie *movie = movie_collection.GetMovie(title);
   if (movie != NULL)
   {
      int copies_to_add;
      std::cout << "This movie already exists in the library. Enter number of copies to add: ";
      std::cin >> copies_to_add;
      movie->copies = movie->copies + copies_to_add;
      return;
   }

   movie = GetNewMovie(title);
   movie_collection.InsertMovie(movie);
}

void ShowStaffMenu()
{
   WriteStaffMenu();

   int valids[] = {1, 2, 3, 4, 0};
   int selection = GetMenuSelection(valids, 5);

   if (selection == 0)
   {
      staff_logged_in = false;
      current_menu = MainMenu;
   }

   if (selection == 1)
   {
      AddNewMovie();
   }

   if (selection == 2)
   {
      RemoveMovie();
   }

   if (selection == 3)
   {
      RegisterNewMember();
   }

   if (selection == 4)
   {
      FindMember();
   }
}

void ShowMainMenu()
{
   std::cout << "\n"
             << std::endl;
   std::cout << "Welcome to the Community Library" << std::endl;
   std::cout << "===========Main Menu===========" << std::endl;
   std::cout << " 1. Staff Login" << std::endl;
   std::cout << " 2. Member Login" << std::endl;
   std::cout << " 0. Exit" << std::endl;
   std::cout << "===============================" << std::endl;
   std::cout << "\nPlease make a selection (1, 2 or 0 to exit): ";

   int valids[] = {1, 2, 0};
   int selection = GetMenuSelection(valids, 3);

   if (selection == 1)
   {
      current_menu = StaffMenu;
   }

   if (selection == 2)
   {
      current_menu = MemberMenu;
   }

   if (selection == 0)
   {
      current_menu = ExitProgram;
   }
}

int main()
{
   AddDummyData();

   current_menu = MainMenu;
   while (current_menu != ExitProgram)
   {

      if (current_menu == MainMenu)
      {
         ShowMainMenu();
      }

      if (current_menu == StaffMenu)
      {
         if (!staff_logged_in)
         {
            LoginToStaffMenu();
         }

         if (staff_logged_in)
         {
            ShowStaffMenu();
         }
         else
         {
            current_menu = MainMenu;
         }
      }

      if (current_menu == MemberMenu)
      {
         if (!member_logged_in)
         {
            LoginToMemberMenu();
         }

         if (member_logged_in)
         {
            ShowMemberMenu();
         }
         else
         {
            current_menu = MainMenu;
         }
      }
   }
   return 0;
}