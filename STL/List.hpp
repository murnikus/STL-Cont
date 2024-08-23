#include <initializer_list>
#include <iostream>

namespace atlas {

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node() : next(nullptr) {}
    Node(const T& value) : data(value), next(nullptr) {}
};

template<class T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}

    ~List() {
        clear();
    }

    List(const List& oth) : head(nullptr) {
        if (oth.head) {
            Node<T>* src = oth.head;
            Node<T>* dst = new Node<T>(src->data);
            head = dst;

            while (src->next) {
                src = src->next;
                dst->next = new Node<T>(src->data);
                dst = dst->next;
            }
        }
    }

    List(List&& oth) noexcept : head(oth.head) {
        oth.head = nullptr;
    }

    List(std::size_t count, const T& val) : head(nullptr) {
        while (count--) {
            push_front(val);
        }
    }

    List& operator=(List&& oth) noexcept {
        if (this != &oth) {
            clear();
            head = oth.head;
            oth.head = nullptr;
        }
        return *this;
    }

    void clear() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
    }

    List(std::initializer_list<T> init_list) : head(nullptr) {
        for (auto& val : init_list) {
            push_front(val);
        }
    }

    void push_front(const T& val) {
        Node<T>* new_node = new Node<T>(val);
        new_node->next = head;
        head = new_node;
    }

    void print() const {
        Node<T>* tmp = head;
        while (tmp) {
            std::cout << tmp->data << std::endl;
            tmp = tmp->next;
        }
    }

    // Iterator class
    class Iterator {
    private:
        Node<T>* ptr;

    public:
        Iterator(Node<T>* value) : ptr(value) {}
        Iterator() : ptr(nullptr) {}

        Iterator& operator=(const Iterator& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        Iterator& operator++() {
            if (ptr) {
                ptr = ptr->next;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T& operator*() {
            return ptr->data;
        }

        T* operator->() {
            return &(ptr->data);
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    class ConstIterator {
    private:
        const Node<T>* ptr;

    public:
        ConstIterator(const Node<T>* value) : ptr(value) {}
        ConstIterator() : ptr(nullptr) {}

        ConstIterator& operator=(const ConstIterator& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        ConstIterator& operator++() {
            if (ptr) {
                ptr = ptr->next;
            }
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const T& operator*() const {
            return ptr->data;
        }

        const T* operator->() const {
            return &(ptr->data);
        }

        bool operator==(const ConstIterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const ConstIterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Function Iterator
    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ConstIterator cbegin() const {
        return ConstIterator(head);
    }

    ConstIterator cend() const {
        return ConstIterator(nullptr);
    }

    Iterator before_begin() {
        return Iterator(nullptr); 
    }
};

} // namespace atlas
