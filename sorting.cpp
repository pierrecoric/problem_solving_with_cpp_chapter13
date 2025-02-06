#include <iostream>
#include <vector>
#include <time.h>
using std::vector;
using std::cout;

vector<int> generateRandomVector(int max, int size);
void swap(int& a, int& b);
void printVector(vector<int>& vector);
void selectionSort(vector<int>& data);
void insertionSort(vector<int>& data);
void mergeSort(vector<int>& data);
void mergeSort(vector<int>& data, int start, int end, vector<int> temp);
void merge(vector<int>& data, int leftPos, int leftEnd, int rightEnd, vector<int>& temp);

int main() {
    srand(time(0));
    vector<int> test = generateRandomVector(100, 100000);

    /*
    printVector(test);
    cout << "\n";
    //selectionSort(test);
    printVector(test);
    cout << "\n";

    test = generateRandomVector(100, 100);
    printVector(test);
    cout << "\n";
    //insertionSort(test);
    printVector(test);
    cout << "\n";
    */

    //test = generateRandomVector(100, 100);
    printVector(test);
    cout << "\n";
    mergeSort(test);
    printVector(test);
    cout << "\n";

    
    return 0;
}

//Function to generate random number into a vector.
vector<int> generateRandomVector(int max, int size) {
    vector<int> result;
    result.reserve(size);
    for(int i = 0; i < size; i++) {
        int randomNum = rand() % max;
        result.push_back(randomNum);
    }
    return result;
}

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//Function to print out a vector.
void printVector(vector<int>& vector) {
    cout << "[";
    for(int i = 0; i < vector.size(); i++) {
        cout << vector[i];
        if(i < vector.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

//Selection sort.
void selectionSort(vector<int>& data) {
    for(int i = 0; i < data.size(); i++) {
        int indexMin = i;
        for(int j = i + 1; j < data.size(); j++) {
            if(data[j] < data[indexMin]) {
                indexMin = j;
            }
            cout << ".";
        }
        swap(data[i], data[indexMin]);
    }
}

//Insertion sort - Bubble sort
void insertionSort(vector<int>& data) {
    //Define the start and the end of the vector.
    int start = 0;
    int end = data.size();
    //Loop over the entire vector.
    for(int i = start; i < end; i ++) {
        //store the data at the ith position in a temporary variable.
        int temp = data[i];
        //initialize the j pointer to i
        int j = i;
        while (j > 0 && data[j - 1] > temp) {
            data[j] = data[j - 1];
            j --;
            cout << ".";
        }
        data[j] = temp;
    }
}

// Driver for merge sort.
void mergeSort(vector<int>& data) {
    vector<int> temp;
    temp.resize(data.size());
    mergeSort(data, 0, data.size() - 1, temp);
}

void mergeSort(vector<int>& data, int start, int end, vector<int> temp) {
    if(start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(data, start, mid, temp);
    mergeSort(data, mid + 1, end, temp);
    merge(data, start, mid, end, temp);
    cout << ".";
}

void merge(vector<int>& data, int leftPos, int leftEnd, int rightEnd, vector<int>& temp) {
    int rightPos = leftEnd + 1;
    int tempPos = leftPos;
    int originalPos = leftPos;

    while(leftPos <= leftEnd && rightPos <= rightEnd) {
        if(data[leftPos] < data[rightPos]) {
            temp[tempPos] = data[leftPos];
            tempPos ++;
            leftPos ++;
        }
        else {
            temp[tempPos] = data[rightPos];
            tempPos ++;
            rightPos ++;
        }
    }

    while(leftPos <= leftEnd) {
        temp[tempPos] = data[leftPos];
        tempPos ++;
        leftPos ++;
    }

    while(rightPos <= rightEnd) {
        temp[tempPos] = data[rightPos];
        tempPos ++;
        rightPos ++;
    }
    //copy temp into data 
    for (int i = originalPos; i <= rightEnd; i++) {
        data[i] = temp[i];
    }
}