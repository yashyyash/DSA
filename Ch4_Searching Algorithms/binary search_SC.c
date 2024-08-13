
  #include<stdio.h>
  //#include<conio.h>
  
  void bubble_sort(int arr[],int n); //binary search requires sorted array  
  int bin_search(int arr[],int n,int x);  //Prototype same as linear search
  
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
		
	bubble_sort(arr,n); 
	result=bin_search(arr,n,x);
	
	if(result==-1)
	    printf("Element not found");
	else
	    printf("Element found at location %d",result+1);
		
	return 0;	
 } //end of main() 
  
  //Method 1  
  void bubble_sort(int arr[],int n) //int arr[] means int *arr;
  {
 	int i,j,temp;
 	
	for(i=0;i<=n-2;i++) //i loop will manage number of passes/trips
    {
 	 for(j=i+1;j<=n-1;j++) //j loop will manage number of comparisons in each pass
 	 { 	//Swapping Logic
 	 	if(arr[i]>arr[j])  //For descending order a[i]<a[j]
 	 	{
 	 		temp=arr[i];
 	 		arr[i]=arr[j];
 	 		arr[j]=temp;
		}//end of swapping logic 		
	 } //end of j loop
    } //end of i loop 		 
 } //end of bubble_sort()

  //prototype same as lin_search()
  int bin_search(int arr[],int n,int x)  
  {
  	//3 indexes are used 
	int l=0,h=n-1,m;  //l-low,h-high,m-mid  	 
 
	 //Run the loop till lower index is less or equal to higher index	 
  	 while(l<=h) 
  	 {
  	 	m=(l+h)/2;  //calculate the mid point ie index of mid point
		     	 	
  	 	//3 Possibilities 
  	 	if(arr[m]==x)  //CASE 1 :: x is found hence return m as its index
  	 	  return m;  
  	    else if(x>arr[m]) //CASE 2 :: hence shift(reset) l=m+1;
  	      l=m+1;  
  	    else //CASE 3 :: x<arr[m] hence shift(reset) h=m-1;
  	      h=m-1; 
     } //end of loop    
     return -1; //x not found  	 	
  } //end of bin search()
  
  
  
