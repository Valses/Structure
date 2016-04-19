#include "Exp1.h"
#include <stdio.h>
#include <stdlib.h>

void menu(void);

int main(int argc, char const *argv[]) {

    ElemType p,q;
    int op = 0,op2 = 1;
    int num,k = 0;
    int flag = 0;
    int loc;
    char *DataFileName = "SequenceStructure.ini";

    printf("\n\n    ----  Input the number of the Linear Table you want to build: ");
    scanf("%d",&num);
    SqList L[num];
    do{
        L[k].elem = NULL;
        k++;
    }while(k<num);
    menu();
    do {
        printf("\n\n    ----  Please input your option[0-15]: ");
        scanf("%d",&op);
        switch(op){
            case 0: break;
            case 1: {
                //printf("\n     Here is IntiaList(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(InitList(&(L[op2-1])) == 1)
                    printf("\n          The L%d is created successfully.",op2);
                else if(InitList(&(L[op2-1])) == -2)
                    printf("\n          Overflow,failed to create!");
                else if(InitList(&(L[op2-1])) == -1)
                    printf("\n          The L%d has already been created.",op2);
                getchar();
                break;
            }
           case 2: {
                //printf("\n     Here is DestroyList(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(DestroyList(&L[op2-1]) == 1){
                    printf("\n          The L%d has been destroyed successfully.",op2);
                }
                else if(DestroyList(&L[op2-1]) == -1)
                    printf("\n          The L%d is not exist!",op2);
                getchar();
                break;
            }
            case 3: {
                //printf("\n     Here is ClearList(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(ClearList(&L[op2-1]) == 1){
                    printf("\n          The L%d has been cleared successfully.",op2);
                }
                else if(ClearList(&L[op2-1]) == -1)
                    printf("\n          The L%d is not exist!",op2);
                getchar();
                break;
            }
            case 4: {
                //printf("\n     Here is ListEmpty(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if (ListEmpty(L[op2-1]) == -1)
                     printf("\n          The L%d is not exist!",op2);
                else if (ListEmpty(L[op2-1]) == 0)
                    printf("\n          The List%d is not Empty.",op2);
                else if(ListEmpty(L[op2-1]) == 1)
                    printf("\n          The List%d is Empty.",op2);
                getchar();
                break;
            }
            case 5: {
                //printf("\n     Here is ListLength() ,which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(ListLength(L[op2-1]) == -1){
                    printf("\n          The L%d is not exist!",op2);
                }
                else if(ListLength(L[op2-1]) >= 0)
                    printf("\n          The L%d has %d elem.",op2,ListLength(L[op2-1]));
                getchar();
                break;
            }
            case 6: {
                //printf("\n     Here is GetElem(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem){
                    printf("\n          The L%d is not exist!",op2);
                    break;
                }
                printf("\n          Please input the element's location for searching: ");
                scanf("%d",&flag);
                if(GetElem(L[op2-1],flag,&p) == 0)
                    printf("\n          WRONG INPUT!");
                else if(GetElem(L[op2-1],flag,&p) == 1)
                    printf("\n          The NO.%d element is %d in L%d.",flag,p,op2);
                getchar();
                break;
            }
            case 7: {
                //printf("\n     Here is LocateElem(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem){
                    printf("\n          The L%d is not exist!",op2);
                    break;
                }
                printf("\n          Please input a integer for searching elem: ");
                scanf("%d",&p);
                if(LocateElem(L[op2-1], p) == 0)
                    printf("\n          The element %d is not exist in the list L%d!",p,op2);
                else
                    printf("\n          The element %d is No.%d in the list L%d.",p,LocateElem(L[op2-1], p),op2);
                getchar();
                break;
            }
            case 8: {
                //printf("\n     Here is PriorElem(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem){
                    printf("\n          The L%d is not exist!",op2);
                    break;
                }
                printf("\n          Please input the current element: ");
                scanf("%d",&p);
                if(PriorElem(L[op2-1], p, &q) == 0)
                    printf("\n          This is the first element!");
                else if(PriorElem(L[op2-1], p, &q) == 1)
                    printf("\n          The element's PriorElem is %d",q);
                else if(PriorElem(L[op2-1], p, &q) == -2)
                    printf("\n          The element is not in the list L%d.",op2);
                getchar();
                break;
            }
            case 9: {
                //printf("\n     Here is NextElem(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem){
                    printf("\n          The L%d is not exist!",op2);
                    break;
                }
                printf("\n          Please input the current element: ");
                scanf("%d",&p);
                if(NextElem(L[op2-1], p, &q) == 0)
                    printf("\n          This is the last element!");
                else if(NextElem(L[op2-1], p, &q) == 1)
                    printf("\n          The element's NextElem is %d",q);
                else if(NextElem(L[op2-1], p, &q) == -2)
                    printf("\n          The element is not in the list L%d.",op2);

                getchar();
                break;
            }
            case 10: {
                //printf("\n     Here is ListInsert(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem){
                    printf("\n          The L%d is not exist!",op2);
                    break;
                }
                printf("\n          Please input elem which need Insert: ");
                scanf("%d",&p);
                printf("\n          Please input the Location: ");
                scanf("%d",&loc);
                if(ListInsert(&L[op2-1], loc, p) == 1)
                    printf("\n          The element:%d is inserted successfully.",p);
                else if(ListInsert(&L[op2-1], loc, p) == 0)
                    printf("\n          WRONG INPUT!");
                getchar();
                break;
            }
            case 11: {
                //printf("\n     Here is ListDelete(),which  being realized\n");
               printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
               if(!L[op2-1].elem){
                    printf("\n          The L%d is not exist!",op2);
                    break;
                }
                printf("\n          Please input the element's location which need to be deleted: ");
                scanf("%d",&loc);
                if(ListDelete(&L[op2-1], loc, &p) == 1)
                    printf("\n          The element:%d is deleted successfully.",p);
                else if(ListDelete(&L[op2-1], loc, &p) == 0)
                    printf("\n          WRONG INPUT!");
                getchar();
                break;
            }
            case 12: {
                // printf("\n     Here is ListTrabverse(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem) printf("\n          The L%d is not exist!",op2);
                else if(!L[op2-1].length) printf("\n          The L%d is empty!",op2);
                else ListTraverse(L[op2-1]);
                getchar();
                break;
            }
            case 13: {
                menu();
                break;
            }
            case 14: {
                //printf("\n     here is SaveList(),which  being realized\n");
                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }
                if(!L[op2-1].elem) printf("\n          The L%d is not exist!",op2);
                else{
                    flag = SaveList(L[op2-1],DataFileName);
                    if(flag) printf("\n          SaveList successfully.");
                    else
                        printf("\n          SaveList error.");

                }
                getchar();
                break;
            }
            case 15: {
                //printf("\n     here is LoadList(),which  being realized\n");

                printf("\n    ----  Input the number of the Linear Table: ");
                scanf("%d",&op2);
                if(op2 > num || op2 <= 0){
                    printf("\n          Wrong list's name!");
                    break;
                }

                flag = LoadList(&L[op2-1],DataFileName);
                if(flag == 1) printf("\n          LoadList successfully.");
                else if(flag == -2)
                    printf("\n          Overflow!");
                else
                    printf("\n          LoadList error!");
                getchar();
                break;
            }
            default: {
                printf("\n          WRONG INPUT!");
            }
        }
    }while(op);
    printf("\n-----------------------------Welcome again!-----------------------------\n");
    getchar();

    return 0;
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
    printf("          13.Menu             14.SaveList         15.LoadList      \n");
    printf("          0. Exit\n");
    printf("------------------------------------------------------------------------");
}

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
/*------------------------------------------------------*/
status SaveList(SqList L,char *pFile){
    FILE *fin;
    int i;
    fin = fopen(pFile, "wb");
    for (i = 0; i < L.length; i++)
        fprintf(fin,"%d\n",*(L.elem + i));
    fclose(fin);
    return OK;
}
status LoadList(SqList *L,char *pFile){
    FILE *fout;
    ElemType *newbase;
    int i=0;
    if (!L->elem)
        InitList(L);

    if ((fout = fopen(pFile, "rb")) == NULL){
        printf("\n          The File is not exited!");
        return ERROR;
    }
    L->length = 0;
    while ((fscanf(fout, "%d\n",(L->elem + i)) != EOF)){
        if (L->length >= L->listsize){
            newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
            if (!newbase)
                exit(OVERFLOW) ;
            L->elem = newbase;
            L->listsize += LISTINCREMENT;
        }
        i++;
        L->length++;
    }
    fclose(fout);
    return OK;
}
