#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    //strlen counts the elements or total length of elements in a string array
	char str1[] = "This is a string"; // spaces count as  elements in a string array
    char str2[] = "This is another string";

    int len1 = strlen(str1); // is strlen a predefined functions directed from the ctring header file?
    int len2 = strlen(str2);

    cout << "Length of str1 = " << len1 << endl;
    cout << "Length of str2 = " << len2 << endl;
    if (len1 > len2)
        cout << "str1 is longer than str2";
    else if (len1 < len2)
        cout << "str2 is longer than str1";
    else
        cout << "str1 and str2 are of equal length";

    return 0;

}
