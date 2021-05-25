// A typical container algorithm

double sum(deque<double> &dq)
{
    deque<double>::iterator p;
    double s = 0.0;

    for (p = dq.begin(); p != dq.end(); ++p)
    {
        s += *p;
    }
    return s;
}