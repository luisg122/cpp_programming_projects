#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

struct Sign{
	
	string m;
	
};

int * matrix_randgen(int n, int a,int b){
    
	int * array = new int[n*n];				//why dynamic memory?
    for(int i=n*n; i--;) 
	array[i] = rand() % (b - a + 1) + a;
    
	
	return array;
}

void show_matrix_array(int * array, int n){
    for(int i = 0; i < n*n; i++) 
	cout << (i % n == 0 ? "[" : "") << array[i] << ((i + 1) % n == 0 ? "]\n" : " ");  //MODULUS is used to show n-elements per row
}
/*void show_twomatrices_array_highlight(int * array1, int * array2, int n, int h1, int h2){
    cout << "       ";
    for (int c=0; c<n; c++) {
    cout << "(" << c << ")  ";
    }
    cout << "         ";
    for (int c=0; c<n; c++) {
    cout << "(" << c << ")  ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << "(" << i << "*n) [";
        for (int j=0; j<n; j++) {
            int k=j+(i*n);
            cout << (k==h1 ? "<" : " ") << array1[k] << (k==h1 ? ">" : " ");
            if (j<(n-1)) cout << ", ";
        }
        if (i==0) {
            cout << "] * (" << i <<"*n) [";
        }
        else {
            cout << "]   (" << i <<"*n) [";
        }
        for (int j=0; j<n; j++) {
            int k=j+(i*n);
            cout << (k==h2 ? "<" : " ") << array2[k] << (k==h2 ? ">" : " ");
            if (j<(n-1)) cout << ", ";
        }
        cout << "]" << endl;
    }
}
void show_matrix_array_highlight(int * array, int n, int j){
    for(int i=0; i<n*n; i++) cout << (i%n==0 ? "[" : "") << (i==j ? "<" : " ") << array[i] << (i==j ? ">" : " ") << ((i+1)%n==0 ? "]\n" : ", ");
    cout << endl;
}*/
int * matrix_add( int * m1, int * m2, int n) {
    int * add= new int[n*n];
    for(int i=n*n; i--;) add[i] = m1[i] + m2[i];
    return add;
}
int * matrix_sub( int * array, int * array2, int n) {
    int * sub = new int[n*n];
    for(int i=n*n; i--;) sub[i] = array[i] - array2[i];
    return sub;
}

int * matrix_multi( int * array1, int * array2, int n){
    int * multi= new int[n*n]{};                                            //declare blank array
    for (int j=0, i=0; j<n; j++)             								//horizontal shift of array1 everytime multi[i] reaches to the end of that row
        for (int l=0; l<n; l++, i++)        								//array2 shifts horizontally everytime multi[i] moves to the next i, note that array1 remains at the same row
            for (int m=0; m<n; m++)     									//the horizontal shift of array1 always matches the vertical shift of array2, so increase at the same time
                multi[i] = array1[m+(j*n)] * array2[l+(m*n)] + multi[i];
    return multi;
}

//Re-written Single-line Multi function
/*

int * matrix_multi( int * array1, int * array2, int n){
    int * multi= new int[n*n]{};
    cout << "multi[] original is:\n";
    show_matrix_array(multi, n);
    for (int m=0; m<n*n*n; m++) {
        int c=multi[m/n];
        if (m%n==0) {
            cout << "n=" << n << "\n";
        }
        multi[m/n] += array1[(m%n)+((m/(n*n))*n)] * array2[((m/n)%n)+((m%n)*n)];
        cout << "m=" << m << " multi[m/n = int " << m << "/" << n << "] = multi[" << m/n << "] = " << c << " (original multi[" << m/n << "]) + " << array1[(m%n)+((m/(n*n))*n)] * array2[((m/n)%n)+((m%n)*n)] << " (" << "array a[" << (m%n)+((m/(n*n))*n) << "] * array b[" << ((m/n)%n)+((m%n)*n) << "] = " << array1[(m%n)+((m/(n*n))*n)] << " * " << array2[((m/n)%n)+((m%n)*n)] << ") = " << multi[m/n] << " (new multi[" << m/n << "])\n";
        cout << "array a[" << (m%n)+((m/(n*n))*n) << "] * array b[" << ((m/n)%n)+((m%n)*n) << "] = " << array1[(m%n)+((m/(n*n))*n)] << " * " << array2[((m/n)%n)+((m%n)*n)] <<" = " << array1[(m%n)+((m/(n*n))*n)] * array2[((m/n)%n)+((m%n)*n)] << "\n";
        show_twomatrices_array_highlight(array1, array2, n, (m%n)+((m/(n*n))*n), ((m/n)%n)+((m%n)*n));
        if ((m+1)%n==0) {
            cout << "\nthe result multi[" << m/n << "] is " << multi[m/n] << "\n";
            show_matrix_array_highlight(multi, n, (m/n));
        }
    }
    return multi;
    }
*/
int main() {
    
	Sign line;
	line.m = "===========================\n";
	
	int n = 0;
    srand(time(NULL));
    cout << "Enter the size n of n*n matrices: ";
    cin  >> n;
    cout << endl;

   
    int *arraya = matrix_randgen(n, 0, 9);
    int *arrayb = matrix_randgen(n, 0, 9);
    
	int *add  = matrix_add(arraya, arrayb, n);
    int *sub  = matrix_sub(arraya, arrayb, n);
    int *multi= matrix_multi(arraya, arrayb, n);

    //cout << "Matrix a is" << endl;
    //show_matrix_array(arraya, n);

    //cout << "Matrix b is" << endl;
    //show_matrix_array(arrayb, n);

    cout << "Matrix (a + b) is:\n" << endl;
    show_matrix_array(add, n);

	cout << line.m;

    cout << "\nMatrix (a - b) is:\n" << endl;
    show_matrix_array(sub, n);

    cout << line.m;
	
	cout << "\nMatrix (a*b) is:\n" << endl;
    show_matrix_array(multi, n);
    
    cout << line.m;

    delete[] arraya;
    delete[] arrayb;
    delete[] add;
    delete[] sub;
    delete[] multi; 


	return 0;
}
