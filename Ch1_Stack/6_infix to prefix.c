
 //Conversion from Infix Expression to Prefix Expression.

 #include<stdio.h>
 #include<string.h>  //CHANGE
 
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
 void convert(char infix[],char prefix[]);  //CHANGE
   
  //main() definition  
  int main()
  {
  	 char infix[20],prefix[20];  //result stored in prefix //CHANGE
  	 
  	 printf("Enter infix expression ");
  	 scanf("%s",infix);
  	 
  	 //CHANGE
  	 convert(infix,prefix); //call by reference used 
  	 printf("Prefix expression is %s",prefix); 
	    	 
  	 return 0;  	 
 }
 
 //convert() definition  - V.IMP (array names are pointer variables only internally)
 void convert(char infix[],char prefix[])   //void char(char *infix,char *postfix) //CHANGE
 {
 	struct Stack s;    
	s.tos=-1;  	
 	int i,j=0; 	 
	int pr; //for storing operator precedence(1 or 0)
	char ch; //to scan infix char array char by char 
		
	for(i=strlen(infix)-1;i>=0;i--) //i will trace char R->L //CHANGE V.IMP
	{
		ch=infix[i]; // ch can be operand or operator hence use if-else		
		
		if(isoprnd(ch)==1) //if ch is an operand push into the prefix array
		{
			prefix[j]=ch; //infix array char stored into prefix array using j //CHANGE
			j++;
		}//end of if
		else  //if ch is an operator 
		{			
			while(isempty(s)==0) //returns 0 if stack is not empty
			{
			   //check precedence of outside char with tos operator
			   pr=prcd(ch,s.arr[s.tos]);  
			   	   			   
			   if(pr==1) //push the element which is written outside this while loop
			   {
			   	break;  //exit from while loop
			   }			    
			 	prefix[j]=pop(&s);  //tos char (operator) //CHANGE
			    j++;		       
			}//end of while			 
	  push(&s,ch);	
    }//end of else	  
	}//end of for - Now "infix is complete but in stack may be some operators are still left" 
 	
 	
 	while(isempty(s)==0) //returns 0 if stack is not empty
 	{
 		prefix[j]=pop(&s);  //CHANGE
 		j++;
 	}//end of while loop
 	prefix[j]='\0'; //for end of postfix expression     //CHANGE 	 	
	strrev(prefix);   //CHANGE (V.IMP)	
 }//end of convert()
   
   
   
   int isoprnd(char ch)
   {
   	 //ch can be uppercase,lower case or digit char 
	 if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||(ch>=48&&ch<=57))
   	   return 1; //if operand is an operand
	 else
	    return 0;  //if operand is an operator	 
   }
      
 
    int isempty(struct Stack s)
    {
   	  if(s.tos==-1)
   	     return 1;  //stack is empty
   	  else
		 return 0;  //stack is not empty		 
	  //return (s.tos==-1);	 "Single Line Version" (== operator gives 1(true) or 0(false)) 
    }
  
     
 int prcd(char op1,char op2)  
 {
 	if(op2=='$')
 	   return 0; 
 	else if(op1=='$')
 	  return 1;  
 	else if(op2=='/'||op2=='*'||op2=='%')
 	  return 0;  
 	else if(op1=='/'||op1=='*'||op1=='%')
 	  return 1;  
 	else if(op2=='+'||op2=='-')
 	  return 1;  //push //CHANGE
 	else  
 	  return 1;
  }//end of prcd()
  
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
   
   
   
   
  
  
