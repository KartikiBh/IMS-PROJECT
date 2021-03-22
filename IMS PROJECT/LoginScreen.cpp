#include "LoginScreen.h"
#include"head_main_menu.h"
//#include"AdminScreen.h"
#include"Read_File.h"
//#include"CandidateScreen.h"
#include"Candidate.h"
#include"RegisterScreen.h"
#include"Admin.h"

menu_item ArrMainMenu[] = {
	{1,"Login As Admin"} ,
	{2, "Login as Candidate"},
	{3,"Register new Candidate"},
	{0,"Quit"}
};


void LoginScreen::display()
{
	int ch;
	vector < vector<string>> Filedata;
	ch = display_menu("PARIKSHAK", ArrMainMenu, _countof(ArrMainMenu));
	Read_File rf;
	do
	{
		switch (ch)
		{
		case 1:
		{
			Admin a;
			bool check = rf.Read( Filedata ,"candidates.txt");
			int chck = rf.Read_Check(check, Filedata);

			if (1 == chck)
			{
				vector<Admin> obj;
				a.Create_array_of_objects(obj, Filedata);
				a.login_validation(obj);

			}

			//AdminScreen as;
			//as.display();
			break;
		}
			
		case 2:
		{
			Candidate c;
			bool check = rf.Read(Filedata, "candidates.txt");
			int chck2 = rf.Read_Check(check, Filedata);

			if (1 == chck2)
			{
				vector<Candidate> obj;
				c.Create_array_of_objects(obj, Filedata);
				c.login_validation(obj);

			}
			
			
			//CandidateScreen cs;
			//cs.display();
			break;
		}
			

		case 3:
		{
			Candidate c;
			bool check = rf.Read(Filedata, "candidates.txt");
			int chck2 = rf.Read_Check(check, Filedata);

			if (1 == chck2)
			{
				vector<Candidate> obj;
				c.Create_array_of_objects(obj, Filedata);
				c.register_("candidates.txt",Filedata);

			}
			//RegisterScreen rs;
			//rs.display();
			break;
		}
			
		case 0:
			exit(0);
		}
	} while (ch != 0);

}