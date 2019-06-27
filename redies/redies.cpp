#include "redies.h"

Redies::Redies(){

}
Redies::~Redies(){

}
bool Redies::put(const char* key,const int valuetype,const char* value){

    sds* k=new sds(key);
    //sds* sdsval= new sds(value);
    rediesObject* v=new rediesObject(value);
    //dictEntry e=dictEntry(&k,&v);
    d.put(k,v);
    return true;
}
const char* Redies::get(const char* key){
     
    d.get(key,strlen(key));
    return "hello";
}
bool Redies::del(const char* key){
    
    d.del(key,strlen(key));
    return true;
}


