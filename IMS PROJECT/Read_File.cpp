#include "Read_File.h"
#include<fstream>
#include<sstream>
#include<vector>

bool Read_File::Read(vector<vector<string>>& Filedata ,string filename)
{
	vector<string> vec;
	Filedata.clear();
	fstream file;

	file.open(filename, ios::in);

	if (!file)
	{
		return 0;
	}

	string line;

	while (!file.eof())
	{
		getline(file, line);
		stringstream   linestream(line);
		string         value;

		while (getline(linestream, value, ','))
		{
			vec.push_back(value);
		}
		Filedata.push_back(vec);
		vec.clear();
	}
	file.close();

	return 1;
}

int Read_File::Read_Check(bool c, vector<vector<string>>& Filedata)
{
	if (1 == c)
	{
		return 1;
	}
	else
	{
		cout << "\nFile not read";
		return 0;
	}
}
