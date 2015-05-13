#include <iostream>
#include"search.h"
#include<ctime>
//#include<search.cpp>
using namespace std;


int main(void){
    //clock_t clock (void); // clock stuff....

   // clock_t startLinear,startBinary,finishLinear,finishBinary;
    //double elapsed_timeLinear;
    //double elapsed_timeBinary;
//int _tmain(int argc, _TCHAR* argv[])

	int n,s;
	int *ItemList, *elementsToBeSearch;
    //cout<< "Welcome to the program" <<endl;
    //cout<<endl;
    //cout<<endl;
	//cout << "Please enter the total number of elements in the array" <<endl;
	cin >> n; //total number of elements in the array
    //cout << "please enter the number of elements that you search for"<<endl;
    cin >> s;//number of elements that you search for
    //cout << "please input your array containing everything"<< endl;
    ItemList = new int[n]; //input your array containing everything using a for loop
        for(int i=0;i<n;i++){
            cin >> ItemList[i];
        }
    //cout << "please input the array containing the elements you wish to search for"<< endl;
    elementsToBeSearch = new int[s]; //the array containing the elements you wish to search for
        for(int i=0; i<s;i++){
            cin >> elementsToBeSearch[i];
        }
	Search *uf = new Search(n,ItemList); //initializes array by passing in the tot num of elements in the big array, and the big array itself.

	cout << "linear search" << endl;
	//startLinear =clock();
	for(int i=0; i<s; i++){ //for every element inside of the toBeSearched array
        if(uf->linearSearch(n,elementsToBeSearch[i])){//compare elements from the toBeSearched array using linear search
            cout<<"Yes"<<endl;//cout yes if the method returns true.
        }
        else{
            cout<<"NO"<<endl; //NO if method returned false.
        }
	}
    //finishLinear = clock();
    //elapsed_timeLinear = (double)(finishLinear - startLinear)/(double)CLOCKS_PER_SEC;
    //cout<<"Linear Search elapsed_time: "<< elapsed_timeLinear <<endl;
	cout << "Binary Search" <<endl;
	//start =clock();
	//sort(ItemList, ItemList + n);//sort the array before doing anything
	//startBinary =clock();
    for(int i= 0; i< s; i++){
        if(uf->binarySearch(n,elementsToBeSearch[i])){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    //finishBinary = clock();
    //elapsed_timeBinary = (double)(finishBinary - startBinary)/(double)CLOCKS_PER_SEC;
    //cout<<"Binary Search elapsed_time: "<< elapsed_timeBinary <<endl;

 return 0;
}
