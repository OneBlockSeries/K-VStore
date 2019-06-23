
#include "sds.h"

enum Type{
    REDIES_STRING=10,
    REDIES_LIST=11,
    REDIES_HASH=12,
    REDIES_SET=13,
    REDIES_ZSET=14,

};
class rediesObject{
public:
    rediesObject(sds* s);
    ~rediesObject();

    const unsigned Gettype();
private:
    unsigned type;      //对象类型  REDIES_STRING,LIST,HASH,SET,ZSET ,暂时只有sds
   // unsigned encoding;  //对象内部编码 I
    
    void *value;      //value指针
};