    #include <initializer_list>
    #include <iostream>
    #include <stdexcept>

    namespace atlas {

    template <class T>
    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* value) : ptr(value) {}
        Iterator() : ptr(nullptr) {}
        ~Iterator() { ptr = nullptr; }

        Iterator& operator=(const Iterator& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            --ptr;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        T& operator[](std::size_t idx) {
            return *(ptr + idx);
        }

        Iterator operator+(std::size_t offset) const {
            return Iterator(ptr + offset);
        }

        Iterator operator-(std::size_t offset) const {
            return Iterator(ptr - offset);
        }

        std::ptrdiff_t operator-(const Iterator& other) const {
            return ptr - other.ptr;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    template <class T>
    class ConstIterator {
    private:
        const T* ptr;

    public:
        ConstIterator(const T* value) : ptr(value) {}
        ConstIterator() : ptr(nullptr) {}
        ~ConstIterator() { ptr = nullptr; }

        ConstIterator& operator=(const ConstIterator& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        ConstIterator& operator++() {
            ++ptr;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        ConstIterator& operator--() {
            --ptr;
            return *this;
        }

        ConstIterator operator--(int) {
            ConstIterator tmp = *this;
            --(*this);
            return tmp;
        }

        const T& operator*() const {
            return *ptr;
        }

        const T* operator->() const {
            return ptr;
        }

        const T& operator[](std::size_t idx) const {
            return *(ptr + idx);
        }

        ConstIterator operator+(std::size_t offset) const {
            return ConstIterator(ptr + offset);
        }

        ConstIterator operator-(std::size_t offset) const {
            return ConstIterator(ptr - offset);
        }

        std::ptrdiff_t operator-(const ConstIterator& other) const {
            return ptr - other.ptr;
        }

        bool operator==(const ConstIterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const ConstIterator& other) const {
            return ptr != other.ptr;
        }
    };

    template <class T>
    class ReverseIterator {
    private:
        T* ptr;

    public:
        ReverseIterator(T* value) : ptr(value) {}
        ReverseIterator() : ptr(nullptr) {}
        ~ReverseIterator() { ptr = nullptr; }

        ReverseIterator& operator=(const ReverseIterator& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        ReverseIterator& operator++() {
            --ptr;
            return *this;
        }

        ReverseIterator operator++(int) {
            ReverseIterator tmp = *this;
            --(*this);
            return tmp;
        }

        ReverseIterator& operator--() {
            ++ptr;
            return *this;
        }

        ReverseIterator operator--(int) {
            ReverseIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        T& operator[](std::size_t idx) {
            return *(ptr - idx);
        }

        ReverseIterator operator+(std::size_t offset) const {
            return ReverseIterator(ptr - offset);
        }

        ReverseIterator operator-(std::size_t offset) const {
            return ReverseIterator(ptr + offset);
        }

        std::ptrdiff_t operator-(const ReverseIterator& other) const {
            return other.ptr - ptr;
        }

        bool operator==(const ReverseIterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const ReverseIterator& other) const {
            return ptr != other.ptr;
        }
    };

    template <class T>
    class ConstReverseIterator {
    private:
        const T* ptr;

    public:
        ConstReverseIterator(const T* value) : ptr(value) {}
        ConstReverseIterator() : ptr(nullptr) {}
        ~ConstReverseIterator() { ptr = nullptr; }

        ConstReverseIterator& operator=(const ConstReverseIterator& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        ConstReverseIterator& operator++() {
            --ptr;
            return *this;
        }

        ConstReverseIterator operator++(int) {
            ConstReverseIterator tmp = *this;
            --(*this);
            return tmp;
        }

        ConstReverseIterator& operator--() {
            ++ptr;
            return *this;
        }

        ConstReverseIterator operator--(int) {
            ConstReverseIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const T& operator*() const {
            return *ptr;
        }

        const T* operator->() const {
            return ptr;
        }

        const T& operator[](std::size_t idx) const {
            return *(ptr - idx);
        }

        ConstReverseIterator operator+(std::size_t offset) const {
            return ConstReverseIterator(ptr - offset);
        }

        ConstReverseIterator operator-(std::size_t offset) const {
            return ConstReverseIterator(ptr + offset);
        }

        std::ptrdiff_t operator-(const ConstReverseIterator& other) const {
            return other.ptr - ptr;
        }

        bool operator==(const ConstReverseIterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const ConstReverseIterator& other) const {
            return ptr != other.ptr;
        }
    };

    template <class T>
    class Vector {
    private:
        T* m_data;
        std::size_t m_size;
        std::size_t m_cap;

        void reallocate(std::size_t new_cap) {
            T* new_data = new T[new_cap];
            for (std::size_t i = 0; i < m_size; ++i) {
                new_data[i] = std::move(m_data[i]);
            }
            delete[] m_data;
            m_data = new_data;
            m_cap = new_cap;
        }

    public:
        Vector() : m_data(nullptr), m_size(0), m_cap(0) {}

        Vector(std::initializer_list<T> init_list) 
            : m_data(new T[init_list.size()]), m_size(init_list.size()), m_cap(init_list.size()) {
            std::size_t i = 0;
            for (const T& value : init_list) {
                m_data[i++] = value;
            }
        }

        ~Vector() {
            delete[] m_data;
        }
        
        T& operator[](size_t index) {
            return m_data[index];
        }

        const T& operator[](size_t index) const {
            return m_data[index];
        }

        Iterator<T> begin() {
            return Iterator<T>(m_data);
        }

        ConstIterator<T> cbegin() const {
            return ConstIterator<T>(m_data);
        }

        Iterator<T> end() {
            return Iterator<T>(m_data + m_size);
        }

        ConstIterator<T> cend() const {
            return ConstIterator<T>(m_data + m_size);
        }

        ReverseIterator<T> rbegin() {
            return ReverseIterator<T>(m_data + m_size - 1);
        }

        ConstReverseIterator<T> crbegin() const {
            return ConstReverseIterator<T>(m_data + m_size - 1);
        }

        ReverseIterator<T> rend() {
            return ReverseIterator<T>(m_data - 1);
        }

        ConstReverseIterator<T> crend() const {
            return ConstReverseIterator<T>(m_data - 1);
        }

        void push_back(const T& value) {
            if (m_size >= m_cap) {
                reallocate(m_cap == 0 ? 1 : m_cap * 2);
            }
            m_data[m_size++] = value;
        }

        void pop_back() { 
            --m_size;
        }

        void insert(std::size_t idx ,const T& value) {
            if (idx > m_size) {
                std::cout << "\033[31mInsert:Out of range\033[0m" << std::endl;
                return;
            }

            if (m_size >= m_cap) {
                reallocate(m_cap == 0 ? 1 : m_cap * 2);
            }

            for (std::size_t i = m_size; i > idx; --i) {
                m_data[i] = std::move(m_data[i - 1]);
            }

            m_data[idx] = value;
            ++m_size;
        }

        T& at(std::size_t idx) {
            if (idx >= m_size) {
                throw std::out_of_range("\033[31mConst at: Index out of range\033[0m");
            }
            return m_data[idx];
        }
        
    void erase(std::size_t idx) {
        if (idx >= m_size) {
            std::cerr << "\033[31mErase: Index out of range\033[0m" << std::endl; // Error message in red
            return;
        }

        for (std::size_t i = idx; i < m_size - 1; ++i) {
            m_data[i] = std::move(m_data[i + 1]);
        }

        --m_size;
    }


        const T& at(std::size_t idx) const {
            if (idx >= m_size) {
                throw std::out_of_range("\033[31mConst at: Index out of range\033[0m");
            }
            return m_data[idx];
        }

        std::size_t size() const {
            return m_size;
        }

        std::size_t capacity() const {
            return m_cap;
        }

        bool is_empty() const {
            return m_size == 0;
        }

        T max() const {
            if (m_size == 0) {
                throw std::runtime_error("\033[31mMax: Vector is empty\033[0m");
            }

            T max_value = m_data[0];
            for (std::size_t i = 1; i < m_size; ++i) {
                if (m_data[i] > max_value) {
                    max_value = m_data[i];
                }
            }
            return max_value;
        }

        T& first() {
            if (m_size == 0) {
                throw std::runtime_error("\033[31mFirst: Vector is empty\033[0m");
            }
            return m_data[0];
        }

        const T& first() const {
            if (m_size == 0) {
                throw std::runtime_error("\033[31mFisrt: Vector is empty\033[0m");
            }
            return m_data[0];
        }

        T& last() {
            if (m_size == 0) {
                throw std::runtime_error("\033[31mLast: Vector is empty\033[0m");
            }
            return m_data[m_size - 1];
        }

        const T& last() const {
            if (m_size == 0) {
                throw std::runtime_error("\033[31mLasr: Vector is empty\033[0m");
            }
            return m_data[m_size - 1];
        }

        void shrink() {
            if (m_size < m_cap) {
                eallocate(m_size);
            }   
        }

        void clear() {
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
            m_cap = 0;
        }



    };


    }  


