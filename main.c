#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* getNode(int x);
struct node* insert(struct node* root,int data){
    if(root ==NULL){
        root=getNode(data);
        return root;
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else root->right=insert(root->right,data);

    return root;
}

struct node* getNode(int x){
    struct node* newNode=(struct node*)malloc (sizeof(struct node));
    newNode->data=x;
    newNode->left=newNode->right=NULL;

    return newNode;
}

bool search(struct node* root,int data){
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return search(root->left,data);
    else  return search(root->right,data);
}

int main(){
    struct node* root=NULL;
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,2);
    root=insert(root,8);

    if(search(root,0)==true) printf("true;");
    else printf("False");
}