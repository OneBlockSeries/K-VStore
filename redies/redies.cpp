#include "redies.h"

Redies::Redies(){

}
Redies::~Redies(){

}
bool Redies::put(const char* key,const int valuetype,const char* value){

    sds k=sds(key);
    sds sdsval=sds(value);
    rediesObject v=rediesObject(&sdsval);
    //dictEntry e=dictEntry(&k,&v);
    d.put(&k,&v);
    return true;
}
const char* Redies::get(const char* key){
    sds k=sds(key);
    d.get(&k);
    return "hello";
}
bool Redies::del(const char* key){
    sds k=sds(key);
    d.del(&k);
    return true;
}


