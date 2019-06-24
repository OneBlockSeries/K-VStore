
#include "dict.h"
#include <stdio.h>
/*----------dictEntry--------------------*/
dictEntry::dictEntry(sds* key,uint64_t v):key(key){
    value.u64=v;
    next=nullptr;
}
dictEntry::dictEntry(sds* key,int64_t v):key(key){
    value.s64=v;
    next=nullptr;
}
dictEntry::dictEntry(sds* key,rediesObject* v):key(key){
    value.val=v;
    next=nullptr;
}
dictEntry::~dictEntry(){

}

/*------------dictht-------------------------*/

dictht::dictht():size(16),used(0),sizemask(15){
    table=new dictEntry*[size];
}
dictht::~dictht(){
    delete []table;
}

bool dictht::put(dictEntry* e,int index){
    if(table[index]==nullptr){
        //空
        table[index]=e;
        printf("put sulless\n"); 
        return true;
    }else{
        dictEntry* next=table[index];
        while(next->next!=nullptr){
            next=next->next;
        }
        printf("put sulless\n"); 
        next->next=e;
        return true;
    }
    printf("put fail\n"); 
    return false;
} 
const rediesObject* dictht::get(sds* s,int index){ 
    dictEntry* now=table[index];
    while(now->next!=nullptr){
        if(now->getkey()==s){
            printf("get sulless\n"); 
            return now->getobject();
        }else{
            now=now->next;
        }
        
    }

    printf("get fail\n"); 
    return nullptr;
} 
bool dictht::del(sds* s,int index){
    dictEntry* now=table[index];
    if(now->getkey()==s){
        delete now;
        table[index]=nullptr;
        printf("del sulless\n"); 
        return true;
    }else{
        //now=now->next;
        while(now->next!=nullptr){
            if(now->next->getkey()==s){
               delete now->next;
               now->next=nullptr;
               printf("del sulless\n"); 
               return true;
            }
            now=now->next;
        }
        printf("can not find key,del fail\n");
        return false;
    }
}

/*------------dict-----------------------------*/
dict::dict():rehashid(-1){

}
dict::~dict(){

}
bool dict::put(sds* k,rediesObject* val){
   unsigned int hash=keyhash((void*)k,k->getusedlen());
    if(rehashid==-1){
        int index=hash & ht[0].getsizemask();
        dictEntry* dentry=new dictEntry(k,val);
        return ht[0].put(dentry,index);
    }else{
        printf("rehashing\n");
    }
    return true;
}
bool dict::put(sds* k,uint64_t u64){
   unsigned int hash=keyhash((void*)k,k->getusedlen());
    if(rehashid==-1){
        int index=hash & ht[0].getsizemask();
        dictEntry* dentry=new dictEntry(k,u64);
        return ht[0].put(dentry,index);
    }else{
        printf("rehashing\n");
    }
    return true;
}
bool dict::put(sds* k,int64_t s64){
    return true;
}
const rediesObject* dict::get(sds* k){
    unsigned int hash=keyhash((void*)k,k->getusedlen());
    if(rehashid==-1){
       int index=hash & ht[0].getsizemask();
        return ht[0].get(k,index);
    }else{
        printf("rehashing\n");
        return nullptr;
    }
    
}
bool dict::del(sds* k){
    unsigned int hash=keyhash((void*)k,k->getusedlen());
    if(rehashid==-1){
        int index=hash & ht[0].getsizemask();
        return ht[0].del(k,index);
    }else{
        printf("rehashing\n");
    }

    return true;
}
unsigned int dict::keyhash(const void *key, int len){
    uint32_t seed = 5381;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    
    /* Initialize the hash to a 'random' value */
    uint32_t h = seed ^ len;
    
    /* Mix 4 bytes at a time into the hash */
    const unsigned char *data = (const unsigned char *)key;
    
    while(len >= 4) {
        uint32_t k = *(uint32_t*)data;
        
        k *= m;
        k ^= k >> r;
        k *= m;
        
        h *= m;
        h ^= k;
        
        data += 4;
        len -= 4;
    }
    
    /* Handle the last few bytes of the input array  */
    switch(len) {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0]; h *= m;
    };
    
    /* Do a few final mixes of the hash to ensure the last few
     * bytes are well-incorporated. */
    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;
    
    return (unsigned int)h;
}