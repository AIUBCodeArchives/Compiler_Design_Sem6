#include<iostream>

using namespace std;

int main()
{
    int n = 5;

    cout<<"Enter the size of the array: 5"<<endl;
    

    int arr[n] = {10, 20, 30, 40, 50};
    cout<<"The array of number is {10, 20, 30, 40, 50}"<<endl;
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    float ave = sum/n;

    cout<<"The average of the array: "<<ave<<endl;
    
}