// we can simply use std::array for this but here is an ADT implementation just for sake of completion

#include <iostream>
#include <stdexcept> // For standard exceptions
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;

public:
    // Constructor
    Array(int size) {
        if (size <= 0) {
            throw invalid_argument("Size must be greater than 0");
        }
        this->size = size;
        data = new T[size];
    }

    // Destructor
    ~Array() {
        delete[] data;
    }

    // Get the size of the array
    int getSize() const {
        return size;
    }

    // Get element at a given index
    T& get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Set element at a given index
    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        data[index] = value;
    }

    // Overloading the [] operator for easy access
    T& operator[](int index) {
        return get(index);
    }

    const T& operator[](int index) const {
        return get(index);
    }

    // Print the array
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Array<int> myArray(5);

        // Set values
        myArray.set(0, 10);
        myArray.set(1, 20);
        myArray.set(2, 30);
        myArray.set(3, 40);
        myArray.set(4, 50);

        // Print values
        myArray.print();

        // Access values
        cout << "Element at index 2: " << myArray.get(2) << endl;

        // Using overloaded [] operator
        myArray[2] = 100;
        cout << "Element at index 2 after update: " << myArray[2] << endl;

        // Print updated values
        myArray.print();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
