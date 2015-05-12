#include"ClosestFit.h"
#include <iostream>
#include <sstream>

//PARSING THE MEASUREMENTS DATA FROM CSV FILE AND ADDING TO THE NODE CONTAINER
void ClosestFit::createBodies()
{
	for (unsigned int i = 0; i < col; i++)
	{
		Body* body = new Body(mat[0][i]);
		for (unsigned int j = 0; j < row - 1; j++)
		{
			istringstream iss(mat[j + 1][i]);
			float f;
			iss >> f;
			body->addMeasurements(f);
		}
		node->addBody(body);
	}
}

//GENERATING THE CLUSTER BASED ON SHORT/PETITE , NORMAL AND TALL CATEGORIES FOR MALE AND FEMALE
void ClosestFit::generateClusters()
{
	node->createClusters();
}

//GENERATING THE ID BASED ON THE SCALED DOWN USER MEASUREMENTS
string ClosestFit::createID(int index,vector<vector<int>>pb_mat,float Bus,float Wus,float Hius)
{
	string ID;
	string id1, id2, id3;
	int min = std::numeric_limits<int>::max();
	for (int i = 0; i<4; i++)
	{
		int result = abs(Bus - pb_mat[index][i]);
		if (min >=result)
		{
			min = result;
			ostringstream oss;
			oss << i+1;
			id1 = oss.str();
		}
	}	
	min = std::numeric_limits<int>::max();;
	for (int i = 4; i<8; i++)
	{
		int result = abs(Wus - pb_mat[index][i]);
		if (min>=result)
		{
			min = result;
			ostringstream oss;
			oss << i - 3;
			id2 = oss.str();
		}
	}
	min = std::numeric_limits<int>::max();;
	for (int i = 8; i<12; i++)
	{
		int result = abs(Hius - pb_mat[index][i]);
		if (min>=result)
		{
			min = result;
			ostringstream oss;
			oss << i - 7;
			id3 = oss.str();
		}
	}

	ID += id1 + id2 + id3;
	return ID;
}

Body* ClosestFit::PB_CATEGORIZER(char gender, float height, float bust, float waist, float hips)
{
	User_Body ub;
	ub.gender = gender;
	ub.Heua = height;
	ub.Bua = bust;
	ub.Wua = waist;
	ub.HIua = hips;

	float height_ratio;
	float Heus;
	float Bus;
	float Wus;
	float Hius;
	try
	{
		//IF GENDER IS MALE
		if (ub.gender == 'M')
		{
			//MALE CATEGORY
			//MS
			if (ub.Heua <= 162.60)
			{
				height_ratio = (float)(Hs[0] / ub.Heua);
				Heus = ub.Heua*height_ratio;
				Bus = round(ub.Bua*height_ratio);
				Wus = round(ub.Wua*height_ratio);
				Hius = round(ub.HIua*height_ratio);
				string gen_ID = createID(0, pb_mat, Bus, Wus, Hius);
				vector<Body*>MS = node->getMaleSHortBodies();
				auto itr = find_if(MS.begin(), MS.end(), [gen_ID](Body* b)->bool{return ("MS" + gen_ID) == b->getID(); });
				return *itr;
			}
			//MN
			else if (ub.Heua > 162.60&&ub.Heua <= 177.80)
			{
				height_ratio = (float)(Hs[1] / ub.Heua);
				Heus = ub.Heua*height_ratio;
				Bus = round(ub.Bua*height_ratio);
				Wus = round(ub.Wua*height_ratio);
				Hius = round(ub.HIua*height_ratio);
				string gen_ID = createID(1, pb_mat, Bus, Wus, Hius);
				vector<Body*>MN = node->getMaleNormalBodies();
				auto itr = find_if(MN.begin(), MN.end(), [gen_ID](Body* b)->bool{return ("MN" + gen_ID) == b->getID(); });
				return *itr;
			}
			//MT
			else if (ub.Heua > 177.8)
			{
				height_ratio = (float)(Hs[2] / ub.Heua);
				Heus = ub.Heua*height_ratio;
				Bus = round(ub.Bua*height_ratio);
				Wus = round(ub.Wua*height_ratio);
				Hius = round(ub.HIua*height_ratio);
				string gen_ID = createID(2, pb_mat, Bus, Wus, Hius);
				vector<Body*>MT = node->getMaleTallBodies();
				auto itr = find_if(MT.begin(), MT.end(), [gen_ID](Body* b)->bool{return ("MT" + gen_ID) == b->getID(); });
				return *itr;
			}
		}
		//IF THE GENDER IS FEMALE
		if (ub.gender == 'F')
		{
			//FP
			if (ub.Heua <= 157.50)
			{
				height_ratio = (float)(Hs[3] / ub.Heua);
				Heus = ub.Heua*height_ratio;
				Bus = round(ub.Bua*height_ratio);
				Wus = round(ub.Wua*height_ratio);
				Hius = round(ub.HIua*height_ratio);
				string gen_ID = createID(3, pb_mat, Bus, Wus, Hius);
				vector<Body*>FP = node->getFemaleSHortBodies();
				auto itr = find_if(FP.begin(), FP.end(), [gen_ID](Body* b)->bool{return ("FP" + gen_ID) == b->getID(); });
				return *itr;
			}
			//FN
			else if (ub.Heua > 157.50&&ub.Heua <= 170.20)
			{

				height_ratio = (float)(Hs[4] / ub.Heua);
				Heus = ub.Heua*height_ratio;
				Bus = round(ub.Bua*height_ratio);
				Wus = round(ub.Wua*height_ratio);
				Hius = round(ub.HIua*height_ratio);
				string gen_ID = createID(4, pb_mat, Bus, Wus, Hius);
				vector<Body*>FN = node->getFemaleNormalBodies();
				auto itr = find_if(FN.begin(), FN.end(), [gen_ID](Body* b)->bool{return ("FN" + gen_ID) == b->getID(); });
				return *itr;
			}
			//FT
			else if (ub.Heua > 170.20)
			{

				height_ratio = (float)(Hs[5] / ub.Heua);
				Heus = ub.Heua*height_ratio;
				Bus = round(ub.Bua*height_ratio);
				Wus = round(ub.Wua*height_ratio	);
				Hius = round(ub.HIua*height_ratio);
				string gen_ID = createID(5, pb_mat, Bus, Wus, Hius);
				vector<Body*>FT = node->getFemaleTallBodies();
				auto itr = find_if(FT.begin(), FT.end(), [gen_ID](Body* b)->bool{return ("FT" + gen_ID) == b->getID(); });
				return *itr;
			}
		}
	}
	catch (exception& e)
	{
		//IF THERE IS NO ID IS GENERATED FROM THE SCALE MEASUREMENTS THIS EXCEPTION WILL THROW
		cout <<"Bodies Not Found : "<< e.what() << endl;
	}
	return nullptr;
}

//FOR DEBUGGING PURPOSE
void ClosestFit::show()
{
	for (auto &i : node->getFemaleNormalBodies())
	{
		cout << i->getMeasurements().front() << endl;
	}
}