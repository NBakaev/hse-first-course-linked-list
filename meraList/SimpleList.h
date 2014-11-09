#pragma once

class SimpleListElement
{
public:int value;
	SimpleListElement* nextAdress;

};



class SimpleList
{
public:
	int length=0;
	SimpleListElement* firstAdress;
	SimpleListElement* lastAdress;

	SimpleListElement tempCur;
	SimpleListElement myTemp;



	SimpleListElement myElement ;
	SimpleListElement* prevElement;



	int curIterator=0;
	SimpleListElement* currIteratorAdress;



	bool hasNext();

	int getValue();
	

	SimpleList();
	~SimpleList();

	int getLength();
	void append(SimpleListElement *element);
	void append(int el);

	void deleteComponent(int num);


	void appendToBeginning();

};


