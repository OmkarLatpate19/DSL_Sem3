/*In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
Write C++ program using stack to check whether given expression is well parenthesized or not.*/

#include<iostream>
using namespace std;
#define size 5

class Stack{
	public:
		int top=-1;
		char exp[size];

		bool isEmpty(){
			return (top==-1) ? true : false ;
		}

		bool isFull(){
			return (top==size-1) ? true : false ;
		}

		int pushExp(char x){
			if(isFull()==true){
				cout<<"Stack Overflow"<<endl;
			}
			else{
				top++;
				exp[top]=x;
			}
		}

		int popExp(){
			char s;
			if(isEmpty()==true){
				cout<<"Stack Underflow"<<endl;
			}
			else{
				s=exp[top];
				top--;
				return s;	
			}
		}
};

int main(){
		Stack st;
		char exp[size],ch; 
		int i=0, flag=0;
		cout<<"Enter expression to check if well paranthesized or not : ";
		cin>>exp;
		if(exp[0]==')' || exp[0]=='}' || exp[0]==']'){
			cout<<"You have entered a wrong expression!!!"<<endl;
			return 0;
		}
		else{
			while(exp[i]!='\0'){
				if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
					st.pushExp(exp[i]);
				}
				else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
					ch=st.popExp();
					if((exp[i]==')' && ch!='(') || (exp[i]=='}' && ch!='{') || (exp[i]==']' && ch!='[')){
						flag=1;
						break;
					}
				}
				i++;	
			}
			
		}
		if(st.isEmpty() and flag==0){
			cout<<"The expression is well paranthesized !!!"<<endl;
		}
		else{	
			cout<<"Expression entered is not well paranthesized !!!"<<endl;
		}
		return 0;
}