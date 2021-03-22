#include "AdminScreen.h"
#include"head_main_menu.h"
menu_item ArrAdminMenu[] =
{
	{1,"Manage Topics"} ,//class screen
	{2, "Manage Questions"},
	{3,"Manage Tests"},
	{4,"Generate questions for a test"},
	{5,"Manage Candidates"},
	{6,"Manage Interviews"},
	{7,"Calculate Marks"},//data /bussiness class
	{8,"Display Marks"},
	{0,"Quit"}
};


void AdminScreen::display()
{
	int chAdmin;
	char AD[2];


	chAdmin = display_menu("You are logged in as Admin!", ArrAdminMenu, _countof(ArrAdminMenu));

	system("cls");
	do
	{
		switch (chAdmin)

		{
		case 1:
			ManageTopicScreen mt;
			mt.display();
			break;
		case 2:
			ManageQuestionScreen mq;
			mq.display();
			break;
		case 3:
			ManageTestScreen mts;
			mts.display();
			break;
		case 4:
			//GeneralQuestionScreen gq;
			//gq.display();
			break;
		case 5:
			ManageCandidateScreen mc;
			mc.display();
			break;
		case 6:
			ManageInterviewScreen mis;
			mis.display();
			break;
		case 7:
			//calculateMarks();
			break;
		case 8:
			//displayMarks();
			break;
		case 0:
			exit(0);
		default: cout << "WRONG INPUT";
			break;
		}


		chAdmin = display_menu("You are logged in as Admin!", ArrAdminMenu, _countof(ArrAdminMenu));
	} while (AD != "N");
}

