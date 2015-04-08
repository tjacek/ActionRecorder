#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include "NuiDepthStream.h"

using  std::string;
using  std::list;

class DepthImage{
  public:
	int height;
	int width;
	USHORT ** data;
	DepthImage(int height,int width);
	~DepthImage();
};

class ActionManager{
  public:
    int n;
	string filename;
	std::list<DepthImage*> action;
	
	ActionManager(string filename,int n);
	~ActionManager();
	bool addFrame();
	void setStream(NuiDepthStream * depth_stream);
  private:
    int counter;
	NuiDepthStream *depth_stream;
    void saveAction();
};

extern DepthImage * getDepthImage(NuiImageBuffer buffer);