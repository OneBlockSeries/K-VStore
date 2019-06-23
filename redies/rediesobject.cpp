
#include "rediesobject.h"
#include <stdio.h>
rediesObject::rediesObject(sds* s):type(REDIES_STRING),value((void*)s){

    
}
rediesObject::~rediesObject(){
    //((sds*)value)->~sds();
    printf("~rediesobjec\n");

}
const unsigned rediesObject::Gettype(){

    return type;
}