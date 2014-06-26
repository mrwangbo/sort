 #include<stdio.h>
 #include<assert.h>
 #include<stdlib.h>
 
 void 
 merge(int *a, int begin, int mid, int end) 
 {
     int *tmp;
     int i;
     int index_1 = begin; 
     int index_2 = mid + 1;  
     int t_index = 0;
 
     tmp = (int *)malloc(sizeof(int)*(end - begin + 1));
     assert(tmp != NULL);
 
     while(index_1 <= mid && index_2 <= end)
     {   
         if(a[index_1] <= a[index_2])
             tmp[t_index++] = a[index_1++];
         else
             tmp[t_index++] = a[index_2++];
     }   
 
     while(index_1 <= mid)
         tmp[t_index++] = a[index_1++];
 
     while(index_2 <= end)
         tmp[t_index++] = a[index_2++];
 
     for(i = 0; i < t_index; i++)
         a[begin + i] = tmp[i];
 
     free(tmp);
 }
 
 void
 merge_sort(int *a, int begin, int end)
 {   
     int mid;
     if(begin < end)
     {   
         mid = begin + (end - begin) / 2;
         merge_sort(a, begin, mid);
         merge_sort(a, mid + 1, end);
         merge(a, begin, mid, end);
     }   
  }       
         
 int     
 main()  
 {   
     int i;
     int a[] = {1,3,9,10,2,4,6,8};
     merge_sort(a, 0, 7);
 
     for(i = 0; i < 8; i++)
         printf("%d\t", a[i]);
     printf("\n");
     
     return 0;
 }   
