#include<iostream>
#include"ClosestFit.h"
#include<cstdlib>

int main()
{
	ClosestFit* cf = new ClosestFit();
	cf->createBodies();
	cf->generateClusters();
	//ORDER OF USER INPUTS--M/F,HEIGHT,BUST,WAIST,HIPS
	Body* test = cf->PB_CATEGORIZER('M',172, 102, 84, 97);
	cout << "----CLOSEST PB OF THE GIVEN USER INPUT----" << endl;
	cout << test->getID() << endl;
	for (auto &i : test->getMeasurements())
	{
		cout << i << endl;
	}

	return 0;
}