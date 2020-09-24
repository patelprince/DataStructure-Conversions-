#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;


bool IsOperator(char c)
{
                if(c=='^' ||  c=='+' || c=='-' ||  c=='/' || c=='*')
                {
                    return true;
                }
                else
                {
                   return false;
                }
}

int  precedence(char c)
{
                if(c=='^')
                                return 3;
                else if(c=='*' ||  c=='/')
                                return 2;
                else if(c=='+' || c=='-')
                                return 1;
                else
                                return -1;
}
/*-------------------------------------------------------*/
string infix_to_prefix(stack<char> s  ,  string infix)
{
               //stack<char> s;
               string prefix;

              reverse(infix.begin(), infix.end());
          for(int i=0;  i<infix.length(); i++)
                {
                                if(infix[i]=='(')
                                {
                                    infix[i]=')';
                                }
                                else if(infix[i]==')')
                                {
                                       infix[i]='(';
                                }
                }
                /*-----------------------------------------*/
                 for(int i=0;  i<infix.length(); i++)
           {
                       if( (infix[i]>='a' &&  infix[i]<='z') || (infix[i]>='A' &&  infix[i]<='Z') )
                       {
                                prefix=prefix+infix[i];
                       }

                      else if(infix[i]=='(')
                      {
                               s.push(infix[i]);
                      }

                      else if(infix[i]==')')
                      {
                                      while( (s.top()!='(') &&  (!s.empty()) )
                                      {
                                                      prefix=prefix+s.top();
                                                      s.pop();
                                      }
                                      if(s.top()=='(')
                                      {
                                                      s.pop();
                                      }
                      }

                      else if(IsOperator(infix[i]))
                {
                           if(s.empty())
                           {
                                s.push(infix[i]);
                           }
                           else
                               {
                                if(precedence(infix[i]) > precedence(s.top()))
                               {
                                               s.push(infix[i]);
                               }
                               /*------------------------------------------------------------*/
                               else if ( (precedence(infix[i]) == precedence(s.top())) && (infix[i]=='^') )
                              {
                                 while( (precedence(infix[i]) == precedence(s.top())) && (infix[i]=='^'))
                                 {
                                                 prefix=prefix+s.top();
                                                 s.pop();
                                 }
                                 s.push(infix[i]);
                              }
                               /*------------------------------------------------------------*/
                             else if(precedence(infix[i]) == precedence(s.top()))
                             {
                                             s.push(infix[i]);
                             }
                              /*------------------------------------------------------------*/
                             else
                             {
                                   while((!s.empty()) && (precedence(infix[i]) < precedence(s.top())) )
                                   {
                                                   prefix=prefix+s.top();
                                                   s.pop();
                                   }
                                   s.push(infix[i]);
                              }
                             }
                    } //else if
           }
while(!s.empty())
{
     prefix=prefix+s.top();
     s.pop();
}
reverse(prefix.begin(), prefix.end());
return prefix;
}

int main()
{
          string infix, prefix;
          cout<<"Enter infix Expression:: ";
          getline(cin, infix);

          stack<char> s;
         prefix= infix_to_prefix(s, infix);
         cout<<"Prefix Expression:: "<<prefix;
}
