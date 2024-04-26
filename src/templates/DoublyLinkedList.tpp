#include <iostream>

// **************************************************************
// **************************************************************
// *******************METODOS CONTRUCTORES***********************
// **************************************************************
// Metodo constructor del Struct
template <typename T>
DoublyLinkedList<T>::Element::Element(T value,
                                   DoublyLinkedList::Element *next /*= nullptr*/,
                                      DoublyLinkedList::Element *previous/* = nullptr*/) : value(value), next(next), previous(previous) {}
// **************************************************************
// Metodo constructor por default
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : size_(0), first(nullptr), last(nullptr)
{

}
// **************************************************************
// Metodo destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}
// **************************************************************
// Metodo constructor de copias
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> & list) : size_(0), first(nullptr), last(nullptr)
{
    *this = list;
}
// **************************************************************
// Metodo operador de asignación
template <typename T>
DoublyLinkedList<T> & DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list){
    if (this == &list) return *this;
    // Vaciar lista por copiar por si en dado caso ya contiene otros valores
    clear();

    Element *aux = list.first;
    while (aux != nullptr)
    {
        insertLast(aux->value);
        aux = aux->next;
    }
    return *this;
}
// **************************************************************
// **************************************************************
// **************************************************************
// Metodo insertar al principio de la lista
template <typename T>
void DoublyLinkedList<T>::insertBeginning(T value)
{
    Element *aux;

    if (isEmpty()) {
        aux = new Element(value, nullptr, nullptr);
        first = aux;
        last = aux;
    } else {
        aux = new Element(value, first, nullptr);
        first->previous = aux;
        first =aux;
    }

    ++size_;
}
// **************************************************************
// Metodo insertar elemento a lo ultimo de la lista
template <typename T>
void DoublyLinkedList<T>::insertLast(T value)
{
    Element *aux = new Element(value, nullptr, last);

    if (isEmpty())
    {
        first = aux;
        last = aux;
    }
    else
    {
        last->next = aux;
        last = aux;
    }
    ++size_;
}
// **************************************************************
// Metodo insertar elemnto en la posicion indicada de la lista

/////***********CORREGIR**********///////
template <typename T>
void DoublyLinkedList<T>::insertIndicatedIndex(T value, int index)
{
    if (index < 0 || index >= size()) throw OutRange();
    if (index == 0) insertBeginning(value);
    else if (index == size()-1) insertLast(value);
    else
    {
        Element *aux = first;
        for (int i = 1; i < index; ++i) aux = aux->next;
        Element *new_ = new Element(value, aux->next, aux);
        aux->next->previous = new_;     
        aux->next = new_;
        ++size_;
    }
}
// **************************************************************
// Metodo eliminar primer elemento de la lista
template <typename T>
void DoublyLinkedList<T>::deleteFirst()
{
    if (isEmpty())
        throw ListEmpty();
    Element *aux = first;
    first = aux->next;
    if(first == nullptr) last = nullptr;
    else
        first->previous = nullptr;
    delete aux;
    --size_;
}
// **************************************************************
// Metodo eliminar ultimo elemento de la lista
template <typename T>
void DoublyLinkedList<T>::deleteLast()
{
    if (isEmpty()) throw ListEmpty();

    Element *aux = last;

    last = last->previous;

    if (last != nullptr)
    {
        last->next = nullptr;
    }
    else
    {
        first = nullptr;
    }

    delete aux;
    --size_;
}
// **************************************************************
// Metodo eliminar elemento de la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::deleteIndicatedIndex(int index) {
    if (index < 0 || index >= size()) OutRange();
    if (index == 0) deleteFirst();
    else if (index == size() - 1) deleteLast();
    else
    {
        // Elemento que va a borrar el indice indicado
        Element *aux = first;
        for (int i = 0; i < index; ++i)
            aux = aux->next;
        
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;
        delete aux;
        --size_;
    }
}
// **************************************************************
// Metodo para verificar si existe un elemento en la lista
template <typename T>
bool DoublyLinkedList<T>::searchValue(T value) const
{
    if (isEmpty()) throw ListEmpty();

    Element *aux = first;

    while (aux != nullptr)
    {
        if (aux->value == value) return true;
        aux = aux->next;
    }

    return false;
}
// **************************************************************
// Metodo para obtener la posicion de un elemento de la lista
template <typename T>
int DoublyLinkedList<T>::searchIndex(T value) const
{
    if (!searchValue(value)) return -1; // Valor no encontrado
    int counter = 0;
    Element *aux = first;

    while (aux != nullptr)
    {
        if (aux->value == value) return counter;
        aux = aux->next;
        ++counter;
    }

    return NO_ENCONTRADO;
}
// **************************************************************
// Metodo para verificar si la lista esta vacia
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return size_ == 0;
}
// **************************************************************
// Metodo para obtener el primer elemento de la lista
template <typename T>
T DoublyLinkedList<T>::getFirstValue() const
{
    return first->value;
}
// **************************************************************
// Metodo para obtener el ultimo elemento de la lista
template <typename T>
T DoublyLinkedList<T>::getLastValue() const
{
    return last->value;
}
// **************************************************************
// Metodo para obtener el valor de la posicion indicada de la lista
template <typename T>
T& DoublyLinkedList<T>::getValueIndicatedIndex(int index) const
{
    if (index < 0 || index >= size())
        throw OutRange();
    
    Element *aux = first; 
    
    for(int i = 0 ; i < index; ++i) aux =  aux->next; 
    return aux->value;
}
// **************************************************************
// Metodo para modificar el valor de la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::modifyValueIndicatedIndex(int index, T value)
{
    if (index < 0 || index >= size()) throw OutRange();

    Element *aux = first;

    for (int i = 0; i < index; ++i) aux = aux->next;

    aux->value = value;
}
// **************************************************************
// Metodo para obtener el tamaño de la lista
template <typename T>
int DoublyLinkedList<T>::size() const
{
    return size_;
}
// **************************************************************
// Metodo para vaciar la lista
template <typename T>
void DoublyLinkedList<T>::clear()
{
    while(!isEmpty()) deleteFirst();
}
// **************************************************************
// Metodo para imprimir la lista de primero a ultimo
template <typename T> void DoublyLinkedList<T>::printForward() const {
    if (isEmpty()){
        std::cout << "()" << std::endl;
        return;
    }
    Element *aux;
    aux = first;
    std::cout << "(";
    for (int i = 0; i < size(); ++i) {
        std::cout << aux->value << ", ";
        aux = aux->next;
    }
    std::cout << "\b\b)" << std::endl;
}
// **************************************************************
// Metodo para eliminar todo elemento que cumpla una condicion
template <typename T>
void DoublyLinkedList<T>::deleteCondition(bool (*func)(const T &)) {
    if (isEmpty()) throw ListEmpty();
    Element *aux = first;
    for (int i = 0; i < size(); ++i) {
        if (func(aux->value)) {
            deleteIndicatedIndex(i);
            break;
        }
        aux = aux->next;
    }
}
template <typename T>
void DoublyLinkedList<T>::deleteOcurrence(T value)
{
    if(isEmpty()) throw ListEmpty();

    Element *aux = first;
    Element *before = aux->next;
    int index = 0;
    
    while(aux != nullptr) {
        if (aux->value == value) {
            aux = aux->next;
            deleteIndicatedIndex(index);
        } else {
            index++;
            aux = aux->next;
        }
        aux = before;
        if (before != nullptr) before = before->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteRepeat()
{
    if(isEmpty()) throw ListEmpty();

    DoublyLinkedList<T> list;
    Element * aux = first;

    for (int i = 0; i < size(); ++i) {
        if(list.isEmpty() || !list.searchValue(aux->value)) list.insertLast(aux->value);
        aux = aux->next;
    }
    *this = list;
}

// Metodo para ordenar de forma ascendente
template <typename T> void DoublyLinkedList<T>::sort(bool (*condition) (const T&, const T&)) {
    if (first == nullptr || first->next == nullptr) {
        // La lista está vacía o tiene un solo elemento, ya está ordenada
        return;
    }

    Element *current = first->next; // Comenzar desde el segundo elemento

    while (current != nullptr) {
        T currentValue = current->value;
        Element *previous = current->previous;
        bool found = false;

        // Mover hacia atrás para encontrar la posición correcta para el elemento actual
        while (previous != nullptr && condition(currentValue, previous->value)) {
            previous->next->value = previous->value; // Mover el valor hacia adelante
            previous = previous->previous;
            found = true; // Indica que se ha encontrado una posición y se ha movido al menos un elemento
        }

        if (found) {
            // Si se encontró la posición, insertar el valor actual
            if (previous == nullptr) {
                // Insertar al principio
                first->value = currentValue;
            } else {
                previous->next->value = currentValue;
            }
        }

        current = current->next; // Mover al siguiente elemento para ordenar
    }
}
// Metodo para ordenar de forma ascendente
template <typename T>
void DoublyLinkedList<T>::transfer(DoublyLinkedList<T>& l)
{
    transfer(l, 0, size() - 1);
}
// Metodo para ordenar de forma ascendente
template <typename T>
void DoublyLinkedList<T>::transfer(DoublyLinkedList<T> &l, int initial, int final) {
    Element *aux = l.first;

    for (int i = 0; i < initial; ++i) {
        aux = aux->next;
    }
    Element *new_ = aux->previous;
    
    aux->previous = last;
    aux->previous->next = aux;

    for (int i = 0; i < final - initial; ++i)
        aux = aux->next;
    
    last = aux;
    if (aux->next != nullptr)
        aux->next->previous = new_;
    else l.last = new_;
     
    if (new_ != nullptr)
        new_->next = aux->next;
    else l.first = aux->next;
    
    size_ += (final - initial + 1);
    l.size_ -= (final - initial + 1);

    last->next = nullptr;
}
// Metodo para ordenar de forma ascendente
template <typename T>
void DoublyLinkedList<T>::transfer(DoublyLinkedList<T>& l, int index)
{
    transfer(l, index, size() - 1);
}
// **************************************************************
// Metodo para imprimir la lista de ultimo a primero
template <typename T>
void DoublyLinkedList<T>::printBackwards() const
{
    if (isEmpty())
    {
        std::cout << "()" << std::endl;
        return;
    }

    Element *aux = last;
    std::cout << "(";

    while (aux != nullptr)
    {
        std::cout << aux->value << ", ";
        aux = aux->previous;
    }
    std::cout << "\b\b)" << std::endl;
}

// Metodo para imprimir la lista de ultimo a primero
template <typename T>
T& DoublyLinkedList<T>::operator[](int i)
{
    return getValueIndicatedIndex(i);
}
template <typename T>
const T& DoublyLinkedList<T>::operator[](int i) const
{
    return getValueIndicatedIndex(i);
}

// Metodo para imprimir la lista de ultimo a primero
template <typename T>
void DoublyLinkedList<T>::intercambiar(DoublyLinkedList<T>& l)
{
    Element *aux = l.first;
    l.first = first;
    first = aux;

    aux = l.last;
    l.last = last;
    last = aux;

    int auxsize_ = l.size();
    l.size_ = size_;
    size_ = auxsize_;
}

/*******************************************************************/

template <typename T>
const char *DoublyLinkedList<T>::ListEmpty::what() const throw() {
  return "Empty list";
}

/*********************************************************************/

template <typename T>
const char *DoublyLinkedList<T>::OutRange::what() const throw() {
  return "Out the range";
}
