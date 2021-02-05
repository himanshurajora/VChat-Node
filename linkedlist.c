 #include<stdio.h>
 

struct node{
	int data;
	struct node* next;
};


struct node* START = NULL;
struct node* createnode(){
	struct node* newnode;
	newnode = malloc(sizeof(struct node));
	printf("Enter a value for the node: ");
	scanf("%d", &newnode->data);\
	newnode->next = NULL;
	return newnode;
}

void deletenode(int n){
	struct node *temp, *t;
	temp = START;
	int i;
	for(i=1; i<n; i++){
		t = temp;
		temp = temp->next;
	}
	if(temp == START){
		START = START->next;
	}
	else{
		t->next = temp->next;
		free(temp);
	}
}
void insert(){
	struct node* newnode, *temp;
	newnode = createnode();
	
	if(START == NULL){
		START = newnode;
	}
	else{
		temp = START;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = newnode;
	}
}
void insertatfirst(){
	struct node* newnode, *temp;
	newnode = createnode();
	temp = START;
	START = newnode;
	newnode->next  = temp;
}

void printlist(){
	struct node* temp;
	temp = START;
	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void insertafter(int n){
	struct node* newnode, *temp, *t;
	newnode = createnode();
	int i;
	temp = START;
	for(i=1; i<n; i++){
		if(temp->next == NULL){
			return;
		}
		temp = temp->next;
	}
	t = temp->next;
	temp->next = newnode;
	newnode->next = t;
}

void getlength(){
	struct node *temp;
	int size = 0;
	temp = START;
	while(temp != NULL){
		temp = temp->next;
		size++;
	}
	printf("the size of the list is: %d\n", size);
}
void main(){
	insert();
	insert();
	insert();
	insert();
	insert();
	insert();
	deletenode(4);
	getlength();
	printlist();
}
