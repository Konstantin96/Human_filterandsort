#pragma once
#include "Human.h"

class filter {
	string key;
	string svalue;
	int ivalue;
public:
	filter(string key, string svalue) {
		this->key = key;
		this->svalue = svalue;
	}
	filter(string key, int ivalue) {
		this->key = key;
		this->ivalue = ivalue;
	}
	bool operator() (human h) {
		if (this->key == "name")
		{
			if (this->svalue == h.getName())
				return true;
		}
		else if (this->key == "sname")
		{
			if (this->svalue == h.geSname())
				return true;
		}
		else if (this->key == "age")
		{
			if (this->ivalue == h.getAge())
				return true;
		}
		return false;
	}
};