#include "ManageTopicScreen.h"
#include"head_main_menu.h"

menu_item ArrManageTopic[] = {
	{1,"Add Topic"} ,
	{2, "Modify Topic"},
	{3, "Delete Topic"},
	{0,"Quit"}
};

void ManageTopicScreen::display()
{
	int topic;
	char TO[2];


	topic = display_menu("Topics Menu", ArrManageTopic, _countof(ArrManageTopic));

	do
	{
		switch (topic)

		{
		case 1:
			//cout << "Add Topic!";
			//Add();
			break;
		case 2:
			//cout << "Modify Topic!";
			//Modify();
			break;
		case 3:
			//cout << "Delete Topic!";
			//Delete();
			break;
		case 0:
			return;
		}

		return;

	} while (TO != "N");
}
