#include "Question.h"
//setter
void Question::setId(string tid)
{
	this->id = tid;
}

void Question::setQues_id(string qid)
{
	this->ques_id = qid;
}

void Question::setQues_txt(string ques)
{
	this->ques_txt = ques;
}

void Question::setOpt1(string op1)
{
	this->opt1 = op1;
}

void Question::setOpt2(string op2)
{
	this->opt2 = op2;
}

void Question::setOpt3(string op3)
{
	this->opt3 = op3;
}

void Question::setOpt4(string op4)
{
	this->opt4 = op4;
}

void Question::setAns(string answer)
{
	this->ans = answer;
}

//getter
string Question::getId()
{
	return id;
}

string Question::getQues_id()
{
	return ques_id;
}

string Question::getQues_txt()
{
	return ques_txt;
}

string Question::getOpt1()
{
	return opt1;
}

string Question::getOpt2()
{
	return opt2;
}

string Question::getOpt3()
{
	return opt3;
}

string Question::getOpt4()
{
	return opt4;
}

string Question::getAns()
{
	return ans;
}

/*
bool Question::Read(string filename, vector<vector<string>>& Filedata)
{
	vector<string> vec;

	fstream file;

	file.open(filename, ios::in);

	if (!file)
	{
		return 0;
	}

	string line;
	while (!file.eof())
	{
		getline(file, line); //line is empty or not
		stringstream   linestream(line);
		string         value;

		while (getline(linestream, value, ','))
		{
			vec.push_back(value);
		}
		Filedata.push_back(vec);
		vec.clear();

	}
	cout << "file size::" << Filedata.size();
	file.close();

	return 1;
}

int Question::Read_Check(bool check, vector<vector<string>>& Filedata)
{

	if (check == 1)
	{
		return 1;
	}
	else
	{
		cout << "\nFile not read";
		return 0;
	}
}
*/
void Question::Create_array_of_objects( vector<vector<string>>& Filedata , vector<Question>& obj)
{
	//i/p will be first --- const Filedata ---good practice
	Question tt;
	//cout << "\nhello" << Filedata.size();
	int i = 0;
	//int j = 0;
	//Filedata.shrink_to_fit();
	//int size = ;
	//size++;
	while (i < Filedata.size() -1)
	{
		
		tt.setId(Filedata[i][0]);

		tt.setQues_id(Filedata[i][1]);

		tt.setQues_txt(Filedata[i][2]);

		tt.setOpt1(Filedata[i][3]);

		tt.setOpt2(Filedata[i][4]);

		tt.setOpt3(Filedata[i][5]);

		tt.setOpt4(Filedata[i][6]);

		tt.setAns(Filedata[i][7]);

		obj.push_back(tt);
		//j++;
		i++;
	}

}
/*
void display_obj(vector<Question>& obj)
{
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		obj[i].display();
	}
}
*/
string auto_q_id(string str)
{
	int s = stoi(str);
	s++;
	str = to_string(s);
	return str;
}
void append_data(Question tt)
{
	fstream fout;

	fout.open("questions.txt", ios::app);

	fout << tt.getId() << "," << tt.getQues_id() << "," << tt.getQues_txt() << "," << tt.getOpt1() << "," << tt.getOpt2() << "," << tt.getOpt3() << "," << tt.getOpt4() << "," << tt.getAns()<<"\n";
}
void Question::add(vector<Question>& obj)
{
	Question tt;
	string val;
	int i = obj.size();
	cout << "\n\nEnter Topic Id:: ";
	cin >> val;
	tt.setId(val);
	cout << "\n\nQuestion Id:: ";
	cout << auto_q_id(obj[i-1].ques_id);
	tt.setQues_id(auto_q_id(obj[i-1].ques_id));
	cout << getQues_id();
	cout << "\n\nQuestion Text:: ";
	getline(cin, val);
	getline(cin, val);
	tt.setQues_txt(val);
	cout << "\n\nOption1 Text:: ";
	getline(cin, val);
	tt.setOpt1(val);
	cout << "\n\nOption2 Text:: ";
	getline(cin, val);
	tt.setOpt2(val);
	cout << "\n\nOption3 Text:: ";
	getline(cin, val);
	tt.setOpt3(val);
	cout << "\n\nOption4 Text:: ";
	getline(cin, val);
	tt.setOpt4(val);
	cout << "\n\nAnswerOption:: ";
	getline(cin, val);
	tt.setAns(val);

	obj.push_back(tt);
	append_data(tt);

}

void Question::modify(vector<Question>& obj)
{
	int ch;
	string tid, qid;

	cout << "\n\nEnter Topic Id:: ";
	while ((getchar()) != '\n');
	getline(cin, tid);
	cout << "\n\nEnter Question Id:: ";
	getline(cin, qid);
	string ques, ans, val;
	int flag = 0;
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (obj[i].getId() == tid && obj[i].getQues_id() == qid)
		{
			cout << "\n1.Modify Ques \n2.Modify Ans\n3.Modify Option1\n4.Modify Option2\n5.Modify Option3\n6.Modify Option4 ";
			cin >> ch;
			flag = 1;
			switch (ch)
			{
			case 1:
				cout << "\nEnter question";
				while ((getchar()) != '\n');
				getline(cin, ques);
				obj[i].setQues_txt(ques);
				break;
			case 2:
				cout << "\nEnter new ans::";
				cin >> ans;
				obj[i].setAns(ans);
				break;
			case 3:
				cout << "\nEnter new option 1::";
				while ((getchar()) != '\n');
				getline(cin, val);
				obj[i].setOpt1(val);
				break;
			case 4:
				cout << "\nEnter new option 2::";
				while ((getchar()) != '\n');
				getline(cin, val);
				obj[i].setOpt2(val);
				break;
			case 5:
				cout << "\nEnter new option 3::";
				while ((getchar()) != '\n');
				getline(cin, val);
				obj[i].setOpt3(val);
				break;
			case 6:
				cout << "\nEnter new option 4::";
				while ((getchar()) != '\n');
				getline(cin, val);
				obj[i].setOpt4(val);
				break;
			default:
				cout << "Wrong choice";
				break;
			}
		}
		
	}
	if(flag==0)
	cout << "\n\nWrong topic_id/Ques_id\n\n";
}

void Question::delete_(vector<Question>& obj)
{
	int flag = 0;
	string tid, qid;
	cout << "\n\nEnter Topic Id:: ";
	while ((getchar()) != '\n');
	getline(cin, tid);
	cout << "\n\nEnter Question Id:: ";
	getline(cin, qid);
	vector<Question>::iterator it = obj.begin();
	unsigned int i = 0;
	while (i < obj.size() && it != obj.end())
	{
		if (obj[i].getId() == tid && obj[i].getQues_id() == qid)
		{
			//it = i;
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
void Question::display()
{
	cout << endl << "\t" << topic_id << "\t" << ques_id << "\t" << ques_txt << "\t" << opt1 << "\t" << opt2 << "\t" << opt3 << "\t" << opt4 << "\t" << ans;
}
*/
void Question::write(vector<Question>& obj)
{
	fstream fout;

	fout.open("questions.txt");
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		fout << obj[i].getId() << "," << obj[i].getQues_id() << "," << obj[i].getQues_txt() << "," << obj[i].getOpt1() << "," << obj[i].getOpt2() << "," << obj[i].getOpt3() << "," << obj[i].getOpt4() << "," << obj[i].getAns()<<"\n";
	}

	fout.close();
}

/*
int main()
{
	vector<vector <string>> Filedata;
	int ch, choice;
	string topic_id, question_id;
	Question mq;
	vector<Question> obj;

	bool check = mq.Read("questions.txt", Filedata);
	ch = mq.Read_Check(check, Filedata);

	//mq.vector_of_objects(obj, Filedata);

	if (1 == ch)
	{
		mq.vector_of_objects(obj, Filedata);
		display_obj(obj);

		cout << "1.Add Question\n2.Modify Question\n3.Delete Question\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//cout << "add";
			mq.add_ques(obj);
			break;

		case 2:
			cout << "\nEnter topic_id:: ";
			cin >> topic_id;
			cout << "\nEnter question_id:: ";
			cin >> question_id;
			mq.modify(obj, topic_id, question_id);
			display_obj(obj);
			break;

		case 3:
			cout << "\nEnter topic_id:: ";
			cin >> topic_id;
			cout << "\nEnter question_id:: ";
			cin >> question_id;
			mq.delete_ques(obj, topic_id, question_id);
			display_obj(obj);
			break;

		default:
			cout << "Wrong Input";


		}

	}

	return 0;
}
*/