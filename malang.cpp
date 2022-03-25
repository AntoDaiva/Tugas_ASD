#include<iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

string get_kalimat(){
    string str;
    cout << "input kalimat: ";
    getline(cin, str);
    return str;
}

string konversi_malang(string kalimat){
    string word, out;
    stack<char> swap;
    queue<string> final;
    for(int i=0; i<kalimat.size(); i++){
        word = "";
        while(kalimat[i] != ' '){//memasukkan char ke stack(agar terbalik)
            if(i==kalimat.size())
                break;
            swap.push(kalimat[i]);
            if(kalimat[i]=='g'){//agar "ng" tetap "ng"
                if(kalimat[i-1]=='n'){
                    swap.pop();swap.pop();
                    swap.push('g');swap.push('n');
                }
            }
            i++;
        }
        while(!swap.empty()){//membuat kata yang dibalik
            word += swap.top();
            swap.pop();
        }
        final.push(word);//masukkin kata yg sudah dibalik k
    }
    while(!final.empty()){//output
        out += final.front() + " ";
        final.pop();
    }
    return out;
}

int main(){
    cout << "program ini mengconvert menjadi slang malang\n\n";

    string kalimat1, kalimat2 = "arek malang";
    kalimat1 = get_kalimat();
    cout << konversi_malang(kalimat1)<< endl;
    cout << konversi_malang(kalimat2);

}