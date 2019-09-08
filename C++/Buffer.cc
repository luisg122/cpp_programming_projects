#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
  {
  // This is where we'll put the stuff we read from file
  char buffer[ 81 ];

  // Here's our file
  ifstream file( "80-chars.txt" );

  // Fill the buffer with zeros (char strings must be null-terminated)
  fill_n( buffer, 81, '\0' );

  // Read as many as 80 bytes (chars) from the file and stick them in our array
  file.read( buffer, 80 );

  file.close();

  // Convert that char array into a STL string, and show the user what we got.
  string s( buffer );
  cout << s << endl;

  return 0;
  }
