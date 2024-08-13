 /* -- Implementation of Stack using Array (SMA) using menu driven approach
       by using do-while and switch approach -- */ 

 #include<stdio.h>

 struct Stack  
 {
	int arr[5]; 
	int tos; 
 };
  
 void push(struct Stack *p,int x);
 int pop(struct Stack *p);  
 void display(struct Stack *p);
 int peek(struct Stack *p);

 int main()
 {
	struct Stack s; 
	s.tos=-1; 
	int x; 
	int i; 
	int option;
	//int x,i,option;
	char choice;
	
	do
	{
		printf("Enter the option from following 1.Push 2.Pop 3.Display 4.Peek \n");
		printf("Enter your option ");
		scanf("%d",&option);
		
		switch(option)
		{
					
			case 1 :
				     	printf("Enter a number to be pushed ");
		                scanf("%d",&x); //Assume as of now user wont enter 0 as a value 
		                push(&s,x);
				        break;
			case 2 :
				        x=pop(&s);
	                    if(x!=0) 
	                      printf("Popped Element is %d\n",x);
				        break;
			case 3 :
				     display(&s);
				     break;
			case 4 :
				        x=peek(&s);
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
 }  //end of main()


 //push() defn  (Refer Pseudo Code)
 void push(struct Stack *p,int x) 
 {
   if(p->tos==4)  
   {
   	 printf("Stack Overflow\n");
   	 return; 
   }
   p->tos=p->tos+1;   
   p->arr[p->tos]=x;    
    // OR p->arr[++p->tos]=x;  //in one line instead of above 2 lines
  }  //end of push()

 //pop() defn 
 int pop(struct Stack *p) 
 {
	int x; 
	
	if(p->tos==-1)
	{
		printf("Stack Underflow\n");
		return 0;  // OR return -1;   
	}	
	x=p->arr[p->tos];
	p->tos=p->tos-1;
	
	return x;		
	//OR return (p->arr[p->tos--]); 
 } //pop() ends

 //display() definition
 void display(struct Stack *p)
 {
    if(p->tos==-1)
	{
		printf("Stack Underflow\n");
		return;		   
	}	
	
	int i;
	for(i=0;i<=p->tos;i++)
	{
		printf("%d\n",p->arr[i]);
	}	
	
 }//end of display()

 //peek() defn 
 int peek(struct Stack *p) 
 {
	int x; 
	
	if(p->tos==-1)
	{
		printf("Stack Underflow\n");
		return 0;  // OR return -1;   
	}	
	x=p->arr[p->tos];
	
	return x;		
	//OR return (p->arr[p->tos]); 
 } //pop() ends
	






