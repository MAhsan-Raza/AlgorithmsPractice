

// Define specializations for the Traits class template here.

template<>
struct Traits<Fruit>
{
public:
    static string name(int i)
    {
        switch((Fruit)i)
        {
            case Fruit::apple:
                return "apple";
                break; 
            case Fruit::orange:
                return "orange";
                break; 
            case Fruit::pear:
                return "pear";
                break;
        }
        return "unknown";
    }
};

template<>
struct Traits<Color>
{
public:
    static string name(int i)
    {
        switch((Color)i)
        {
            case Color::red:
                return "red";
                break; 
            case Color::green:
                return "green";
                break; 
            case Color::orange:
                return "orange";
                break;
        }
        return "unknown";
    }
};

