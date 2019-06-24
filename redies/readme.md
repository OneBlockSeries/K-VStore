
#redies分五个部分来分析，写代码
## part1 redies内存模型，也就是redies是如何把key-value数据存储到内存中，如何管理
    1. 数据存储：dictEntry(指针:key,value,next)  key:sds结构体  value:rediesObject  next:*dictEntry
    2. 保存五种数据结构以后分析  字符串，列表，哈希，集合，有序集合
    3. dict 和dictht

## part2 redies持久化，分两种rdb和aof 
    1. RDB: 数据保存到硬盘
    2. AOF: 每次执行的写命令保存到硬盘
    3. 
## part3 redies数据主从复制
    1. dd
## part4 redies 哨兵
    1. dd
    2. dd
## part5 redies 集群
    1. dd