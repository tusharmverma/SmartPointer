#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include "Foo.h"
#include "UniquePtr.h"
#include <string>
    using std::string;


int main ()
{


    UniquePtr<Foo> fooPtr{new Foo};
    std::cout << "Creating first object...\n";
    UniquePtr<Foo> p1{new Foo};
    {
        std::cout << "Creating second object with short lifetime...\n";
        UniquePtr<Foo> p2{new Foo};
        std::cout << "Second object is about to go out of scope...\n";
    }
    std::cout << "Second object should be gone.\n";

    UniquePtr<Foo> fPtr{"Bond, James Bond"};
    std::cout << "Creating first object...\n";
    cout << "fPtr serial(): " << fPtr->serial() << endl;
    cout << "fPtr serial(): " << *fPtr          << endl;
    UniquePtr<Foo> p3{"I've got a bad feeling about this"};
    {
        std::cout << "Creating second object with short lifetime...\n";
        UniquePtr<Foo> p4{"The force will be with you, always..."};
        cout << "p4 serial(): " << p4->serial() << endl;
        std::cout << "Second object is about to go out of scope...\n";
    }
    std::cout << "Second object should be gone.\n";

    //UniquePtr<Foo> p5 = p3;

    UniquePtr<Foo[]>    array_of_Foos{5};     // managed array of 5 `Foo`s.
    UniquePtr<double[]> array_of_doubles{10}; // managed array of 10 `double`s.
    return 0;
}
