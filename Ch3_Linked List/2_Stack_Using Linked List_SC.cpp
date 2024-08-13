
 //W.A.P to implement Stack using linked list

 #include<stdio.h>
 #include<stdlib.h> //malloc() & free() are declared
 
 struct Stack 
 {
 	int data;
 	struct Stack *next;
 }; 
 
 void push(struct Stack **ptos,int x);  
 int pop(struct Stack **ptos);  
 void display(struct Stack *ptos);
 int peek(struct Stack *ptos);
  
 int main()
 {
 	struct Stack *tos=NULL;  	 	
 	int x;  
	int option;
	char choice;	
	
	do
	{
		printf("Enter the option from following 1.Push 2.Pop 3.Display All 4.Display Peek Value \n");
		printf("Enter your option ");
		scanf("%d",&option);
		
		switch(option)
		{
					
			case 1 :
				     	printf("Enter a number to be pushed ");
		                scanf("%d",&x); 
		                push(&tos,x);
				        break;
			case 2 :
				        x=pop(&tos);
	                    if(x!=0) 
	                      printf("Popped Element is %d\n",x);
				        break;
			case 3 :
			          display(tos);
					  break;
			case 4 :
			         x=peek(tos);
	                    if(x!=0) 
	                       printf("Peek Element is %d\n",x);
				        break;			
				     
			default :
				     printf("Invalid Choice");
		}//end of switch
		
		fflush(stdin);  //To flush the stdin (input) buffer
		printf("Do you want to continue (y/n) ");
		scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');
	
	printf("Thank You");
 } //end of main()
 	 

 void push(struct Stack **ptos,int x) 
 {
 	struct Stack *p;
 	
 	p=(struct Stack *)malloc(sizeof(struct Stack));  	
 	
 	if(p==NULL) 
 	{
 		printf("Stack Overflow\n");
 		return;
	}
	p->data=x;
	p->next=*ptos; 
	*ptos=p;   
 }//end of push()
 
 
 int pop(struct Stack **ptos)
 {
 	struct Stack *temp;
 	int x;
 	
 	
 	if(*ptos==NULL)  
 	{
 		printf("Stack Underflow\n");
 		return 0;  
	}
	temp=*ptos; 
	x=temp->data;
	
	*ptos=temp->next;	
	free(temp); //delete the node 
	return x; 
 } //end of pop() 
 
 void display(struct Stack *p) 
 {
 	if(p==NULL)
 	{
 		printf("Stack Underflow\n");
 		return;
	}
	printf("The Stack Elements are \n");
	while(p!=NULL)
	{
	  printf("%d\n",p->data);
	  p=p->next; 
	}	
 } //end of display()
 
 //peek()
 int peek(struct Stack *p)
 {
   	int x;
 	
 	if(p==NULL)
 	{
 		printf("Stack Underflow\n");
 		return 0;
	}	
	x=p->data;
	return x;	
 } //end of peek()
 
 
 
 
 
 
 
 
 
 
 
 
 
