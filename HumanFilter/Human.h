#include "Libery.h"
#pragma once

class human {
	string name;
	string sname;
	int age;
public:
	human(string name, string sname, int age) {
		this->name = name;
		this->sname = sname;
		this->age = age;
	}
	string getName()const { return name; }
	string geSname() const { return sname; }
	int getAge()const { return age; }
};

