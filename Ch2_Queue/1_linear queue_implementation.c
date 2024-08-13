 // A C Program to implement Linear Queue 
 
 #include<stdio.h>
 //#include<conio.h>
 
 //Structure Declaration
 struct Queue 
 {
	int arr[5]; 
	int rear,front; 
 };

 //Function Headers(Template) - insertq() & deleteq()   
 void insertq(struct Queue *p,int x);  
 int removeq(struct Queue *p);

 //main() definition
 int main()
 {
	struct Queue q;  	
	q.rear=-1; 
	q.front=0; 
	
	int x; //To store value received from the user or during deletion.
	int i; //loop variable used as insertq() and deleteq() are called multiple times from main().	
	
	//Calling insertq() 	    
	for(i=1;i<=6;i++)
	{
		printf("Enter a number to be inserted ");   
		scanf("%d",&x); //Assume as of now user wont enter 0 as a value 
		insertq(&q,x);
	}		
	//Calling removeq()
	for(i=1;i<=6;i++)
	{
	  x=removeq(&q);
	  if(x!=0) 
	    printf("Removed Element is %d\n",x);
    }	
 }//end of main()


 //insertq() defn  (Refer Pseudo Code)
 void insertq(struct Queue *p,int x) 
 {
   if(p->rear==4)  
   {
   	 printf("Queue Overflow(Full)\n");
   	 return; 
   }
   p->rear=p->rear+1; //rear will go one index up   
   p->arr[p->rear]=x; //store user value(x) in to queue currently pointed by rear   
   // OR p->arr[p->rear++]=x;  //in one line instead of above 2 lines
 }  //insertq() ends

 //removeq() defn (Refer Pseudo Code)
 int removeq(struct Queue *p) 
 {
	int x; //to store front queue value and return to main()		
	
	if(p->front > p->rear)  //*** TWIST *** not like stack if(p->tos==-1)
	{
		printf("Queue Underflow(Empty)\n");
		return 0;  // OR return -1;   
	}	
	x=p->arr[p->front];
	p->front=p->front+1;   //IMP Change In stack it was p->tos=p->tos-1;	
	return x;			
	//OR return (p-->arr[p->front++]); 
 } //removeq() ends
	






