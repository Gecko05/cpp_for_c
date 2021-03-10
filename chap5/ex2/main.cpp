
// void add(int i);

class mod_int
{
    public:
        void add(int i);
    private:
        int v;
};

void mod_int::add(int i)
{
    v = (v + i) % 60;   
}