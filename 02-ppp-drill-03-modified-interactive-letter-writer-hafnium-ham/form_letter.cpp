/**
Base code for the Chapter 3 drill from PPP. Code by Bjarne Stroustrup.

Provided for NMSU CS 371 students for drill. 
*/

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name; // first_name is a variable of type string
	cin >> first_name;
	cout << "Enter the name of a mutual friend\n";
	string friend_name;
	cin >> friend_name;
	cout << "What are the mutal friend's pronouns?\n";
	char friend_pronouns;
	cin >> friend_pronouns;
	cout << "Enter the age of the letter recipient\n";
	int age;
	cin >> age;


	//letter here 
	cout << "Dear " << first_name << ",\n";
	cout << "\tHow are you? I am fine. I miss you. We need to get together soon! "; //add more lines
	cout << "Have you seen " << friend_name << " lately? ";
	if (friend_pronouns == 'z'){
		cout << "If you see " << friend_name << " please ask zir to call me. ";
	}
	if (friend_pronouns == 't'){
		cout << "If you see " << friend_name << " please ask them to call me. ";
	}
	if (friend_pronouns == 's'){
		cout << "If you see " << friend_name << " please ask her to call me. ";
	}
	if (friend_pronouns == 'h'){
		cout << "If you see " << friend_name << " please ask him to call me. ";
	}
	if (age <= 0 || age >= 150){
		simple_error("You're kidding!\n");
	}
	else{
		cout << "I hear you just had a birthday and are " << age << " years old. ";
	}
	if (age < 12){
		cout << "Next year you will be " << age + 1 << ". ";
	}
	if (age == 17){
		cout << "Next year you will be able to vote. ";
	}
	if (age > 70){
		cout << "I hope you are enjoying retirement. ";
	}
	cout << "\n\nYours sincerely,\n\n\nBen\n";
}