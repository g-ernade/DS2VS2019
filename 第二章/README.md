# 线性表


## Basic.h

原c1.h 引用了几乎本章所有程序都要引的header
包含了系统header
定义了布尔值以及状态值

## Utils_SqList.h

包含了原c2-1.h,bo2-1.h,c1.h
定义了动态线性表的结构体以及各种操作

## Utils_PrivateFunc.cpp

原程序包中，独立地存在，实现了几个用于嵌入函数的函数，比较，输出等，之后可能会整合到别的header中去

## New_main 2-1.cpp

对原main2-1.cpp 变更了头文件，使用了自定义的头文件

## Utils_List.cpp

书中定义了一种List,它可以是顺序表，也可以是单链表或各种链表
这个cpp在可变的List上定义了几种操作

## Utils_LNode.h

单向链表，定义了单项链表的结构体以及基于单项链表的各种操作

## New_Algo 2-2.cpp

对原algo2-2.cpp 变更了头文件，使用了自定义的头文件