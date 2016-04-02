#include "Exp1.h"
#include <stdio.h>
#include <stdlib.h>


void menu(void);

int main(int argc, char const *argv[]) {
    SqList L1,L2;
    ElemType p,q;
    int op=0;
    int op2;
    int flag = 0;
    int loc;
    char *DataFileName = "SequenceStructure.ini";

    // L1.elem=L2.elem=NULL;
    // L1.elem=(ElemType *) malloc(sizeof(ElemType)*10);
    // L1.length=4;
    // L1.elem[0].item1=1;
    // L1.elem[1].item1=2;
    // L1.elem[2].item1=3;
    // L1.elem[3].item1=520;
    do {
        //clrscr();
        menu();
        printf("          Please input your option[0-14]:");
        scanf("%d",&op);
        switch(op){
            case 0: break;
            case 1: {
                printf("\n     Here is IntiaList(),which  being realized\n");
                InitList(&L1);
                // INITALIST(&L2)
                getchar();
                // getchar();
                break;
            }
            case 2: {
                printf("\n     Here is DestroyList(),which  being realized\n");
                printf("Please Input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         DestroyList(L1);
                //         break;
                //     case 2:
                //         DestroyList(L2);
                //         break;
                //     default:
                //         break;
                // }
                // getchar();
                // getchar();
                break;
            }
            case 3: {
                printf("\n     Here is ClearList(),which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         ClearList(L1);
                //         break;
                //     case 2:
                //         ClearList(L2);
                //         break;
                //     default:
                //         break;
                // }
                // getchar();
                // getchar();
                break;
            }
            case 4: {
                printf("\n     Here is ListEmpty(),which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         flag =  ListEmpty(L1);
                //         break;
                //     case 2:
                //         flag =  ListEmpty(L1);
                //         break;
                //     default:
                //         break;
                // }
                // if (flag)
                //     printf("The List is Empty!");
                // else
                //     printf("The List is not Empty!");
                // getchar();
                // getchar();
                break;
            }
            case 5: {
                printf("\n     Here is ListLength() ,which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         printf("The List L1 has %d elem!",ListLength(L1));
                //         break;
                //     case 2:
                //         printf("The List L2 has %d elem!",ListLength(L2));
                //         break;
                //     default:
                //         break;
                // }
                // getchar();
                // getchar();
                break;

            }
            case 6: {
                printf("\n     Here is GetElem(),which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         printf("Please input a Integer for searching elem!\n");
                //         scanf("%d",&flag);
                //         GetElem(L1,flag,&p);
                //         printf("The NO.%d elem is %d",flag ,(p.item1));
                //         break;
                //     case 2:
                //         printf("Please input a Integer for searching elem!\n");
                //         scanf("%d",&flag);
                //         GetElem(L1,flag,&p);
                //         printf("The NO.%d elem is %d",flag,(p.item1));
                //         break;
                //     default:
                //         break;
                // }
                // getchar();
                // getchar();
                break;
            }
            case 7: {
                printf("\n     Here is LocateElem(),which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         printf("Please input a integer for searching elem!\n");
                //         scanf("%d",&p.item1);
                //         flag = LocateElem(L1, p, equal) + 1;
                //         break;
                //     case 2:
                //         printf("Please input a integer for searching elem!\n");
                //         scanf("%d",&p.item1);
                //         flag = LocateElem(L2, p, equal) + 1;
                //         break;
                //     default:
                //         break;
                // }
                // if (flag)
                //     printf("The elem %d is No.%d in the list\n",p.item1,flag);
                // else
                //     printf("The elem %d is not exited in the list!\n",p.item1);
                // getchar();
                // getchar();
                break;

            }
            case 8: {
                printf("\n     Here is PriorElem(),which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // printf("Please input current Element!\n");
                // scanf("%d",&p.item1);
                // switch (op2) {
                //     case 1:
                //         PriorElem(L1, p, &q);
                //         printf("The Element's PriorElem is %d",q.item1);
                //         break;
                //     case 2:
                //         PriorElem(L2, p, &q);
                //         printf("The Element's PriorElem is %d",q.item1);
                //         break;
                //     default:
                //         break;
                // }
                // getchar();getchar();
                break;
            }
            case 9: {
                printf("\n     Here is NextElem(),which  being realized\n");
                printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // printf("Please input current Element!\n");
                // scanf("%d",&p.item1);
                // switch (op2) {
                //     case 1:
                //         NextElem(L1, p, &q);
                //         printf("The Element's NextElem is %d",q.item1);
                //         break;
                //     case 2:
                //         NextElem(L2, p, &q);
                //         printf("The Element's NextElem is %d",q.item1);
                //         break;
                //     default:
                //         break;
                // }
                // getchar();getchar();
                break;
            }

            case 10: {
                printf("Please input your option[1-2]:");
                scanf("%d",&op2);
                printf("\n     Here is ListInsert(),which  being realized\n");
                printf("Please input elem which need Insert\n");
                // scanf("%d",&p.item1);
                // printf("Please input the Location\n");
                // scanf("%d",&loc);
                // switch (op2) {
                //     case 1:
                //         ListInsert(L1, loc, p);
                //         break;
                //     case 2:
                //         ListInsert(L2, loc, p);
                //         break;
                //     default:
                //         break;
                // }
                // getchar();
                // getchar();
                break;
            }
            case 11: {
                printf("\n     Here is ListDelete(),which  being realized\n");
                printf("Please input your option[1-2]:");
                scanf("%d",&op2);
                printf("Please input the element Location which will be Deleted!\n");
                // scanf("%d",&loc);
                // switch (op2) {
                //     case 1:
                //         ListDelete(L1, loc, &p);
                //         break;
                //     case 2:
                //         ListDelete(L2, loc, &p);
                //         break;
                //     default:
                //         break;
                // }
                // printf("The element:%d which was Delete in the List:L%d\n",p.item1,op2);
                // getchar();
                // getchar();
                break;

            }
            case 12: {
                // printf("\n     Here is ListTrabverse(),which  being realized\n");
                //
                // char tablename[9];
                // do{
                //     printf("\n          please specify liear table name[L1,L2]: ");
                //     scanf("%s",tablename);
                // }while(strcmp(tablename,"L1") && strcmp(tablename,"L2"));
                //
                // if(!strcmp(tablename,"L1")){
                //     if(!L1.elem)
                //         printf("\n          liear table L1 does not exist!\n");
                //     else if(!ListTrabverse(L1,display))
                //         printf("\n          this liear table is empty!\n");
                // }
                // if(!strcmp(tablename,"L2")){
                //     if(!L2.elem)
                //         printf("\n          liear table L2 does not exist!\n");
                //     else if(!ListTrabverse(L2,display))
                //         printf("\n          this liear table is empty!\n");
                // }
                // getchar();getchar();
                break;
            }
            case 13: printf("\n     here is SaveList(),which  being realized\n");
                // SaveList(L1,DataFileName);
                // getchar();
                break;
            case 14: {
                // printf("\n     here is LoadList(),which  being realized\n");
                // printf("Please input your option[1-2]:");
                // scanf("%d",&op2);
                // switch (op2) {
                //     case 1:
                //         LoadList(L1,DataFileName);
                //         break;
                //     case 2:
                //         LoadList(L2,DataFileName);
                //     default:
                //         break;
                // }
                getchar();getchar();
                break;
            }
            default: ;
        }
    }while(op);
    printf("\n--------------------Welcome again!--------------------\n");
    getchar();
}


/*------------------------------------------------------*/
void menu(void){
    printf("\n\n");
    printf("                               Menu for Linear Table On Sequence Structure \n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("          1. InitList           5. ListLength           9. NextElem             12. ListTrabverse\n");
    printf("          2. DestroyList        6. GetElem              10. ListInsert          13. SaveList\n");
    printf("          3. ClearList          7. LocateElem            11. ListDelete          14. LoadList\n");
    printf("          4. ListEmpty          8. PriorElem            0. Exit\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");

}

status InitList(SqList *L){
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem) {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}//InitList

status DestroyList(SqList L){
    if (!L.elem) {
        return INFEASTABLE;
    }
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}//DestroyList

status ClearList(SqList L){
    if (!L.elem) {
        return INFEASTABLE;
    }
    L.length = 0;
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
    if(!L.elem) return INFEASTABLE;
    if (i < 1 || i > L.length) {
        printf("WRONG INPUT!");
        return ERROR;
    }
    // L.elem = L.elem + i - 1;
    *e = L.elem[i-1];
    return OK;
}//GetElem

status LocateElem(SqList L,ElemType e){
    if (!L.elem) return INFEASTABLE;
    int i;
    for(i = 0; i <= L.length; i++){
        if (L.elem[i] == e) {
            return i+1;
        }
    }
    printf("WRONG INPUT!");
    return ERROR;
}//LocateElem

status PriorElem(SqList L,ElemType cur,ElemType *pre_e){
    if(!L.elem) return INFEASTABLE;
    int s;
    s = LocateElem(L,cur);
    if(s <= 1){
        printf("WRONG INPUT!");
        return 0;
    }
    *pre_e = L.elem[s-2];
    return OK;
}//PriorElem

status NextElem(SqList L,ElemType cur,ElemType *next_e){
    if(!L.elem) return INFEASTABLE;
    int s;
    s = LocateElem(L,cur);
    if (s <= 0 || s >= L.length) {
        printf("WRONG INPUT!");
        return ERROR;
    }
    *next_e = L.elem[s];
    return OK;
}//NextElem

status ListInsert(SqList L,int i,ElemType e){
    if(!L.elem) return INFEASTABLE;
    if (i <= 0 || i > L.length+1) {
        printf("WRONG INPUT!");
        return ERROR;
    }
    // ElemType *p;
    ElemType *newbase, *p, *q;
    if(L.length >= L.listsize){
        newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    q = &(L.elem[i-1]);
    for(p = &(L.elem[L.length-1]); p >= q; --p){
        *(p+1) = *p;
    }
    *q = e;
    ++L.length;
    return OK;
}//ListInsert

status ListDelete(SqList L,int i,ElemType *e){
    if(!L.elem) return INFEASTABLE;
    if (i < 1 || i > L.length) {
        printf("WRONG INPUT!");
        return ERROR;
    }
    *e = L.elem[i-1];
    int j;
    for(j = i; j < L.length; j++){
        L.elem[i-1] = L.elem[i];
    }
    L.length--;
    return OK;
}//ListDelete

status ListTrabverse(SqList L){
    int i;
    if(!L.length) return(0);
    printf("\n-------------all elements of liear table----------------\n");
    for(i=0;i<L.length;i++) {
        printf("%d ", L.elem[i]);
    }

    return OK;
}
