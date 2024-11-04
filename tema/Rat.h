class Rat{
public:
    Rat();
    Rat(int);
    Rat(int, int);

    const int& Numerator(); 
    const int& Denominator();

    Rat const operator+(const Rat& other) const;
    Rat const operator-(const Rat& other) const;
    Rat const operator*(const Rat& other) const;
    Rat const operator/(const Rat& other) const;

    bool operator==(Rat const& r) const{
        return (num * r.denom == denom * r.num);
    }
    bool operator==(int r) const{
        return (num == denom * r);
    }

    void Normalize();
    void Show();
private:
    int num,denom;
    friend std::istream& operator >>(std::istream& is, Rat& r);
    friend std::ostream& operator <<(std::ostream& os, Rat& r);
};
std::istream& operator >>(std::istream& is, Rat& r);
std::ostream& operator <<(std::ostream& os, Rat& r);