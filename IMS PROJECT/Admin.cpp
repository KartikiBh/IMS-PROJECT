#include "Admin.h"
#include "AdminScreen.h"
void Admin::setusername(string un)
{
	this->username = un;
}
void Admin::setpass(string pass)
{
	this->password = pass;
}
void Admin::setcid(string cid)
{
	this->id = cid;
}
void Admin::setcname(string cname)
{
	this->name = cname;
}
void Admin::setaadhar(string aa)
{
	this->aadhar_no = aa;
}
void Admin::setaddress(string add)
{
	this->address = add;
}
void Admin::setqual(string q)
{
	this->qualifications = q;
}

string Admin::getusername()
{
	return username;
}
string Admin::getpass()
{
	return password;
}
string Admin::getcid()
{
	return id;
}
string Admin::getcname()
{
	return name;
}
string Admin::getaadhar()
{
	return aadhar_no;
}
string Admin::getaddress()
{
	return address;
}
string Admin::getqual()
{
	return qualifications;
}

void Admin::Create_array_of_objects(vector<Admin>& obj, vector<vector<string>>& Filedata)
{
	Admin tt;

	unsigned int i = 0;
	
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

void Admin::login_validation(vector<Admin>& obj)
{
	string username, password;
	int i = 0;
	AdminScreen as;
	cout << "\nEnter the username :: ";
	getline(cin, username);
	getline(cin, username);

	cout << "\nEnter the Password :: ";
	getline(cin, password);

	//int flag = 0;

	if (obj[i].getusername() == username && obj[i].getpass() == password)
		as.display();
	else
	{
		cout << "\n\nWRONG USERNAME/PASSWORD\n\n";
		exit(0);
	}
		
	/*
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
		as.display();
	}
	//cout << "\n\nLOGGED IN !!!!!!!\n\n";
	else
		cout << "\n\nWRONG USERNAME/PASSWORD\n\n";
	*/
}
