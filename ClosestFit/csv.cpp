#include "csv.h"

//PARSING THE DATA FROM CSV FILE
void CSVLoader::Load()
{
	string line;
	if (reader.bad())
	{
		cout << "Couldn't open file" << endl;
	}
	else
	{
		reader.open(file, ios::in);
		string line;
		while (getline(reader, line))
		{
			if (line[0] == ',')continue;
			stringstream ss(line);
			string str;
			c = 0;
			while (getline(ss, str, ','))
			{
				v.push_back(str);
				c++;//NO OF COLS
			}
			//NO OF ROWS
			counter++;
		}

		line.clear();
		reader.close();
	}
}
//FIND THE 1ST ROW SPECIFIED COLUMN IN THE 2D ARRAY 
int CSVLoader::Find_Column_Label(string str)
{
	auto itr = find_if(v.begin(), v.end(), [=](string s){return s == str; });
	int dist = distance(v.begin(), itr);
	*itr = nullptr;
	return dist;
}

//PARSED DATA ARE LOADED INTO A 2D ARRAY OF STRING 
string** CSVLoader::loadData()
{
	mat = new string*[(unsigned)getRow()];
	for (int i = 0; i < getRow(); i++)
	{
		mat[i] = new string[(unsigned)getCol()];
	}


	int index = 0;
	for (unsigned int i = 0; i < getRow(); i++)
	{
		for (unsigned int j = 0; j < getCol(); j++)
		{
			mat[i][j] = v[index];
			index++;
		}
	}
	index = 0;
	return mat;
}

