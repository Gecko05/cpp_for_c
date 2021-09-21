// Predator-Prey simulation using class living

const int N = 40;
enum state {
    EMPTY,
    GRASS,
    RABBIT,
    FOX,
    STATES,
};
const int DRAB = 3, DFOX = 6, CYCLES = 5;

class living;
typedef living* world[N][N];

class living{
    public:
    virtual state who() = 0;
    virtual living* next(world w) = 0;
    protected:
    int row, column;
    void sums(world w, int sm[]);
};

void living::sums(world w, int sm[])
{
    int i, j;
    sm[EMPTY] = sm[GRASS] = sm[RABBIT] = sm[FOX] = 0;
    for (i = -1; i <= 1; ++i)
        for (j = -1; j <= 1; ++j)
            sm[w[row + i][column + j]->who()]++;
}

class fox : public living {
public:
    fox(int r, int c, int a = 0) : age(a)
    { row = r; column = c; }
    state who() { return FOX; }     // deferred method for foxes
    living* next(world w);
protected:
    int age;    // used to decide on dying
};

class grass : public living {
public:
    grass(int r, int c) { row = r; column = c; }
    state who() { return GRASS; }
    living* next(world w);
};

class rabbit : public living {
public:
    rabbit(int r, int c, int a = 0) : age(a)
    { row = r; column = c; }
    state who() { return RABBIT; }
    living* next(world w);
protected:
    int age;
};

class empty : public living {
public:
    empty(int r, int c) { row = r; column = c; }
    state who() { return EMPTY; }
    living* next(world w);
};

living* grass::next(world w)
{
    int sum[STATES];

    sums(w, sum);
    if (sum[GRASS] > sum[RABBIT])   // eat grass
        return (new grass(row, column));
    else
        return (new empty(row, column));
}

living* rabbit::next(world w)
{
    int sum[STATES];

    sums(w, sum);
    if (sum[FOX] >= sum[RABBIT]) // eat rabbits
        return (new empty(row, column));
    else if (age > DRAB)    // rabbit is too old
        return (new empty(row, column));
    else
        return (new rabbit(row, column, age + 1));
}

living* fox::next(world w)
{
    int sum[STATES];

    sums(w, sum);
    if (sum[FOX] > 5)
        return (new empty(row, column));
    else if (age > DFOX)
        return (new empty(row, column));
    else
        return (new fox(row, column, age + 1));
}

living* empty::next(world w)
{
    int sum[STATES];
    sums(w, sum);
    if (sum[FOX] > 1)
        return (new fox(row, column));
    else if (sum[RABBIT] > 1)
        return (new rabbit(row, column));
    else if (sum[GRASS])
        return (new grass(row, column));
    else
        return (new empty(row, column));
}

// world is all empty

void init(world w)
{
    int i, j;

    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            w[i][j] = new empty(i, j);
}

// new world w_new is computed from old world w_old

void update(world w_new, world w_old)
{
    int i, j;

    for (i = 1; i < N - 1; ++i)         // borders are taboo
        for (j = 1; j < N - 1; ++j)
            w_new[i][j] = w_old[i][j] -> next(w_old);
}

//clean world up
void dele(world w)
{
    int i, j;
    for (i = 1; i < N - 1; ++i)
        for (j = 1; j < N - 1; ++j)
            delete(w[i][j]);
}

int main()
{
    world odd, even;
    int i;

    init(odd);
    init(even);
    eden(even);
    pr_state(even); //print Garden of Eden state

    for (i = 0; i < CYCLES; ++i) // simulation
    {
        if (i % 2) {
            update(even, odd);
            pr_state(even);
            dele(odd);
        }
        else {
            update(odd, even);
            pr_state(odd);
            dele(even);
        }
    }
}