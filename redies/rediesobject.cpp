
#include "rediesobject.h"
#include <stdio.h>
rediesObject::rediesObject(const char* s):type(REDIES_STRING){
    printf("rediesobject construct\n");
    if(type==REDIES_STRING){
        sds* va=new sds(s);
        value=(void*)va;
    }
    
}
rediesObject::~rediesObject(){
    ((sds*)value)->~sds();
    printf("~rediesobjec\n");

}
const unsigned rediesObject::Gettype(){

    return type;
}