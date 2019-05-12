#include <stdio.h>
#include <stdlib.h>
#include "CircleSingleLinkList.h"

//创建单向循环链表
pNODE CreateSgCcLinkList(void) {
    int i = 0, length = 0, data = 0;
    pNODE pTail = NULL, pNew = NULL;
    pNODE pHead = (pNODE)malloc(sizeof(NODE));

    if (NULL == pHead)
	{
		printf("内存分配失败!\n");
		return 0;
	}

    pHead->data = 0;
    pHead->next = pHead;
    pTail = pHead;

    printf("请输入要创建链表的长度：");
	scanf("%d", &length);

    for(i = 1; i < length + 1; i++) {
        pNew = (pNODE)malloc(sizeof(NODE));

        if (NULL == pNew)
		{
			printf("内存分配失败！\n");
			return 0;
		}
 
		printf("请输入第%d个节点的元素值：", i);
		scanf("%d", &data);

        pNew->data = data;
        pNew->next = pHead;
        pTail->next = pNew;
        pTail = pNew;
    }

    return pHead;
}

//打印链表
void TraverseSgCcLinkList(pNODE pHead) {
    pNODE pt = pHead->next;

    printf("打印链表如下：");
    while(pt != pHead) {
        printf("%d ",pt->data);
        pt = pt->next;
    }
    putchar('\n');
}

//判断链表是否为空
int IsEmptySgCcLinkList(pNODE pHead) {
    if(pHead->next == pHead) {
        return 1;
    }
    else {
        return 0;
    }
}

//计算链表长度
int GetLengthSgCcLinkList(pNODE pHead) {
    int length = 0;
    pNODE pt = pHead->next;

    while(pt != pHead) {
        length++;
        pt = pt->next;
    }
    return length;
}

//向链表中插入节点
int InsertEleSgCcLinkList(pNODE pHead, int pos, int data) {
    pNODE pNew = NULL;

    if(pos > 0 && pos < GetLengthSgCcLinkList(pHead) + 2) {
        pNew = (pNODE)malloc(sizeof(NODE));

        if (NULL == pNew )
		{
			printf("内存分配失败!\n");
			return 0;
		}

        while(1) {
            pos--;
            if(pos == 0) {
                break;
            }
            pHead = pHead->next; 
        }

        pNew->data = data;
        pNew->next = pHead->next;
        pHead->next = pNew;

        return 1;
    }
    else {
        return 0;
    }
}

//从链表中删除节点
int DeleteEleSgCcLinkList(pNODE pHead, int pos) {
    pNODE pt = NULL;

    if(pos > 0 && pos < GetLengthSgCcLinkList(pHead) + 1) {
        while(1) {
            pos--;
            if(pos == 0) {
                break;
            }
            pHead = pHead->next;
        }

        pt = pHead->next->next;
        free(pHead->next);
        pHead->next = pt;

        return 1;
    }
    else {
        return 0;
    }
}

//删除整个链表

void FreeMemory(pNODE *ppHead)
{
	pNODE pt = NULL;
 
	while (*ppHead != NULL)
	{
		if (*ppHead == (*ppHead)->next)	//如果只有头节点一个
		{
			free(*ppHead);
			*ppHead = NULL;
		}
		else					//如果不止头节点一个
		{
			pt = (*ppHead)->next->next;
			free((*ppHead)->next);
			(*ppHead)->next = pt;
		}
	}
}

