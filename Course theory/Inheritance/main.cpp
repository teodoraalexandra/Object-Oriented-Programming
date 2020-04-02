#include "Penguin.h"
#include "Dog.h"
#include <iostream>

using namespace std;

void virtualFunctions()
{
    Animal* Skipper = new Penguin{ "black and white", 7, "Magellanic" };
    cout << Skipper->toString() << "here"<<endl;

    Animal d{Dog{ "black", 25, "rottweiler", 0.2 }};
    cout << d.toString() << endl;

    //Animal a{ d };
    //cout << a.toString() << endl;

    Animal x(*Skipper);
    cout << x.toString() << endl; // polymorphism does NOT work with objects!

    delete Skipper;
}

void upCasting()
{
    // all the casts are implicit

    Penguin Rico{ "black and white", 7, "Magellanic" };
    Animal a1{ Rico };
    cout << a1.toString() << endl;

    Dog d{ "black", 25, "rottweiler", 0.2 };
    Animal& a2{ d };
    cout << a2.toString() << endl;

    Penguin* Kowalski = new Penguin{ "white and black", 5, "Imperial" };
    Animal* a3{ Kowalski };
    cout << a3->toString() << endl;

    delete Kowalski;
}

void showAnimal(Animal a)
{
    cout << a.toString() << endl;
}

void showDog(Dog d)
{
    cout << d.toString() << endl;
}

void substitutionPrinciple()
{
    Penguin penguin{ "black and white", 10, "Magellanic" };
    Dog dog{ "brown", 20, "Labrador Retriever", 2.5 };

    Animal animal{ "green", 0.2 };
    showAnimal(animal);

    animal = penguin;		// implicit upcast
    showAnimal(penguin);	// implicit upcast
    showAnimal(dog);		// implicit upcast
    cout << endl;

    //dog = animal;	// error!
    //showDog(animal); // error !
}

void pointersAndInheritance()
{
    Animal* animal = new Animal{ "black", 65 };
    cout << animal->toString() << endl;

    Penguin* penguin = new Penguin{ "black and white", 12, "Imperial" };
    animal = penguin;	// this is allowed;
    // In this particular case, is it correct, or can you identify an error? Hint: look at the deallocation at the end of the function.

    cout << animal->toString() << endl;
    //penguin = animal; //error!

    delete penguin;
    delete animal; // !!! memory error
}

void methodOverriding()
{
    Penguin penguin{ "black and white", 10, "Magellanic" };
    Dog dog{ "brown", 20, "Labrador Retriever", 2.5 };

    cout << penguin.toString() << endl;
    cout << dog.toString() << endl;
}

int main()
{
    Penguin penguin{ "black and white", 10, "Magellanic" };
    // penguin is an animal => we can use any method from the Animal class
    cout << penguin.toString() << endl;

    // constructing and destructing objects of derived classes
    {
        Penguin penguin{ "black and white", 10, "Magellanic" };
        Dog dog{ "brown", 20, "Labrador Retriever", 2.5 };
        cout << dog.toString();
    }

    // ---------------------------------------------------------------------------------------------------
    //Substitution principle
    substitutionPrinciple();

    // ---------------------------------------------------------------------------------------------------
    // Pointers and inheritance
    // pointersAndInheritance();

    // ---------------------------------------------------------------------------------------------------
    // Method orverriding
    methodOverriding();


    //start lecture 6
    Penguin p{ "black and white", 10, "Emperor" };
    Animal* a = &p;
    cout << a->toString();

    //virtualFunctions();

    //virtualDestructors();

    upCasting();

    //downCasting();

    return 0;
}
