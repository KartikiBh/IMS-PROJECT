#include "Test.h"

//setter
void Test::setId(string tid)
{
	this->Id = tid;
}

void Test::setDesc(string did)
{
	this->Desc = did;
}

void Test::setTopic1(string tt1)
{
	this->Topic1 = tt1;
}

void Test::setTopic2(string tt2)
{
	this->Topic2 = tt2;
}

void Test::setTopic3(string tt3)
{
	this->Topic3 = tt3;
}

//getter
string Test::getId()
{
	return Id;
}

string Test::getDesc()
{
	return Desc;
}

string Test::getTopic1()
{
	return Topic1;
}

string Test::getTopic2()
{
	return Topic2;
}

string Test::getTopic3()
{
	return Topic3;
}


void Test::Create_array_of_objects(vector<vector<string>>& Filedata,vector<Test>& obj)
{
	Test tt;
	//cout << "\nhello" << Filedata.size();
	unsigned int i = 0;
	//int j = 0;
	//Filedata.shrink_to_fit();
	//unsigned int size = Filedata.size();
	//size++;
	while (i < Filedata.size()-1)
	{


		tt.setId(Filedata[i][0]);

		tt.setDesc(Filedata[i][1]);

		tt.setTopic1(Filedata[i][2]);

		tt.setTopic2(Filedata[i][3]);

		tt.setTopic3(Filedata[i][4]);

		obj.push_back(tt);
		//j++;
		i++;
	}

}

/*
void display_obj(vector<ManageTests>& obj)
{
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		obj[i].display();
	}
}
*/
string auto_testid(string str)
{
	int s = stoi(str);
	s++;
	str = to_string(s);
	return str;
}


void append_data(Test tt)
{
	fstream fout;

	fout.open("questions.txt", ios::app);

	fout << tt.getId() << "," << tt.getDesc() << "," << tt.getTopic1() << "," << tt.getTopic2() << "," << tt.getTopic3()<<"\n";
}

void Test::add(vector<Test>& obj)
{
	Test tt;
	string val;

	unsigned int i = obj.size();
	//i--;
	cout << "\n\nTest Id:: ";
	cout << auto_testid(obj[i-1].Id);
	tt.setId(auto_testid(obj[i-1].Id));
	cout << tt.getId();
	cout << "\n\nEnter Test Description:: ";
	getline(cin, val);
	getline(cin, val);
	tt.setDesc(val);
	cout << "\n\nEnter Topic 1:: ";
	getline(cin, val);
	tt.setTopic1(val);
	cout << "\n\nEnter Topic 2:: ";
	getline(cin, val);
	tt.setTopic2(val);
	cout << "\n\nEnter Topic 3:: ";
	getline(cin, val);
	tt.setTopic3(val);

	obj.push_back(tt);
	append_data(tt);

}

void Test::modify(vector<Test>& obj)
{
	string tid;
	cout << "\n\nEnter Test Id:: ";
	cin >> tid;


	int ch;
	string ques, ans, val;
	int flag = 0;
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (obj[i].getId() == tid)
		{
			flag = 1;
			cout << "\n1.Modify Test Description \n2.Modify Test Topic 1\n3.Modify Test Topic 2\n3.Modify Test Topic 3";
			cin >> ch;
			switch (ch)
			{
			case 1:
				cout << "\nEnter question";
				getline(cin ,ques);
				getline(cin, ques);
				obj[i].setDesc(ques);
				break;
			case 2:
				cout << "\nEnter new option 1::";
				getline(cin, val);
				obj[i].setTopic1(val);
				break;
			case 3:
				cout << "\nEnter new option 2::";
				getline(cin, val);
				obj[i].setTopic2(val);
				break;
			case 4:
				cout << "\nEnter new option 3::";
				getline(cin, val);
				obj[i].setTopic3(val);
				break;
			default:
				cout << "Invalid Choice!";
				break;
			}
		}

	}
	if (flag == 0)
		cout << "\n\nInvalid Test ID!\n\n";
}

void Test::delete_(vector<Test>& obj)
{
	string tid;
	cout << "\n\nEnter Test Id:: ";
	while ((getchar()) != '\n');
	getline(cin, tid);


	int flag = 0;
	vector<Test>::iterator it = obj.begin();
	unsigned int i = 0;
	while (i < obj.size() && it <= obj.end())
	{
		if (obj[i].getId() == tid )
		{
			
			obj.erase(it);
			flag = 1;
			break;
		}
		i++;
		it++;
	}

	if (flag == 0)
	{
		cout << "\n\nWrong topoic id/question id\n\n";
	}
}
/*
void ManageTests::display()
{
	cout << endl << "\t" << TestId << "\t" << TestDesc << "\t" << Topic1 << "\t" << Topic2 << "\t" << Topic3;
}
*/
void Test::writeToFile(vector<Test>& obj)
{
	fstream fout;

	fout.open("tests.txt");
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		fout << obj[i].getId() << "," << obj[i].getDesc() << "," << obj[i].getTopic1() << "," << obj[i].getTopic2() << "," << obj[i].getTopic3()<<"\n";
	}

	fout.close();
}

/*
int main()
{
	vector<vector <string>> Filedata;
	int ch, choice;
	string TestId;
	ManageTests mt;
	vector<ManageTests> obj;

	bool check = mt.Read("tests.txt", Filedata);
	ch = mt.Read_Check(check, Filedata);

	//mq.vector_of_objects(obj, Filedata);

	if (1 == ch)
	{
		mt.vector_of_objects(obj, Filedata);
		display_obj(obj);

		cout << "\t1.Add Test\n\t2.Modify Test\n\t3.Delete Test\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//cout << "add";
			mt.addTest(obj);
			break;

		case 2:
			cout << "\nEnter Test ID: ";
			cin >> TestId;
			mt.modifyTest(obj, TestId);
			display_obj(obj);
			break;

		case 3:
			cout << "\nEnter Test ID:: ";
			cin >> TestId;
			mt.deleteTest(obj, TestId);
			display_obj(obj);
			break;

		default:
			cout << "Invalid Choice!";
		}
	}
	return 0;
}
*/