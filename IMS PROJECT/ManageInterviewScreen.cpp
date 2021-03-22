#include "ManageInterviewScreen.h"
#include "head_main_menu.h"

menu_item ArrManageInterview[] = {
	{1,"Add Interview"} ,
	{2, "Modify Interview"},
	{3, "Delete Interview"},
	{0,"Quit"}
};

void ManageInterviewScreen::display()
{
	int inter;
	char IT[2];
	inter = display_menu(" Interviews Menu", ArrManageInterview, _countof(ArrManageInterview));


	do
	{
		switch (inter)

		{
		case 1:
			//cout << "Add Topic!";
			//void Add();
			break;
		case 2:
			//cout << "Modify Topic!";
			//void Modify();
			break;
		case 3:
			//cout << "Delete Topic!";
			//void Delete();
			break;
		case 0:
			return;
		default: cout << "WRONG INPUT";
			break;
		}

		return;

	} while (IT != "N");
}