#pragma once
#include "Libery.h"
#include "Human.h"

class SortByKey
{
public:
	SortByKey(string key):key(key) {}

	bool operator()(const human& h1, const human& h2) {
		if (key == "name") 
			return h1.getName() > h2.getName();
		else if (key == "sname") 
			return h1.geSname() > h2.geSname();
		else if (key == "age") {
			return h1.getAge() > h2.getAge();
		}
		return false;
	}
private:
	string key;
};

