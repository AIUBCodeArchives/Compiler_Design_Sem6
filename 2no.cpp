#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char first_name[20]= "", last_name[20] = "";
    cout<<"Enter your first name: ";
    cin>>first_name;
    cout<<"Enter your last name: ";
    cin>>last_name;
    strcat(first_name, " ");
    strcat(first_name, last_name);
    cout<<"Your full name: "<<first_name<<endl;

}
