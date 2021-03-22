#pragma once
#include<iostream>
using namespace std;
#include <windows.h>

struct menu_item
{
	int index;
	string text;
};

inline void display_header(string s)
{
	system("cls");
	system("Color 0B");
	cout << "*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^*^*^*^*^*" << endl;
	cout << "\n\t" << s << "\n\n";
	cout << "*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^*^*^*^*^*" << endl;
}

inline int display_menu(string header, menu_item* mt, int count)
{
	int choice;
	display_header(header);
	for (int i = 0; i < count; i++)
	{
		cout << "\n" << mt[i].index << "\t" << mt[i].text;
	}
	cout << "\nEnter your Choice: ";
	cin >> choice;
	return choice;
}
