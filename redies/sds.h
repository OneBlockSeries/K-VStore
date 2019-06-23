

//sds  simple dynamic string  简单动态字符串，用预 分配方式来减少内存频繁分配
//sds二进制安全，一般的char* 遇到’\0‘则停止，因此不能存错二进制文件。
class sds{
public:
    sds();
    ~sds();
    sds(const char* wdata);
    const char* getdata();
    const int  getusedlen();
    const int  getfreelen();
private:
    char* data;
    int len;        //已使用长度
    int free;       //空闲长度   //总长度=len+free
};