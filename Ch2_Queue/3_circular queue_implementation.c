  //C Program to implement Circular Queue 
 
 #include<stdio.h>
 //#include<conio.h>

 struct Queue   
 {
	int arr[5]; 
	int rear,front; 
 };

 void insertq(struct Queue *p,int x);  
 int removeq(struct Queue *p);  

 //main() definition
 int main()
 { 
	struct Queue q; 
    q.rear=-1; 
	q.front=-1; 
	//q.rear=q.front=-1;  //ONE LINE Statement
	int x; 
	int i; 	
	
	//Calling insertq() 	
	for(i=1;i<=6;i++)
	{
		printf("Enter a number to be inserted ");
		scanf("%d",&x); 
		insertq(&q,x);
	}	
	//Calling removeq()
	for(i=1;i<=6;i++)
	{
	  x=removeq(&q);
	  if(x!=-1) 
	    printf("Removed Element is %d\n",x);
    }	
 } //end of main()

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
	
	






