Separate Chaining in hashing
 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node {
      int data;
      struct node *next;
};
struct node *head[SIZE]={NULL};
void insert(int k){
      int hk=k%SIZE;
      struct node *newnode;
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=k;
      newnode->next=head[hk];
      head[hk]=newnode;
}
void display(){
      int i;
      for(i=0;i<SIZE;i++)
      {
            struct node *t=head[i];
            printf("head[%d]->",i);
            while(t!=NULL){
                  printf("%d-->",t->data);
                  t=t->next;
            }
            printf("NULL\n");
      }
}
void search(int skey){
      int hk=skey%SIZE;
      struct node *t=head[hk];
      while(t!=NULL){
            if(t->data==skey){
                  printf("key found\n");
                  break;
            }
            t=t->next;
      }
      if(t==NULL)
       printf("key not found");
}
int main(){
      int i,k,op;
      while(1){
            printf("1.insert 2.display 3.search othersExit\n");
            scanf("%d",&op);
            switch(op){
                  case 1:
                        scanf("%d",&k);
                        insert(k);
                        break;
                  case 2:
                        display();
                        break;
                  case 3:
                     scanf("%d",&k);      
                     search(k);
                     break;
                  default:
                        exit(0);
            }
      } 
}
