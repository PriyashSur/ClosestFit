#include<iostream>
#include"ClosestFit.h"
#include<cstdlib>

int main()
{
	ClosestFit* cf = new ClosestFit();
	cf->createBodies();
	cf->generateClusters();
	//ORDER OF USER INPUTS--M/F,HEIGHT,BUST,WAIST,HIPS
	Body* test = cf->PB_CATEGORIZER('M',182, 102, 84, 97);
	cout << test->getID() << endl;
	for (auto &i : test->getMeasurements())
	{
		cout << i << endl;
	}
	return 0;
}