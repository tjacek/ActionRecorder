#include "ActionRecording.h"

ActionManager::ActionManager(string filename,int n){
  this->filename=filename;
  this->n=n;
  this->counter=n;
}

void ActionManager::addFrame(){
  if(counter>0){
    counter--;
  }else{
	saveAction();
  }
}

void ActionManager::saveAction(){
}
