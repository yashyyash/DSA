// A C Program to implement Linear Queue using switch

 #include<stdio.h>
 //#include<conio.h>
 #include<stdlib.h>  //exit(0) - successful exit hence 0

 struct Queue  //structure is declared (global declr) 
 {
	int arr[5]; 
	int rear,front; 
 };
 
 void insertq(struct Queue *p,int x);  //Function Header(Template)
 int removeq(struct Queue *p);
 void display(struct Queue  *p);

 //main() definition
 int main()
 {
	struct Queue q; 
	q.rear=-1; //Initial value we are assuming OR Q.rear=0; is also fine
	q.front=0; 
	int x; //To store value received from the user or during deletion.
	int i; //loop variable used as insertq() and deleteq() are called multiple times from main().
	int option;
	char choice;
	
	do
	{
	    printf("Enter the option from following 1.Insert 2.Remove 3.Display Queue 4.Exit \n");
		printf("Enter your option ");
		scanf("%d",&option);
		
		switch(option)
		{
					
			case 1 :
				     	printf("Enter a number to be stored ");
		                scanf("%d",&x); //Assume as of now user wont enter 0 as a value 
		                insertq(&q,x);
				        break;
			case 2 :
				        x=removeq(&q);
	                    if(x!=0) 
	                      printf("Removed Element is %d\n",x);
				        break;
			case 3 :
				        display(&q);
				        break;	
			case 4 :
				        printf("Thanks for using our App");
				        exit(0); //#include<stdlib.h>
				     
			default :
				     printf("Invalid Choice");
		}//end of switch
		
		fflush(stdin);  //To flush the stdin (input) buffer
		printf("Do you want to continue (y/n) ");
		scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');
	
	printf("Thank You");
   }  //end of main()	


 //insertq() defn  (Refer Pseudo Code)
 void insertq(struct Queue *p,int x) //Function Header
 {
   if(p->rear==4)  //rear is at last index of array(p is pointer variable of structure and not struct variable.
   {
   	 printf("Queue Overflow(Full)\n");
   	 return; //to stop further execution of insert() and control goes back to main()
   }

   p->rear=p->rear+1; //rear will go one index up   
   p->arr[p->rear]=x; //store user value(x) in to queue currently pointed by rear
   
   // OR p->arr[p->rear++]=x;  //in one line instead of above 2 lines
 }  //insertq() ends

 //removeq() defn (Refer Pseudo Code)
 int removeq(struct Queue *p) //function header
 {
	int x; //to store front queue value and return to main()
		
	//(Whenever front > rear linear queue will be in a state of Underflow)
	if(p->front > p->rear)  //*** TWIST *** and not like in stack if(p->tos==-1) 
	{
		printf("Queue Underflow(Empty)\n");
		return 0;  // OR return -1;   
	}
	
	x=p->arr[p->front];
	p->front=p->front+1; //IMP Change In stack it was p->tos=p->tos-1;	
	return x;	
		
	//OR return (p-->arr[p-->front++]); 
 } //removeq() ends
 
 void display(struct Queue *p) 
 {		
	
	if(p->front > p->rear) 
	{
		printf("Queue Underflow(Empty)\n");
		return;   
	}
	
	int i;
	for(i=p->front;i<=p->rear;i++)
	{
		printf("%d\n",p->arr[i]);
	}
	
 } //display() ends
	






