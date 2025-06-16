#include<stdio.h>
#include<stdio.h>
int max, min;
int a[100];
void maxmin(int low, int high)
{
 int max1, min1, mid;
 if(low==high)
 {
  max = min = a[low];
 }
 else
 {
  if(low == high-1)
  {
   if(a[low] <a[high])
   {
    max = a[high];
    min = a[low];
   }
   else
   {
    max = a[low];
    min = a[high];
   }
  }
  else
  {
   mid = (low+high)/2;
   maxmin(low, mid);
   max1 = max; min1 = min;
   maxmin(mid+1, high);
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 }
}
int main ()
{
 int i, num;
 printf ("\nEnter the total number of elements of an array : ");
 scanf ("%d",&num);
 printf ("Enter the numbers : \n");
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);

 max = a[0];
 min = a[0];
 maxmin(1, num);
 printf ("Minimum element in an array : %d\n", min);
 printf ("Maximum element in an array : %d\n", max);
 return 0;
}

