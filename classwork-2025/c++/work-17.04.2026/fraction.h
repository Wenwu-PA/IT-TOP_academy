class Fraction
{
    int num;
    int denom;
public:
    Fraction() = default;
    Fraction(int numP, int enumP): num{numP},enum{enumP}


    void print()

    Fraction operator+(Fraction obj2){
        return {num * obj2.denom + obj2.num * denom,
            denom * obj2.denom};
    }
}