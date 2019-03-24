#ifndef __SORTMASS
#define __SORTMASS

//#include <alloc.h>

template <typename T>
void merge(T *a, int low, int mid, int high)
{ // ?????????????? ???????????? ?????? ?????????? ????????
// Variables declaration. 
   T *b;
   int h,i,j,k;

   b = (T *)calloc(high+1-low, sizeof(T));
   h = low;
   i = 0;
   j = mid+1;
// Merges the two array's into b[] until the first one is finish
   while((h<=mid) && (j<=high))
   {
      if(a[h] <= a[j])
      {
         b[i] = a[h];
         h++;
      }
      else
      {
         b[i]=a[j];
         j++;
      }
      i++;
   }
// Completes the array filling in it the missing values
   if(h > mid)
   {
      for(k=j; k<=high; k++)
      {
         b[i] = a[k];
         i++;
      }
   }
   else
   {
      for(k=h; k<=mid; k++)
      {
         b[i] = a[k];
         i++;
      }
   }
// Prints into the original array
   for(k=0; k<=high-low; k++) 
   {
      a[k+low] = b[k];
   }
   free(b);
}

template <typename T>
void merge_sort(T *a, int low, int high)		
{// ??????????? ?????????? ??????? ???????
   int mid;
   if(low < high)
   {
      mid = (low+high)/2;
      merge_sort(a,low,mid);
      merge_sort(a,mid+1,high);
      merge(a,low,mid,high);
   }
}

#endif