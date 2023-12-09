//NOTE: PLEASE CREATE A *reg.txt* FILE BEFORE YOU RUN THIS PROGRAM
//THE *reg.txt* WILL WORK AS OUR DATABASE TO SAVE USER'S DATA
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//login function
void login(){
	string Username,Password;
	string UseEnter,PassEnter;
	bool on_off = true;
	bool off = true;
	int countt = 0;
	int left = 5;
	
	cout<<"\n***Login to your account***\n";
	while(on_off){
		//*******************************
		fstream user;
		user.open("reg.txt", ios::in);
		if(countt < 5 && off && user.is_open()){
			if(countt > 0){
				cout<<"\n** Password or Username are not Correct!!**" <<endl;
				left--;
				cout <<"You have *" <<left <<"* attempts left \n" <<endl;
			}
			cout <<"Enter Username: ";
			getline(cin,UseEnter);
			cout <<"Enter Password: ";
			getline(cin,PassEnter);
			countt++;
			string read;
			//=====================================
			while(getline(user,read)){
				stringstream convertor(read);
				convertor >> Username >> Password;
				if(UseEnter == Username && PassEnter == Password){
					off = false;}}
			//======================================
				}
				else if(!off){
					cout<<"\n***Welcome***\n\n";
					user.close();
					on_off = false;
				}
			}
		}
		
// registry function
void registry(){
	string newName,checkName,newPass,confirmPass;
	int MiniPass;
	bool if_On = true;
	bool oo = true;
	
	cout<<"\n *** Create New Account *** \n";
	
	//user validation
	
	while(oo){
		cout<<"Enter New Username: ";
		getline(cin,newName);
		MiniPass = newName.length();
		fstream yusers;
		yusers.open("reg.txt",ios::in);
		if(if_On && MiniPass >= 1 && yusers.is_open()){
			string readd;
			while(getline(yusers,readd)){
				stringstream OnlyUsers(readd);
				OnlyUsers >> checkName;
				if(newName==checkName){
					cout<<"\n***Username already Exists. Try another one***\n" <<endl;
					if_On = false;
				}
			}
			yusers.close();
			if(!if_On){
				if_On = true;
			}
			else{
				oo = false;
			}
		}
	}
//Password validation
while(true){
	cout<<"Enter New Password: ";
	getline(cin,newPass);
	cout <<"Confirm Password: ";
	getline(cin,confirmPass);
	MiniPass = newPass.length();
	
	if(MiniPass < 5){
		cout<<"\nYour Password is weak at least 5 letters\n \n";
	}
	else if(confirmPass == newPass){
		fstream users;
	 	users.open("reg.txt",ios::app);
		if(users.is_open()){
			users <<newName +" "+ newPass <<endl;
			users.close();
		}
		cout <<"\n========================================\n";
		cout <<"\nAccount Created Successfully! \n \n";
		cout <<"\n=========================================\n";
		break;}
		else{
			cout<<"\nPassword Confirmation not correct! \n" <<endl;
		}
}
login();
}


int main(){
//User can choose Login or Register by writing <Login> or <Register>

string LoR;
cout<<"\n*** Login or Register ***\n \n";
cout<<"\n=======================================================\n";
cout<<"\n*** Please write (Login) or (Register) ***\n \n";

while(true){
	getline(cin,LoR);
	if(LoR == "Login"){
		login();
		break;
	}
	else if(LoR == "Register"){
		registry();
		break;
	}
	else{
		cout<<"\n*** Please write (Login) or (Register) Correctly ***\n";
	}
}
return 0;
}
