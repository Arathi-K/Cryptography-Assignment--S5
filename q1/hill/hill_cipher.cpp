#include<bits/stdc++.h>
using namespace std;

int modInverse(int a, int m){ 
    a=a%m; 
    for(int x=-m;x<m;x++) 
       if((a*x)%m==1) 
          return x; 
    return 0;
} 
void getCofactor(vector<vector<int> > &a, vector<vector<int> > &temp, int p, int q, int n){ 
    int i=0,j=0; 
    for(int row=0;row<n;row++){ 
        for(int col=0;col<n;col++){ 
            if(row!=p&&col!=q){ 
                temp[i][j++] = a[row][col]; 
                if (j==n-1){ 
                    j=0; 
                    i++; 
                } 
            } 
        } 
    } 
}
int determinant(vector<vector<int> > &a, int n, int N){ 
    int D = 0;
    if(n==1) 
        return a[0][0]; 
    vector<vector<int> > temp(N, vector<int>(N));
    int sign = 1;
    for(int f=0;f<n;f++){ 
        getCofactor(a, temp, 0, f, n); 
        D += sign * a[0][f] * determinant(temp, n - 1, N); 
        sign = -sign; 
    }
    return D; 
} 
void adjoint(vector<vector<int> > &a,vector<vector<int> > &adj,int N){ 
    if(N == 1){ 
        adj[0][0] = 1; 
        return; 
    } 
    int sign = 1;
    vector<vector<int> > temp(N, vector<int>(N));
    for(int i=0;i<N;i++){ 
        for(int j=0;j<N;j++){ 
            getCofactor(a, temp, i, j, N); 
            sign = ((i+j)%2==0)? 1: -1; 
            adj[j][i] = (sign)*(determinant(temp, N-1 , N)); 
        } 
    } 
} 
bool inverse(vector<vector<int> > &a, vector<vector<int> > &inv, int N){ 
    int det = determinant(a, N, N); 
    if(det == 0){ 
        // cout << "Inverse does not exist"; 
        return false; 
    } 
    int invDet = modInverse(det,26);
    // cout<<det%26<<' '<<invDet<<'\n';
    vector<vector<int> > adj(N, vector<int>(N));
    adjoint(a, adj, N);  
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) 
            inv[i][j] = (adj[i][j]*invDet)%26; 
    return true; 
} 
int main(){

    vector<vector<int> > key(4, vector<int>(4));
    key={{2,14,13,13},{4,2,19,4},{3,6,17,0},{15,7,8,2}};

    vector<vector<int> > k_inv(4, vector<int>(4));
    inverse(key,k_inv,4);
// for(int i=0;i<4;i++){
//     for(int j=0;j<4;j++)
//         cout<<k_inv[i][j]<<" ";
//     cout<<endl;}
    string cipher;
    // cin>>s;
    ifstream file;
    file.open("File1_hill_input.txt");
    getline(file,cipher);
    file.close();
    int k=0;
    string ans;
    while(k<cipher.size()){
        for(int i=0;i<4;i++){
            int sum = 0;
            int temp = k;
            for(int j=0;j<4;j++){
                sum += ((k_inv[i][j] + 26)%26*(cipher[temp++]-'A')%26)%26;
                sum = sum%26;
            }
            ans+=(sum+'A');
        }
        k+=4;
    }
    //ans+='\0';
    int f=ans.size()-1;
    while(ans[f]=='X'){
        f--;
    }
    ofstream Myfile;
    Myfile.open("Hill_cipher_output.txt");
    string s_ans;
    for(int i=0;i<=f;i++){
        cout<<ans[i];
        s_ans.push_back(ans[i]);
    }
    Myfile<<s_ans;
    cout<<'\n';
    return 0;    
}
