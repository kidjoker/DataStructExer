#ifndef DOUBLE_CIRCULAR_LINKED_LIST_H
#define DOUBLE_CIRCULAR_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *prior;
    struct Node *next;
} NODE, *pNODE;

//创建双向循环链表
pNODE CreateDbCcLinkList(void);
 
//打印链表
void TraverseDbCcLinkList(pNODE pHead);
 
//判断链表是否为空
int IsEmptyDbCcLinkList(pNODE pHead);
 
//计算链表的长度
int GetLengthDbCcLinkList(pNODE pHead);
 
//向链表中插入节点
int InsertEleDbCcLinkList(pNODE pHead, int pos, int data);
 
//从链表中删除节点
int DeleteEleDbCcLinkList(pNODE pHead, int pos);
 
//删除整个链表，释放内存
void FreeMemory(pNODE *ppHead);

#endif