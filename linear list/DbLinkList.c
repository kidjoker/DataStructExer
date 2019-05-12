#include <stdio.h>
#include <stdlib.h>
#include "DbLinkList.h"

//创建双向链表
pNODE CreateDbLinkList(void) {
    int i, length = 0, data = 0;
    pNODE pTail = NULL, pNew = NULL;
    pNODE pHead = (pNODE)malloc(sizeof(NODE));

    if(pHead == NULL) {
        printf("内存分配失败!\n");
        return NULL;
    }

    pHead->data = 0;
    pHead->prior = NULL;
    pHead->next =NULL;
    pTail = pHead;

    printf("请输入想要创建链表的长度: ");
    scanf("%d",&length);
    
    for(i = 1; i < 5 + 1; i++) {
        pNew = (pNODE)malloc(sizeof(NODE));

        if(pNew == NULL) {
            printf("内存分配失败!\n");
            return NULL;
        }

        printf("请输入第%d个元素的值：",i);
        scanf("%d", &data);

        pNew->data = data;
        pNew->next = NULL;
        pNew->prior = pTail;
        pTail->next = pNew;
        pTail = pNew;
    }

    return pHead;
}

//打印链表
void TraverseDbLinkList(pNODE pHead) {
    pNODE pt = pHead->next;

    printf("打印链表如下: ");
    while(pt) {
        printf("%d ",pt->data);
        pt = pt->next;
    }
    putchar('\n');
}

//判断链表是否为空
int IsEmptyDbLinkList(pNODE pHead) {
    pNODE pt = pHead->next;
    if(pt == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

//计算链表长度
int GetLengthDbLinkList(pNODE pHead) {
    int length = 0;
    pNODE pt = pHead->next;
    
    while(pt != NULL) {
        length++;
        pt = pt->next;
    }
    return length;
}

//向双向链表中插入节点
int InsertEleDbLinkList(pNODE pHead, int pos, int data) {
    pNODE pt = NULL, pNew = NULL;
    if(pos > 0 && pos < GetLengthDbLinkList(pHead) + 2) {
        pNew = (pNODE)malloc(sizeof(NODE));
        
        if(pNew == NULL) {
            printf("内存分配失败！\n");
            return 0;
        }

        while(1) {
            pos--;
            if(pos == 0) {
                break;
            }
            pHead = pHead->next;
        }

        pt = pHead->next;
        pNew->data = data;

        pNew->prior = pt->prior;
        if(pt != NULL) {
            pt->prior->next = pNew;
        }
        pNew->next = pt;
        pt->prior = pNew;

        return 1;
    }
    else {
        return 0;
    }
}

//从链表中删除节点
int DeleteEleDbLinkList(pNODE pHead, int pos) {
    pNODE pt = NULL;
    if(pos > 0 && pos < GetLengthDbLinkList(pHead) + 1) {
        while(1) {
            pos--;
            if(pos == 0) {
                break;
            }
            pHead = pHead->next;
        }
        
        pt = pHead->next->next;
        free(pHead->next);
        if(pt != NULL) {
            pt->prior = pHead;
        }
        pHead->next = pt;

        return 1;
    }
    else {
        return 0;
    }
}

//删除整个链表，释放内存
void FreeMemory(pNODE *ppHead) {
    pNODE pt = NULL;
 
	while (*ppHead != NULL)
	{
		pt = (*ppHead)->next;
		free(*ppHead);
		// if (NULL != pt)
		// 	pt->prior = NULL;
		*ppHead = pt;
    }
}