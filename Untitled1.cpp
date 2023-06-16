	label:
		if(element==arr[low])
	 {
		printf("Element %d found at index %d\n",element,low);
		return 0;
	 } 
	  else if(element==arr[high])
	 {
		printf("Element %d found at index %d\n",element,high);
		return 0;
	 }
	 else
	 {
	 	   mid=ceil((low+high)/2);
	 	   if(element>mid && mid!=high)
	 	   {
	 	   	low=mid;
	 	   	goto label;
			 }
			 else if(element<mid && mid!=high)
			 {
			 	high=mid;
			 	goto label;
			 }
	 }
	 
	  printf("Element not found\n");
	  return -1
