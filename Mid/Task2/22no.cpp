
#include<iostream>

using namespace std;

int main(){
    string CommentString;

    cout<<"Enter string:";
    cin>>CommentString;

    if(CommentString.substr(0,2) == "//"){
        cout<<"This single line comment."<<endl;
    }
    else if(CommentString.substr(0,2) == "/*" && CommentString[CommentString.length()-2] == '*' && CommentString[CommentString.length()-1] == '/'){
        cout<<"This is a multi-line comment."<<endl;
    }
    else{
        cout<<"This is not a comment."<<endl;
    }



    /*
    if(CommentString[1] != "/" || (CommentString[1] != "#" || CommentString[CommentString.length-2] != "#") ||(CommentString[0] != "/" || CommentString[CommentString.length-1] != "/")  ){
        cout<<""
    }

    */

    return 0;
}
