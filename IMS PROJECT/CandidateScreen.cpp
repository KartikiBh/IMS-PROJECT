#include "CandidateScreen.h"
#include "head_main_menu.h"

menu_item ArrCandidateMenu[] =
{
	{1,"Modify profile"},
	{2,"Appear for Test"},
	{3,"Check marks"},
	{0,"Quit"}
};

void CandidateScreen::display()
{

	int chCan;
	char CN[2];

	chCan = display_menu("You are logged in as Candidate!", ArrCandidateMenu, _countof(ArrCandidateMenu));

	do
	{
		switch (chCan)

		{
		case 1:
			//cout << "Modify Candidate!";
			//modifyProfile();
			break;
		case 2:
			//cout << "Appear for Test!";
			//appearTest();
			break;
		case 3:
			//cout << "Check Marks!";
			//checkMarks();
			break;
		case 0:
			exit(0);

		}

		chCan = display_menu("You are logged in as Candidate!", ArrCandidateMenu, _countof(ArrCandidateMenu));

	} while (CN != "N");
}
