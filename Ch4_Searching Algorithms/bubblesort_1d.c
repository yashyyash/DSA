
 #include<stdio.h>
 //#include<conio.h>
 
 int main()
 {
 	int a[50],n,i,j,temp;
 	//clrscr();
 	
 	printf("How many array elements to be sorted? ");
 	scanf("%d",&n);
 	
 	//To accept n array elements from the user
 	for(i=0;i<n;i++)
 	{
 		printf("Enter array element ");
 		scanf("%d",&a[i]);
	}
	
	//Bubble Sort Logic
	for(i=0;i<=n-2;i++) //i loop will manage number of passes/trips
    {
 	 for(j=i+1;j<=n-1;j++) //j loop will manage number of comparisons in each pass
 	 { 	//Swapping Logic
 	 	if(a[i]>a[j])  //For descending order a[i]<a[j]
 	 	{
 	 		temp=a[i];
 	 		a[i]=a[j];
 	 		a[j]=temp;
		}//end of swapping logic 		
	 } //end of j loop
    } //end of i loop
    
    printf("The Ascending Order is \n");
    for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);  //*(&a[i])
	}
	
	//getch();
	return 0;
 } //end of main()
