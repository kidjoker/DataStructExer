#include <stdio.h>
#include <stdlib.h>
#include "DbCircleLinkList.h"

//创建双向循环链表
pNODE CreateDbCcLinkList(void) {
    int i, length = 0, data = 0;
    pNODE pNew = NULL, pTail = NULL;
    pNODE pHead = (pNODE)malloc(sizeof(NODE));

    if(pHead == NULL) {
        printf("内存分配失败！\n");
		return 0;
    }

    pHead->data = 0;
    pHead->next = NULL;
    pHead->prior = pHead;
    pTail = pHead;

    printf("请输入想要创建链表的长度：");
	scanf("%d", &length);

    for(i = 1; i < length + 1; i++) {
        pNew = (pNODE)malloc(sizeof(NODE));
        
        if (NULL == pNew)
		{
			printf("内存分配失败！\n");
			return 0;
		}

		printf("请输入第%d个节点元素值：", i);
		scanf("%d", &data);

        pNew->data = data;
        pNew->next = pHead;
        pNew->prior = pTail;
        pTail->next = pNew;
        pHead->prior = pNew;

        pTail = pNew;
    }

    return pHead;
}

//打印链表
void TraverseDbCcLinkList(pNODE pHead) {
    pNODE pt = pHead->next;

    printf("链表打印如：");
    while(pt != pHead) {
        printf("%d ", pt->data);
        pt = pt->next;
    }
    putchar('\n');
}

//判断链表是否为空
int IsEmptyDbCcLinkList(pNODE pHead) {
    pNODE pt = pHead->next;
    
    if(pt == pHead) {
        return 1; 
    }
    else {
        return 0;
    }
}

//计算链表的长度
int GetLengthDbCcLinkList(pNODE pHead) {
    int length = 0;
    pNODE pt = pHead->next;

    while(pt != pHead) {
        length++;
        pt = pt->next;
    }
    return length;
}

//向链表中插入节点
int InsertEleDbCcLinkList(pNODE pHead, int pos, int data) {
    pNODE pNew = NULL, pt = NULL;

    if(pos > 0 && pos < GetLengthDbCcLinkList(pHead) + 2) {
        pNew = (pNODE)malloc(sizeof(NODE));
        
        while(1) {
            pos--;
            if(pos == 0) {
                break;
            }
            pHead = pHead->next;
        }

        pt = pHead->next;
        pNew->data = data;

        pNew->next = pt;
        pNew->prior = pt->prior;
        pt->prior->next = pNew;
        pt->prior = pNew;

        return 1;
    }
    else {
        return 0;
    }
}

//从链表中删除节点
int DeleteEleDbCcLinkList(pNODE pHead, int pos) {
    pNODE pt = NULL;

    if(pos > 0 && pos < GetLengthDbCcLinkList(pHead) + 1) {
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
        pt->prior = pHead;

        return 1;
    }
    else {
        return 0;
    }
}

//删除整个链表，释放内存空间
void FreeMemory(pNODE *ppHead)
{
	pNODE pt = NULL;
	while (*ppHead != NULL) {
		pt = (*ppHead)->next->next;
 
		if ((*ppHead)->next == *ppHead) {
			free(*ppHead);
			*ppHead = NULL;
		}
		else {
			free((*ppHead)->next);
			(*ppHead)->next = pt;
			pt->prior = *ppHead;
		}
	}
}

