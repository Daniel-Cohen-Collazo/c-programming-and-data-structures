#include <stdio.h>

int binSearch (int numList[], int target, int startIndex, int endIndex){
	int begin = startIndex;
	int end = endIndex;	
	int mid = (begin + end) / 2;
	
	if (target == numList[mid]){
		return mid;
	} else if (target > numList[mid]){
		return binSearch(numList,target,mid+1,endIndex);
	} else {
		return binSearch(numList,target,mid-1,endIndex);
	}
}

int main(){
	
	int num;
	int arr[5];
	int t;

	printf("Quintana utt318\n Binary Search (Recursive Approach)\n");
	printf("Enter 5 numbers.\n");

	for (int i = 0; i < 5; i++){
		scanf("%d",&num);
		arr[i] = num;
	}
	
	printf("Enter target value:\n");
	scanf("%d",&t);

	int result = binSearch(arr,t,0,4);

	printf("Element found at:%d\n",result);

	return 0;
}
