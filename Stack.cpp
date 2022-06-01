#include "Stack.h"

Status MyStack::initializeStack(int size, int inc) {
    elem = (ElemType *) malloc(sizeof (ElemType));
    if ( elem == nullptr) return OVERFLOW;
    _top = 0;
    _size = size;
    _increment = inc;

    return OK;
}

Status MyStack::deleteStack() {
    free(elem);
    elem = nullptr;

    return OK;
}

Status MyStack::Clear() {
    _top = 0;
    _size = 0;

    return OK;
}

Status MyStack::isEmpty() {
    if (_top == 0) {
        std::cout << "The Stack is empty." << std::endl;
        return TRUE;
    }
    std::cout << "The Stack is not empty." << std::endl;
    return FALSE;
}

Status MyStack::Push(ElemType e) {
    if (_top >= _size){
        auto * newbase = (ElemType *) realloc( elem, sizeof( ElemType) * (_size + _increment));
        if ( newbase == nullptr) return  OVERFLOW;
        _size += _increment;
        elem = newbase; // !!!很重要，没有这一步的话，在testArray2入栈的过程中会出现内存错误
    }
    elem[_top] = e; // _top指向的位置就是入栈的位置
    _top++;
    return OK;
}

ElemType MyStack::getTopElem() {
    if (_top == 0) return ERROR;
    return elem[_top - 1];
}

MyStack::~MyStack() {
    std::cout << "MyStack is free." << std::endl;
}

Status MyStack::Pop() {
    if (_top == 0){
        std::cout << "The stack is alredy empty, have nothing to pop." << std::endl;
    }
    //elem[_top - 1]为POP的对象
    ElemType tmp;
    tmp = elem[_top - 1];
    elem[--_top] = 0;
    std::cout << tmp << " is pop out." << std::endl;

    return OK;
}

void MyStack::getElemAddress() {
    std::cout << elem << std::endl;
}