#include "SingleLinkList.c"

int main(void) {
    int flag = 0, length = 0;
    int position = 0, value = 0;
    pNODE pHead = NULL;

    pHead = CreateSgLinkList();

    flag = IsEmptySgLinkList(pHead);
    if(flag) {
        printf("单向链表为空！\n");
    }
    else {
        length = GetLengthSgLinkList(pHead);
		printf("单向链表的长度为：%d\n", length);
		TraverseSgLinkList(pHead);
    }

    printf("请输入要插入节点的位置和元素值(两个数用空格隔开)：");
	scanf("%d %d", &position, &value);
	flag = InsertEleSgLinkList(pHead, position, value);
	if (flag) {
		printf("插入节点成功！\n");
		TraverseSgLinkList(pHead);
	}	
	else {
		printf("插入节点失败！\n");
    }

    flag = IsEmptySgLinkList(pHead);
	if (flag)
		printf("单向链表为空，不能进行删除操作！\n");
	else
	{
		printf("请输入要删除节点的位置：");
		scanf("%d", &position);
		flag = DeleteEleSgLinkList(pHead, position);
		if (flag)
		{
			printf("删除节点成功！\n");
			TraverseSgLinkList(pHead);
		}	
		else
			printf("删除节点失败！\n");
	}

    FreeMemory(&pHead);
	if (NULL == pHead)
		printf("已成功删除单向链表，释放内存完成！\n");
	else
		printf("删除单向链表失败，释放内存未完成！\n");
 
	return 0;
}