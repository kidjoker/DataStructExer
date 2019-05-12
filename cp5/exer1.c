//练习广义表【十字链表】
#include<stdio.h>

#define ElementType int

typedef struct GNode {
    int Tag; //标志域 0表示单元素 1表示广义表
    union 
    {
        ElementType data;
        struct GNode * subList;
    } *URegion;
    struct GNode * next;
} GNode;

//获取矩阵的行数
int getMatrixRowNum(GNode * gNode) {
    GNode *gn = gNode;
    int i = 0;
    while(gn) {
        gn = gn->next;
        i++;
    }
    return i;
}

//获取矩阵的列数
int getMatrixColNum(GNode * gNode) {
    GNode *gn = gNode;
    int j = 0;
    while(gn) {
        gn = gn->URegion->subList;
        j++;
    }
    return j;
}


//对某行某列添加数据
GNode * FindMatrixByRowAndColoum(GNode *gNode, int m, int n) {
    GNode *rowGn = gNode;
    int i = 1, j = 1; //i搜索行, j搜索列
    while(rowGn != NULL && i < m) {
        rowGn = rowGn->next;
        i++;
    }
    if(i == m) {
        GNode *colGn = rowGn;
        while(colGn != NULL && j < n) {
            colGn = colGn->URegion->subList;
            j++;
        }
        if(j == n) {
            return colGn;
        }
        else {
            return NULL;
        }
    }
    else {
        return NULL;
    }
}

//按值查找
GNode * FindMatrixByValue(ElementType x, GNode *gNode) {
    GNode *rowGn = gNode;
    GNode *colGn = gNode;

    while(rowGn != NULL && rowGn->URegion->data != x) {
        colGn = rowGn->URegion->subList;
        while(colGn != NULL && colGn->URegion->data != x) {
            colGn = colGn->URegion->subList;
        }
        if(colGn != NULL) {
            return colGn;
        }
        rowGn = rowGn->next;
    }
    return rowGn;
}

GNode * Insert(ElementType x, int m, int n) {
    
}

int main(void) {
    GNode *gNode;
    printf("行数%d\n",getMatrixRowNum(gNode));
}