//双向链表
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct DNode {
    ElementType data;
    struct DNode *prior;
    struct DNode *next;
} DNode;



