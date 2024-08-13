 //C Program to implement Circular Queue - Menu Driven Approach


 #include<stdio.h>
 //#include<conio.h>
 #include<stdlib.h> //for exit(0);

 struct Queue   
 {
	int arr[5]; 
	int rear,front; 
 };


 void insertq(struct Queue *p,int x);  
 int removeq(struct Queue *p);  
 void display(struct Queue *p); 
 
 //main() definition
 int main()
 { 
	struct Queue q; 
    q.rear=-1; 
	q.front=-1; 
	//q.rear=q.front=-1;  //ONE LINE Statement
	int x; 
	int i; 
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
		                scanf("%d",&x); 
		                insertq(&q,x);
				        break;
			case 2 :
				        x=removeq(&q);
	                    if(x!=-1) 
	                      printf("Removed Element is %d\n",x);
				        break;
			case 3 :
				        display(&q);
				        break;	
			case 4 :
				        exit(0);				        
				     
			default :
				     printf("Invalid Choice");
		}//end of switch
		
		fflush(stdin);  //To flush the stdin (input) buffer
		printf("Do you want to continue (y/n) ");
		scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');
	
	printf("Thank You");
   }  //end of main()	
	


 //insertq() defn  
 void insertq(struct Queue *p,int x) 
 {
   if((p->rear==4 && p->front==0) || (p->rear+1==p->front))  
   {
   	 printf("Queue Overflow(Full)\n");
   	 return; 
   }

   //reset(adjust) rear : 2 possibilities
   if(p->rear==4)   
     p->rear=0;   //place it to 0th index
   else //it means wherever rear is increment it by 1
     p->rear=p->rear+1; //rear will go one index up as usual 
	  
     p->arr[p->rear]=x; //Now store user value(x) data element in to queue 
  
   //Special Condition for first element insertion where front should be set to 0th index 
   if(p->front==-1)  
     p->front=0;   
 }  //insertq() ends

 //removeq() 
 int removeq(struct Queue *p) 
 {
	int x; //to store front queue value and return to main()		
	
	if(p->front==-1) 
	{
		printf("Queue Underflow(Empty)\n");
		return -1;  // OR return 0;   
	}
	
	x=p->arr[p->front];  //remove the data element
		
	//adjust(reset) front 3 Possibilties
	if(p->rear==p->front)  //both are at same index means its the last element of the queue hence remove it.
	  p->rear=p->front=-1;
	else if(p->front==4) //both are not at same index and front is at 4 (array size-1) (ignore rear when both are not at same index)
	  p->front=0;
	else     // front is between 0-3
	  p->front=p->front+1; 	//as usual
	  	
	return x;  //return the deleted element to main()
 } //removeq() ends
	
	 
 void display(struct Queue *p) 
 {
	int x; //to store front queue value and return to main()
	int i;		
	
	if(p->front==-1)   
	{
		printf("Queue Underflow(Empty)\n");
		return;   
	}	
    else
    {
    	if(p->front<=p->rear)
    	{
    	  for(i=p->front;i<=p->rear;i++)
	      { 
		    printf("%d\n",p->arr[i]);
	      }
		}
		else  
		{
		  for(i=p->front;i<5;i++)
	      {
	    	printf("%d\n",p->arr[i]);
		  } 
		  for(i=0;i<=p->rear;i++)
	      {
	    	printf("%d\n",p->arr[i]);
		  }  
		}//end of inner else
  } //end of outer else  
 } //end of display()


	
	






