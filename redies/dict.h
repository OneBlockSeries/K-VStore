//#include "sds.h"
#include "rediesobject.h"
#include <stdint.h>

class dictEntry;  //前向声明


class dictht{
public:
    dictht();
    ~dictht();

  
    bool put(dictEntry* e,int index); //增加
    const rediesObject* get(const char* s,int index);  //根据key 得到value
    bool del(const char* s,int index);   //根据key,删除整个dictEntry;

    unsigned long getsize(){return size;};
    unsigned long getused(){return used;};
    unsigned long getsizemask(){return sizemask;}
private:  
    dictEntry **table; //数组指针，里面存放着dictEntry* 
    unsigned long size;//数组大小 2的n次方大小
    unsigned long sizemask;//大小等于size-1
    unsigned long used;//dictEntry数量
};
class dict{
public:
    dict();
    ~dict();
    bool put(sds* k,rediesObject* val);
    bool put(sds* k,uint64_t u64);
    bool put(sds* k,int64_t s64);
    const rediesObject* get(const char* k,unsigned int len);
    bool del(const char* k,unsigned int len);

    unsigned int keyhash(const void *key, int len);
private:
    dictht  ht[2];
    int rehashid;//rehash进度，如果没有进行rehash,为-1，
};




class dictEntry{
public:
    dictEntry(sds* key,uint64_t v);
    dictEntry(sds* key,int64_t v);
    dictEntry(sds* key,rediesObject* v);

    ~dictEntry();
    sds* getkey(){return key;};
    const rediesObject* getobject(){return value.val;};
    dictEntry* next;//解决冲突
private:
    sds* key;
    union{
        rediesObject* val;
        uint64_t u64;
        int64_t s64;
    }value;
    
};

