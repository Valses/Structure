#ifndef __EXP1__H_
#define __EXP1__H_

#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef struct BiTNode{  //链式结构的定义
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode;
typedef struct Queue{
    BiTNode* data;
    struct Queue *next;
}QNode;
typedef struct {
    QNode *front; //对头指针
    QNode *rear; //对尾指针
}LinkQueue;


status InitBiTree(BiTNode **T);
status DestroyBiTree(BiTNode **T);
status CreateBiTree(BiTNode **T);
status ClearBiTree(BiTNode **T);

status BiTreeEmpty(BiTNode *T);
int BiTreeDepth(BiTNode *T);
BiTNode* Root(BiTNode *T);
status Value(BiTNode *T,char e);
status Assign(BiTNode *T,char e,char value);

BiTNode* Parent(BiTNode *T,char e);
BiTNode* LeftChild(BiTNode *T,char e);
BiTNode* RightChild(BiTNode *T,char e);
BiTNode* LeftSibling(BiTNode *T,char e);
BiTNode* RightSibling(BiTNode *T,char e);

status InsertChild(BiTNode *T,BiTNode *pin,int LR,BiTNode *C);
status DeleteChild(BiTNode *T,BiTNode *pin,int LR);

status PreOrderTraverse(BiTNode *T);
status InOrderTraverse(BiTNode *T);
status PostOrderTraverse(BiTNode *T);
status LevelOrderTraverse(BiTNode *T);
/*--------------------------------------------------*/
BiTNode *Search(BiTNode *T,char e);
BiTNode *Psearch(BiTNode *T,char e);
/*------------------------------------------------------*/
status InitQueue(LinkQueue *Q);
status EnQueue(LinkQueue *Q,BiTNode *e);
status DeQueue(LinkQueue *Q,BiTNode **e);
status QueueEmpty(LinkQueue *Q);
status DestroyQueue(LinkQueue *Q);

#endif
