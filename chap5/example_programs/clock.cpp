// modify clock program

class clock {
    public:
        clock(unsigned long i);     // construct & conversion
        void print() const;         // formatted printout
        void tick();                // add one second
        clock operator++() { this->tick(); return *this; }
        void reset(const clock& c);
    private:
        unsgined long tot_secs, secs, mins, hours, days;
};

void clock::reset(const clock& c)
{
    tot_secs = c.tot_secs;
    secs = c.secs;
    mins = c.mins;
    hours = c.hours;
    days = c.days;
}

int main()
{
    clock c1(900), c2(400);
    // ....
    c1.reset(c2);
    c2.reset(100);
    // ....
}