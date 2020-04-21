enum Menu
{
   MainMenu,
   StaffMenu,
   MemberMenu,
   ExitProgram
};
extern Menu current_menu;

int get_menu_selection(int valid_inputs[], int length);

bool get_y_or_n();