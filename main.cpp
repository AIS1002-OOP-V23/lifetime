#include <iostream>
#include <memory>
#include <vector>

class MyClass {

public:

    void saySomething() const {
        std::cout << "Hei" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructed" << std::endl;
    }

};

void doSomthing(MyClass& cls) {}

void doSomething(MyClass* cls) {
    cls->saySomething();
}

void doSomething(const std::shared_ptr<MyClass>& cls) {}

std::shared_ptr<MyClass> createMyclass() {
    return std::make_shared<MyClass>();
}

int main() {

    std::vector<std::unique_ptr<MyClass>> v;

    {
        auto cls = std::make_unique<MyClass>();
        v.emplace_back(std::move(cls)); // unique_ptr cannot be copied, but we can __move__ ownership.
    } // the instance of MyClass outlives the scope as it is allocated on the heap.

    std::shared_ptr<MyClass> cls = nullptr; // pointers can be nullptr
    {
        cls = createMyclass(); // copying shared_ptr is allowed
    }

    doSomething(cls.get()); // .get() to get hold of the underlying raw pointer -> MyClass*
    doSomthing(*cls); // dereference csl -> MyClass&
    doSomething(cls); // pass by reference (or value if we wanted to..)

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
