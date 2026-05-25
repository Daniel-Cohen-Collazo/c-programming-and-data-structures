#include <stdio.h>

int binSearch (int numList[], int target){
	int begin = 0;
	int end = 4;
	

	while (begin <= end){
		int mid = (begin + end) / 2;
		if (target == numList[mid]){
			return mid;
		} else if (target > numList[mid]){
			begin = mid + 1;
		} else{
			end = mid - 1;
		}
	}
}

int main(){
	
	int num;
	int arr[5];
	int t;

	printf("Quintana utt318\nBinary Search(Iterative approach)\n");
	printf("Enter 5 numbers.\n");

	for (int i = 0; i < 5; i++){
		scanf("%d",&num);
		arr[i] = num;
	}
	
	printf("Enter target value:\n");
	scanf("%d",&t);

	int result = binSearch(arr,t);

	printf("Element found at:%d\n",result);

	return 0;
}
