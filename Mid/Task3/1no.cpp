#include<iostream>
#include<linestream>
using namespace std;

int main(){
//hehe
std::string   line;
while(std::getline(std::cin,line))
{

    // If you then want to tokenize the line use a string stream:

    std::stringstream lineStream(line);
    std::string token;
    while(lineStream >> token)
    {
        std::cout << "Token(" << token << ")\n";
    }

    std::cout << "New Line Detected\n";
}


return 0;
}
