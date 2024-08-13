 
  //W.A.P to implement a Linked List
  
  #include<stdio.h>
  #include<stdlib.h>  //It has malloc(),exit() declarations  
  
  struct Node  
  {
  	int data;  
  	struct Node *next;  
  }; 
	
  void append(struct Node **,int); 
  void display(struct Node*);   
  int count(struct Node *);  
      
  int main()
  {
  	struct Node *start=NULL;    	
  	int x,option;
	char choice;	
	do
	{
		printf("Enter the option from following 1.Append/Create a Node 2.Display List 3.Count Nodes 4.Exit  \n");
		printf("Enter your option ");
		scanf("%d",&option);
		
		switch(option)
		{
					
			case 1 :
				     	printf("Enter a value to be stored in the new node ");
		                scanf("%d",&x); 
		                append(&start,x); 
				        break;
			case 2 :
				        display(start); 
				        break;
			case 3 :				        
				        printf("Number of Nodes in the list are %d\n",count(start));
				        break;		
			case 4 :
				        printf("Thanks for using our App");
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

        
  void append(struct Node **ps,int x)  
  {  	
	struct Node *p,*temp;   	
	p=(struct Node *)malloc(sizeof(struct Node));  
  	p->data=x;	
  	p->next=NULL;  
   	
   	 	
	if(*ps==NULL) //*ps means start (value at address pointed by ps) has NULL value
  	{
  	  *ps=p;   //Assign address of first node pointed by p to start by writing *ps
  	   return; 
	} //end of if
	else //Means its not the first node to be created
	{	  
	  temp=*ps; 	 
	  while(temp->next!=NULL) 
	  {
	    temp=temp->next;  
	  }
	   
    }//end of else
  } //end of append()
    
  //display() - the entire list
  void display(struct Node *p) 
  {
  	if(p==NULL)  
  	{
  	  printf("List is Empty\n");
  	  return;
	}	
	
	while(p!=NULL)
	{
	  printf("%d\n",p->data);  
	  p=p->next;  
	}
  } //end of display()
  
  
  int count(struct Node *p)
  {
  	int count=0;  
	while(p!=NULL)
	{
	    count++;  
		p=p->next; 
	}	
	return count; 
  } //end of count()
  
   
