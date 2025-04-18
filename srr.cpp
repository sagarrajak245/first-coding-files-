
#include <iostream>
#include <string>

int main()
{
    std::string str = "Hello World";

    // Concatenation
    std::string str2 = str + "!";
    std::cout << "Concatenated: " << str2 << std::endl;

    // Length
    std::cout << "Length: " << str.length() << std::endl;

    // Accessing characters
    std::cout << "Character at index 6: " << str[6] << std::endl;

    // Substring
    std::string substr = str.substr(6, 5);
    std::cout << "Substring: " << substr << std::endl;

    // Find
    size_t pos = str.find("World");
    if (pos != std::string::npos)
    {
        std::cout << "'World' found at position: " << pos << std::endl;
    }

    // Replace
    str.replace(6, 5, "Universe");
    std::cout << "Replaced: " << str << std::endl;

    // Erase
    str.erase(5, 9);
    std::cout << "Erased: " << str << std::endl;

    // Insert
    str.insert(5, ",");
    std::cout << "Inserted: " << str << std::endl;

    return 0;
}
