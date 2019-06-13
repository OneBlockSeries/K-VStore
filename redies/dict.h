

class dict{
public:

private:

}

class dictht{
public:

private:  

}


class dictEntry{
public:
    dictEntry();
    ~dictEntry();

private:
    sds* key;
    rediesobject* value;
    dictEntry* next;
}