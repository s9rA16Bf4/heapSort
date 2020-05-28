#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>

template<typename T>
class heapSort{
private:
  std::vector<T> internalVector; // This will hold our unsorted and hopefully sorted list

public:
  std::vector<T> getVector(); // Returns internalVector
  void sort(); // Sorts our vector
  void loadVector(std::vector<T> &originVector);
};

template<typename T>
std::vector<T> heapSort<T>::getVector(){ return this->internalVector; }

template<typename T>
void heapSort<T>::loadVector(std::vector<T> &originVector){ this->internalVector = originVector; }

template<typename T>
void heapSort<T>::sort(){
  T largestValue = T();
  int index = 0; // The index of our largest element
  unsigned int vectorSize = this->internalVector.size(); // Original size of our vector

  while (vectorSize > 0){
    for (unsigned int i = 0; i < vectorSize; i++){ // Create the max-heap
      if (this->internalVector[i] > largestValue || largestValue == T()){ // Find the largest value
        largestValue = this->internalVector[i];
        index = i;
      }
    }

    largestValue = T(); // Reset
    T temp = this->internalVector[vectorSize-1]; // Get the last element
    this->internalVector[vectorSize-1] = this->internalVector[index]; // Place it att the end of the heap
    this->internalVector[index] = temp; // Change places
    vectorSize--;
  }
}
#endif
