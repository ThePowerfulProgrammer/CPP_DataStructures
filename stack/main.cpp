#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "stackType.h"
#include "linkedStackType.h"
using namespace std;

/*
Program to model the data structure Stack
Think Yu-Gi-Oh cards
*/

void highestGPA(ifstream &filename)
{
    // Validate file
    if (!filename.is_open())
        {
            cout << "File cannot be open or file does not exist" << endl;
            return;
        }

     cout << fixed << showpoint;
     cout << setprecision(2);

    double GPA; // current value
    double highestGPA; // highest value
    string name; // current name
    stackType<string> stack(100); // stack to hold only highest GPA corresponding name

    highestGPA = 0;
    while (filename >> GPA >> name) // read-in values from text file
        {
            // situation 1
            if (GPA > highestGPA)
                {
                    highestGPA = GPA;
                    stack.initializeStack();
                    if (!stack.isFullStack())
                        {
                            stack.push(name);
                        }
                }
            else if  (GPA == highestGPA)
                {
                    if (!stack.isFullStack())
                        {
                            stack.push(name);
                        }
                    else
                        {
                            cout << "Stack is at capacity" << endl;
                            return;
                        }
                }

        }
    filename.close();

    cout << "Highest GPA = " << highestGPA << " ";
    cout << "Students with the highest GPA's: " << endl;
    while (!stack.isEmptyStack())
        {
            cout << stack.top() << endl;
            stack.pop();
        }
    cout << endl;

}


void evaluateOpr(ofstream& out, linkedStackType<double>& stack, char& ch, bool& isExpOk)
{
    double op1,op2;
    if (stack.isEmptyStack())
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
    else
        {
            op2 = stack.top();
            stack.pop();

            if (stack.isEmptyStack())
                {
                    out << " (Not enough operands)";
                    isExpOk = false;
                }
            else
                {
                    op1 = stack.top();
                    stack.pop();
                    switch(ch)
                    {
                    case '+':
                        stack.push(op1 + op2);
                        break;
                    case '-':
                        stack.push(op1-op2);
                        break;
                    case '*':
                        stack.push(op1 * op2);
                        break;
                    case '/':
                        if (op2 != 0)
                            {
                                stack.push(op1/op2);
                            }
                        else
                            {
                                out << " (Division by 0)";
                                isExpOk = false;
                            }
                        break;
                    default:
                        out << " (Illegal operation)";
                        isExpOk = false;
                    }
                }
        }
}

void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
        {
            in.get(ch);
            out << ch;
        }
}

void evaluateExpression(ifstream& inpF, ofstream& outF, linkedStackType<double>& stack, char& ch, bool& isExpOk)
{
    double num;
    while (ch != '=')
        {
            switch (ch)
            {
            case '#':
                inpF >> num;
                outF << num << " ";
                if (!stack.isFullStack())
                    {
                        stack.push(num);
                    }
                else
                    {
                        cout << "Stack overflow. " << "Program terminates!" << endl;
                        exit(0);
                    }
                break;
            default:
                evaluateOpr(outF,stack,ch,isExpOk);
            } // end switch
            if (isExpOk)
                {
                    inpF >> ch;
                    outF << ch;

                    if (ch != '#')
                        {
                            outF << " ";
                        }
                }
            else
                {
                    discardExp(inpF,outF,ch);
                }
        }
}



void printResult(ofstream& outF, linkedStackType<double>& stack, bool isExpOk)
{
    double result;
    if (!stack.isEmptyStack())
        {
            result = stack.top();
            stack.pop();

            if (stack.isEmptyStack())
                {
                    outF << result << endl;
                }
            else
                {
                    outF << " (Error: Too many operands)" << endl;
                }
        }
    else
        {
            outF << " (Error in the expression)" << endl;
        }
    outF << "__________________________________________" << endl << endl;
}

int main()
{
    string filename = "GPA.txt"; // Replace "input.txt" with your desired filename
    ifstream inputFile(filename); // Create an ifstream object and open the file
    highestGPA(inputFile);
    cout << "let us now use linkedStacks" << endl << endl;

    bool expressionOk;
    char ch;
    linkedStackType<double> STACK;
    ifstream infile;
    ofstream outfile;

    infile.open("Input.txt");
    if (!infile)
        {
            cout << "Cannot open input file" << endl;
            return 1;
        }
    outfile.open("outPut.txt");

    outfile << fixed << showpoint;
    outfile << setprecision(2);

    infile >> ch;
    while (infile)
        {
            STACK.initializeStack();
            expressionOk = true;
            outfile << ch;

            evaluateExpression(infile,outfile,STACK,ch,expressionOk);
            printResult(outfile,STACK,expressionOk);
            infile >> ch;
        }
    infile.close();
    outfile.close();

    return 0;
}
