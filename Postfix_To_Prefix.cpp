#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool IsOperand(char c)
{
                if((c>='a' &&  c<='z') || (c>='A' &&  c<='Z') )
                {
                    return true;
                }
                else
                {
                   return false;
                }
}

string postfix_to_prefix(string postfix)
{
                stack<string> s;
                for(int i=0; i<postfix.length(); i++)
                {
                                if(IsOperand(postfix[i]))
                                {
                                    string op(1,postfix[i]);
                                     s.push(op);
                                }
                                else
                                {
                                       string op1=s.top();
                                       s.pop();
                                       string op2=s.top();
                                       s.pop();
                                       s.push(postfix[i]+op2+op1);
                                }
                }
return s.top();
}
int main()
{
          string  prefix, postfix;

          cout<<"Enter Postfix Expression:: ";
          getline(cin,postfix);

         prefix=postfix_to_prefix(postfix);
         cout<<"Prefix Expression:: "<<prefix;
         return 0;
}
