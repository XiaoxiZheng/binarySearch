#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <algorithm>

using namespace std;


class Search{


private:
    int sizeOfArray; //the size of the entire Big array list
    int lo,mid,hi;//corresponds with the lower bound, mid of array, and upper bound
    int *ItemList; // the array that contains everything
    int element; //the element to be search(passed in from main)

public:


Search(int tempSize,int temp[]){
    int sizeOfArray = tempSize;
    ItemList = new int[sizeOfArray];
    for(int i=0;i<sizeOfArray;i++){
        ItemList[i] = temp[i];
    }
}
~Search(){
    delete [] ItemList; //destructor
}

bool linearSearch(int num,int element){
    int sizeOfArray = num; //set the size of array to n that was passed in from main
    bool found = false; //initially assume found is false
      for(int i=0;i<sizeOfArray;i++){
        if(element == ItemList[i]){
            found = true; //if found an item identical to some element in the ith position, then set found to true.
        }
    }
    return found; //return  the bool result back to main
}

bool binarySearch(int num, int element){
    int sizeOfArray = num; //set the size of array to n from main.
    sort(ItemList, ItemList + sizeOfArray); //sort the array before performing searches
    int lo = 0; //lower bound before search begins
    int hi = sizeOfArray;//upper bound before search begins
    mid = (lo+hi)/2;//the mid base on lower bound and upper bound
    while((ItemList[mid]!=element)&&(lo<=hi)){ //loops thru as long the element isn't found
        if(ItemList[mid]>element){ //if the element at midPoint in the sorted array is greater than element to be look for
            hi= mid-1; //reset the upper bound to mid-1,
        }
        else{
            lo = mid +1; //otherwise set lower bound to mid+1
        }

        mid = (lo + hi) /2; //reset mid base on new lower bound and upper bound
    }
    if(lo<=hi) return true; //comes here after the while loop ends, which is when the elements is found in the list.
    else return false; //will only come here when the element is NOT inside the array
}

};
#endif // SEARCH_H_INCLUDED

