#include<iostream>
#include<string>
using namespace std;

int main()
{
    string first_name, last_name;
    cout<<"Enter your first name: ";
    cin>>first_name;
    cout<<"Enter your last name: ";
    cin>>last_name;
    cout<<"Your full name: "<<strcat(first_name, last_name)<<endl;

}
