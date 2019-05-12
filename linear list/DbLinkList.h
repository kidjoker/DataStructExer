#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *prior;
    struct Node *next;
} NODE, *pNODE;

//创建双向链表
pNODE CreateDbLinkList(void);

//打印链表
void TraverseDbLinkList(pNODE pHeader);

//判断链表是否为空
int IsEmptyDbLinkList(pNODE pHeader);

//计算链表长度
int GetLengthDbLinkList(pNODE pHeader);

//向链表插入节点
int InsertEleDbLinkList(pNODE pHeader, int pos, int data);

//从链表删除节点
int DeleteEleDbLinkList(pNODE pHeader, int pos);

//删除整个链表,释放内存
void freeMemory(pNODE *ppHead);

#endif

