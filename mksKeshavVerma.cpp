// mksKeshavVerma.cpp : This file contains the 'main' function.
//
#include <iostream>
#include<istream>
#include <fstream>
#include<sstream>
#include <vector>

using namespace std;

void tolower_by_char(string* &str)
{
    for (int i = 0; i < str->size(); i++) 
    {
        (*str)[i] = tolower((*str)[i]);
    }
}
void tolowercase(vector<string>&vector_of_string)
{
    for (int i = 0; i < vector_of_string.size(); i++)
    {
        string* str_ptr = &vector_of_string[i];
        tolower_by_char(str_ptr);
    }

}
void SortingAlgo(vector<string>& vector_of_string ,ofstream &outfile)
{
    for (int i = 0; i < vector_of_string.size(); i++)
    {
        for (vector<string>::iterator iter = vector_of_string.begin(); iter != vector_of_string.end() - 1; iter++) 
        {
            if ((*iter) > *(iter + 1) )
            {
                string temp = *iter;
                *iter = *(iter + 1);
                *(iter + 1) = temp;
            }
        }
    }
    if (outfile.is_open())
    {
        for (const string& word : vector_of_string) {
            outfile << word << " ";
        }
        outfile << endl;  
    }
    else
    {
        cout << "Error: Output file is not open." << endl;
    }
    for (string word : vector_of_string) 
    {
        cout << word << " ";
    }
}

void DivideSentanceInWords(string& sentance,ofstream& OutPutfile) 
{
    istringstream ss(sentance);
    string word;
    vector<string>vector_of_string;
    while (ss >> word)
    {
        vector_of_string.push_back(word);
    }
    tolowercase(vector_of_string);
    SortingAlgo(vector_of_string,OutPutfile);
    cout << endl;
    cout << endl;
}
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "pls enter the file path name: ";
        return 0;
    }
    cout << "Opening file: " << argv[1] << endl;
    ofstream outputFile(argv[2]);
    if (!outputFile.is_open())
    {
        cout << "Error: Could not open output file." << endl;
        return 1;
    }
    ifstream file;
    file.open(argv[1]);
    if (file.is_open()) 
    {
        string sentance_from_file;
        while (getline(file, sentance_from_file)) {
            DivideSentanceInWords(sentance_from_file,outputFile);
        }
    }

    else 
    {
        cout << "file does not open" << endl;
    }
    return 0;
}

/* 
Instructions
How To Run Program:

So basically I have two files one input file named:-dummy.txt (Which has some lines which I have to in ascending order).

Output file named: empty.txt (this is an empty file in which user will get the sorted strings )

so, go to programm properties->debugging->arguments_commands and under argumetn_commands give arguments dummy.txt empty.txt

That's all then just simply run the program on vsstudio code you will see the output and open the empty.txt file there you can find
the sorted string .

*/