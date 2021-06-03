// C++ implementation of a priority queue

#include <iostream>
#include "Node.h"
using namespace std;
template <typename T> 
class PrioQueue {
private:
    const static int MAX_SIZE = 100;
    Node<T> heap[MAX_SIZE]; //Initialize an array of nodes
    int size = 0;

public:
    PrioQueue() {
        size = 0;
    }

    // returns the index of the parent node
    static int parent(int i) {
        return (i - 1) / 2;
    }

    // return the index of the left child 
    static int leftChild(int i) {
        return 2 * i + 1;
    }

    // return the index of the right child 
    static int rightChild(int i) {
        return 2 * i + 2;
    }


    static void swap(Node<T>* x, Node<T>* y) {
        Node<T> temp = *x;
        *x = *y;
        *y = temp;
    }

    // insert the item at the appropriate position
    void enqueue(T data,int key) {
        if (size >= MAX_SIZE) {
            cout << "The heap is full. Cannot insert" << endl;
            return;
        }

        // first insert the time at the last position of the array 
        // and move it up
        heap[size].setItem(data);
        heap[size].setKey(key);
        size = size + 1;


        // move up until the heap property satisfies
        int i = size - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(&heap[parent(i)], &heap[i]);
            i = parent(i);
        }
    }

    // moves the item at position i of array a
    // into its appropriate position
    void maxHeapify(int i) {
        // find left child node
        int left = leftChild(i);

        // find right child node
        int right = rightChild(i);

        // find the largest among 3 nodes
        int largest = i;

        // check if the left node is larger than the current node
        if (left <= size && heap[left] < heap[largest]) {
            largest = left;
        }

        // check if the right node is larger than the current node 
        // and left node
        if (right <= size && heap[right] < heap[largest]) {
            largest = right;
        }

        // swap the largest node with the current node 
        // and repeat this process until the current node is larger than 
        // the right and the left node
        if (largest != i) {
            Node<T> temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            maxHeapify(largest);
        }

    }

    // returns the  maximum item of the heap
    int peek() {
        return heap[0];
    }

    // deletes the max item and return
    bool dequeue(T &maxItem) {
        if (size == 0)
            return false;

        maxItem = heap[0].getItem();
        

        // replace the first item with the last item
        heap[0] = heap[size - 1];
        size = size - 1;

        // maintain the heap property by heapifying the 
        // first item
        maxHeapify(0);
        return true;
    }

    //dequeue overloaded with key
    bool dequeue(T& maxItem, int &Key) {
        if (size == 0)
            return false;

        maxItem = heap[0].getItem();
        Key = heap[0].getKey();

        // replace the first item with the last item
        heap[0] = heap[size - 1];
        size = size - 1;

        // maintain the heap property by heapifying the 
        // first item
        maxHeapify(0);
        return true;
    }

    // prints the heap
    void printQueue() {
        PrioQueue<T> Temp;
        T data;
        int key;
        while(dequeue(data, key))
        {
            cout << data <<","<< key << endl;
            Temp.enqueue(data, key);
        }
        cout << endl;
    }

   
};
