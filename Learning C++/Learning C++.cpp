// Learning C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MyClass
{
    int z; //this is private
public:
    //constructor
    MyClass() {
        cout << "Hello World! from constructor" << "\n";
    }
    //fields
    int myNum;
    string myString;
    //methods
    void myMethod() {
        cout << "Hello World! Called from a class method" << "\n";
    }
    void myMethod2();
private:
    int y;
};

//method definition outside the class
void MyClass::myMethod2() {
    cout << "Method defined outside the class" << "\n";
}

class Car {
    public:
        int speed(int maxSpeed);
        string brand;
        string model;
        int year;
        //constructor with parameters
        Car(string x, string y, int z) {
            brand = x;
            model = y;
            year = z;
        }
};

int Car::speed(int maxSpeed) {
    return maxSpeed;
}

class Employee
{
public:
    void setSalary(int s) {
        salary = s;
    }
    int getSalary() {
        return salary;
    }

private:
    int salary;
};

//Inheritance
//base class
class Vehicle {
public:
    string brand = "Ford";
    void honk() {
        cout << "Tuut, tuut! \n";
    }
};

//derived class
class Truck : public Vehicle {
public:
    string model = "F150";
};

/*Multi Level Inheritance*/
//Base Parent class
class Parent {
public:
    void myFunction(){
        cout << "Some content from parent class.\n";
    }
};
//Derived Child class
class Child : public Parent {
    //empty class
};
//Derived Grandchild class
class GrandChild : public Child {
    //empty class
};

/*Multiple Inheritance*/
//first base class
class FirstClass {
public:
    void myFunction() {
        cout << "Some content in first parent class\n";
    }
};
//second base class
class SecondClass {
public:
    void myOtherFunction() {
        cout << "Some content in second parent class\n";
    }
};
//derived class
class ThirdClass : public FirstClass, public SecondClass {
    //empty class
};

/*Polymorphism*/
//base class
class Animal {
public:
    void animalSound() {
        cout << "The animal makes a sound\n";
    }
    void eat() {
        cout << "The animal ate the food\n";
    }
};
//first derived class
class Pig : public Animal {
public:
    void animalSound() {
        cout << "The pig says: wee wee \n";
    }
};
//second derived class
class Dog : public Animal {
public:
    void animalSound() {
        cout << "The dog says: bow wow \n";
    }
};

/*Write to a file*/
class WriteFile {
public:
    void writeToFile() {
        //create and open a text file
        ofstream MyFile("filename.txt");
        //write to the file
        MyFile << "Files can be tricky, but it is fun enough!";
        //close the file
        MyFile.close();
    }
    void readTheFile() {
        //create string to read the text to
        string myText;
        //read the file
        ifstream MyReadFile("filename.txt");
        //use while loop to read the file line by line 
        while (getline(MyReadFile, myText)) {
            //output text to file
            cout << myText << "\n";
        }
        //close the file
        MyReadFile.close();
    }
};

/*Try Catch Throw*/
class TCT {
public:
    void tryCatchThrow() {
        try {
            int age = 15;
            if (age > 18) {
                cout << "Access granted - you are old enough\n";
            }
            else {
                throw(age);
            }
        }
        catch (int myNum) {
            cout << "Access denied - you must be at least 18 years old.\n";
            cout << "Age is: " << myNum << "\n";
        }
    }
    //throw custom error number
    void tryCatchThrow2() {
        try {
            int age = 15;
            if (age > 18) {
                cout << "Access granted - you are old enough\n";
            }
            else {
                throw 505;
            }
        }
        catch (int myNum) {
            cout << "Access denied - you must be at least 18 years old.\n";
            cout << "Error Number: " << myNum << "\n";
        }
    }
    //handle any type of exception with (...)
    void tryCatchThrow3() {
        try {
            int age = 15;
            if (age > 18) {
                cout << "Access granted - you are old enough\n";
            }
            else {
                throw 505;
            }
        }
        catch (...) {
            cout << "Access denied - you must be at least 18 years old.\n";
        }
    }
};
/*User input*/
class AddNumbers {
public:
    void add() {
        int x, y;
        int sum;
        cout << "Type a number: ";
        cin >> x;
        cout << "Type another number: ";
        cin >> y;
        sum = x + y;
        cout << "Sum is: " << sum << "\n";
    }
};

/*References and Pointers*/
class References {
public:
    void makeReference() {
        string food = "Pizza";
        //& is the memory address symbol used to make a reference to another variable
        string& meal = food;

        cout << "food: " + food + "\n";
        cout << "meal: " + meal + "\n";
        cout << "Change food to burger\n";
        food = "burger";
        cout << "food: " + food + "\n";
        cout << "meal: " + meal + "\n";
    }
    void pointers() {
        string food = "Pizza";
        //pointer variable of same type is created with * operator
        string* ptr = &food;

        cout << food << "\n"; //outputs variable
        cout << &food << "\n";//outputs memory address
        cout << ptr << "\n";  //outputs memory address with pointer
    }
    void dereference() {
        string food = "Pizza"; //variable
        string* ptr = &food;   //pointer
        //Reference: Output the memory address of food with the pointer
        cout << ptr << "\n";
        //Dereference: Output the value of food with the pointer(Pizza)
        cout << *ptr << "\n";
    }
    void modify() {
        //set the variable
        string food = "Pizza";
        string* ptr = &food;
        cout << food << "\n";
        cout << &food << "\n";
        cout << *ptr << "\n";
        //change the pointer refererence value
        *ptr = "Hamburger";
        cout << *ptr << "\n";
        cout << food << "\n";
    }
};
/*function overloading*/
//have the same function name with different parameters
class Overload {
public:
    int plusFunc(int x, int y) {
        return x + y;
    }
    double plusFunc(double x, double y) {
        return x + y;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    //create instance of class
    MyClass myObj;
    Car carObj("BMW", "X5", 1999);
    Employee employeeObj;
    Truck myTruck;
    GrandChild myGrandChild;
    ThirdClass multiParentClass;
    Animal myAnimal;
    Pig myPig;
    Dog myDog;
    WriteFile myFile;
    TCT myTCT;
    AddNumbers addNumbers;
    References references;
    Overload overload;

    //give fields a value
    myObj.myNum = 15;
    myObj.myString = "Some text";

    //try to access private field
    /*myObj.y = 50;*/ //removed as causes errors

    //print the fields
    cout << myObj.myNum << "\n";
    cout << myObj.myString << "\n";
    cout << carObj.brand << " " << carObj.model << " " << carObj.year << "\n";
    cout << myTruck.brand + " " + myTruck.model << "\n";

    //call the class method
    myObj.myMethod();
    myObj.myMethod2();
    employeeObj.setSalary(50000);
    cout << employeeObj.getSalary() << "\n";
    myTruck.honk();
    myGrandChild.myFunction();
    multiParentClass.myFunction();
    multiParentClass.myOtherFunction();
    myAnimal.eat();
    myAnimal.animalSound();
    myPig.eat();
    myPig.animalSound();
    myDog.eat();
    myDog.animalSound();
    myFile.writeToFile();
    myFile.readTheFile();
    myTCT.tryCatchThrow();
    myTCT.tryCatchThrow2();
    myTCT.tryCatchThrow3();
    references.makeReference();
    references.pointers();
    references.dereference();
    references.modify();

    //set variables from return functions
    int myNum1 = overload.plusFunc(8, 5);
    double myNum2 = overload.plusFunc(4.3, 6.26);
    cout << "Int: " << myNum1 << "\n";
    cout << "Double: " << myNum2 << "\n";

    //call method with parameter
    cout << carObj.speed(200) << "\n";

    //user input method
    addNumbers.add();

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
