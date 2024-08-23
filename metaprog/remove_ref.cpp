template <typename T>
struct remove_ref {
     typedef T type;
};

template <typename T>
struct remove_ref<T&> {
     typedef T type;
};

template <typename T>
struct remove_ref<T&&> {
     typedef T type;
};
