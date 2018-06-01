#include <iostream>
#include <cstdio>
using namespace std;

typedef int ElemType;

typedef struct DLNode   //带头结点的双向链表
{
    ElemType data;
    struct DLNode *prior;
    struct DLNode *next;
    int length;
}DLNode;

void initDList(DLNode *&L)
{
    L = (DLNode*)malloc(sizeof(DLNode));
    L->length = 0;
    L->prior = L->next = NULL;
}

bool insertDList(DLNode *&L, int p, ElemType elem)  //插入结点至p位置， 值为elem
{
    DLNode *s, *r;
    //r作为遍历链表的指针
    if(p<0 || p>L->length)
        return 0;
    r = L;
    s = (DLNode*)malloc(sizeof(DLNode));      
    s->data = elem;
    s->next = s->prior = NULL;
    for(int i=0;i<p;i++)
    {
        r = r->next;
    }
    //双向链表插入结点4步， 画张图好理解
    if(r->next!=NULL)
    {
        r->next->prior = s;
        s->prior = r;
        s->next = r->next;
        r->next = s;
    }else{
        r->next = s;
        s->prior = r;
    }
    
    L->length++;
    return 1;
}

bool deleteDList(DLNode *&L, int p)    //删除P位置的结点
{
    if(p<0 || p>=L->length)
        return 0;
    DLNode *r;
    r = L;
    for(int i=0;i<p;i++)
    {
        r = r->next;
    }
    DLNode *q = r->next;
    q->next->prior = r;
    r->next = q->next;
    free(q);
    L->length--;
    return 1;
}

void displayInverse(DLNode *L)  //逆序输出
{
    DLNode *r;
    r = L;
    while(r->next!=NULL)
    {
        r = r->next;
    }
    while(r!=L)
    {
        cout<<r->data<<" ";
        r = r->prior;
    }
    cout<<endl;
}

int main()
{
    DLNode *L;
    initDList(L);
    for(int i=0;i<10;i++)
        insertDList(L,i,i);
    displayInverse(L);
    insertDList(L,0,55);
    cout<<"after insert 55 into position 0(inverse):"<<endl;
    displayInverse(L);
    deleteDList(L,4);
    cout<<"after delete from position 4(inverse):"<<endl;
    displayInverse(L);
    return 0;
}
