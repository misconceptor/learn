class Rat{
public:
    Rat();
    explicit Rat(int);
    Rat(int, int);
    ~Rat(){}

    int& Numerator();
    const int& Numerator() const; 
    int& Denominator();
    const int& Denominator() const;

    Rat const operator+(const Rat& other) const;
    Rat const operator-(const Rat& other) const;
    Rat const operator*(const Rat& other) const;
    Rat const operator/(const Rat& other) const;
    inline Rat& operator++(); //prefix
    inline Rat const operator++(int); //postfix

    Rat& operator+=(const Rat& other);
    Rat& operator+=(int other);
    Rat& operator-=(const Rat& other);
    Rat& operator-=(int other);

    explicit operator double() const;

    inline bool operator==(Rat const& rhs) const{
        return (num * rhs.denom == denom * rhs.num);
    }
    inline bool operator==(int rhs) const{
        return (num == denom * rhs);
    }
    std::strong_ordering operator<=>(Rat const& rhs) const {
        return num*rhs.denom <=> denom*rhs.num;
    }
    std::strong_ordering operator<=>(int rhs) const {
        return num <=> rhs*denom;
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