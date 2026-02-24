#ifndef LIST_H
#define LIST_H

#include <cstdlib>

template <class T>
class List {
public:
    List();

    T* list;
    void add(T* item);
    int get_size() const;
    T* operator[](int);

private:
    int size;
};


template<class T>
List<T>::List() {
    size = 0;
    list = (T*)malloc(sizeof(T));
}

template<class T>
void List<T>::add(T *item) {

    // copy old values
    if (size == 0) {
        list = item;
    }
    else {
        T* newList = (T*)malloc(sizeof(T)*(size+1));
        for (int i = 0; i < size+1; i++) {
            newList[i] = list[i];
        }
        // add new one
        newList[size] = *item;
        list = newList;
    }
    size++;
}

template<class T>
T* List<T>::operator[](int i) {
    if (i < size) {
        return &list[i];
    }
    else {
        throw 404;
    }
}

template<class T>
int List<T>::get_size() const {
    return size;
}

#endif //SS01_LIST_H
