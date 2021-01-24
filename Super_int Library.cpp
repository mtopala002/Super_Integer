
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string cz(string s){
    if(s.length()>1){
         while(s[0]=='0'){
          
                s.erase(s.begin());
            
        }
    }
    return s;
}
string absol(string a){
    if(a.size()==0){
        return "";
    }
    if(a[0]=='-'){
        a.erase(a.begin());
    }
    return a;
}
bool isbigger(string a, string b){
   
	if (a.length()>b.length()){
		return true;
	}
	else if (a.length()<b.length()){
		return false;
	}
	else{
		for (int i = 0; i<a.length(); i++){
			if (a[i]>b[i]){
				return true;
			}
			else if (a[i]<b[i]){
				return false;
			}
		}
	}
}

bool isequal(string a, string b){
	if (a.length() != b.length()){
		return false;
	}
	else{
		for (int i = 0; i< a.length(); i++){
			if (a[i] != b[i]){
				return false;
			}
		}
	}

	return true;
}

string add(string a, string b){
	string sum = "";
	string c;
	//if a has more elements, switch
	if (b.length()<a.length()){
		c = a;
		a = b;
		b = c;

	}

	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--){
		if ((a[i] - '0') + (b[i + b.length() - a.length()] - '0') + carry >9){

			sum.insert(0, to_string((a[i] - '0') + (b[i + b.length() - a.length()] - '0') - 10 + carry));
			carry = 1;
		}
		else{
			sum.insert(0, to_string((a[i] - '0') + (b[i + b.length() - a.length()] - '0') + carry));

			carry = 0;
		}
	}

	if (a.length() == b.length()){
		if (carry != 0){
			sum.insert(0, to_string(1));
		}
	}
	for (int i = b.length() - a.length() - 1; i >= 0; i--){
		if (i == b.length() - a.length() - 1){

			sum.insert(0, to_string((b[i] - '0') + carry));
		}
		else{
			sum.insert(0, to_string(b[i] - '0'));
		}
	}

	return sum;
}

string product(string a, string b){
	string prdct = "";
	string prdct_now = "";
	string c;
	//if a has more elements, switch
	if (b.length()<a.length()){
		c = a;
		a = b;
		b = c;

	}

	int carry = 0;

	for (int i = a.length() - 1; i >= 0; i--){
		prdct_now = "";
		carry = 0;
		for (int j = b.length() - 1; j >= 0; j--){

			int n = (a[i] - '0') * (b[j] - '0');
			if (n + carry >9){


				prdct_now.insert(0, to_string((n + carry) % 10));
				carry = ((n + carry) - (n + carry) % 10) / 10;
			}



			else{
				prdct_now.insert(0, to_string(n + carry));
				carry = 0;
			}
		}
		if (carry != 0){
			prdct_now.insert(0, to_string(carry));
		}


		for (int k = 0; k<a.length() - 1 - i; k++){
			prdct_now.insert(prdct_now.length(), to_string(0));
		}

		prdct = add(prdct, prdct_now);


	}

	return prdct;
}

string subtract(string a, string b){
	bool loan = false;
	string c = "";
	string diff = "";

	if (isbigger(a, b)){
		c = a;
		a = b;
		b = c;

	}

	for (int i = a.length() - 1; i >= 0; i--){


		if (loan == true){
			if (b[i + b.length() - a.length()] == '0' && a[i] != '0'){
				diff.insert(0, to_string(9 - (a[i] - '0')));
			}
			else{
				b[i + b.length() - a.length()]--;

				loan = false;

				if ((b[i + b.length() - a.length()] - '0') >= (a[i] - '0')){

					diff.insert(0, to_string((b[i + b.length() - a.length()] - '0') - (a[i] - '0')));
				}

				else{
					diff.insert(0, to_string((b[i + b.length() - a.length()] - '0') - (a[i] - '0') + 10));
					loan = true;
				}
			}

		}





		else{
			if ((b[i + b.length() - a.length()] - '0') == 0 && a[i] != '0'){
				diff.insert(0, to_string(10 - (a[i] - '0')));
				loan = true;
			}
			else if ((b[i + b.length() - a.length()] - '0') >= (a[i] - '0')){


				diff.insert(0, to_string((b[i + b.length() - a.length()] - '0') - (a[i] - '0')));

			}

			else{
				diff.insert(0, to_string((b[i + b.length() - a.length()] - '0') - (a[i] - '0') + 10));
				loan = true;
			}

		}
	}
	if (b.length() != a.length()){
		for (int i = b.length() - a.length() - 1; i >= 0; i--){
			if (loan == true){

				if (b[i] == '0'){
					diff.insert(0, to_string(9));
				}
				else{
					b[i]--;

					loan = false;


					diff.insert(0, to_string((b[i] - '0')));
				}
			}
			else{
				diff.insert(0, to_string((b[i] - '0')));
			}

		}
	}


	
	
	 while(diff.length()>1 ){
       if(diff[0]=='0'){
           diff.erase(diff.begin() );
       }
       else{
           break;
       }
	 }
	
	
	return diff;

}

string divide(string b, string a){

	string quotient = "";
	long long int down = b.length();
	
	

	if (isbigger(a, b)){
		return "0";
	}


	string s = "";
	int i = 0;
while(down>0){
    
    s = cz(s);
	s.insert(s.length(), to_string(b[i] - '0'));
	 s = cz(s);
	down--;
	i++;
	

	while (isbigger(a, s)){
		if (i != b.length()){
		    
			s.insert(s.length(), to_string(b[i] - '0'));
			 s = cz(s);
			down--;
			quotient.insert(quotient.length(),"0");

			i++;

		}
		else if (i == b.length()){
		    quotient.insert(quotient.length(),"0");
			return cz(quotient);
		}


	}


	
  






	string x;
	for (int j = 0; j<10; j++){
		x = product(a, to_string(j));

		if ((isbigger(s, x) || isequal(x, s)) && isbigger(product(a, to_string(j + 1)), s)){

			quotient.insert(quotient.length(), to_string(j));
            



			s = subtract(s, product(a, to_string(j)));
			s = cz(s);

			break;
		}

	}

   


	

	
    
    
    
    
}

        
		return  cz(quotient);
	
	

}

string mod(string a, string b){
    return subtract(b,product(a,divide(b,a)));
}

string power(string a, string e){
    string power=a;
    while(isbigger(subtract(e,"0"),"1")){
       power = product(a,power);
        e = subtract(e,"1");
    }
    return power;
}

int main(){
    string b = "1476512132186451651654654564891131238987561589476";
   string a = "12453216845186456156489456153131310";
 
    

	cout <<divide(b,a);

	return 0;
}





