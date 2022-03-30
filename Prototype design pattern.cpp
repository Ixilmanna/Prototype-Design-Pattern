// Prototype design pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Terdapat 2 type Character dimana setiap character yang dibuat dari 
kedua type memiliki attack point yang berbeda beda*/

#include <iostream>
#include <string>

/* Class Prototype */
class Prototype
{
protected:
    std::string type;
    int value;

public:
    virtual Prototype* clone() = 0;

    std::string getType()
    {
        return type;
    }

    int getValue()
    {
        return value;
    }
};
/*Concrete Object */
class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1(int number)
    {
        type = "CharacterType1";
        value = number;
    }

    Prototype* clone()
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype
{
public:
    ConcretePrototype2(int number)
    {
        type = "CharacterType2";
        value = number;
    }

    Prototype* clone()
    {
        return new ConcretePrototype2(*this);
    }
};

/* Class Factory Yang memanage Prototype instance dan Clone */
class ObjectFactory
{
    static Prototype* type1value1;
    static Prototype* type1value2;
    static Prototype* type2value1;
    static Prototype* type2value2;

public:
    /*inisialisasi object yang di clone*/
    static void  initialize()
    {
        type1value1 = new ConcretePrototype1(20);
        type1value2 = new ConcretePrototype1(60);
        type2value1 = new ConcretePrototype2(10);
        type2value2 = new ConcretePrototype2(50);
    }

    static Prototype* getType1Value1()
    {
        return type1value1->clone();
    }

    static Prototype* getType1Value2()
    {
        return type1value2->clone();
    }

    static Prototype* getType2Value1()
    {
        return type2value1->clone();
    }

    static Prototype* getType2Value2()
    {
        return type2value2->clone();
    }
};

Prototype* ObjectFactory::type1value1 = 0;
Prototype* ObjectFactory::type1value2 = 0;
Prototype* ObjectFactory::type2value1 = 0;
Prototype* ObjectFactory::type2value2 = 0;

int main()
{
    ObjectFactory::initialize();
    Prototype* object;

    /* All the object were created by cloning the prototypes. */
    object = ObjectFactory::getType1Value1();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType1Value2();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType2Value1();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType2Value2();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
