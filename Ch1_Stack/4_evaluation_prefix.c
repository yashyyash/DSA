
  #include<stdio.h>
  #include<math.h> //pow() used
  #include<string.h> //CHANGE
 
  //struct declaration
  struct Stack 
  {
   float arr[10]; 
   int tos;
  }; 
 
   void push(struct Stack *p,float x); 
   float pop(struct Stack *p);
   int isoprnd(char ch);
   float calculate(float op1,float op2,char opt); 
   float solve(char prefix[]);  //CHANGE
   
   //main() definition   
   int main()
   {
   	 char prefix[20]; //CHANGE	 
   	 float ans;  
   	 
   	 printf("Enter valid pre-fix expression "); //CHANGE
   	 scanf("%s",prefix);   //CHANGE	 
   	
   	 ans=solve(prefix);  //Entire Processing done in solve()  //CHANGE 	 
   	 printf("Result of %s is %f",prefix,ans);  //CHANGE 
			 
   	 return 0;
   }//end of main()
   
   
   //isoprnd() definition
   int isoprnd(char ch)
   {
   	 if(ch>=48 && ch<=57)  //'0'=48 and '9'=57
   	    return 1;  //if operand is a digit (0-9)
	 else
	    return 0;
			    
	//OR return (ch>=48 && ch<=57); because && either gives 1(true) or 0(false) "One Line"
	//?: cant be used because return; not allowed. 
   }//end of isoprnd()
   
   //calculate() definition
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
	 			      return (op1/op2); //type casting
	 		case '$':	 			        
	 			      return (pow(op1,op2));  //use pow() of math.h
	 		case '%':	 			        
	 			      return (fmod(op1,op2)); //use fmod() of math.h gives float mod
	 			      
			default :  
					  return (0.0);  					  
				     
		 } //end of switch()	 	
	 } //end of calculate()
	 
   
   //push() defn
   void push(struct Stack *p,float x)
   {
     if(p->tos==9) //our stack size is 10
     {
     	printf("Stack Overflow");
     	return;
	 }
	 p->tos=p->tos+1;  	 
	 p->arr[p->tos]=x; 
   }//end of push()
   
   //pop() definition
   float pop(struct Stack *p)
   {
   	float x;
   	
   	if(p->tos==-1)
   	{
   		printf("Stack Underflow(Empty)");
   		return 0.0;
	}
	
	x=p->arr[p->tos]; 
	p->tos=p->tos-1; 
	
	return x;
   }//end of pop()
   
   //solve() definition
   float solve(char prefix[]) //CHANGE
   {
   	  struct Stack s;  
   	  s.tos=-1; 
		 
	  int i;  
   	  char ch; 
   	  float op1,op2,ans;   	   	  
   	  
   	  for(i=strlen(prefix)-1;i>=0;i--) //*********  CHANGE (V.IMP) *****************                                      
   	  {
   	  	ch=prefix[i];  //CHANGE   	  	
   	  	if(isoprnd(ch)==1) 
   	  	{
		  push(&s,(float)(ch-48));  
		} //end of if
		else
		{
			//*********  CHANGE (V.IMP) operands interchanged *****************
			op1=pop(&s); 			
			op2=pop(&s); 
					
			ans=calculate(op1,op2,ch);
			push(&s,ans);  
		}//end of else
     }//end of for loop
    return ans;
 } //end of solve()
   
   
   
   
   
   
