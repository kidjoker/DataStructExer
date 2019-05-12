//
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct Node {
    ElementType data;
    struct Node *next;
} Node;

//获取链表的长度
int length(Node *node) {
    Node *p = node;
    int j = 0;
    while(node) {
        p = p->next;
        j++;
    }
    return j;
}

//寻找链表的第k个元素
Node * FindKth(int k, Node *node) {
    Node *p = node;
    int i = 1;
    while(p != NULL && i < k) {
        p = p->next;
        i++;
    }
    if(i == k) {
        return p;
    }
    else {
        return NULL;
    }
}

//按值查找
Node * Find(ElementType x, Node *node) {
    Node *p = node;
    while(p != NULL && p->data != x) {
        p = p->next;
    }
    return p;
}

//插入
Node * Insert(ElementType x, int i, Node *node) {
    Node *p,*s;
    if(i == 1) {
        s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = node;
        return s;
    }
    p = FindKth(i-1, node);
    if(p == NULL) {
        printf("参数错误\n");
        return NULL;
    }
    s = (Node *)malloc(sizeof(Node));
    s->data = x;
    s->next = p->next;
    p->next = s;
    return node;
}

//改装成循环链表
Node * InsertCircle(ElementType x, int i, Node *node) {
    Node *p,*s;
    if(i == 1) {
        s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = node;
        return s;
    }
    p = FindKth(i-1, node);
    if(p == NULL) {
        printf("参数错误\n");
        return NULL;
    }
    s = (Node *)malloc(sizeof(Node));
    s->data = x;
    s->next = p->next;
    p->next = s;
    if(!s->next) {
        s->next = node;
    }
    return node;
}

//删除
Node * delete(int i, Node *node) {
    Node *p,*s;
    if(i == 1) {
        s = node;
        if(node != NULL) {
            node = node->next;
        }
        else {
            return NULL;
        }
        free(s);
        return node;
    }
    p = FindKth(i-1, node);
    if(p == NULL) {
        printf("第%d个结点不存在",i-1);
    }
    s = p->next;
    p->next = s->next;
    free(s);
    return node;
}

//归并链表
void MergeList(Node *nodeA, Node *nodeB, Node *nodeC) {
    Node *pa = nodeA;
    Node *pb = nodeB;
    Node *pointer = nodeC;

    while(pa && pb) {
        if(pa->data <= pb->data) {
            pointer->next = pa;
            pointer = pa;
            pa = pa->next;
        }
        else {
            pointer->next = pb;
            pointer = pb;
            pb = pb->next;
        }
    }
    pointer->next = pa ? pa : pb;
    free(nodeB);
}

int main(void) {
    int i;
    Node *nodeA,*nodeB,*nodeC;
    nodeC = (Node *)malloc(sizeof(Node));
    for(i = 1; i < 6; i++) {
        nodeA = Insert(2*i,i,nodeA);
    }
    for(i = 1; i < 6; i++) {
        nodeB = InsertCircle(2*i-1,i,nodeB);
    }
    MergeList(nodeA,nodeB,nodeC);
    printf("1231");
}