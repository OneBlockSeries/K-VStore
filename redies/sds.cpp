
#include"sds.h"
#include<cstring>
#include <stdio.h>
sds::sds(){

    data=new char[10+1]; //默认开始是10，
    data[10]='\0';         //方便使用一些字符操作函数       
    len=0;
    free=10;
}
sds::sds(const char* wdata){

    int wlen=strlen(wdata);
    if(wlen>10){
        data=new char[wlen+1+10];
        memcpy(data,wdata,wlen);
        data[wlen]='\0';
        free=10;
        len=wlen;
    }else{

        data=new char[10+1];
        memcpy(data,wdata,wlen);
        data[wlen]='\0';
        free=10-wlen;
        len=wlen;
    }

}
sds::~sds(){
    printf("~sds\n");
    delete []data;
}
const char* sds::getdata(){

    return data;
}
const int sds::getusedlen(){

    return len;
}
const int sds::getfreelen(){
    return free;
}