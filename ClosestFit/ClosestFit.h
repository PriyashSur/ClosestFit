#ifndef CLOSEST_FIT
#define CLOSEST_FIT
#include"csv.h"
#include"node.h"
#include<utility>


//STRUCTURE FOR USER DATA
struct User_Body
{
	//GENDER OF THE USER
	char gender;
	//HEIGHT USER ACTUAL
	float Heua;
	//BUST USER ACTUAL
	float Bua;
	//WAIST USER ACTUAL
	float Wua;
	//HIPS USER ACTUAL
	float HIua;
};

//CLOSEST FIT CLASS IMPLEMENTATION
class ClosestFit
{
	string pb_path;
	CSVLoader* csvFile;
	unsigned int row;
	unsigned int col;
	string **mat;
	Node* node;
	vector<float>Hs;
	//CLOSEST PB DATA
	string path;
	CSVLoader* csvPB;
	unsigned int _row;
	unsigned int _col;
	string **mat2;
	vector<vector<int>>pb_mat;
public:
	ClosestFit()
	{
		//PARAMETERIZED BODY DATA
		pb_path = "PB.csv";
		csvFile = new CSVLoader(pb_path);
		csvFile->Load();
		row = (unsigned)csvFile->getRow();
		col = (unsigned)csvFile->getCol();
		mat = csvFile->loadData();
		node = new Node();
		Hs.push_back(157.50);
		Hs.push_back(170.20);
		Hs.push_back(182.90);
		Hs.push_back(152.40);
		Hs.push_back(162.60);
		Hs.push_back(177.80);
		//CLOSEST PB DATA
		path = "PB_DATA.csv";
		csvPB = new CSVLoader(path);
		csvPB->Load();
		_row = (unsigned)csvPB->getRow();
		_col = (unsigned)csvPB->getCol();
		mat2 = csvPB->loadData();
		for (int i = 0; i < _row; i++)
		{
			vector<int>v;
			for (int j = 0; j < _col; j++)
			{
				istringstream iss(mat2[i][j]);
				int n;
				iss >> n;
				v.push_back(n);
			}
			pb_mat.push_back(v);
		}

	}
	~ClosestFit()
	{
		node = nullptr;
		csvFile = nullptr;
		row = 0;
		col = 0;
		_row = 0;
		_col = 0;
		mat = nullptr;
		pb_path.clear();
		pb_mat.clear();
		Hs.clear();
		path.clear();
	}
	//PARSING MEASUREMENT DATA FROM CSV FILE AND GENERATING BODY NODE AND ADDING TO THE CONTAINER 
	void createBodies();
	//PARSED DATA ARE BEING CATEGORIZED BASED ON SHORT/PETITE,NORMAL,TALL BOTH FOR MALE AND FEMALE
	void generateClusters();
	//FOR DEBUGGING PURPOSE
	void show();
	//FIND THE CLOSEST PARAMETERIZED BODY BASED ON THE USER MEASUREMENTS
	Body* PB_CATEGORIZER(char gender,float height,float bust,float waist,float hips);
private:
	//GENERATE THE ID FROM THE SCALED DOWN MEASUREMENTS FROM THE USER 
	string createID(int index,vector<vector<int>>_mat,float Bus, float Wus, float Hius);
};















#endif