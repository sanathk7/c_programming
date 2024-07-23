#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node* append(struct node* head,int data){
    struct node* temp;
    if (head==NULL){
        head=temp=create(data);
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
        temp=temp->next;
    }
        temp->next=create(data);
        //temp=create(data);
    }
    return head;
}

void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("None\n");
    
}
struct node* reverse(struct node* head){
    struct node* prev=NULL;
    struct node* curr=head;
    struct node* temp=NULL;
    while(curr!=NULL){
         temp=curr->next;
         curr->next=prev;
         prev=curr;
         curr=temp;
    }
    head=prev;
    return head;
}
int main(){
    struct node* head=NULL;
    head=append(head,25);
    head=append(head,35);
    head=append(head,45);
    head=append(head,55);
    display(head);
    head=reverse(head);
    display(head);
    return 0;
    
}
