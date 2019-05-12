//最大子列和问题
//给定N个正数的序列{A1,A2,...,An}求函数f(i,j)=max{0,子列求和}的最大值
#include <stdio.h>
#include <time.h>

#define MAXK 1e7

clock_t start,stop;
double duration;

//算法一
int maxSubseqSum1(int A[], int N) {
    int ThisNum, MaxSum = 0,start,end;
    int i ,j ,k;
    for(i = 0; i < N; i++) {  //i是子列左端点
        for(j = i; j < N; j++) { //j是子列右端点
            ThisNum = 0;
            for(k = i; k <=j; k++) {
                ThisNum += A[k]; //开始进行暴力累加
            }
            if(ThisNum > MaxSum) { //判断是否需要更新结果
                MaxSum = ThisNum;
                start = i;
                end = j;
            }
        }
    }
    //printf("选取的子列起点为%d,终点为%d\n",start,end);
    return MaxSum;
}

//算法二
int maxSubseqSum2(int A[], int N) {
    int ThisNum, MaxSum = 0,start,end;
    int i ,j ,k;
    for(i = 0; i < N; i++) {  //i是子列左端点
        ThisNum = 0;
        for(j = i; j < N; j++) { //j是子列右端点
            ThisNum += A[j]; //开始累加
            if(ThisNum > MaxSum) { //判断是否需要更新结果
                MaxSum = ThisNum;
                start = i;
                end = j;
            }
        }
    }
    //printf("选取的子列起点为%d,终点为%d\n",start,end);
    return MaxSum;
}

//算法三【分而治之】
 
//算法四【在线处理】
int maxSubseqSum4(int A[], int N) {
    int i,ThisSum,MaxSum;
    ThisSum=MaxSum=0;
    for(i = 0; i < N; i++) {
        ThisSum += A[i];
        if(ThisSum > MaxSum) {
            MaxSum = ThisSum;
        }
        if(ThisSum < 0) {
            ThisSum = 0;
        }
    }
    return MaxSum;
}

int main (void) {
    int i;
    start = clock(); //开始计时
    
    int arr[] = {1,34,2,35,-67,2,-25,2,2,34,78,-68,3,6,23,-68,3,5,-6,1,35,36,-234};
    int result;
    for(i = 0; i < MAXK; i++) {
        result = maxSubseqSum4(arr, 23);
    }
    stop = clock(); //结束计时

    printf("%3d\n",result);
    duration = ((double)(stop-start))/CLOCKS_PER_SEC;
    printf("%6.2f\n", duration);
}