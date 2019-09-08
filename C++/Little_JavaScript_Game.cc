#include<iostream>
using namespace std;
int main(){
	
	int arr_height[2] = {};
	int arr_age[2] = {};
	int height, age, score1, score2;
	
	
	for(int i = 0; i < 2; i++){
		if(i == 0){
			cout << "Your height in centimeters: ";
			cin  >> height;
			arr_height[i] = height;
			cout << "Your age: ";
			cin  >> age;
			arr_age[i] =  age;
			score1 = arr_height[i] + (5 * age);
		}
		
		else if(i == 1){
			cout << "Your Friend's height in centimeters: ";
			cin  >> height;
			arr_height[i] = height;
			cout << "Your Friend's age: ";
			cin  >> age;
			arr_age[i] =  age;
			score2 = arr_height[i] + (5 * age);
		}
		
	}
	if(score1 > score2) cout << "You Win!!!";
	else if(score1 < score2) cout << "Your Friend Wins!!!";
	else cout << "TIE!!!";
	
	
	
	
	
	
	return 0;
}
