#include<iostream>
using namespace std;


bool isValid(string str, int N)

{

if(!((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z') || str [0]=='_'))




     for (int i=1; i<str.length(); i++)
{

    if(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]>='Z') || str [i]=='_'))




        return  false;

}

return true;
}


int main()
{
string user;
int N;
cout<<"Input Text: ";
cin>>user;


if(isValid(user,N))
{

    cout<<"Text is valid";

}

    else
    {

        cout<<"Not valid";

    }

  return 0;

}
