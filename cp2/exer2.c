//练习连续线性表【数组】
#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MAXSIZE 20

typedef struct {
    ElementType Data[MAXSIZE];
    int last;
} List;

//操作集
//空表初始化
List* MakeEmpty() {
    List *pList;
    pList = (List *)malloc(sizeof(List));
    pList->last = -1;
    return pList;
}

//查找某一元素
int Find(ElementType x, List *Plist) {
    int i = 0;
    while(i <= Plist->last && Plist->Data[i] != x) {
        i++;
    }
    if(i > Plist->last) {
        return -1; //没有找到
    }
    else {
        return i;
    }
}

//插入操作
void insert(ElementType x, List *Plist,int i) {
    int j;
    if(Plist->last == MAXSIZE-1) {
        printf("表满");
        return;
    }
    if(i < 0 || i > Plist->last+2) {
        printf("位置不合法");
        return;
    }
    for(j = Plist->last; j > i-2; j--) {
        Plist->Data[j+1] = Plist->Data[j];
    }
    Plist->Data[i-1] = x;
    Plist->last++;
    return;
}

//删除操作
void delete(ElementType x, List *Plist,int i) {
    int j;
    if(i < 0 || i > Plist->last+1 ) {
        printf("位置不合法");
        return;
    }
    for(j = i; j < Plist->last+1; j++) {
        Plist->Data[j-1] = Plist->Data[j];
    }
    Plist->last--;
    return;
}

//合并线性表
void mergeList(List *La, List *Lb, List *Lc) {
    int i = 0,j = 0;

    while(i <= La->last && j <= Lb->last) {
        if(La->Data[i] < Lb->Data[j]) {
            Lc->Data[++Lc->last] = La->Data[i++];
        }
        else {
            Lc->Data[++Lc->last] = Lb->Data[j++];
        }
    }
    while(i <= La->last) {
        Lc->Data[++Lc->last] = La->Data[i++];
    }
    while(j <= Lb->last) {
        Lc->Data[++Lc->last] = Lb->Data[j++]; 
    }
}

int main(void) {
    int i;
    int findX = 4;
    List *pListA = MakeEmpty();
    List *pListB = MakeEmpty();
    for(i = 1; i <= 5; i++) {
        insert(i,pListA,i);
        insert(i+5,pListB,i);
    }

    List *pListC = MakeEmpty();
    mergeList(pListA,pListB,pListC);

    // printf("%d\n",pList->Data[4]);
    // printf("数组存储的数据个数为%d\n",pList->last+1);
    // printf("元素%d的位置为%d\n",findX,Find(findX,pList));
    return 0;
}

