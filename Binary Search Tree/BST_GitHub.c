#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};


struct node *NewNode(int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
	
}

void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d \n",root->data);
		inorder(root->right);
	}
}


struct node *insert(struct node *root , int data ){
	
	if(root == NULL){
		return NewNode(data);
	}
	
	if(data<root->data ){
		root->left=insert(root->left,data);
		}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}
	
	return root;
	
}

struct node *minval(struct node *node){
	
	struct node *cur = node;
	while(cur->left!=NULL){
		cur=cur->left;
	}
	return cur;
}



void search(struct node *root, int data){
	
	if(root==NULL)
		printf("number is not found! \n");
	
	else if(root->data==data){
		printf("number is found! \n");
	}
	else if( data < root->data){
		search(root->left, data);
	}
	else if(data >= root->data){
		search(root->right, data);
	}
}


struct node *delete_node(struct node* root, int data){

	if(root==NULL)
		return root;
	
	if(data<root->data)
		root->left = delete_node(root->left,data);
	
	else if(data> root->data)
		root->right = delete_node(root->right,data);
	
	else{
		if(root->left==NULL){
			struct node *temp = root->right;
			printf("%d is deleted \n\n", root->data);
			free(root);
			return temp;
			
			
		}
		
		else if(root->right==NULL){
			struct node *temp = root->left;
			printf("%d is deleted \n\n", root->data);
			free(root);
			return temp;
		
		}
		
		else{
			struct node *temp = minval(root->right);
			printf("%d is deleted \n\n", root->data);
			root->data=temp->data;
			return delete_node(root->right, temp->data);
		}
	}
return root;
}



int main(int argc, char *argv[]) {
	
	struct node *root = NULL;
	root = insert(root,5);
	insert(root,78);
	insert(root,90);
	insert(root,3);
	insert(root,14);
	insert(root,7);
	insert(root,4);
	insert(root,80);
	insert(root,20);
	insert(root,16);	
	insert(root,17);
	insert(root,70);
	
	inorder(root);
	
	search(root,100);
	search(root,5);
	
	delete_node(root,5);
	delete_node(root,90);
	delete_node(root,3);

	inorder(root);
	
	return 0;
}
