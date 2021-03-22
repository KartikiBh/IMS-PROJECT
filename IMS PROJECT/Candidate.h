#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class Candidate
{
	string username;
	string password;
	string id;
	string name;
	string aadhar_no;
	string address;
	string qualifications;

public:
	Candidate();
	void login_validation(vector<Candidate>&);
	void modify(vector<Candidate>&);

	//registering of a new candidate
	void register_(string, vector<vector<string>>&);

	//in admin's power only
	//Only candidate for whom interview is not scheduled can be deleted.
	void delete_(vector<Candidate>&);

	void Create_array_of_objects(vector<Candidate>& , vector<vector<string>>&);

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


	//void display();


};

