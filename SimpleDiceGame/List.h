#ifndef LIST_H
#define LIST_H

template <class T>
class List {
public:
    // *structors
    List();
    ~List();

    // variables
    T** list;

    // methods
    void add(T* item);
    int get_size() const;
    T* operator[](int) const;

private:
    int size;
};

template<class T>
List<T>::List() {
    size = 0;
    list = new T*[1];
}

template<class T>
List<T>::~List() {
    delete[] list;
}

template<class T>
void List<T>::add(T *item) {
    // copy old values
    if (size == 0) {
        list[0] = item;
    }
    else {
        T** newList = new T*[size+1];
        for (int i = 0; i < size; i++) {
            newList[i] = list[i];
        }
        // add new one
        newList[size] = item;

        delete[] list;
        list = newList;
    }
    size++;
}

template<class T>
T* List<T>::operator[](int i) const {
    if (i < size) {
        return list[i];
    }
    else {
        throw 404;
    }
}

template<class T>
int List<T>::get_size() const {
    return size;
}

#endif
