#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <utils.h>
#include <staff_menu.h>
#include <member_menu.h>
#include <MemberCollection.h>

void main_menu()
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
   int selection = get_menu_selection(valids, 3);

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

   current_menu = MainMenu;
   while (current_menu != ExitProgram)
   {

      if (current_menu == MainMenu)
      {
         main_menu();
      }

      if (current_menu == StaffMenu)
      {
         if (login_to_staff_menu())
         {
            staff_menu();
         }
         else
         {
            current_menu = MainMenu;
         }
      }

      if (current_menu == MemberMenu)
      {
         //member_menu();
      }
   }
   return 0;
}