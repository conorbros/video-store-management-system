#pragma once

enum Menu
{
   MainMenu,
   StaffMenu,
   MemberMenu,
   ExitProgram
};
extern Menu current_menu;

void GetLinePrompt(std::string to_display, std::string *result);

int GetMenuSelection(int valid_inputs[], int length);

bool GetYesOrNo();

void ZeroToExit();

bool IsStringNumbersOnly(std::string str);