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

int main() {
    srand(time(0));
    vector<int> test = generateRandomVector(100, 10);
    printVector(test);
    cout << "\n";
    selectionSort(test);
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
        }
        swap(data[i], data[indexMin]);
        printVector(data);
        cout << "\n";
    }
}

//Insertion sort - Bubble sort
void insertionSort(vector<int>& data) {

}