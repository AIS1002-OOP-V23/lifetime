#include <iostream>
#include <fstream>
#include <string>

class MyClass {

public:
    MyClass(const std::string& path) {

        if_.open(path);
    }

    std::string readLine() {
        std::string line;
        std::getline(if_, line);

        return line;
    }

    ~MyClass() {
        if_.close();
    }

private:
    std::ifstream if_;

};

int main() {

    {
        MyClass fileReader("CMakeCache.txt"); // object set ups and manages the file resource
        std::cout << fileReader.readLine() << std::endl;
    } // destructor is called, file is closed


    return 0;
}
