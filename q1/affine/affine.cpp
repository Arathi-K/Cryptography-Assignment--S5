#include<bits/stdc++.h>
using namespace std;

string decryption(string cipher,int ainv,int b)
{
	string p = "";
	
	for (int i = 0; i < cipher.length(); i++)
			p=p+(char) (((ainv * ((cipher[i]+'A' - b)) % 26)) + 'A');
			
	return p;
}
int main(void)
{
	//p=ainv*(y-b)
	string ct;
	ifstream file;
	file.open("File2_affine_input.txt");
	getline(file,ct);
	file.close();
	int a[12]={1,3,5,7,9,11,15,17,19,21,23,25};
	int ainv[12]={1,9,21,15,3,19,7,23,11,5,17,25};
	ofstream myFile;
	myFile.open("Affine_output.txt");

	//b from 0 to 25
	for(int i=0;i<12;i++){
	    for(int b=0;b<=25;b++){
	       cout<<"key is ("<<a[i]<<","<<b<<")"<<endl;
	        cout <<decryption(ct,ainv[i],b)<<endl<<endl;
			myFile<<"key is ("<<a[i]<<","<<b<<")"<<endl;
			myFile<<decryption(ct,ainv[i],b)<<endl<<endl;
	    }
	}
	
	
	return 0;
}

