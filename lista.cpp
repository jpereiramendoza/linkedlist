#include <iostream>
#include <stdexcept>

/**
 * Implementamos un nodo generico para cualquier tipo de dato
 */
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& data, Node* next = nullptr)
        : data(data), next(next) {}
};

/**
 * Implementacion del objeto lista enlazada
 */
template <typename T>
class LinkedList {
private:
    //Primer nodo, mantiene la informacion de la lista 
    Node<T>* head;

    //Tamano de la lista, hay que actualizar este valor al momento de eliminar o agregar algun elemento
    size_t listSize;

public:
    //Constructor de la clase 
    LinkedList() : head(nullptr), listSize(0) {}

    ~LinkedList() {
        clear();
    }

    // Agrega un elemento al final de la lista
    void add(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        listSize++;
    }

    // Elimina el primer nodo que contenga el valor especificado
    bool remove(const T& value) {
        if (head == nullptr) return false; // Lista vacía

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            listSize--;
            return true;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return false; // Valor no encontrado
        }

        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        listSize--;
        return true;
    }

    // Devuelve el tamaño de la lista
    size_t size() const {
        return listSize;
    }

    // Verifica si la lista está vacía
    bool empty() const {
        return listSize == 0;
    }

    // Limpia la lista eliminando todos los nodos
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        listSize = 0;
    }

    // Imprime los elementos de la lista (para depuración)
    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "null" << std::endl;
    }
};

// Ejemplo de uso
int main() {
    LinkedList<int> list;

    // Agregar elementos
    list.add(10);
    list.add(20);
    list.add(30);

    std::cout << "Lista tras agregar elementos: ";
    list.print();

    // Eliminar un elemento
    list.remove(20);
    std::cout << "Lista tras eliminar 20: ";
    list.print();

    // Tamaño de la lista
    std::cout << "Tamaño de la lista: " << list.size() << std::endl;

    // Verificar si la lista está vacía
    std::cout << "La lista está vacía: " << (list.empty() ? "Sí" : "No") << std::endl;

    // Limpiar la lista
    list.clear();
    std::cout << "Lista tras limpiar: ";
    list.print();
    std::cout << "La lista está vacía: " << (list.empty() ? "Sí" : "No") << std::endl;

    return 0;
}

