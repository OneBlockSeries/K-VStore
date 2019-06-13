
class sds{

public:
    sds();
    ~sds();
    sds(const char*);
    char* getdata();
    int  getdatalen();
private:
    char* data;
    int len;        //已使用长度
    int free;       //空闲长度
}