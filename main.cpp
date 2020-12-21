#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include <cstring>
#include <cmath>
using namespace std;

template<typename T>
class Array{
	int size;
	T* data;
  
public:
	Array(int len){
		size = len;
    	data = new T[size];
	}
	~Array(){
		delete[] data;
	}
	Array(Array &arr){
		size = arr.size;
    	data = new T[size];
    	for(int i = 0; i < size; i++){
      		data[i] = arr.data[i];
		}
	}
	operator = (Array &arr){
		//return this(arr);
		size = arr.size;
    	data = new T[size];
    	for(int i = 0; i < size; i++){
      		data[i] = arr.data[i];
		}
	}
	friend ostream& operator << (ostream &out, const Array &arr){
		for(int i = 0; i < arr.size; i++){
			out << arr.data[i] << " ";
		}
		return out;	
	}
	
    T get(int index){
    	try{
    		checkIndex(index);
    		return data[index];
		}
    	catch(string err){
        	cout << err;
    		return -1;
    	}
	}
    void set(T value, int index){
    	try{
	    	checkIndex(index);
			checkValue(value);
	        data[index] = value;
		}
		catch(string err){
        	cout << err;
    	}
    	catch(string err){
        	cout << err;
    	}	
	}
    T push(T number){
    	size++;
    	try{
    		data = (T*)realloc(data,size*sizeof(T));
    		T *newArray;
        	newArray = new T[size];
        	memcpy(newArray, data, (size-1)*sizeof(T));
        	delete[] data;
        	data = newArray;
        	set(number, size-1);
		}	
    	catch(bad_alloc err){
    		cout << "Unsuccsessfull realloc";
    	}
	}
    
    void sum(Array &arr){
    	int lenght;
    	lenght = min(size, arr.size);
    	for(int i = 0; i < lenght; i++)
        	data[i] += arr.data[i];
	}
    void minus(Array &arr){
    	int lenght;
    	lenght = min(size, arr.size);
      	for(int i = 0; i < lenght; i++)
        	data[i] -= arr.data[i];
	}
	
	friend T lenVector(Array &arr, Array &brr){
		T sum = 0;
		for(int i = 0; i < arr.size; i++){
			sum += (arr.data[i] - brr.data[i])*(arr.data[i] - brr.data[i]);
		}
		return sqrt(sum);
	}
    
    
private:
    int checkSizeForSecondArray(Array &arr) {
      return size - arr.size;
    }
    void checkIndex(int index){
    	if(!(index <= size) && (index >= 0))
      		throw "Invalid index";
    }
    void checkValue(T value){
    	if(!((value > -101) && (value < 101)))
    		throw "Value out of range";
    }
};


int main(){
	Array <int>arr1(3);
	arr1.set(3, 0);
	arr1.set(12, 1);
	arr1.set(74, 2);
	
	//Array arr2(arr1);
	Array <int>arr2 = arr1;
	
	//arr2.show();
	cout << arr1 << endl;
	cout << arr2 << endl;
	cout << "distance between the vectors " << lenVector(arr1, arr2);
	return 0;
}























