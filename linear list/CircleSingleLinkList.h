#ifndef ONE_WAY_CIRCLE_LINK_LIST_H
#define ONE_WAY_CIRCLE_LINK_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} NODE, *pNODE;

//创建单向循环链表
pNODE CreateSgCcLinkList(void);
 
//打印链表
void TraverseSgCcLinkList(pNODE pHead);
 
//判断链表是否为空
int IsEmptySgCcLinkList(pNODE pHead);
 
//计算链表的长度
int GetLengthSgCcLinkList(pNODE pHead);
 
//向链表中插入节点
int InsertEleSgCcLinkList(pNODE pHead, int pos, int data);
 
//从链表中删除节点
int DeleteEleSgCcLinkList(pNODE pHead, int pos);
 
//删除整个链表，释放内存
void FreeMemory(pNODE *ppHead);

#endif