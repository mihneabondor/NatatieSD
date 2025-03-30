// Created by Mihnea on 3/22/25.
//

#ifndef VECTORDINAMIC_H
#define VECTORDINAMIC_H
#include <iostream>
#include <ostream>

template <class T>
class VectorDinamic {
    int size;
    T* data;

    void resize(int);
    void quickSort(int, int);
    int partition(int, int);

public:
    VectorDinamic<T>();
    VectorDinamic<T>(VectorDinamic<T>&);
    ~VectorDinamic<T>();

    T* getData();
    T getElem(int);
    int getSize();

    void add(T);
    bool del(T);
    int getIndex(T);
    void sort();

    T& operator[](int);

    friend std::ostream& operator<<(std::ostream& os, const VectorDinamic<T>& v) {
        for (int i = 0; i < v.size; i++)
            os << v[i] << " ";
        return os;
    }
};

template<class T>
void VectorDinamic<T>::resize(int capacity) {
    T* newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template<class T>
int VectorDinamic<T>::getIndex(T t) {
    int index = -1;
    for (int i = 0; i < size && index == -1; i++) {
        if (data[i] == t) {
            index = i;
        }
    }
    return index;
}

template<class T>
VectorDinamic<T>::VectorDinamic() {
    size = 0;
    data = new T[size + 1];
}

template<class T>
VectorDinamic<T>::VectorDinamic(VectorDinamic<T>& v) {
    size = v.getSize();
    data = new T[size + 1];
    for (int i = 0; i < size; i++)
        data[i] = v[i];
}

template<class T>
VectorDinamic<T>::~VectorDinamic() {
    delete[] data;
}

template<class T>
T* VectorDinamic<T>::getData() {
    return data;
}

template<class T>
T VectorDinamic<T>::getElem(int index) {
    return data[index];
}

template<class T>
int VectorDinamic<T>::getSize() {
    return size;
}

template<class T>
void VectorDinamic<T>::add(T t) {
    resize(size + 1);
    data[size++] = t;
    sort();
}

template<class T>
bool VectorDinamic<T>::del(T t) {
    int index = getIndex(t);
    if (index == -1) {
        return false;
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    resize(--size);
    return true;
}

template<class T>
T& VectorDinamic<T>::operator[](int index) {
    return data[index];
}

template<class T>
int VectorDinamic<T>::partition(int low, int high) {
    T pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] <= pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

template<class T>
void VectorDinamic<T>::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

template<class T>
void VectorDinamic<T>::sort() {
    if (size > 1) {
        quickSort(0, size - 1);
    }
}

#endif //VECTORDINAMIC_H
