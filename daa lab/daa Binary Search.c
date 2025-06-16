#include <stdio.h>
void sort(int arr[],int n){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=0 ; j<n-1-i ;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int binarysearch(int arr[],int n,int target){
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(arr[mid]==target) return mid;
        if(target>arr[mid]){
            lo=mid+1;
            
        }
        else{
            hi=mid-1;
        }
        
    }
    return -1;
}
void display(int arr[],int n){
	
	for(int i=0 ; i<n ; i++){
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

void inputArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
int main() {
   
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    inputArray(arr, n);
    printf("Array before sort: ");
    display(arr, n);
    sort(arr, n);
    printf("Array after sort: ");
    display(arr,n);

    int target=6;
    int result=binarysearch(arr,n,target);
    if(result==-1){
        printf("NOT FOUND \n");
    }
    else{
        printf(" the target= %d was found in the index :%d ",target,result+1);
    }

    return 0;
}

/*
Enter the number of elements in the array: 5
Enter 5 elements:
9
11
4
6
7
Array before sort:  9  11  4  6  7 
Array after sort:  4  6  7  9  11 
 the target= 6 was found in the index :2 
*/