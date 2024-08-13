 
 /* -- Implementation of Stack using Array (SMA) without any menu driven approach -- */ 

 #include<stdio.h>
 //#include<conio.h>

 struct Stack 
 {
	int arr[5]; 
	int tos; 
 };
 
 void push(struct Stack *p,int x); 
 int pop(struct Stack *p);  

 int main()
 {
	struct Stack s; 
	s.tos=-1; 
	int x; 
	int i; 
	//clrscr();
	
	//Calling push() 	
	for(i=1;i<=6;i++)
	{
		printf("Enter a number to be pushed ");
		scanf("%d",&x); 
		push(&s,x);
	}	
	
	//Calling pop() 
	for(i=1;i<=6;i++)
	{
	  x=pop(&s);
	  if(x!=0) 
	    printf("Popped Element is %d\n",x);
    }	
    
    //getch();
    return 0;
 }  //end of main()

 //push() defn  (Refer Pseudo Code)
 void push(struct Stack *p,int x) //Function Header
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
 int pop(struct Stack *p) //function header
 {
	int x; //to store top stack value and return to main()
	
	if(p->tos==-1)
	{
		printf("Stack Underflow\n");
		return 0;  // OR return -1;   
	}
	//Pop the top most stack element,decrement tos and return the popped element to main()
	x=p->arr[p->tos];
	p->tos=p->tos-1;	
	return x;		
	//OR return (p->arr[p->tos--]); 
 } //pop() ends
	






