#include <stdio.h>
#include <stdlib.h>
struct node
{
	char data;
	struct node* next;
};
void addNode(char ch, struct node** ptr)
{
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ch;
	if(*ptr == 0){
		*ptr = temp;
		temp->next = 0;
	}
	else{
		struct node* last = *ptr;
		while(last->next != 0){
			last = last->next;
		}
		last->next = temp;
		temp->next =0;
	}
}
void print(struct node*ptr)
{
	while(ptr != 0){
		printf("%c",ptr->data);
		ptr = ptr->next;
	}
}
void reversePrint(struct node*ptr)
{
	if(ptr->next != 0){
		reversePrint(ptr->next);
	}
	printf("%c",ptr->data);
}
int main(int argc, char**argv)
{
	if(argc != 2)
	{
		if(argc == 1){
			printf("You should provide atleast one command line argument\n");
			return 0;
		}
		else{
			printf("Format --> ./a.out inputWord\n");
			return 0;
		}
	}
	struct node** head = 0;
	int i;
	for(i=0;argv[1][i];i++){
		addNode(argv[1][i],(struct node**)&head);
	}
	printf("Normal print ->");
	print((struct node*)head);
	printf("\n");
	printf("Reverse print ->");
	reversePrint((struct node*)head);
	printf("\n");
}

