////memmcached
#include"stdio.h"
#include "memcached.h"
int main(){
    
    Memcached m;
    m.set();
    m.get();
    m.del();
    return 0;
}