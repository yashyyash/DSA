
  //Unique elements means an array element only occurs once in the entire array

  #include<stdio.h>  
  int lin_search(int arr[],int n,int x);  //int *arr (actually  a pointer)
  
  int main()
  {
  	int arr[50],n,i,x,result;
  	
  	printf("How many array elements to be stored? ");
  	scanf("%d",&n);
  	
  	printf("Enter array elements \n");
  	for(i=0;i<n;i++)
  	{
  	  scanf("%d",&arr[i]);
	}
	printf("Enter array element to be searched ");
	scanf("%d",&x);
	
	result=lin_search(arr,n,x);
	
	if(result==-1)
	    printf("Element not found");
	else
	    printf("Element found at location %d",result+1);
	    
    return 0;
  } //end of main()
  
  //Version 1 - using return i;
  int lin_search(int arr[],int n,int x)  
  {
  	int i; //to manage index
  	
  	for(i=0;i<n;i++)
  	{
  	   if(arr[i]==x)
  	   {
  		 return i;   //If element found - exit from the function with its index value
	   }
	}
	return -1; //if element not found return -1
  }
  
  /*
  //Version 2 - using break;
  int lin_search(int arr[],int n,int x)  
  {
  	int i;  
	  	
  	for(i=0;i<n;i++)
  	{
  	   if(arr[i]==x)
  	   {
  		 break;  //Only exit from the loop and not the function
	   }
	}	
	if(i==n)
	   return -1;  //if element not found return -1
	else
	   return i;  //If element found - exit from the function with its index value
  } */
