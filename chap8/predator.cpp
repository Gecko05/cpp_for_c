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
        for (j = 01; j <= 1; ++j)
            sm[w[row + i][column + j]->who()]++;
}