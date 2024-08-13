
 //Conversion from a valid Infix Expression to Postfix Expression.

 #include<stdio.h>
 //#include<conio.h>
 
 struct Stack
 {
 	char arr[10];  //char array(string) only operators will be stored
 	int tos;
 };
 
 void push(struct Stack *p,char ch);  
 char pop(struct Stack *p);  
 int isoprnd(char ch); 
 int isempty(struct Stack s);  
 int prcd(char op1,char op2);   
 void convert(char infix[],char postfix[]);  
   
  //main() definition  
  int main()
  {
  	 char infix[20],postfix[20];  //result stored in postfix
  	 
  	 printf("Enter infix expression ");
  	 scanf("%s",infix);
  	 
  	 convert(infix,postfix); //call by reference used 
  	 printf("Postfix expression is %s",postfix); 
	    	 
  	 return 0;  	 
 }
 
 //convert() definition  - V.IMP (array names are pointer variables only internally)
 void convert(char infix[],char postfix[])   //void char(char *infix,char *postfix)
 { 	
	struct Stack s;   
	s.tos=-1; 	
 	int i,j=0; 

	char ch; //to scan infix char array char by char   
	int pr; //for storing operator precedence result(1 or 0) //int result;
	 
	//Pseudo Code - Real Algorithm		
	for(i=0;infix[i]!='\0';i++) 
	{
		ch=infix[i]; // copy infix char into ch to check its operand or operator
	
		//if else used for character is operand or operator.		
		if(isoprnd(ch)==1) //if ch is an operand then copy into the postfix array
		{
			postfix[j]=ch; //copy ch 
			j++; //increment j by 1
		}//end of if		
		else  //if infix ch is an operator (----many things to be done---)
		{
			while(isempty(s)==0) //returns 0(false) if stack is not empty			
			{			   
			   pr=prcd(ch,s.arr[s.tos]);  			    			   
			   if(pr==1) //push the element which is written outside this while loop (IMP)
			   {
			    	break;  //exit from the while loop
			   }			    
			 	postfix[j]=pop(&s);  //tos char (operator)
			    j++; //j is managing the postfix array		       
			}//end of while			 
	  push(&s,ch);	//into the stack
    }//end of else	  
	}//end of for - Now "infix is complete but in stack may be some operators are still left" 
 	
 	while(isempty(s)==0) //returns 0 if stack is not empty
 	{
 		postfix[j]=pop(&s);
 		j++;
 	}//end of while loop
 	postfix[j]='\0'; //for end of postfix expression its programmer's responsibility	
  }//end of convert()   
       
   
   int isoprnd(char ch)  
   {
   	 //ch can be uppercase,lower case or digit char 
	 if( (ch>=65&&ch<=90)||
	     (ch>=97&&ch<=122)||
		 (ch>=48&&ch<=57) )
   	   return 1; //if char is an operand
	 else //If all above conditions are false
	    return 0;  //if char is an operator	 
   }
   
    
    int isempty(struct Stack s)
    {
   	  if(s.tos==-1)
   	     return 1;  //stack is empty
   	  else
		 return 0;  //stack is not empty		 
	  //return (s.tos==-1);	 "Single Line Version" (== operator gives 1(true) or 0(false)) 
    }
 
 
  //push() defn
   void push(struct Stack *p,char x)
   {
     if(p->tos==9)
     {
     	printf("Stack Overflow");
     	return;
	 }
	 p->tos=p->tos+1;
	 p->arr[p->tos]=x;	 
   }//end of push()   
   
   
   //pop() defn
   char pop(struct Stack *p)
   {
   	char x;   	
   	if(p->tos==-1)
   	{
   		printf("Stack Empty (Underflow)");
   		return '\0';
	}	
	x=p->arr[p->tos];
	p->tos=p->tos-1;	
	return x;
   }//end of pop()
   
  
      
 /*prcd() definition op1 means outside operator and op2 means tos operator 
 
  Returns 1 if outside operator precedence > top of stack operator (inside) 
  then outside operator will be pushed in to the stack.
  
  Returns 0 if inside operator precedence >= outside operator precedence 
  then pop the top stack operator(inner operator) from the stack.
  
  op1 means outside operator
  op2 tos operator
 */    
  
  int prcd(char op1,char op2)  
  {
 	if(op2=='$') 
 	   return 0; 
 	else if(op1=='$') 
 	  return 1;  
 	else if(op2=='*'||op2=='/'||op2=='%') 
 	  return 0;  
 	else if(op1=='*'||op1=='/'||op1=='%') 
 	  return 1;  
 	else if(op2=='+'||op2=='-') 
 	  return 0;  
 	else  
 	   return 1; 
  }//end of prcd()
  
  
  
