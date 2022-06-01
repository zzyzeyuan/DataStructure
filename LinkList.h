#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

#include<iostream>
using namespace std;

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//类型定义
typedef int Status;
typedef int ElemType;

#define LONGTH 5

//定义一个链表结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//创建包含n个元素的链表L，元素值存储在data数组中
Status CreateList_L(LinkList &L, ElemType data[], int n)
{
    LNode *p, *q;
    L = nullptr;
    p = L;
    if ( n < 0) return ERROR;
    for( int i = 0; i < n ; i++) {
        q = (LNode *) malloc(sizeof(LNode));
        if (q == nullptr) return OVERFLOW;
        q->data = data[i];
        q->next = nullptr;
        if (p == nullptr) L = q;
        else p->next = q;
        p = q;
    }
    return OK;
}

Status TailInsert(LinkList &L, ElemType &e)
{
    // L即当前链表的头地址
    LNode *p, *q;
    q = (LNode *)malloc(sizeof (LNode));
    if( q == nullptr ) return OVERFLOW;
    q->data = e;
    q->next = nullptr;

    //如果当前链表为空
    if ( L == nullptr) L = q;
    else //不为空
    {
        p = L;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = q;
    }
    return OK;
}

Status HeadOut_LinkList(LinkList &L)
{
    //如果链表为空，则返回ERROR
    if ( L == nullptr) return ERROR;
    LNode *p = L;
    ElemType e  = p->data;  //e为头结点data
    L = L->next;
    free(p);

    return OK;
}

Status visit(ElemType e)
{
    cout << e << "  ";
    return OK;
}

Status ListTraverse_L(LinkList L, Status (*fuc_ptr)(ElemType e))
{
    if ( L == nullptr) return ERROR;
    LNode * node = L;
    while (node){
        visit(node->data);
        node = node->next;
    }
    cout << endl;
    return OK;
}

#endif //DATASTRUCTURE_LINKLIST_H
