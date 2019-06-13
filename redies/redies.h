#include"stdio.h"
#include <iostream>
#include <string.h>

#include "dict.h"
#include "sds"
#include "rediesobject.h"
class Redies{
    public:
        Redies();
        ~Redies();
        Redies(const Redies&)=delete;
        Redies & operator=(const Redies&)=delete;

        bool put(const char* key,const int valuetype,const char* value);
        const char* get(const char* key);
        bool del(const char* key);
    private:

    dictht  ht;
};
