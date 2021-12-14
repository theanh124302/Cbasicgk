#include <stdio.h> //bai 1.3 va 1.4
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20],email[20],sdt[20];
} st;
st s[30],fi[30];
int front=0;
int rear=0;
void Enqueue(st s[], int *rear, int arraySize,char a[], char b[], char c[]) {
    if(*rear == arraySize)
            printf("Hang cho da day\n");
    else{
         strcpy(s[*rear].name,a);
         strcpy(s[*rear].sdt,b);
         strcpy(s[*rear].email,c);
         (*rear)++;
    }
}
void Dequeue(st s[], int *front, int rear) {
    if(*front == rear)
        printf("Hang cho da can\n");
    else {
        s[*front].name[0]='\0';
        s[*front].sdt[0]='\0';
        s[*front].email[0]='\0';
        (*front)++;
    }
}
void search(st s[], int rear, int front, FILE *dr)
{
    char x[100];
    printf("ten muon tim kiem: ");
    fflush(stdin);
    gets(x);
    for(int i=front;i<rear;i++){
        if(strcmp(s[i].name,x)==0){
            fprintf(dr,"\n\nket qua tim kiem : \nvi tri: %d\n",i);
            fprintf(dr,"ten: %s\nsdt: %s\ngmail: %s\n",s[i].name,s[i].sdt,s[i].email);
        }
    }
}
char x,y[1000];
int main(){

    int dem1=0,dem2=0,dem3=0;
    FILE *f=fopen("ds.txt","r+");
    FILE *dr=fopen("daura.txt","w+");
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
    for(int i=0;(i<size&&i<10);i++){
        Enqueue(s,&rear,size,fi[i].name,fi[i].sdt,fi[i].email);
    }
    for(int i=front;i<rear;i++){
        fprintf(dr,"ten: %s\nsdt: %s\ngmail: %s\n",s[i].name,s[i].sdt,s[i].email);
    }
    if(size>9){
        fprintf(dr,"\n\nphan tu bi day ra: \nten: %s\nsdt: %s\ngmail: %s\n\n",s[0].name,s[0].sdt,s[0].email);
        Dequeue(s,&front,rear);
    }
    Enqueue(s,&rear,size,fi[10].name,fi[10].sdt,fi[10].email);
    fprintf(dr,"sau khi day phan tu thu 11 vao:\n");
    for(int i=front;i<rear;i++){
        fprintf(dr,"%d  ten: %s\nsdt: %s\ngmail: %s\n",i,s[i].name,s[i].sdt,s[i].email);
    }
    search(s,rear,front,dr);
    int n=rear-front;
    for(int i=0;i<n;i++){
        Dequeue(s,&front,rear);
    }
    fclose(f);
    fclose(dr);
}
