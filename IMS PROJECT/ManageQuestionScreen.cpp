#include "ManageQuestionScreen.h"
#include"head_main_menu.h"
#include"Question.h"
#include"Read_File.h"
menu_item ArrQuestionsMenu[] = {
	{1,"Add Question"} ,
	{2, "Modify Question"},
	{3, "Delete Question"},
	{0,"Quit"}
};

void ManageQuestionScreen::display()
{
	int que;
	//char QT[2];



	//ManageQuestionScreen mq;
	
	Question t;
	bool check;
	int chck;
	vector<Question> obj;
	vector < vector<string>> Filedata;
	Read_File rf;
	do
	{
		que = display_menu("Question Menu", ArrQuestionsMenu, _countof(ArrQuestionsMenu));
		check = rf.Read(Filedata, "questions.txt");
		chck = rf.Read_Check(check, Filedata);

		if (1 == chck)
		{
		t.Create_array_of_objects(Filedata, obj);
		}

		cout << "\n\nh1";
		switch (que)

		{
		case 1:
			cout << "\n\nh1";
			t.add(obj);
			//cout << "Add Question!";
			//mq.Add();
			break;
		case 2:
			t.modify(obj);
			//cout << "Modify Question!";
			//mq.Modify();
			break;
		case 3:
			t.delete_(obj);
			//cout << "Delete Question!";
			//mq.Delete();
			break;
		case 0:
			return;
		default: cout << "WRONG INPUT";
			break;
		}
		t.write(obj);
		return;
	} while (que !=0);
}
