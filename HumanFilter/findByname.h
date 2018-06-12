#pragma once
#include "Libery.h"
#include "Human.h"

class findByName {
	string name;
public:
	findByName(string name):name(name){}

	bool operator()(const human& h) {
		return(name == h.getName());
	}
};