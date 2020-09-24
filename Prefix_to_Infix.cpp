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

string prefix_to_infix(string prefix)
{
                stack<string> s;
                for(int i=prefix.length()-1; i>=0; i--)
                {
                                if(IsOperand(prefix[i]))
                                {
                                    string op(1,prefix[i]);
                                     s.push(op);
                                }
                                else
                                {
                                       string op1=s.top();
                                       s.pop();
                                       string op2=s.top();
                                       s.pop();
                                       s.push(op1+prefix[i]+op2);
                                }
                }
return s.top();
}
int main()
{
          string  prefix, infix;

          cout<<"Enter Prefix Expression:: ";
          getline(cin,prefix);

         infix=prefix_to_infix(prefix);
         cout<<"Infix Expression:: "<<infix;
         return 0;
}

