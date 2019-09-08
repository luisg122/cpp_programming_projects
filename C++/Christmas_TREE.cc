#include <iostream>

using namespace std;

int main()

{

  int stars = 1;

  int size;

  cout << "Enter the size of the tree: ";

  cin >> size;

  cout << "The size you chose was " << size << ", and your tree is: " << endl;

  int leaves = size / 2;

  for (int i = size; i > leaves; --i)

  {

    for (int k = 1; k < i - leaves; ++k)

    {

      cout << " ";

    }

    for (int j = 0; j < stars; ++j)

    {

      cout << "*";

    }

    stars += 2;

    cout << '\n';

  }

  // Stump of the tree

  int stump = size / 2;

  for (int i = 0; i < stump; ++i)

  {

    for (int k = 0; k < stump; ++k)

    {

      cout << " ";

    }

    cout << "*" << endl;

  }

  return 0;

}
