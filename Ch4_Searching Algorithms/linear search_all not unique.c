
  //Array elements are not unique means same element may be repeated multiple times
  
  #include<stdio.h>  
  void lin_search(int arr[],int n,int x);  //int *arr (actually  a pointer)
  
  int main()
  {
  	int arr[50],n,i,x;
  	
  	printf("How many array elements to be stored? ");
  	scanf("%d",&n);
  	
  	printf("Enter array elements \n");
  	for(i=0;i<n;i++)
  	{
  	  scanf("%d",&arr[i]);
	}
	printf("Enter array element to be searched ");
	scanf("%d",&x);
	
	lin_search(arr,n,x);
		    
    return 0;
  } //end of main()  
  
  void lin_search(int arr[],int n,int x)  
  {
  	int i,count=0; //to manage index
  	
  	for(i=0;i<n;i++)
  	{
  	   if(arr[i]==x)
  	   {
  		 printf("Number found at position %d \n",i+1);  //IMP : i+1
    	 count++;
	   }
	}
	
	if(count==0)
       printf("Number not found");	
  }
  
  
