#include "Exp1.h"
#include <stdio.h>
#include <stdlib.h>

void menu(void);

int main(int argc, char const *argv[]) {
    SqList L;
    L.elem = NULL;
    ElemType p,q;
    int op=0;
    int flag = 0;
    int loc;
    char *DataFileName = "SequenceStructure.ini";

    /*L.elem=(ElemType *) malloc(sizeof(ElemType)*10);           //测试用线性表
    L.length=6;
    L.elem[0]=1;
    L.elem[1]=2;
    L.elem[2]=3;
    L.elem[3]=520;
    L.elem[4]=9;
    L.elem[5]=8;
    */
    menu();
    do {
        //clrscr();
        printf("\n\n    ----  Please input your option[0-13]: ");
        scanf("%d",&op);
        switch(op){
            case 0: break;
            case 1: {
                //printf("\n     Here is IntiaList(),which  being realized\n");
                if(InitList(&L) == 1)
                    printf("\n          The L is created successfully.");
                else if(InitList(&L) == -2)
                    printf("\n          Overflow,failed to create!");
                else if(InitList(&L) == -1)
                    printf("\n          The L has already been created.");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 2: {
                //printf("\n     Here is DestroyList(),which  being realized\n");
                if(DestroyList(&L) == 1){
                    printf("\n          The L has been destroyed successfully.");
                }
                else if(DestroyList(&L) == -1)
                    printf("\n          The L is not exist!");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 3: {
                //printf("\n     Here is ClearList(),which  being realized\n");
                if(ClearList(&L) == 1){
                    printf("\n          The L has been cleared successfully.");
                }
                else if(ClearList(&L) == -1)
                    printf("\n          The L is not exist!");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 4: {
                //printf("\n     Here is ListEmpty(),which  being realized\n");
                if (ListEmpty(L) == -1)
                     printf("\n          The L is not exist!");
                else if (ListEmpty(L) == 0)
                    printf("\n          The List is not Empty.");
                else if(ListEmpty(L) == 1)
                    printf("\n          The List is Empty.");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 5: {
                //printf("\n     Here is ListLength() ,which  being realized\n");
                if(ListLength(L) == -1){
                    printf("\n          The L is not exist!");
                }
                else if(ListLength(L) >= 0)
                    printf("\n          The List L has %d elem.",ListLength(L));
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 6: {
                //printf("\n     Here is GetElem(),which  being realized\n");
                if(!L.elem){
                    printf("\n          The L is not exist!");
                    break;
                }
                printf("\n          Please input the element's location for searching: ");
                scanf("%d",&flag);
                if(GetElem(L,flag,&p) == 0)
                    printf("\n          WRONG INPUT!");
                else if(GetElem(L,flag,&p) == 1)
                    printf("\n          The NO.%d element is %d.",flag,p);
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 7: {
                //printf("\n     Here is LocateElem(),which  being realized\n");
                if(!L.elem){
                    printf("\n          The L is not exist!");
                    break;
                }
                printf("\n          Please input a integer for searching elem: ");
                scanf("%d",&flag);
                if(LocateElem(L, flag) == 0)
                    printf("\n          The element %d is not exist in the list L!",flag);
                else
                    printf("\n          The element %d is No.%d in the list L.",flag,LocateElem(L, flag));
                getchar();
                break;
            }
            case 8: {
                //printf("\n     Here is PriorElem(),which  being realized\n");
                if(!L.elem){
                    printf("\n          The L is not exist!");
                    break;
                }
                printf("\n          Please input the current element: ");
                scanf("%d",&flag);
                if(PriorElem(L, flag, &q) == 0)
                    printf("\n          This is the first element!");
                else if(PriorElem(L, flag, &q) == 1)
                    printf("\n          The element's PriorElem is %d",q);
                else if(PriorElem(L, flag, &q) == -2)
                    printf("\n          The element is not in the list L.");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 9: {
                //printf("\n     Here is NextElem(),which  being realized\n");
                if(!L.elem){
                    printf("\n          The L is not exist!");
                    break;
                }
                printf("\n          Please input the current element: ");
                scanf("%d",&flag);
                if(NextElem(L, flag, &q) == 0)
                    printf("\n          This is the last element!");
                else if(NextElem(L, flag, &q) == 1)
                    printf("\n          The element's NextElem is %d",q);
                else if(NextElem(L, flag, &q) == -2)
                    printf("\n          The element is not in the list L.");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 10: {
                //printf("\n     Here is ListInsert(),which  being realized\n");
                if(!L.elem){
                    printf("\n          The L is not exist!");
                    break;
                }
                printf("\n          Please input elem which need Insert: ");
                scanf("%d",&p);
                printf("\n          Please input the Location: ");
                scanf("%d",&loc);
                if(ListInsert(&L, loc, p) == 1)
                    printf("\n          The element:%d is inserted successfully.",p);
                else if(ListInsert(&L, loc, p) == 0)
                    printf("\n          WRONG INPUT!");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 11: {
                //printf("\n     Here is ListDelete(),which  being realized\n");
               if(!L.elem){
                    printf("\n          The L is not exist!");
                    break;
                }
                printf("\n          Please input the element's location which need to be deleted: ");
                scanf("%d",&loc);
                if(ListDelete(&L, loc, &p) == 1)
                    printf("\n          The element:%d is deleted successfully.",p);
                else if(ListDelete(&L, loc, &p) == 0)
                    printf("\n          WRONG INPUT!");
                else
                    printf("\n          ERROR!");
                getchar();
                break;
            }
            case 12: {
                // printf("\n     Here is ListTrabverse(),which  being realized\n");
                if(!L.elem) printf("\n          The L is not exist!");
                else if(!L.length) printf("\n          The L is empty!");
                else ListTraverse(L);
                getchar();
                break;
            }
            case 13: {
                menu();
                break;
            }
            default: {
                printf("\n          WRONG INPUT!");
            }
        }
    }while(op);
    printf("\n-----------------------------Welcome again!-----------------------------\n");
    getchar();
}
/*------------------------------------------------------*/
void menu(void){
    printf("\n");
    printf("          Menu for Linear Table On Sequence Structure \n");
    printf("------------------------------------------------------------------------\n");
    printf("          1. InitList         5. ListLength       9. NextElem       \n");
    printf("          2. DestroyList      6. GetElem          10.ListInsert    \n");
    printf("          3. ClearList        7. LocateElem       11.ListDelete    \n");
    printf("          4. ListEmpty        8. PriorElem        12.ListTraverse  \n");
    printf("          13.Menu             0. Exit\n");
    printf("------------------------------------------------------------------------");
}
/*------------------------------------------------------*/
status InitList(SqList *L){
    if(L->elem) return INFEASTABLE;
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem) {
        return OVERFLOW;
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}//InitList

status DestroyList(SqList *L){
    if (!L->elem) return INFEASTABLE;
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
    return OK;
}//DestroyList

status ClearList(SqList *L){
    if (!L->elem) return INFEASTABLE;
    L->length = 0;
    return OK;
}//ClearList

status ListEmpty(SqList L){
    if(!L.elem){
        return INFEASTABLE;
    }
    if (!L.length)
        return TRUE;
    else
        return FALSE;
}//ListEmpty

int ListLength(SqList L){
    if (!L.elem) {
        return INFEASTABLE;
    }
    return L.length;
}//ListLength

status GetElem(SqList L,int i,ElemType *e){
    if (i < 1 || i > L.length)
        return ERROR;
    // L.elem = L.elem + i - 1;
    *e = L.elem[i-1];
    return OK;
}//GetElem

int LocateElem(SqList L,ElemType e){
    int i;
    for(i = 0; i <= L.length; i++){
        if (L.elem[i] == e){
            return i+1;
        }
    }
    return ERROR;
}//LocateElem

status PriorElem(SqList L,ElemType cur,ElemType *pre_e){
    int s;
    s = LocateElem(L,cur);
    if(s == 1) return ERROR;
    else if(s == 0) return -2;
    *pre_e = L.elem[s-2];
    return OK;
}//PriorElem

status NextElem(SqList L,ElemType cur,ElemType *next_e){
    int s;
    s = LocateElem(L,cur);
    if(s == L.length && L.length != 0) return ERROR;
    else if(s == 0) return -2;
    *next_e = L.elem[s];
    return OK;
}//NextElem

status ListInsert(SqList *L,int i,ElemType e){
    if (i <= 0 || i > L->length+1) return ERROR;
    ElemType *newbase, *p, *q;
    if(L->length >= L->listsize){
        newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    q = &(L->elem[i-1]);
    for(p = &(L->elem[L->length-1]); p >= q; --p){
        *(p+1) = *p;
    }
    *q = e;
    ++L->length;
    return OK;
}//ListInsert

status ListDelete(SqList *L,int i,ElemType *e){
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i-1];
    int j;
    for(j = i; j < L->length; j++){
        L->elem[j-1] = L->elem[j];
    }
    L->length--;
    return OK;
}//ListDelete

status ListTraverse(SqList L){
    int i;
    printf("\n----------------------all elements of liear table-----------------------\n");
    printf("    ");
    for(i=0;i<L.length;i++) {
        printf("%d ", L.elem[i]);
    }
    return OK;
}
