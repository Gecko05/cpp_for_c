#include <iostream>
using namespace std;

struct dairy{
    string name;
    double weight;
    double calories;
    double protein;
    double fat;
    double carbohydrates;
};

double get_calories(struct dairy prod, double portion)
{
    double ratio = portion / prod.weight;
    return ratio * prod.calories;
}

int main(int argc, char *argv[])
{
    struct dairy milk = {"Milk", 10, 200, 30, 12, 15};
    cout << get_calories(milk, 600);
}