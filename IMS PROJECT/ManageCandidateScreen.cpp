#include "ManageCandidateScreen.h"
#include"head_main_menu.h"


menu_item ArrManageCandidate[] =
{
	{1,"Modify Candidate"},
	{2, "Delete Candidate"},
	{0,"Quit"}
};

void ManageCandidateScreen::display()
{
	int can;
	char CA[2];
	system("CLS");
	system("Color 0B");

	can = display_menu("Manage Candidate Menu", ArrManageCandidate, _countof(ArrManageCandidate));


	do
	{
		switch (can)

		{
		case 1:

			break;
		case 2:

			break;
		case 0:
			return;
		default: cout << "WRONG INPUT";
			break;
		}

		return;
	} while (CA != "N");
}