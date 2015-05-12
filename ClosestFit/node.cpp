#include"node.h"

//3 CLUSTER{SHORT/PETITE,NORMAL,TALL}
//CREATING 3 CLUSTER OF MALE and 3 CLUSTER FEMALE BODIES
void Node::createClusters()
{
	for (auto &i : bodies)
	{
		if (i->getGender() == 'M'&&i->getBodyType()=='S')
		{
			mSB.push_back(i);
		}
		else if (i->getGender() == 'M'&&i->getBodyType() == 'N')
		{
			mNB.push_back(i);
		}
		else if (i->getGender() == 'M'&&i->getBodyType() == 'T')
		{
			mTB.push_back(i);
		}
		else if (i->getGender() == 'F'&&i->getBodyType() == 'P')
		{
			fPB.push_back(i);
		}
		else if (i->getGender() == 'F'&&i->getBodyType() == 'N')
		{
			fNB.push_back(i);
		}
		else if (i->getGender() == 'F'&&i->getBodyType() == 'T')
		{
			fTB.push_back(i);
		}
	}
}
