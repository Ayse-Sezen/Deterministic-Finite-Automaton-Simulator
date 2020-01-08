#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>


class MessageCenter{
 public:
  MessageCenter(){};
  MessageCenter(bool flag1, bool flag2){
    if(flag1){
      vFlag = flag1;
    }
    
    if(flag2){
      hFlag = flag2;
      
    }
  }
  
  void printVFlagMsg();
  void printHFlagMsg();

  bool vFlag = false;
  bool hFlag = false;
  
};
