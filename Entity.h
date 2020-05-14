#pragma once
class Entity {
protected:
	int ID;
public:
	//This is a default constructor
	Entity();
	//This is a destructor
	~Entity();
	//Description: Returns the ID of the object
	virtual int getID();
	//Description: Sets the ID of the object
	virtual void setID(int newID);
};
