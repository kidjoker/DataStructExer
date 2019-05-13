#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR -1
#define FALSE 0
#define TRUE 2

typedef struct PolyNode {
    double coef;
    int expn;
    struct PolyNode *next;
} PolyNode, *PolyList;

//单链表初始化
void init_linklist(PolyList *list) {
    *list = (PolyList)malloc(sizeof(PolyNode));
    (*list)->next = NULL;
}

//
void polyCreate(PolyList head) {
    PolyNode *rear, *newNode;
    double coef;
    int expn;

    rear = head;
    printf("请输入系数和指数：");
    scanf("%lf %d",&coef, &expn);

    while(coef != 0) {
        newNode = (PolyNode *)malloc(sizeof(PolyNode));
        newNode->coef = coef;
        newNode->expn = expn;
        newNode->next = NULL;

        rear->next = newNode;
        rear = newNode;

        printf("请输入系数和指数：");
        scanf("%lf %d",&coef, &expn);
    }

    rear->next = NULL;
}

void polyAdd(PolyList polyA, PolyList polyB) {
    PolyNode *p, *q, *pre, *temp;
    int sum;
    p = polyA->next;
    q = polyB->next;
    pre = polyA; //以polyA为主线

    while(p != NULL && q != NULL) {
        if(p->expn < q->expn) {
            pre->next = p;
            pre = p;
            p = p->next;
        }
        else if(p->expn > q->expn) {
            pre->next = q;
            pre = q;
            q = q->next;
        }
        else {
            sum = p->coef + q->coef;
            if(sum == 0) {
                temp = p;
                p = p->next;
                free(temp);

                temp = q;
                q = q->next;
                free(temp);
            }
            else {
                p->coef = sum;
                pre->next = p;
                pre = p;
                p = p->next;

                q = q->next;
            }
        }
    }
    if(p != NULL) {
        pre->next = p;
    }
    else {
        pre->next = q;
    }
    free(polyB);
}

//打印一元多项式
void print(PolyList head) {
    PolyList pl = head->next;

    while(pl != NULL) {
        printf("%2.1f*x^%d",pl->coef,pl->expn);
        pl = pl->next;
        if(pl != NULL) putchar('+');
    }
    putchar('\n');
}

int main()
{	
	PolyList LA,LB;
	init_linklist(&LA);
	init_linklist(&LB);
	polyCreate(LA);
	print(LA);
	
	polyCreate(LB);
	print(LB);
	
	polyAdd(LA,LB);
	print(LA);
	return 0;
}

