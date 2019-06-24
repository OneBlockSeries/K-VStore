# K-VStore
key-value store,including memcache redies



总的领导，具体readme 在各自文件夹里，两者不同和区别，介绍为什么要写这个？讨论下分布式数据存储？一致性算法？


## **两者内存模型** 哈希表
哈希表
1. memcached 的内存模型：
* 预分配类型，预先分配好内存，来了数据item往内存塞
* 数据来了封装成Item,找个合适的chunk,往里塞
* 1. 如何封装Item,
  ```
  struct Item{
      key
      value
  }
* 2. 如何分割成合适chunk
*  先初始化一个slabclass[] 数组，里面size不同代表存储不同的item,当slabclass[i] 空间不够时，申请一个slab(固定大小，如1m)，按照size大小分割成chunk

1. redies的内存模型：
* 动态分配，来了数据rediesObject，再开辟内存
  ```
  struct dictEntry{
      string        key;
      rediesObject   value;
      dictEntry  *next;
  }dictEntry;
  struct rediesObjec{
      //包含五种数据结构，string list  hash  set sortset
      int type; //那种类型
      union{
          void *voiddata;
          uint64_t uint64;
          int64_t   i64;
      }data;
      //void* data;
  }rediesObject;
  struct dict{
      dictEntry[]
      //rehash //暂不考虑rehash
  }dict
## **添加网络功能**
增加网络功能。从中分离出一个网络层。主要就说提供网络服务，使上层逻辑层只关注本身逻辑，而数据的收发，重发，解析功能，交给网络层，当然还有一些异常情况，比如收发数据太快。

## **完善memcached多线程和redies持久化功能**
1. 


## **分布式**
很有意思的是redies分布式实现再服务端，通过集群实现。而memecache 分布式实现再客户端

