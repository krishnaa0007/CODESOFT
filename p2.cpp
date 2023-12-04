#include<iostream>
using namespace std;
int main(){
    char op;
    float num1, num2;
    cout<<" Enter the opertaors : +,*,-,/: "<<endl;
    cin>>op;
    cout<<"enter the two operands "<< endl;
    cin>>num1>>num2;
    switch(op){
        case '+':
        cout<<num1 <<"+"<<num2<<" = "<<num1+num2;
        break;
        case '-':
        cout<<num1 <<"-"<<num2<<" = "<<num1-num2;
        break;
        case '*':
        cout<<num1 <<"*"<<num2<<" = "<<num1*num2;
        break;
        case '/':
        cout<<num1 <<"/"<<num2<<" = "<<num1/num2;
        break;
        default:
        cout<<"error !!!!!! operator given is not in choise pls select wise";
        break;
    
    }
    return 0;
}