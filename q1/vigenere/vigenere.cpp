
#include<bits/stdc++.h>
using namespace std;

string decryption(string d, string k)
{
	string p="";
    int l=d.size();
	for (int i = 0 ; i < l; i++)
	{
		p.push_back(((d[i] - k[i] + 26) %26)+'A');
	}
	return p;
}

int main()
{
	string ct;
	// cin>>cipher;
	ifstream file;
	file.open("File3_vigenere_input.txt");
	getline(file,ct);
	file.close();
	string keyword = "INTEGRITY";
	string key="";
	int kl=keyword.size();
	int cl=ct.size();
	int n;
	if(cl%kl==0)
	    n=cl/kl;
	else
	    n=(cl/kl)+1;
	
    for(int i=0;i<n;i++)
        key=key+keyword;
    // cout<<endl<<key;
    
	string plain=decryption(ct, key);
	ofstream myFile;
	myFile.open("Vigenere_output.txt");
	myFile<<plain<<endl;
	cout<<"Plain text is: "<<endl<<plain<<endl;
	return 0;
}

