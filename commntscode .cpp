#include<iostream>
#include<string>


using namespace std;

int main()

{
  string s;
  cout<<"Input Text: ";
 cin>>s;

if((s[0]=='/'  && s[1]=='/'))

{

    cout<<"Single line comments";


}

if((s[0]=='/'  && s[1]=='*') && (s[s.length()-2]=='*'&& s[s.length()-1]== '/'))


{

    cout<<" Multiple line comments";
}

return 0;

}
