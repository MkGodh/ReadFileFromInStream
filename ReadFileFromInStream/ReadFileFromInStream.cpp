#include <iostream>
#include <fstream>
#include <string>


int main()
{
    char buffer[20];
    std::string filePath;
    std::cout << "Please, input a way to your your file: " << std::endl;
    std::getline(std::cin, filePath); // nums.txt 
    std::ifstream readPath;
    readPath.open(filePath, std::ios::binary);

    if (!readPath.is_open())
    {
        std::cerr << "Fail to open file or mistake in a path to it" << std::endl;
        return 1;
    }

    while (readPath.read(buffer, sizeof(buffer)))
    {
        std::streamsize bytesRead = readPath.gcount();
        std::cout.write(buffer, bytesRead);
    }

    std::streamsize bytesRead = readPath.gcount();
    if (bytesRead > 0)
    {
        std::cout.write(buffer, bytesRead);
    }
}
