template <class T, int n>
class assign_array {
    public:
        T a[n];
};

assign_array<double, 50> x, y;

x = y;