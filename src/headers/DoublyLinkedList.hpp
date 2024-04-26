/**
 * \file Bank.hpp
 * \brief Implementacion de la clase DoublyLinkedList.
 * \author Braulio Alessandro Sánchez Bermúdez
 * \author Carlos Enrique Mancillas Duran
 * \date 22/03/2024
 * */

#ifndef LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_HPP
#define LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_HPP

#define NO_ENCONTRADO (-1)

#include <exception>


/** \class DoublyLinkedList
 *
 * Esta clase template ofrece una implementaci&oacute;n de lista doble con operaciones
 para agregar,
 * eliminar elementos, y consultar el ultimo de la lista, entre otras.
 *
 * \tparam T Tipo de elementos almacenados en la lista doble.
 *
 *
 *
 * \code Ejemplo.cpp
 #include "DoublyLinkedList.hpp"
 #include <exception>
 #include <iostream>
 #include <functional>

// Función de comparación para ordenamiento ascendente
   bool ascendingOrder(const int& a, const int& b) {
   return a > b;
   }

// Función para determinar si un valor es par (utilizada en deleteCondition)
   bool isEven(const int& value) {
   return value % 2 == 0;
   }

int main() {
try {
    
        DoublyLinkedList<int> list;

        // Insertar elementos al principio y al final
           list.insertBeginning(3);
           list.insertLast(1);
           list.insertLast(4);
           list.insertLast(1);
           list.insertLast(5);
            
        // Insertar en índice indicado
           list.insertIndicatedIndex(9, 2); // Inserta el 9 en la posición 2

        // Imprimir la lista
           std::cout << "Lista después de inserciones: ";
           list.printForward();

        // Eliminar el primer y último elemento
           list.deleteFirst();
           list.deleteLast();

        // Eliminar en índice indicado
           list.deleteIndicatedIndex(2); // Elimina el elemento en la posición 1
           // Imprimir la lista después de las eliminaciones
              std::cout << "Lista después de eliminaciones: ";
              list.printForward();

        // Buscar un valor y obtener su índice
           int valueToSearch = 4;
           if (list.searchValue(valueToSearch)) {
           std::cout << "Valor " << valueToSearch << " encontrado en el índice " << list.searchIndex(valueToSearch) << std::endl;
           } else {
           std::cout << "Valor " << valueToSearch << " no encontrado." << std::endl;
           }

        // Modificar un valor en un índice específico
           list.modifyValueIndicatedIndex(1, 2); // Cambia el valor en el índice 1 a 2

        // Imprimir la lista después de la modificación
           std::cout << "Lista después de modificar el índice 1: ";
           list.printForward();

        // Ordenar la lista
           list.sort(ascendingOrder);

        // Imprimir la lista después de ordenar
           std::cout << "Lista después de ordenar: ";
           list.printForward();

        // Eliminar elementos bajo una condición (eliminar números pares)
           list.deleteCondition(isEven);

        // Imprimir la lista después de eliminar elementos pares
           std::cout << "Lista después de eliminar números pares: ";
           list.printForward();

        // Eliminar ocurrencias de un valor específico
           list.deleteOcurrence(1); // Elimina la primera ocurrencia del valor 1

        // Imprimir la lista después de eliminar ocurrencias de 1
           std::cout << "Lista después de eliminar la primera ocurrencia de 1: ";
           list.printForward();

        // Comprobar si la lista está vacía
           if (list.isEmpty()) {
           std::cout << "La lista está vacía." << std::endl;
           } else {
           std::cout << "La lista no está vacía." << std::endl;
           }

        // Obtener el tamaño de la lista
           std::cout << "Tamaño de la lista: " << list.size() << std::endl;

        // Limpiar la lista
           list.clear();

        // Comprobar si la lista está vacía después de limpiar
           if (list.isEmpty()) {
           std::cout << "La lista está vacía después de limpiar." << std::endl;
           } else {
           std::cout << "La lista no está vacía después de limpiar." << std::endl;
           }

    } catch (std::exception& msg) {
    std::cout << msg.what() << std::endl;
    }

    return 0;
    }

 * \endcode
 *
 \verbatim Salida:
 Lista después de inserciones: (3, 1, 9, 4, 1, 5)
 Lista después de eliminaciones: (1, 9, 1)
 Valor 4 no encontrado.
 Lista después de modificar el índice 1: (1, 2, 1)
 Lista después de ordenar: (2, 1, 1)
 Lista después de eliminar números pares: (1, 1)
 Lista después de eliminar la primera ocurrencia de 1: ()
 La lista está vacía.
 Tamaño de la lista: 0
 La lista está vacía después de limpiar.
 \endverbatim
 *
 */
template <typename T>
class DoublyLinkedList{
public:
    /**
     * \brief Constructor por defecto que inicializa una lista doble vac&iacute;a.
     */
    // Constructor
    DoublyLinkedList();
    /**
     * \brief Destructor que libera la memoria de la lista doble.
     */
    // Destructor
    ~DoublyLinkedList();
    /**
     * \brief Constructor de copia.
     * \param list Otra lista de la cual se copiar&aacute;n los elementos.
     */
    // Construtor de copias
    DoublyLinkedList(const DoublyLinkedList<T> & list);
    /**
     * \brief Sobrecarga del operador de asignaci&oacute;n.
     * \param list Otra lista doble de la cual se copiar&aacute;n los elementos.
     * \exception const <b>char *</b> La lista doble copia no puede ser creado.
     *
     * \return Referencia a la lista actual.
     */
    // Operador de asignacion
    DoublyLinkedList<T> & operator=(const DoublyLinkedList<T> & list);

    /**
     * \brief Agrega un nuevo elemento al principio de la lista doble.
     * \param value El valor a agregar.
     */
    void insertBeginning(T value);
    /**
     * \brief Agrega un nuevo elemento al final de la lista doble.
     * \param value El valor a agregar.
     */
    void insertLast(T value);
    /**
     * \brief Agrega un nuevo elemento en el indice indicado de la lista doble.
     * \param value El valor a agregar.
     * \param index El indice en donde se agregara.
     */
    void insertIndicatedIndex(T value, int index);
    /**
     * \brief Elimina el primer elemento de la lista doble.
     */
    void deleteFirst();
    /**
     * \brief Elimina el ultimo elemento de la lista doble.
     */
    void deleteLast();
    /**
     * \brief Elimina el elemento en el indice indicado de la lista doble.
     * \param index indice el cual sera eliminado.
     */
    void deleteIndicatedIndex(int index);
    /**
     * \brief Busca elemento en la lista doble.
     * \param value Valor a verificar si esta en la lista.
     */
    bool searchValue(T value) const;
    /**
     * \brief Regresa inciso del valor a buscar.
     * \param value valor que buscaremos en la lista.
     */
    int searchIndex(T value) const;
    /**
     * \brief Verifica si la lista esta vacia.
     *
     */
    bool isEmpty() const;
    /**
     *\brief Regresa primer valor de la lista.
     *
     */
    T getFirstValue() const;
    /**
     *\brief Regresa ultimo valor de la lista.
     *
     */
    T getLastValue() const;
    /**
     *\brief Regresa valor indicado de la lista.
     * \param index inciso de la lista a regresar.
     */
    T& getValueIndicatedIndex(int index) const;
    /**
     *\brief Modifica valor indicado de la lista.
     * \param index inciso de la lista a modificar.
     * \param value valor que se insertara en la lista.
     */
    void modifyValueIndicatedIndex(int index,T value);
    /**
     *\brief Regresa tamaño de la lista.
     */
    int size() const;
    /**
     *\brief Vacia la lista.
     */
    void clear();
    /**
     *\brief Imprime lista de primero a ultimo.
     */
    void printForward() const;
    /**
     *\brief Imprime lista de ultimo a primero.
     */
    void printBackwards() const;
    /**
     * \brief Elimina la primera ocurrencia de un valor específico en la lista.
     * \param value El valor a eliminar.
     */
    void deleteOcurrence(T value);

    /**
     * \brief Elimina todos los elementos de la lista que cumplen con una condición específica.
     * \param func Un puntero a función que define la condición. Esta función debe tomar un elemento de tipo T y devolver un valor booleano.
     */
    void deleteCondition(bool (*func)(const T&));

    /**
     * \brief Elimina todos los elementos duplicados en la lista, dejando solo una ocurrencia de cada elemento.
     */
    void deleteRepeat();

    /**
     * \brief Ordena los elementos de la lista según una condición específica proporcionada por el usuario.
     * \param condition Un puntero a función que define la condición de ordenamiento. Esta función debe tomar dos elementos de tipo T y devolver un valor booleano.
     */
    void sort(bool (*condition)(const T&, const T&));

    /**
     * \brief Transfiere todos los elementos de esta lista a otra lista.
     * \param l La lista destino a la que se transferirán los elementos.
     */
    void transfer(DoublyLinkedList<T>& l);

    /**
     * \brief Transfiere un rango de elementos de esta lista a otra lista.
     * \param l La lista destino a la que se transferirán los elementos.
     * \param initial El índice inicial del rango en esta lista.
     * \param final El índice final del rango en esta lista.
     */
    void transfer(DoublyLinkedList<T> &l, int initial, int final);

    /**
     * \brief Transfiere un elemento específico de esta lista a otra lista.
     * \param l La lista destino a la que se transferirá el elemento.
     * \param index El índice del elemento en esta lista que se transferirá.
     */
    void transfer(DoublyLinkedList<T>& l, int index);

    /**
     * \brief Sobrecarga del operador de acceso para obtener el elemento en una posición específica de la lista de forma constante.
     * \param i El índice del elemento a obtener.
     * \return Una referencia constante al elemento en el índice especificado.
     */
    const T & operator[](int i) const;

    /**
     * \brief Sobrecarga del operador de acceso para modificar el elemento en una posición específica de la lista.
     * \param i El índice del elemento a modificar.
     * \return Una referencia al elemento en el índice especificado, permitiendo su modificación.
     */
    T & operator[](int i);

    /**
     * \brief Intercambia todos los elementos de esta lista con los de otra lista.
     * \param l La lista con la que se intercambiarán los elementos.
     */
    void intercambiar(DoublyLinkedList<T> &l);

    /**
     * \class ListEmpty
     * \brief Excepción que se lanza cuando se intenta realizar una operación inválida en una lista vacía.
     */
    class ListEmpty : public std::exception {
    public:
        /**
         * \brief Proporciona un mensaje describiendo la excepción.
         * \return Una cadena de caracteres constante que describe la excepción.
         */
        virtual const char *what() const throw();
    };

    /**
     * \class OutRange
     * \brief Excepción que se lanza cuando se intenta acceder a un elemento fuera del rango válido de la lista.
     */
    class OutRange : public std::exception {
    public:
        /**
         * \brief Proporciona un mensaje describiendo la excepción.
         * \return Una cadena de caracteres constante que describe la excepción.
         */
        virtual const char *what() const throw();
    };
private:
    // Tamaño de la lista doblemente enlazada
    int size_;

    // Doubly linked list
    struct Element{
        // Constructor por default del struct
        Element(T value, Element *next = nullptr, Element *previous = nullptr) ;
        T value;
        Element *next;
        Element *previous;
    };

    Element *first;
    Element *last;
};

#include "../templates/DoublyLinkedList.tpp"
#endif //LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
