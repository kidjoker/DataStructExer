#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkList.h"

//创建单向链表
pNODE CreateSgLinkList(void) {
    int i, length, data;
    pNODE pNew = NULL, pTail = NULL;
    pNODE pHead = (pNODE)malloc(sizeof(NODE));

    if(pHead == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }

    pHead->data = 0;
    pHead->next = NULL;
    pTail = pHead;

    printf("请输入要创建的链表的长度: ");
    scanf("%d",&length);

    for(i = 1; i < length+1; i++) {
        pNew = (pNODE)malloc(sizeof(NODE));
        if(pNew == NULL) {
            printf("内存分配失败!\n");
            return NULL;
        }
        
        printf("请输入第%d个节点的值：",i);
        scanf("%d",&data);

        pNew->data = data;
        pNew->next = NULL;
        pTail->next = pNew;
        pTail = pNew;
    }

    return pHead;
}

//打印链表
void TraverseSgLinkList(pNODE pHead) {
    pNODE pt = pHead->next;

    printf("打印链表: ");
    while(pt) {
        printf("%d ",pt->data);
        pt = pt->next;
    }
    putchar('\n');
}

//判断链表是否为空
int IsEmptySgLinkList(pNODE pHead) {
    if(pHead->next == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

//计算链表的长度
int GetLengthSgLinkList(pNODE pHead) {
    int length = 0;
    pNODE pt = pHead->next;

    while(pt != NULL) {
        length++;
        pt = pt->next;
    }
    return length;
}

//向单向链表插入数据
int InsertEleSgLinkList(pNODE pHead, int pos, int data) {
    pNODE pNew = NULL;

    if(pos > 0 && pos < GetLengthSgLinkList(pHead) + 2) {
        pNew = (pNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
		{
			printf("内存分配失败!\n");
			return 0;
		}
        pNew->data = data;

        while(1) {
            pos--;
            if(pos == 0) {
                break;
            }
            pHead = pHead->next;
        }

        pNew->next = pHead->next;
        pHead->next = pNew;
        
        return 1;
    }
    else {
        return 0;
    }
}

//从单链表中删除数据
int DeleteEleSgLinkList(pNODE pHead, int pos) {
    
    pNODE pt = NULL;
    if(pos > 0 && pos < GetLengthSgLinkList(pHead) + 1) {
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

//删除整个单向链表，释放内存。
void FreeMemory(pNODE *ppHead)
{
	pNODE pt = NULL;
	while (*ppHead != NULL)
	{
		pt = (*ppHead)->next;
		free(*ppHead);
		*ppHead = pt;
	}
}