#include <stdio.h>
#include <stdlib.h>
#include "exp.h"

void menu(void);
int f = 0;                //全局变量，f=1时树为非空树
int main(int argc, char const *argv[]) {
    int op = 0;
    BiTNode *point;           //返回的BiTNode类型指针
    char elem,elem2;
    int LR;

    //int flag = 0;
    //int loc;
    //char *DataFileName = "SequenceStructure.ini";

    BiTNode *T, *C;
    T = C = NULL;
    menu();
    do {
        printf("\n\n    ----  Please input your option[0-23]: ");
        scanf("%d",&op);
        switch(op){
            case 0: break;
            case 1: {
                if(T){
                    printf("\n          The empty binary tree was already exist!");
                    break;
                }
                InitBiTree(&T);
                f = 0;                //创建空二叉树，f置零
                printf("\n          The empty binary tree is created successfully!");
                getchar();
                break;
            }
            case 2:{
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(DestroyBiTree(&T)){
                    printf("\n          The binary tree is destroyed successfully!");
                    f = 0;          //销毁二叉树，f置零
                }

                getchar();
                break;
            }
            case 3:{
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(f){
                    printf("\n          You have to clear the tree before create!");
                    break;
                }
                printf("\n          Input the preorder of a tree with ' ' as empty node:\n          ");
                getchar();
                CreateBiTree(&T);
                f = 1;              //二叉树完成插入，f置1
                printf("\n          Finish creating!");
                getchar();
                break;
            }
            case 4:{
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                ClearBiTree(&T);
                f = 0;             //二叉树清空，f置零
                getchar();
                break;
            }
            case 5:{
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                BiTreeEmpty(T);
                getchar();
                break;
            }
            case 6:{
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){               //空二叉树
                    printf("\n          The depth of the tree is 0");
                    break;
                }
                printf("\n          The depth of the tree is %d",BiTreeDepth(T));
                getchar();
                break;
            }
            case 7:{
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                point = Root(T);
                getchar();
                break;
            }
            case 8: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node you want to get:");
                scanf("%c",&elem);
                Value(T,elem);
                getchar();
                break;
            }
            case 9: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node you want to change:");
                scanf("%c",&elem);
                getchar();
                printf("\n          Input the new value:");
                scanf("%c",&elem2);
                Assign(T,elem,elem2);
                getchar();
                break;
            }

            case 10: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node whose parent you want to get:");
                scanf("%c",&elem);
                point = Parent(T,elem);
                getchar();
                break;
            }
            case 11: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node whose left child you want to get:");
                scanf("%c",&elem);
                point = LeftChild(T,elem);
                getchar();
                break;
            }

            case 12: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node whose right child you want to get:");
                scanf("%c",&elem);
                point = RightChild(T,elem);
                getchar();
                break;
            }
            case 13: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node whose left sibiling you want to get:");
                scanf("%c",&elem);
                point = LeftSibling(T,elem);
                getchar();
                break;
            }
            case 14: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node whose right sibiling you want to get:");
                scanf("%c",&elem);
                point = RightSibling(T,elem);
                getchar();
                break;
            }
            case 15: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }

                InitBiTree(&C);
                getchar();
                printf("\n          Create the insert tree without right child(preorder):\n          ");
                CreateBiTree(&C);
                if(!C->rchild){
                    getchar();
                    printf("\n          Input the node whose child you want to insert:");
                    scanf("%c",&elem);
                    getchar();
                    if(point = Search(T,elem)){
                        printf("\n          Input 0 for left child or 1 for right child:");
                        scanf("%d",&LR);
                        InsertChild(T,point,LR,C);
                    }
                    else
                        printf("\n          No this node %c!",elem);
                }
                else{
                    printf("\n          Wrong create of the insert tree!!!No right child!");
                }
                DestroyBiTree(&C);
                getchar();
                break;

            }
            case 16: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(!f){
                    printf("\n          This is an empty tree!");
                    break;
                }
                getchar();
                printf("\n          Input the node whose child you want to delete:");
                scanf("%c",&elem);
                getchar();
                if(point = Search(T,elem)){

                    printf("\n          Input 0 for left child or 1 for right child:");
                    scanf("%d",&LR);
                    DeleteChild(T,point,LR);
                }
                else
                  printf("\n          No this node %c!",elem);
                getchar();
                break;
            }

            case 17: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(f){
                    printf("\n    ----------------------------PreOrder--------------------------------\n         ");
                    PreOrderTraverse(T);
                }
                getchar();
                break;
            }
            case 18: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(f){
                    printf("\n    -----------------------------InOrder--------------------------------\n         ");
                    InOrderTraverse(T);
                }
                getchar();
                break;
            }
            case 19: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(f){
                    printf("\n    ----------------------------PostOrder-------------------------------\n         ");
                    PostOrderTraverse(T);
                }
                getchar();
                break;
            }
            case 20: {
                if(!T){
                    printf("\n          No binary tree!");
                    break;
                }
                if(f){
                    printf("\n    ---------------------------LeverOrder-------------------------------\n         ");
                    LevelOrderTraverse(T);
                }
                getchar();
                break;
            }
            case 21: {
                menu();
                getchar();
                break;
            }
            case 22: {
                printf("\n     Here is SaveTree(),which  being realized");
                getchar();
                break;

            }
            case 23: {
                printf("\n     Here is LoadTree(),which  being realized");
                getchar();
                break;


            }
            default: {
                printf("\n          WRONG INPUT!");
                getchar();
            }


        }
    }while(op);
    printf("\n-----------------------------Welcome again!-----------------------------\n");
    getchar();
    return 0;

}

void menu(void){                                                           //菜单输出
    printf("\n");
    printf("                 Menu for Binary Tree On Link Structure \n");
    printf("------------------------------------------------------------------------\n");
    printf("          1.InitBiTree         2.DestroyBiTree       3.CreateBiTree    \n");
    printf("          4.ClearBiTree        5.BiTreeEmpty         6.BiTreeDepth     \n");
    printf("          7.Root               8.Value               9.Assign          \n");
    printf("          10.Parent            11.LeftChild          12.RightChild     \n");
    printf("          13.LeftSibling       14.RightSibling       15.InsertChild    \n");
    printf("          16.DeleteChild       17.PreOrderTraverse   18.InOrderTraverse\n");
    printf("          19.PostOrderTraverse 20.LeverOrderTraverse 21.menu      \n");
    printf("          22.SaveTree          23.LoadTree   \n");
    printf("          0. Exit\n");
    printf("------------------------------------------------------------------------");
}//menu
