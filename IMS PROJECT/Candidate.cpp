#include "Candidate.h"
#include"Read_File.h"
#include"CandidateScreen.h"
Candidate::Candidate()
{
	username = "n/a";
	password = "n/a";
	id = "n/a";
	name = "n/a";
	aadhar_no = "n/a";
	address = "n/a";
	qualifications = "n/a";
}

void Candidate::login_validation(vector<Candidate>& obj)
{
	string username, password;
	int i = 0;
	CandidateScreen cs;
	cout << "\nEnter the username :: ";
	getline(cin, username);
	getline(cin, username);

	cout << "\nEnter the Password :: ";
	getline(cin, password);

	int flag = 0;
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (obj[i].getusername() == username && obj[i].getpass() == password)
		{
			flag = 1;
			break;
		}
		
	}
	if (flag == 1)
	{
		cs.display();
	}
		//cout << "\n\nLOGGED IN !!!!!!!\n\n";
	else
	{
		cout << "\n\nWRONG USERNAME/PASSWORD\n\n";
		exit(0);
	}
		
}

void Candidate::modify(vector<Candidate>& obj)
{

}

void Candidate::register_(string filename, vector<vector<string>>& Filedata)
{
	vector<string> vec;

	fstream fout;

	fout.open(filename, ios::app);

	string username, password, candidate_name, address, qualifications, candidate_id, aadhar;

	cout << "\n\n--------------------------------------\n\n";

	cout << "\nEnter the username (Format= For 'John Doe'; Username= 'jdoe'):: ";
	getline(cin, username);
	getline(cin, username);
	vec.push_back(username);

	cout << "\nEnter the Password (Alpha Numeric of atleast 7 characters):: ";
	getline(cin, password);
	vec.push_back(password);

	cout << "\nCandidate ID :: ";
	getline(cin, candidate_id);
	vec.push_back(candidate_id);

	cout << "\nEnter Candidate Name:: ";
	getline(cin, candidate_name);
	vec.push_back(candidate_name);

	cout << "\nEnter your Aadhar Card No:: ";
	getline(cin, aadhar);
	vec.push_back(aadhar);

	cout << "\nEnter your address:: ";
	getline(cin, address);
	vec.push_back(address);

	cout << "\nEnter Qualification:: ";
	getline(cin, qualifications);
	vec.push_back(qualifications);

	fout << username << "," << password << "," << candidate_id << "," << candidate_name << "," << aadhar << "," << address << "," << qualifications << "\n";
	Filedata.push_back(vec);

	//call the create_array_of objects after this function returns
}

void Candidate::delete_(vector<Candidate>& obj)
{
	string username;
	cout << "\nEnter the username :: ";
	getline(cin, username);
	getline(cin, username);

	int flag = 0;
	vector<Candidate>::iterator it = obj.begin();

	unsigned int i = 0;

	while (i < obj.size() && it != obj.end())
	{
		if (obj[i].getusername() == username)
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
		cout << "\nWrong username!!!";
	}
}

void Candidate::setusername(string un)
{
	this->username = un;
}
void Candidate::setpass(string pass)
{
	this->password = pass;
}
void Candidate::setcid(string cid)
{
	this->id = cid;
}
void Candidate::setcname(string cname)
{
	this->name = cname;
}
void Candidate::setaadhar(string aa)
{
	this->aadhar_no = aa;
}
void Candidate::setaddress(string add)
{
	this->address = add;
}
void Candidate::setqual(string q)
{
	this->qualifications = q;
}

string Candidate::getusername()
{
	return username;
}
string Candidate::getpass()
{
	return password;
}
string Candidate::getcid()
{
	return id;
}
string Candidate::getcname()
{
	return name;
}
string Candidate::getaadhar()
{
	return aadhar_no;
}
string Candidate::getaddress()
{
	return address;
}
string Candidate::getqual()
{
	return qualifications;
}

void Candidate::Create_array_of_objects(vector<Candidate>& obj, vector<vector<string>>& Filedata)
{
	Candidate tt;

	unsigned int i = 0;
	//int j = 0;

	//***************************
	/*
	fstream file;

	int n = 0;

	file.open("candidates.txt", ios::in);
	string line;

	while (!file.eof())
	{
		getline(file, line);
		n++;
	}

	file.seekg(0, ios::beg);

	file.close();

	//********************************
	*/
	//Filedata.resize(n - 1);

	while (i < Filedata.size())
	{

		tt.setusername(Filedata[i][0]);

		tt.setpass(Filedata[i][1]);

		tt.setcid(Filedata[i][2]);

		tt.setcname(Filedata[i][3]);

		tt.setaadhar(Filedata[i][4]);

		tt.setaddress(Filedata[i][5]);

		tt.setqual(Filedata[i][6]);

		obj.push_back(tt);
		//j++;
		i++;
	}

}



void write_back_to_file(string filename, vector<Candidate>& obj)
{
	fstream fout;

	fout.open(filename, ios::out);

	for (unsigned int i = 0; i < obj.size(); i++)
	{
		fout << obj[i].getusername() << "," << obj[i].getpass() << "," << obj[i].getcid() << "," << obj[i].getcname() << "," << obj[i].getaadhar() << "," << obj[i].getaddress() << "," << obj[i].getqual() << "\n";
	}
	fout.close();
}

void display_vector(vector<vector<string>>& Filedata)
{
	for (unsigned int i = 0; i < Filedata.size(); i++)
	{
		for (unsigned int j = 0; j < Filedata[i].size(); j++)
		{
			cout << Filedata[i][j] << " ";
		}
		cout << endl;
	}
}

/*
void write(string filename, vector<vector<string>>& Filedata)
{
	vector<string> vec;

	fstream fout;

	fout.open(filename, ios::app);

	string username, password, candidate_name, address, qualifications, candidate_id, aadhar;

	cout << "\n\n--------------------------------------\n\n";

	cout << "\nEnter the username (Format= For 'John Doe'; Username= 'jdoe'):: ";
	getline(cin, username);
	vec.push_back(username);

	cout << "\nEnter the Password (Alpha Numeric of atleast 7 characters):: ";
	getline(cin, password);
	vec.push_back(password);

	cout << "\nCandidate ID :: ";
	getline(cin, candidate_id);
	vec.push_back(candidate_id);

	cout << "\nEnter Candidate Name:: ";
	getline(cin, candidate_name);
	vec.push_back(candidate_name);

	cout << "\nEnter your Aadhar Card No:: ";
	getline(cin, aadhar);
	vec.push_back(aadhar);

	cout << "\nEnter your address:: ";
	getline(cin, address);
	vec.push_back(address);

	cout << "\nEnter Qualification:: ";
	getline(cin, qualifications);
	vec.push_back(qualifications);

	fout << username << "," << password << "," << candidate_id << "," << candidate_name << "," << aadhar << "," << address << "," << qualifications << "\n";
	Filedata.push_back(vec);

	fout.close();
	//call the create_array_of objects after this function returns
}
*/
/*
void display_obj(vector<Candidate>& obj)
{
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		obj[i].display();
	}
}
*/
/*
void Candidate::display()
{
	cout << endl << "\t" << username << "\t" << password << "\t" << id << "\t" << name << "\t" << aadhar_no << "\t" << address << "\t" << qualifications;
}
*/

/*
int main()
{
	vector<vector <string>> Filedata;
	Read_File rf;
	bool check = rf.Read("candidates.txt", Filedata);

	int ch = rf.Read_Check(check, Filedata);

	//Filedata.clear();
	if (1 == ch)
	{
		vector<Candidate> obj;
		//Create_array_of_objects(obj, Filedata);

	}
	return 0;
}

	

	//displaying array of objects
	//display_obj(obj);
	/*
	cout << "\n\t\t1.modify candidate";
	cout << "\n\t\t2.Login Candidate";
	cout << "\n\t\t3.Register ";
	cout << "\n\t\t4.Delete candidate";

	Candidate n;

	int choice = 1;
	cout << "\n\tEnter the Choices:: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		n.modify(obj);
		write_back_to_file("candidates.txt", obj);
		Filedata.clear();
		bool check = Read("candidates.txt", Filedata);
		//Read_Check(check, Filedata);
		obj.clear();
		Create_array_of_objects(obj, Filedata);
		display_obj(obj);
		break;
	}
	case 2:n.login_validation(obj);
		break;
	case 3:
		n.register_("candidates.txt", Filedata);
		Create_array_of_objects(obj, Filedata);
		break;
	case 4:
	{
		n.delete_(obj);
		write_back_to_file("candidates.txt", obj);
		Filedata.clear();
		bool check = Read("candidates.txt", Filedata);
		//Read_Check(check, Filedata);
		obj.clear();
		Create_array_of_objects(obj, Filedata);
		display_obj(obj);
		break;
	}
	default:cout << "\n\n----------WRONG INPUT-------------\n\n";
		break;
	}
	*/
	