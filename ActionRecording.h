#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

using  std::string;

class ActionManager{
  public:
    int n;
	string filename;

	ActionManager(string filename,int n);
	void addFrame();
  private:
    int counter;
    void saveAction();
};

