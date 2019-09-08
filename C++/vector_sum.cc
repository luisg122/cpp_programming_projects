//using heap memory

#include<iostream>
using namespace std;
void vsum(int *v1, int *v2,int *v3, int n){	//passing by pointers
	
		
	
	for(int i = 0; i < n; i++){
		
		v3[i] = v1[i] + v2[i];
		
	}

}

void print(int *v3, int n){				//passing by array is the same as passing by pointer
										//the array gets converted to a pointer 
	
	
		cout << "< ";
	for(int i = 0; i < n; i++){
		
		cout << v3[i] << " " ;
	}
		cout << ">";
}



int main(){
	
	/*int *p = new int[4]{1,2,3,4};
	int *q = new int;
	delete[] p;
	delete q;
	*/
	
	int v1[3] = {1,2,3}, v2[3] = {4,5,6}, v3[3];
	//int *v3 = vsum(v1,v2,3);
	
	vsum (v1,v2,v3,3);
	print(v3, 3);
	
	//delete[] v3;
	return 0;
}

//Why is that sometimes it is appropriate to PASS b pointers, and
//other time it is appropriate to PASS by references
