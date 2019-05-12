#include "CircleSingleLinkList.c"

int main(void) {
    int flag = 0, length = 0;
	int position = 0, value = 0;
	pNODE head = NULL;
 
	head = CreateSgCcLinkList();
 
	flag = IsEmptySgCcLinkList(head);
	if (flag) {
		printf("单向循环链表为空！\n");
    }
	else
	{
		length = GetLengthSgCcLinkList(head);
		printf("单向循环链表的长度为：%d\n", length);
		TraverseSgCcLinkList(head);
	}
 
	printf("请输入要插入节点的位置和元素值(两个数用空格隔开)：");
	scanf("%d %d", &position, &value);

	flag = InsertEleSgCcLinkList(head, position, value);
	if (flag) {
		printf("插入节点成功！\n");
		TraverseSgCcLinkList(head);
	}	
	else {
		printf("插入节点失败！\n");
    }

	flag = IsEmptySgCcLinkList(head);
	if (flag) {
		printf("单向循环链表为空，不能进行删除操作！\n");
    }
	else {
		printf("请输入要删除节点的位置：");
		scanf("%d", &position);

		flag = DeleteEleSgCcLinkList(head, position);
		if (flag)
		{
			printf("删除节点成功！\n");
			TraverseSgCcLinkList(head);
		}	
		else {
			printf("删除节点失败！\n");
        }
	}
 
	FreeMemory(&head);
	if (NULL == head) {
		printf("已成功删除单向循环链表，释放内存完成！\n");
    }
	else {
		printf("删除单向循环链表失败，释放内存未完成！\n");
    }
	return 0;
}