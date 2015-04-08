#include "ActionRecording.h"

DepthImage::DepthImage(int height,int width){
  this->width=width;
  this->height=height;
  data=new USHORT*[width];
  for(int i=0;i<width;i++){
    data[i]=new USHORT[height];
  }
}

DepthImage::~DepthImage(){
  for(int i=0;i<width;i++){
    delete data[i];
  }
  delete data;
}

ActionManager::ActionManager(string filename,int n){
  this->filename=filename;
  this->n=n;
  this->counter=n;
  depth_stream=NULL;
}

ActionManager::~ActionManager(){
  for(int i=0;i<action.size();i++){
	  DepthImage * dimage=action.back();
	  delete dimage;
	  action.pop_back();
  }
}

bool ActionManager::addFrame(){
  if(counter>0){
    DepthImage * dimage=getDepthImage(depth_stream->getImage());
    this->action.push_back(dimage);
    counter--;
	return false;
  }else{
	saveAction();
	return true;
  }
}

void ActionManager::saveAction(){

}

void ActionManager::setStream(NuiDepthStream * depth_stream){
  if(this->depth_stream==NULL){
	  this->depth_stream=depth_stream;
  }
}

DepthImage * getDepthImage(NuiImageBuffer buffer){
  DepthImage * dimage= new DepthImage(buffer.GetWidth(),buffer.GetHeight());
  //USHORT* frame=buffer.depthFrame;
  /*for(int i=0;i<dimage->width;i++){
	for(int j=0;j<dimage->height;j++){
	  dimage->data[i][j]=frame[i*dimage->width+j];
    }
  }*/
  return dimage;
}