//#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

int main() {
        int count = 0;
        std::ios_base::sync_with_stdio(false);
        char buffer[1024];
        cout.rdbuf() -> pubsetbuf(buffer, 1024);
        for(int i = 1; i <= 200000; i++)
        {       
            //cout << "Hello world!\n";
            cout << i << endl;
			count++;
        }
        cout << "Count:" << count;
        return 0;
}
