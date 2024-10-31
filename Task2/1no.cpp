#include<iostream>

using namespace std;

bool checkOperator(char c){
    return (c=='+' || c=='-' ||c=='*' ||c=='/' ||c=='=');
}

int main(){
    string OperatorString;

    cout<<"Enter string:";
    getline(cin, OperatorString);

    int count = 0;

    for(int i=0; i<OperatorString.length(); i++){
        if(checkOperator(OperatorString[i])){
            count++;
            cout<<"Operator No."<<count << ": "<<OperatorString[i]<<endl;
        }
    }


    cout<<"The total operator count "<<count<<endl;


    return 0;
}
