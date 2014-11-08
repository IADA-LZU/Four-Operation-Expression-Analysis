#include <iostream>

using namespace std;

void RPN()
{
    stack<char> oprtr;
    stack<double> oprnd;
    string input;
    bool quie=false;
    double x, y;
    while(!quit)
    {
        cout<<"RPN>";
        cin>>input;
        switch(input[0])
        {
        case 'Q':case 'q':
            quit = true;
            break;
        case '+':
            y=oprnd.top();
            oprnd.pop();
            x=oprnd.top();
            oprnd.pop();
            cout<<"\t"<<x<<"+"<<y<<"="<<x+y<<"\n";
            oprnd.push(x+y);
            break;
        case '-':
            y=oprnd.top();
            oprnd.pop();
            x=oprnd.top();
            oprnd.pop();
            cout<<"\t"<<x<<"-"<<y<<"="<<x-y<<"\n";
            oprnd.push(x-y);
            break;
        case '*':
            y=oprnd.top();
            oprnd.pop();
            x=oprnd.top();
            oprnd.pop();
            cout<<"\t"<<x<<"*"<<y<<"="<<x*y<<"\n";
            oprnd.push(x*y);
            break;
        case '/':
            y=oprnd.top();
            oprnd.pop();
            x=oprnd.top();
            oprnd.pop();
            cout<<"\t"<<x<<"/"<<y<<"="<<x/y<<"\n";
            oprnd.push(x/y);
            break;
        default:
            istringstream in(input);
            in >> x;
            oprnd.push(x);
        }
    }
}

void convert()
{
    stack<char> op;
    string s;
    cout<<"Enter an infix expression: ";
    getline(cin, s);
    istringstream in(s);
    char c;
    while(in>>c)
    {
        if(c=='+' || c=='-' || c=='*' || c=='/')    op.push(c);
        else if(c==')')
        {
            cout << op.top() << " ";
            op.top();
        }
        else if(c>='0' && c<= '9')
        {
            in.putback(c);
            int n;
            in >> n;
            cout << n << " ";
        }
    }
    while(!op.empty())
        cout<<op.pop()<<endl;
}
