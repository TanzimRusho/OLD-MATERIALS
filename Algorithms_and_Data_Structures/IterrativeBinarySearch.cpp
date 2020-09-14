//Iterative Binary Search

/*
#include<stdio.h>

int main(){
	int low, high, key, n, a[100], mid;

	printf("Enter array size:\n");
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	printf("Enter key to Search for:\n");
	scanf("%d", &key);

	low = 0;
	high = n-1;
	while(low <= high){
		mid = (low+high) /2;
		if(a[mid] == key){
			printf("Found %d at index %d\n", key, mid);
			break;
		}
		else if(a[mid] > key){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}

	if(low > high){
		printf("Key Not found\n");
	}

	return 0;
}
*/


//Recursive Binary Search Algorithm

#include<stdio.h>

int bsearch(int a[], int low, int high, int key);

int main(){
	int a[100], n, index, key;
	printf("Enter array size:\n");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Enter key to find:\n");
	scanf("%d", &key);
	index = bsearch(a, 0, n-1, key);
	if(index == -1){
		printf("Key not found.\n");
	}else{
		printf("key found at index %d", index);
	}

	return 0;
}

int bsearch(int a[], int low, int high, int key){
	if(low>high){
		return -1;
	}
	int mid = (low+high)/2;
	if(a[mid]==key){
		return mid;
	}
	else if(a[mid]>key){
		bsearch(a, low, mid-1, key);
	}else{
		bsearch(a, mid+1, high, key);
	}
}
