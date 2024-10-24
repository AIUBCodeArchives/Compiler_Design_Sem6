#include<iostream>
#include<fstream>
using namespace std;

struct Student
{
    string name;
    float marks;
};


int main()
{
    int no_of_student;
    cout<<"Enter the number of students:";
    cin>>no_of_student;

    Student student[no_of_student];

    for (int i = 0; i < no_of_student; i++)
    {
    cout<<"Enter the name of the No."<<i+1<<" student:";
    cin>>student[i].name;
    cout<<endl;
    cout<<"Enter the marks of the No."<<i+1<<" student:";
    cin>>student[i].marks;
    cout<<endl;

    }
    /*for (int i = 0; i < no_of_student; i++)
    {
        cout<<"The name of the no."<<i+1<<": "<<student[i].name<<endl;
        cout<<"The marks of the no."<<i+1<<": "<<student[i].marks<<endl;
    }*/

    ofstream my_file("student3no.txt");
    if(my_file.is_open()){
        for(int i = 0; i < no_of_student; i++){
            my_file <<student[i].name<<" "<<student[i].marks<<endl;
        }
        my_file.close();
        cout<<"Wrote in file"<<endl;
    }
    else{
        cout<<"Can not write in file"<<endl;
    }

    //read

    ifstream my_file1("student3no.txt");
    if (my_file1.is_open()) {
        for (int i = 0; i < no_of_student; ++i) {
            my_file1 >> student[i].name >> student[i].marks;
        }
        my_file1.close();

        // Display the read data
        for (int i = 0; i < no_of_student; i++) {
            cout << "Name: " << student[i].name
                      << ", marks: " << student[i].marks<<endl;
        }
    } else {
        cout << "Unable to open file for reading." << std::endl;
    }

}
