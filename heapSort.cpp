//heapSort.cpp file
//Description: This class sorts the array using heap sort.
//Author: Aaryan Gupta
//Creation Date: June 17, 2021


#include<iostream>

using namespace std;


//swap the elements of the array
void swap(int data[], int a, int b){
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}


//moves the heap to heapify it when it gets distorted
void movedown(int data[], int i, int n){

	int max = (2 * i) + 1;

	while(max <= n){

		if((max < n) && (data[max] < data[max + 1])){
			max = max + 1;
		}

		if(data[i] < data[max]){
			swap(data, i, max);
			i = max;
			max = (2 * i) + 1;
		}
		else{
			max = n + 1;
		}
	}
}


//heap sort function that sorts the array using heap sort.
void heapSort(int data[], int n){

	for(int i = (n-2)/2; i >= 0; i--){
		movedown(data, i, n-1);	
	}

	n = n-1;

	while(n > 0){

		swap(data, 0, n);

		movedown(data, 0, n-1);

		n = n-1;

	}
}





//main function that initiates the array and calls other function.
int main(){

	int data[9] = {2, 8, 12, 7, 1, 15, 1, 4, 9};

	int n = sizeof(data)/sizeof(data[0]);

	heapSort(data, n);


	for(int i = 0; i < n; i++){
		cout << data[i] << " ";
	}


}