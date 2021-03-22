#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Admin
{
	string username;
	string password;
	string id;
	string name;
	string aadhar_no;
	string address;
	string qualifications;

public:
	void login_validation(vector<Admin>&);
	void Create_array_of_objects(vector<Admin>&, vector<vector<string>>&);


	void setusername(string);
	void setpass(string);
	void setcid(string);
	void setcname(string);
	void setaadhar(string);
	void setaddress(string);
	void setqual(string);

	string getusername();
	string getpass();
	string getcid();
	string getcname();
	string getaadhar();
	string getaddress();
	string getqual();

};

