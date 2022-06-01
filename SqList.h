//
// Created by 赵泽源 on 2022/5/30.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H
/*
 * 实现一个顺序表
 * */
#include<iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define LONGTH 5

using std::cout;
using std::endl;
using std::cin;

typedef int Status;
typedef int ElemType;

typedef struct{
    ElemType *elem;
    int length;
    int size;
    int increment;
} SqList;

//初始化顺序表L
Status InitList_Sq(SqList &L, int size, int inc)
{
    //给顺序表L分配地址
    L.elem = (ElemType *)malloc(size * sizeof(ElemType));  // malloc 返回值是所分配区域的起始地址
    if (L.elem == nullptr ) return OVERFLOW; //如果地址为nullptr，表示一个不被使用的地址
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}

//销毁顺序表L
Status DestroyList_Sq(SqList &L)
{
    //释放所分配的内存
    free(L.elem);
    L.elem = nullptr;
    return OK;
}

//清空顺序表L
Status ClearList_Sq(SqList &L)
{
    if (L.length != 0) L.length = 0;
    return OK;
}

//检查是否为空表
Status CheckEmpty_Sq(SqList L)
{
    if (L.length == 0) return TRUE;
    else return FALSE;
}

//顺序表中的元素个数 即顺序表长度
int getSqListLength(SqList L)
{
    return L.length;
}

//返回顺序表第i个元素值
Status getElem(SqList L, int i, ElemType &e)
{
    e = L.elem[--i];
    return OK;
}


//在L中查找元素e，查找成功返回该元素第一次出现的位置，否则返回-1
int SearchElem(SqList L, ElemType e)
{
    int i = 0;
    while (i < L.length && L.elem[i] != e) i++;
    if ( i < L.length) return i;
    else return -1;
}

Status visit(ElemType e) {
    printf("%d\t", e);
    return OK;
}

//遍历顺序表L，依次对每个元素调用函数visit()
Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType e)) {  //此处的visit是一个函数指针，指向的是visit(ElemType e)这个函数
                                                                // 需要使用函数作为形参时，就使用函数指针
    if (0 == L.length) return ERROR;
    for (int i = 0; i < L.length; i++) {
        visit(L.elem[i]);
    }
    return OK;
}

//将顺序表L中第i个元素赋值为e
Status PutElem_Sq(SqList &L, int i, ElemType e) {
    if (i > L.length) return ERROR;
    e = L.elem[--i];
    return OK;

}

//在顺序表L表尾添加元素e
Status Append_Sq(SqList &L, ElemType e) {
    if (L.length >= L.size) return ERROR;
    L.elem[L.length] = e;
    L.length++;
    return OK;
}

//删除顺序表L的表尾元素，并用参数e返回其值
Status DeleteLast_Sq(SqList &L, ElemType &e) {
    if (0 == L.length) return ERROR;
    e = L.elem[L.length - 1];
    L.length--;
    return OK;
}
#endif //DATASTRUCTURE_LINKLIST_H
