#include <stdio.h>
#include <stdlib.h>
#include "exp.h"

status InitBiTree(BiTNode **T){

    if(!(*T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    return OK;
}//1-InitBiTree

status DestroyBiTree(BiTNode **T){
    if(*T != NULL){             //递归销毁树
        DestroyBiTree(&((*T)->lchild));
        DestroyBiTree(&((*T)->rchild));
        free(*T);
        *T = NULL;
    }
    return OK;
}//2-DestroyBiTree

status CreateBiTree(BiTNode **T){
    char ch;
    scanf("%c",&ch);
    if(ch == ' ')
        *T = NULL;
    else{
        if(!(*T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return OK;

}//3-CreateBiTree


status ClearBiTree(BiTNode **T){

    DestroyBiTree(&((*T)->lchild));  //销毁根节点的左子树
    DestroyBiTree(&((*T)->rchild));  //销毁根节点的右子树
    printf("\n          The binary tree is cleared successfully!");
    return OK;
}//4-ClearBiTree


status BiTreeEmpty(BiTNode *T){
    extern int f;            //引入全局变量，判断二叉树是否为空树
    if(f == 0)
        printf("\n          Empty!");
    else if(f == 1)
        printf("\n          Not empty!");
    return OK;
}//5-BiTreeEmpty

int BiTreeDepth(BiTNode *T){
    if(T==NULL){                 //递归求树深度
        return 0;
    }
    if(T->lchild==NULL&&T->rchild==NULL){
        return 1;
    }
    int left=BiTreeDepth(T->lchild);
    int right=BiTreeDepth(T->rchild);
    return 1+(left>right?left:right);
}//6-BiTreeDeeth

BiTNode* Root(BiTNode *T){
    extern int f;
    if(f)
        printf("\n          The root data is %c",T->data);
    else
        printf("\n          This is an empty tree!");
    return T;
}//7-Root

BiTNode *Search(BiTNode *T,char e){
    //根据关键字寻找结点，返回一个指向该结点的指针
    if(T != NULL){
        if(T->data == e){         //找到结点
            return T;
        }
        else{                         //进入子树
            if(Search(T->lchild,e))   //若在左子树中找到
                return Search(T->lchild,e);     //返回
            else if(Search(T->rchild,e))        //若在右子树中找到
                return Search(T->rchild,e);     //返回
            else  return NULL;                  //子树中未找到
        }
    }
    else
        return NULL;
}//Search

status Value(BiTNode *T,char e){
    BiTNode *p;
    p = Search(T,e);
    if(p)                    //找到结点
        printf("\n          The data of this node is %c",p->data);
    else                     //未找到结点
        printf("\n          No this node %c!",e);
    return OK;
}//8-Value
status Assign(BiTNode *T,char e,char value){
    BiTNode *p;
    p = Search(T,e);
    if(p){               //找到则替换
        p->data = value;
        printf("\n          The data is changed successfully!");
    }
    else                  //未找到结点
        printf("\n          No this node %c!",e);
    return OK;
}//9-Assign


BiTNode* Psearch(BiTNode *T,char e){
    //根据关键字寻找父结点，返回指向父结点的指针
    if(T != NULL){
        if((T->lchild && T->lchild->data == e)||(T->rchild && T->rchild->data == e)){
            return T;                          //该节点的左儿子或者右儿子等于关键字
        }
        else{                                   //进入子树
            if(Psearch(T->lchild,e))
                return Psearch(T->lchild,e);
            else if(Psearch(T->rchild,e))
                return Psearch(T->rchild,e);
            else  return NULL;                  //子树中未找到
        }
    }
    else
        return NULL;
}//Psearch

BiTNode *Parent(BiTNode *T,char e){
    BiTNode *p;
    p = Search(T,e);
    if(p){                         //结点存在
        if(e == T->data)           //是根结点
            printf("\n          Node %c is the root!",e);
        else{                      //非根结点则一定有父结点
            printf("\n          Parent's data is %c.",Psearch(T,e)->data);
            return Psearch(T,e);
        }
    }
    else                            //未找到结点
        printf("\n          No this node %c!",e);
    return NULL;

}//10-Parent
BiTNode* LeftChild(BiTNode *T,char e){
    BiTNode *p;
    p = Search(T,e);
    if(p){
        if(p->lchild){
            printf("\n          Left child's data is %c.",p->lchild->data);
            return p->lchild;
        }
        else
            printf("\n          Node %c don't have left child!",e);
    }
    else
       printf("\n          No this node %c!",e);
    return NULL;
}//11-LeftChild

BiTNode* RightChild(BiTNode *T,char e){
    BiTNode *p;
    p = Search(T,e);
    if(p){
        if(p->rchild){
            printf("\n          Right child's data is %c.",p->rchild->data);
            return p->rchild;
        }
        else
            printf("\n          Node %c don't have right child",e);
    }
    else
       printf("\n          No this node %c!",e);
    return NULL;

}//12-RightChild
BiTNode* LeftSibling(BiTNode *T,char e){
    BiTNode *p;
    p = Psearch(T,e);
    if(p){
        if(!p->lchild)
            printf("\n          Node %c don't have left sibling!",e);
        else if(e == p->lchild->data)
            printf("\n          Node %c don't have left sibling!",e);
        else{
            printf("\n          Left sibling's data is %c.",p->lchild->data);
            return p->lchild;
        }
    }
    else if(e == T->data)
        printf("\n          Node %c is the root!",e);
    else
        printf("\n          No this node %c!",e);
    return NULL;


}//13-LeftSibling
BiTNode* RightSibling(BiTNode *T,char e){
    BiTNode *p;
    p = Psearch(T,e);
    if(p){
        if(!p->rchild)
            printf("\n          Node %c don't have right sibling!",e);
        else if(e == p->rchild->data)
            printf("\n          Node %c don't have right sibling!",e);
        else{
            printf("\n          Right sibling's data is %c.",p->rchild->data);
            return p->rchild;
        }
    }
    else if(e == T->data)
        printf("\n          Node %c is the root!",e);
    else
        printf("\n          No this node %c!",e);
    return NULL;
}//14-RightSibling

status InsertChild(BiTNode *T,BiTNode *pin,int LR,BiTNode *C){
    BiTNode *p;
    if(LR == 0){
        p = pin->lchild;
        pin->lchild = C;
        C->rchild = p;
        printf("\n          Insert successfully!");
    }
    else if(LR == 1){
        p = pin->rchild;
        pin->rchild = C;
        C->rchild = p;
        printf("\n          Insert successfully!");
    }

    return OK;
}//15-InsertChild

status DeleteChild(BiTNode *T,BiTNode *pin,int LR){
    if(LR == 0){
        DestroyBiTree(&(pin->lchild));
        printf("\n          Delete successfully!");
    }
    else if(LR == 1){
        DestroyBiTree(&(pin->rchild));
        printf("\n          Delete successfully!");
    }
    return OK;
}//16-DeleteChild

status PreOrderTraverse(BiTNode *T){
    if(T){
        printf(" %c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}
status InOrderTraverse(BiTNode *T){
    if(T){
        InOrderTraverse(T->lchild);
        printf(" %c",T->data);
        InOrderTraverse(T->rchild);
    }
    return OK;
}
status PostOrderTraverse(BiTNode *T){
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf(" %c",T->data);
    }
    return OK;
}
status LevelOrderTraverse(BiTNode *T){
    LinkQueue *Q;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    InitQueue(Q);
    BiTNode *ps = T;
    EnQueue(Q,T);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q, &ps);
        printf(" %c",ps->data);
        if(ps->lchild)
            EnQueue(Q,ps->lchild);
        if(ps->rchild)
            EnQueue(Q,ps->rchild);
    }
    DestroyQueue(Q);
    free(Q);
    return OK;
}

/*------------------------------------------------------*/
status InitQueue(LinkQueue *Q){

    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next=NULL;

    return OK;
}//InitQueue
status EnQueue(LinkQueue *Q,BiTNode *e){   //插入元素e为Q的新的队尾元素
    QNode *p;

    p = (QNode*)malloc(sizeof(QNode));
    if(!p)
        return ERROR;
    p->data = e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;

    return OK;
}//EnQueue
status DeQueue(LinkQueue *Q,BiTNode **e){
    //若队列不为空,则删除Q的对头元素，用e返回其值，并返回OK;
    //否则返回ERROR
    QNode *p;
    if(Q->front==Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next=p->next;
    if(Q->rear==p) Q->rear=Q->front;
    free(p);

    return OK;
}//DeQueue
status QueueEmpty(LinkQueue *Q){
    if(Q->front == Q->rear)
        return 1;
    else
        return 0;
}//QueueEmpty
status DestroyQueue(LinkQueue *Q){
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}//DestroyQueue
