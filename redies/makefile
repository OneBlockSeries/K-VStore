
#1 简单的makefile 
#rediesapp: main.o  redies.o
#	gcc main.o redies.o -o rediesapp

#main.o:main.cpp
#	gcc -c main.cpp -o main.o

#redies.o:redies.cpp
#	gcc -c redies.cpp -o redies.o



#### 22  更新makefile  使用变量，使用模式规则 ， $<:第一个一来文件  $@:目标  $^:所有不重复依赖文件，以空格分开

#obj=main.o redies.o
#target=rediesapp
#CC=gcc 

#$(target):$(obj)
#	CC $(obj) -o ${target}

#%.o: %.cpp
#	$(CC) -c $< -o $@


####3333 更新makefile  如果文件很多，obj会很长，每增加删除文件都要修改makefile,所以增加自动推导功能
### 函数wildcard:扩展通配符，搜索指定文件  src=$(wildcard./*cpp) 代表在当前目录下搜索所有cpp文件，并赋值给src,,两个文件是src结果为main.cpp redies.cpp
##函数patsubst:替换通配符，按指定规则替换 obj=$(patsubst %.cpp,%.o,$(src))  代表src里每个文件都由.c替换成.o, obj变为main.o redies.o
# obj=$(src:%.cpp=%.o) 也可以达到patsubst效果

src = $(wildcard ./*.cpp)  
obj = $(patsubst %.cpp, %.o, $(src))  
#obj = $(src:%.c=%.o)  
target=rediesapp
CC=g++ -std=c++11

$(target):$(obj)
	CC $(obj)  -lstdc++ -o ${target}

%.o: %.cpp
	$(CC) -c $< -o   $@

.PHONY:	clean  
clean:  
	rm -rf $(obj) $(target)  
