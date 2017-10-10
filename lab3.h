class Fraction
{
    private:
        int x;//числитель
        int y;//знаминатель
    public:
        static int count;
        Fraction(int a, int b);
        int Set(int a, int b);
        //set(double a);
        ~Fraction();// как грамотно реализовать уборку мусора в классе;
        Fraction operator+ (const Fraction &a);
        Fraction operator* (Fraction &right);
        Fraction operator- (const Fraction &a);
        Fraction operator/ (  Fraction &right);
        void Print();
};