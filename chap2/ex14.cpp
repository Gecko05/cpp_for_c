int main()
{
    int how_many = 100;
    cout << "Print " << how_many
         << " random integers.\n";
    int min, max, av;
    for (int i = 0; i < how_many; ++i)
    {
        int new_n = rand();
        if (i == 0)
        {
            min = max = new_n;
        }
        else
        {
            av = av + new_n;
            if (new_n < min)
            {
                min = new_n;
            }
            if (new_n > max)
            {
                max = new_n;
            }
        }
        cout << new_n << '\t';
    }
    cout << "Average: " << av << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}