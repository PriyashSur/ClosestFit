#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Body
{
	//ID OF THE PB
	string id;
	//MEASUREMENT ATTRIBUTES CONTAINER
	vector<float>measure;
	//GENDER TYPE
	char gender;
	//TYPE OF BODY
	char bodyType;
public:
	Body(string id)
	{
		this->id = id;
		gender = id[0];
		bodyType = id[1];
	}
	~Body()
	{
		measure.clear();
		id = nullptr;
	}
	//ID OF THE PARAMETERIZED BODY
	string getID(){ return id; }
	//ADD THE PARSED MEASUREMENT ATTRIBUTES FROM CSV FILE IN THE VECTOR CONTAINER
	void addMeasurements(float f){ measure.push_back(f); }
	//GET THE MEASUREMENTS ATTRIBUTES FROM THE VECTOR CONATINER
	vector<float>getMeasurements(){ return measure; }
	//GET THE GENDER TYPE MALE OF FEMALE
	char getGender(){ return gender; }
	//GET BODY TYPE SHORT/PETITE OR NORMAL OR TALL
	char getBodyType(){ return bodyType; }
};


class Node
{
	vector<Body*>bodies;
	//MALE clusters
	//m-MALE,f-FEMALE
	//B-BODIES 
	//S-SHORT,P-PETITE,N-NORMAL,T-TALL
	vector<Body*>mSB;
	vector<Body*>mNB;
	vector<Body*>mTB;
	//FEMALE clusters
	vector<Body*>fPB;
	vector<Body*>fNB;
	vector<Body*>fTB;
public:
	Node()
	{

	}
	~Node()
	{
		bodies.clear();
		mSB.clear();
		mNB.clear();
		mTB.clear();
		fPB.clear();
		fNB.clear();
		fTB.clear();
	}
	//THE PARAMETERIZED BODY DATA's WHICH ARE PARSED FROM CSV FILE ARE ADDED IN THE CONTAINER
	void addBody(Body* b){ bodies.push_back(b); }
	//GET THE PB DATA FROM THE CONTAINER.
	vector<Body*>getBodies(){ return bodies; }
	//CLUSTER WILL BE CREATED FOR MALE AND FEMALE
	void createClusters();
	//RETRIEVING THE CLUSTER DATA FOR MALE
	vector<Body*>getMaleSHortBodies(){ return mSB; }
	vector<Body*>getMaleNormalBodies(){ return mNB; }
	vector<Body*>getMaleTallBodies(){ return mTB; }
	//RETRIEVING THE CLUSTER DATA FOR FEMALE
	vector<Body*>getFemaleSHortBodies(){ return fPB; }
	vector<Body*>getFemaleNormalBodies(){ return fNB; }
	vector<Body*>getFemaleTallBodies(){ return fTB; }

};


#endif