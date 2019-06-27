/////redies

#include "stdio.h"
#include "redies.h"


int main(){
    
    Redies R;
    R.put("hello",1,"redies");
    R.put("hellodd",1,"redies2");
    R.put("helddlo",1,"redies3");
    R.put("helddflo",1,"redies4");
    R.put("hedfdllo",1,"redies5");
    
    R.get("hell");
    R.get("hello");
    R.del("hell");
    R.del("hello");
    
    return 0;
}
