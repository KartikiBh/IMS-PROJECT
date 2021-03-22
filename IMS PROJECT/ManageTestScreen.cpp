#include "ManageTestScreen.h"
#include "head_main_menu.h"
#include"Test.h"
#include"Read_File.h"
menu_item ArrManageTest[] = {
	{1,"Add Test"} ,
	{2, "Modify Test"},
	{3, "Delete Test"},
	{0,"Quit"}
};

void ManageTestScreen::display()
{
	int test, chck;
	char TE[2];
	Test t;
	bool check;
	vector<Test> obj;
	vector < vector<string>> Filedata;
	Read_File rf;
	do
	{
		test = display_menu("Tests Menu", ArrManageTest, _countof(ArrManageTest));
		check = rf.Read(Filedata, "tests.txt");
		chck = rf.Read_Check(check, Filedata);
		
		if (1 == chck)
		{
		
			t.Create_array_of_objects(Filedata, obj);
		}

	
		switch (test)

		{
		case 1:
			t.add(obj);
			//cout << "Add Topic!";
			//void Add();
			break;
		case 2:
			t.modify(obj);
			//cout << "Modify Topic!";
			//void Modify();
			break;
		case 3:
			t.delete_(obj);
			//cout << "Delete Topic!";
			//void Delete();
			break;
		case 0:
			return;
		default: cout << "WRONG INPUT";
			break;
		}
		t.writeToFile(obj);
		return;
	} while (TE != "N");
}
