                                             
 //W.A.P to evaluate the given postfix expression
 
 #include<stdio.h>
 //#include<conio.h>
 #include<math.h>
 
 //struct declr
 struct Stack
 {
 	float arr[10];
 	int tos;
 };
 
 void push(struct Stack *p,float x);  
 float pop(struct Stack *p);  
 float solve(char postfix[]);   //OR float solve(char *postfix); 
 int isoprnd(char ch);
 float calculate(float op1,float op2,char opt);
 
 int main()
 {
 	char postfix[20];
 	float ans;
 	
 	printf("Enter valid Post-fix expression ");
 	scanf("%s",postfix);
 	
 	ans=solve(postfix);
 	printf("Result of %s is %f",postfix,ans);
 	
 	return 0;
 } //end of main()
 
 
 //push() defn  (Refer Pseudo Code)
 void push(struct Stack *p,float x) //Function Header
 {
   if(p->tos==9)  
   {
   	 printf("Stack Overflow\n");
   	 return; 
   }
   //Increment tos and push the element in the stack pointed by tos using ->
   p->tos=p->tos+1; //tos will go one index up   
   p->arr[p->tos]=x; //store user value(x) in to stack
   
    // OR p->arr[++p->tos]=x;  //in one line instead of above 2 lines
 }  //end of push()
 
 //pop() defn 
 float pop(struct Stack *p) //function header
 {
	float x; //to store top stack value and return to main()
	
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
 
 //solve() defn
 float solve(char postfix[]) //char *postfix
 {
 	struct Stack s; 
	s.tos=-1; 
	
	int i; //for traversing purpose of postfix expression
	char ch; //to store each char from the postfix expression
	float op1,op2,ans;
	
	for(i=0;postfix[i]!='\0';i++)  //OR postfix[i]
	{
	  ch=postfix[i];
	  
	  if(isoprnd(ch)==1) //if ch is a digit (0-9)
	  {
	  	push(&s,(float)(ch-48)); //pushing the face value of ch
	  }//end of if
	  else //if ch is an operator (+,*,-.....)
	  {
	  	op2=pop(&s); 
	  	op1=pop(&s);
	  	
	  	ans=calculate(op1,op2,ch);
	  	push(&s,ans);
	  } //end of else	
	} //end of for
	return ans;
 } //end of solve()
 
 //isoprnd() defn is called by solve()
 /*It will return an int value ie if ch is a digit(0-9) then 1 will be returned
   else it will return 0 */
 int isoprnd(char ch)
 {
 	if(ch>=48 && ch<=57)  //OR if(ch>='0' && ch<='9')
 	{
 	   return 1;	
	}
	else
	{
		return 0;
	}	
  }  //end of isoprnd()
  
  /*
  int isoprnd(char ch)
  {
 	return (ch>=48 && ch<=57);
  }  */
  
  
  //calculate will be called by solve() and it returns the result of operation
  float calculate(float op1,float op2,char opt)
  {
  	  switch(opt)
  	  {
  	  	case '+':
  	  		      return (op1+op2);
  	  	case '-':
  	  		      return (op1-op2);
  	  	case '*':
  	  		      return (op1*op2);
  	  	case '/':
  	  		      return ((float)op1/op2); //type casting
  	  	case '$':
  	  		      return (pow(op1,op2));
  	  	case '%' :
  	  		       return(fmod(op1,op2));
  	    default :
  	    	       return (0.0);
  	  		      
		}//end of switch()
  }
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
