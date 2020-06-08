

class Box
{  
private:
    int l,b,h;

public:

    Box() : l(0), b(0), h(0) {}
    Box(int ll,int bb,int hh) : l(ll), b(bb), h(hh) {}
    Box(const Box& b1) : l(b1.l), b(b1.b), h(b1.h) {}


    int getLength() const { return l; }
    int getBreadth () const { return b; }
    int getHeight () const { return h; }
    long long CalculateVolume() const { return (long)l*(long)b*(long)h; }

//Overload operator < as specified
    bool operator<(Box& b)
    {
        if(this->l < b.l)
            return true;
        else if(this->l == b.l)
        {
            if(this->b < b.b)
                return true;
            else if(this->b == b.b)
            {
                if(this->h < b.h)
                    return true;
            }
        }

        return false;
    }
};

//Overload operator << as specified
ostream& operator << (ostream& out, Box& B)
{
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}

