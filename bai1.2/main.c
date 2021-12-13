#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    char sdt[30];
    char name[30];
    char gmail[30];
    struct link *next;
};
typedef struct link *node;
typedef struct
{
    char name[20],email[20],sdt[20];
} st;
st fi[30];
char x,y[1000];
int BinarySearch(st A[ ], char x[], int Low, int High ) {
    if (Low > High) return -1;
    int Mid = ( Low + High ) / 2;
    if (strcmp(A[Mid].name,x) < 0 )
        return BinarySearch(A, x, Mid+1, High);
    if (strcmp(A[Mid].name,x) > 0 )
        return BinarySearch(A, x, Low, Mid-1);
    if (strcmp(A[Mid].name,x) == 0 )
        return Mid;
    return -1;
}
node crt(char a[], char b[], char c[]){
    node p;
    p = (node)malloc(sizeof(struct link));
    p->next = NULL;
    strcpy(p->name,a);
    strcpy(p->sdt,b);
    strcpy(p->gmail,c);
    return p;
}
node ahead(){
    node head;
    head = NULL;
    return head;
}
node themcuoi(node head, char a[], char b[], char c[]){
    node x,p;
    x = crt(a,b,c);
    if(head == NULL){
        head = x;
    }
    else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = x;
    }
    return head;
}

void in(node head){
    printf("\nDanh sach:\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%s\n",p->sdt);
        printf("%s\n",p->name);
        printf("%s\n",p->gmail);
    }
}
int main(){
    int dem1=0,dem2=0,dem3=0;
    FILE *f=fopen("ds.txt","r+");
    FILE *dr=fopen("daura.txt","r+");
    while(fscanf(f,"%c",&x)!=EOF){
        y[dem1]=x;
        dem1++;
        if(x=='\n'){
            dem3=0;
            dem2++;
        }
        if(dem2%3==0){
            fi[dem2/3].name[dem3]=x;
        }
        if(dem2%3==1){
            fi[dem2/3].sdt[dem3]=x;
        }
        if(dem2%3==2){
            fi[dem2/3].email[dem3]=x;
        }
        dem3++;
        if(x=='\n'){
            dem3--;
        }
    }
    y[dem1]='\0';
    int size=(dem2)/3;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(strcmp(fi[i].name,fi[j].name)>0){
                st a=fi[i];
                fi[i]=fi[j];
                fi[j]=a;
            }
        }
    }
    node head = ahead();
    for(int i=0;i<size;i++){
        head=themcuoi(head,fi[i].name,fi[i].sdt,fi[i].email);
    }
    for(node p = head; p != NULL; p = p->next){
        fprintf(dr,"%s\n",p->name);
        fprintf(dr,"%s\n",p->sdt);
        fprintf(dr,"%s\n",p->gmail);
    };
    int a = BinarySearch(fi,"hoangtheanh",0,size-1);
    if(a!=-1){
        fprintf(dr,"\nVi tri: %d\nten: %s\nsdt: %s\ngmail: %s\n",a+1,fi[a].name,fi[a].sdt,fi[a].email);
    }
    else{
        fprintf(dr,"\nkhong tim thay\n");
    };
    fclose(f);
    fclose(dr);
}
