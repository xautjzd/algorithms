/*
 *约瑟夫问题(猴子选大王)
 * */
#include <stdio.h>
#include <stdlib.h>

/* 定义链表节点类型 */
typedef struct node{
    int data;
    struct node *next;
}linklist;

int main(int argc, char **argv)
{
    int i, n, k, m, total;
    linklist *head, *p, *s, *temp;
    
    printf("请输入猴子个数: ");
    scanf("%d", &n);
    printf("请输入要从第几只猴子开始报数: ");
    scanf("%d", &k);
    printf("请输入出局数字: ");
    scanf("%d", &m);

    /* 创建循环链表 */
    head = (linklist *)malloc(sizeof(linklist));
    p = head;
    p->data = 1;
    p->next = p;

    /* 初始化循环链表 */
    for (i = 2; i < n; i++) {
        s = (linklist *)malloc(sizeof(linklist));
        s->data = i;
        s->next = head;
        p->next = s;
    }

    /* 找第k个节点 */
    p = head;
    for (i = 1; i < k; i++) {
        p = p->next;
    }
    
    printf("\n出局顺序为: ");
    temp = head;
    while (n != 1) {
        /* 开始报数，找到要删除的节点 */
        for (i = 1; i < m; i++) {
            p = p->next;
        }

        /* 打印要删除的节点序号*/
        printf("[%d] ", p->data);
        
        /* 找p的千驱节点*/
        while (temp->next != p)
            temp = temp->next;
       
        /* 删除节点 */
        temp->next = p->next;
        temp = p;
        free(temp);
        p = p->next;
        n--;
    }
    printf("\n\n猴子大王为第[%d]号\n\n", p->data);
    free(p);
    return 0;
}
