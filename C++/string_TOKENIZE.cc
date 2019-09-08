/* C++ program that breaks an English sentence into words */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    //Vector to hold tokens
    vector<string> tokens;
    char input[1024];

    //Delimiters
    const char *delimeters = " ,./?!;:";
    char *token;

    int i;

    //Reading input from user
    cout << "\n\n Enter one or more English sentences: ";
    cin.getline(input, 1024);

    //Splitting the string into tokens
    token = strtok(input, delimeters);

    //Iterate till all words are placed
    while( token != NULL )
    {
        //Storing in vector
        tokens.push_back(token);

        //Moving to next word
        token = strtok(NULL, delimeters);
    }

    //Printing vector contents in specified format
    cout << "\n\n {";
    for(i=0; i<tokens.size() - 1; i++)
    {
        //Printing token
        cout << tokens.at(i) << ", ";
    }

    //Printing last token
    cout << tokens.at(i) << "} \n\n";

    return 0;
}
