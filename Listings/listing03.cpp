// Class member access
SomeClass myClass;          // a class
SomeClass* myClassPointer;  // a pointer to a class

myClassPointer = new SomeClass();  // dynamic creation, don't forget to delete it

myClass.someint = 43;          // set value by direct member access
myClassPointer->someint = 43;  // set value by pointer member access

(*myClassPointer).someint = 43;  // Equivalent but less clear syntax for "->"
(&myClass)->someint = 43;        // "&" creates a pointer to a variable

delete myClassPointer;  // don't forget to free dynamically created objects