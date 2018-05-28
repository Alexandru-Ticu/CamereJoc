#ifndef HEAP_H
#define HEAP_H

//typedef struct{
//
//            char nume[20];
//            int scor;
//        }NodH;
//
//class Heap
//{
//    public:
//        Heap();
//        ~Heap();
//        void schimba(int copil, int parinta);
//        int getStanga(int parinte);
//        int getDreapta(int parinte);
//        int getParinte(int copil);
//        void addNod(NodH);
//        int getMarime(){
//            return this->marime;
//        }
//        void HeapS();
//        void afiseaza();
//
//    private:
//
//        int marime;
//        NodH nod[50];
//
//};

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
class Heap {
  vector<T> list;
  vector<string> nume;

  void bubbleUp();
  void bubbleDown();
  void swap(int child, int parent);
  int getLeftChild(int parent);
  int getRightChild(int parent);
  int getParent(int child);
public:
  Heap();
  void insert(T , string);
  T remove();
  int getSize();

};

template <class T>
Heap<T> :: Heap(){

}

template <class T>
int Heap<T> :: getSize(){
  return list.size();
}

template <class T>
void Heap<T>::swap(int child, int parent) {
  T temp;
  string temp2;
  temp = list[child];
  list[child] = list[parent];
  list[parent] = temp;
  temp2 = nume[child];
  nume[child] = nume[parent];
  nume[parent] = temp2;

}

template <class T>
int Heap<T> :: getParent(int child) {
  if (child % 2 == 0)
	return (child /2 ) -1;
  else
	return child/2;

}

template <class T>
int Heap<T> :: getLeftChild(int parent){
  return 2*parent +1;
}

template <class T>
int Heap<T> :: getRightChild(int parent){
  return 2 * parent + 2;
}

template <class T>
void Heap<T> :: insert(T value, string nume1) {

  list.push_back(value);
  nume.push_back(nume1);
  bubbleUp();

}

template <class T>
void Heap <T>:: bubbleUp() {
  int child = list.size() - 1;
  int parent = getParent(child);

  while (list[child] > list[parent] && child >=0 && parent >= 0) {

	swap(child, parent);
	child = parent;
	parent = getParent(child);

  }


}


template <class T>
T Heap<T> :: remove() {
  int child = list.size()  - 1;
  swap(child, 0);

  T value = list.back();
  list.pop_back();
  cout<<"Nume: "<<nume.back()<<" scor:";
  nume.pop_back();

  bubbleDown();

  return value;


}


template <class T>
void Heap<T> :: bubbleDown() {
  int parent = 0;

  while (1) {
	int left = getLeftChild(parent);
	int right = getRightChild(parent);
	int length = list.size();
	int largest = parent;

	if (left < length && list[left] > list[largest])
	  largest = left;

	if (right < length && list[right] > list[largest])
	  largest = right;

	if (largest != parent) {
	  swap(largest, parent);
	  parent = largest;
	}
	else
	  break;


  }

}

#endif // HEAP_H
