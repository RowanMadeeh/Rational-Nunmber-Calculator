/*
*Author: Rowan Madeeh Mohamed Fathy Mahmoud Shoeib
*Program Name: Rational Number Calculator
*Purpose: This program is a rational number calculator that is capable of taking two
 rational numbers and an operation to perform on them.
 Program handles cases of negative numbers and nominator without denominator.
 It also contains defensive programming to reject bad inputs.

*/
#include <iostream>
#include <regex>
#include <string>
using namespace std;
string equation;
int n,d,s;

// a function to check if the input of the user is in this format(a/b -+*/ c/d) and return true if the input matches this format

bool valid_rational1(string& equation){
    regex rational1 ("[-+]?[0-9]+(\\/[1-9][0-9]*)[ ]?[-+*/]?[ ]?[-+]?[0-9]+(\\/[1-9][0-9]*)");
    return regex_match(equation,rational1);
}

// a function to check if the input of the user is in this format(a -+*/ b/c) and return true if the input matches this format

bool valid_int1(string& equation){
    regex int1 ("[-+]?[0-9]+[ ]?[-+*/]?[ ]?[-+]?[0-9]+(\\/[1-9][0-9]*)");
    return regex_match(equation,int1);
}

// a function to check if the input of the user is in this format (a/b -+*/ c) and return true if the input matches this format

bool valid_int2(string& equation){
    regex int2 ("[-+]?[0-9]+(\\/[1-9][0-9]*)[ ]?[-+*/]?[ ]?[-+]?[0-9]+");
    return regex_match(equation,int2);
}

// a function to check if the input contains any alphabetical letter

bool check_alpha(string equation){
    bool checker = false;
        for(int i=0;i<equation.length();i++)
            {
            if(isalpha(equation[i]))
                {
                    checker = true;
                    i=equation.length()+1;
                }
            }

    return checker;
}

// a function to check if the input is the word quit

bool Quit(string equation){
    bool check = true;
    string word ="quit";
    for(int i=0;i<equation.length();i++){
        if(word[i]!=equation[i]){
            check = false;
            i=equation.length();
        }
    }
    return check;
}

// a function that perform mathematical operations

void calculate(char operation,int n1,int n2,int n3,int n4){
            if(operation=='/')
            {
            n = n1*n4;
            d = n2*n3;
             // a loop for simplifying the fraction
            for (int i = 1;i <= d; i++)
                {
                if (n % i == 0 && d % i == 0) {
                        s=i;
                }
            }
            cout << "answer= " << (n / s) << '/' << (d / s)<<'\n';

            }
            else if (operation == '+')
                {
                n = (n1 * n4) + (n2 * n3);
                d = (n2 * n4);
                // a loop for simplifying the fraction
                for (int i = 1;i <= d; i++)
                {
                    if (n % i == 0 && d % i == 0)
                    {
                        s=i;
                    }

                }
                cout << "answer= " << (n / s) << '/' << (d / s)<<'\n';
            }
            else if (operation == '-')
             {
                n = (n1 * n4) - (n2 * n3);
                d = (n2 * n4);
                // a loop for simplifying the fraction
                for (int i = 1;i <=d; i++)
                    {
                    if (n % i == 0 && d % i == 0) {
                            s=i;

                    }
                }
                cout << "answer= " << (n / s) << '/' << (d / s)<<'\n';
            }
            else if (operation == '*')
                {
                n = n1 * n3;
                d = n2 * n4;
                // a loop for simplifying the fraction
                for (int i = 1;i <= d; i++)
                 {
                    if (n % i == 0 && d % i == 0)
                     {
                         s=i;
                    }
                }
                cout << "answer= " << (n / s) << '/' << (d / s)<<'\n';
            }
}
using namespace std;
int main()
{
    int type=0,a=0,b=0,c=0,n1=0,n2=0,n3=0,n4=0,quit=0;
    string n_1,n_2,n_3,n_4;
    char operation;
    while(true){
            // getting input from user until the input matches one of the three formats or quiting the program
        while(true){
            cout<<"please enter a valid equation (or quit to exit program): ";
            getline(cin,equation);
            if(valid_rational1(equation)){
                type = 1;
                break;
            }else if(valid_int1(equation)){
                type = 2;
                break;
            }else if(valid_int2(equation)){
                type = 3;
                break;
            }else if(Quit(equation)){
                quit=1;
                break;
            }else if(check_alpha(equation)){
                 cout<<"invalid input"<<'\n';

            }
        }
        // a condition to exit from the program if the user enters quit
        if(quit==1){
            cout<<"Thank you for using rational number calculator";
            break;
        }

        if(type==1){

                //getting first nominator from equation
           for(int i=0;i<equation.length();i++){
               if(equation[i]!='/'){
                  n_1+=equation[i];
                  a=i+2;
               }else if(equation[i]=='/'){
                   i=equation.length();
               }
           }

            //getting first denominator from equation
           for(int i=a;i<equation.length();i++){
               if(equation[i]!='/' && equation[i]!='*' && equation[i]!='-' && equation[i]!='+'){
                  n_2+=equation[i];
                  b=i+1;
               }else{
                   i=equation.length();
               }
           }
           operation=equation[b]; //getting operator to work with

           //getting second nominator from equation
           for(int i=b+1;i<equation.length();i++){
               if(equation[i]!='/'){
                  n_3+=equation[i];
                  c=i+2;
               }else if(equation[i]=='/'){
                   i=equation.length();
               }
           }

           //getting second denominator from equation
           for(int i=c;i<equation.length();i++){
               n_4+=equation[i];
           }
           // converting numbers of the equation from string to integer
           n1 = stoi(n_1);
           n2 = stoi(n_2);
           n3 = stoi(n_3);
           n4 = stoi(n_4);

           // using calculate function to calculate the equation
           calculate(operation,n1,n2,n3,n4);

           //clearing each string after each operation to be able to use it again
           n_1.clear();
           n_2.clear();
           n_3.clear();
           n_4.clear();

            }else if(type==2){

                //getting first nominator from equation
                for(int i=0;i<equation.length();i++){
                   if(equation[i]!='/' && equation[i]!='*' && equation[i]!='-' && equation[i]!='+'){
                      n_1+=equation[i];
                      a=i+1;
                   }else{
                       i=equation.length();
                   }
               }

               operation=equation[a]; // getting operator to work with

               //getting second nominator from equation
               for(int i=a+1;i<equation.length();i++){
                   if(equation[i]!='/'){
                      n_3+=equation[i];
                      b=i+2;
                   }else{
                       i=equation.length();
                   }
               }

               //getting first denominator from equation
               for(int i=b;i<equation.length();i++){
                      n_4+=equation[i];
               }

            // converting numbers of the equation from string to integer
            n1 = stoi(n_1);
            n2 = 1;
            n3 = stoi(n_3);
            n4 = stoi(n_4);

            // clearing each string after each operation to be able to use it again
            n_1.clear();
            n_3.clear();
            n_4.clear();

            // using calculate function to calculate the equation
            calculate(operation,n1,n2,n3,n4);

            }else if(type==3){

                //getting first nominator from equation
                for(int i=0;i<equation.length();i++){
                       if(equation[i]!='/'){
                          n_1+=equation[i];
                          a=i+2;
                       }else if(equation[i]=='/'){
                           i=equation.length();
                       }
                }

                //getting first denominator from equation
                for(int i=a;i<equation.length();i++){
                       if(equation[i]!='/' && equation[i]!='*' && equation[i]!='-' && equation[i]!='+'){
                          n_2+=equation[i];
                          b=i+1;
                       }else{
                           i=equation.length();
                       }
                }

                operation=equation[b]; // getting operator to work with

                //getting second nominator from equation
                for(int i=b+1;i<equation.length();i++){
                       n_3+=equation[i];
                }

                // converting numbers of the equation from string to integer
                n1 = stoi(n_1);
                n2 = stoi(n_2);
                n3 = stoi(n_3);
                n4 = 1;

                // clearing each string after each operation to be able to use it again
                n_1.clear();
                n_2.clear();
                n_3.clear();

                // using calculate function to calculate the equation
                calculate(operation,n1,n2,n3,n4);
            }
    }




    return 0;
}
