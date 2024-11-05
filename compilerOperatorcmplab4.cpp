#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Create and open a text file
    ofstream MyFile;
    MyFile.open("NewFile.txt");

    // Write to the file
    MyFile << "Name \t"  "DEPT.\t" "CGPA\t\n";
    MyFile<<"Rahim \t"  "IPE\t" "3.88\t\n";
    MyFile<<"Karim \t"  "EEE\t" "3.92\t\n";
    MyFile<<"Akash \t"  "CSE\t" "3.97\t\n";
    MyFile<<"Chinmoi\t"  "CSE\t" "3.97\t\n";
    MyFile<<"Ansarul\t"  "CSE\t" "3.97\t\n";
    MyFile<<"Tawhid \t"  "CSE\t" "3.96\t";
    // Close the file
    MyFile.close();

    string myText;

    // Read from the text file
    //ifstream MyReadFile("C://Users//Teacher//Desktop//Fall-24-25//Compiler Design//New folder//LAB//Lab 1//Lab-1 Codes//student.txt");
    ifstream MyReadFile("NewFile.txt");
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText))
    {
        // Output the text from the file
        cout << myText<<endl;
    }

    // Close the file
    MyReadFile.close();

}

