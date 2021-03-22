#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Question
{
	string id, ques_id, ques_txt, opt1, opt2, opt3, opt4, ans;
public:
	string getId();
	string getQues_id();
	string getQues_txt();
	string getOpt1();
	string getOpt2();
	string getOpt3();
	string getOpt4();
	string getAns();

	void setId(string);
	void setQues_id(string);
	void setQues_txt(string);
	void setOpt1(string);
	void setOpt2(string);
	void setOpt3(string);
	void setOpt4(string);
	void setAns(string);

	void Create_array_of_objects( vector<vector<string>>&, vector<Question>& );

	void delete_(vector<Question>&);
	void add(vector<Question>&);
	void modify(vector<Question>&);

	void write(vector<Question>&);

	
};

