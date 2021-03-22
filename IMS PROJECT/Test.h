#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Test
{
	string Id, Desc, Topic1, Topic2, Topic3;
public:
	string getId();
	string getDesc();
	string getTopic1();
	string getTopic2();
	string getTopic3();

	void setId(string);
	void setDesc(string);
	void setTopic1(string);
	void setTopic2(string);
	void setTopic3(string);

	
	void Create_array_of_objects( vector<vector<string>>& ,vector<Test>&);

	void add(vector<Test>&);
	void modify(vector<Test>&);
	void delete_(vector<Test>&);

	void writeToFile( vector<Test>&);

	//void display();
};

