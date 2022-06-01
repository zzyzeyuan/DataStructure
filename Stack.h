#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LONGTH 5 //测试程序长度

typedef int Status;
typedef int ElemType;

//栈的类型


class MyStack{
    ElemType *elem;
    ElemType _top;
    int _size;
    int _increment;

public:
    MyStack(){
        std::cout << "构造函数 什么都不做" << std::endl;
    };
    //初始化顺序栈
    Status initializeStack(int size, int inc);
//销毁顺序栈
    Status deleteStack();
//判断S是否空，若空则返回TRUE，否则返回FALSE
    Status isEmpty();
//清空栈S
    Status Clear();
//元素e压入栈S
    Status Push(ElemType e);
//元素出栈
    Status Pop();
//取栈S的栈顶元素，并用e返回
    ElemType getTopElem();
//栈S的栈顶元素出栈，并用e返回
    void getElemAddress();
    ~MyStack();
};

#endif //DATASTRUCTURE_STACK_H
