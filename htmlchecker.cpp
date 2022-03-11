#include<iostream>
#include<stack>
#include<string>
#include<fstream>

using namespace std;

string stringify(string filename){
    fstream thefile;//setup untuk membaca file html nya
    thefile.open(filename, ios::in);
    char ch;
    string doc;

    while (true){//membaca file lalu menjadikannya satu string
        thefile >> ch;
        if (thefile.eof())
            break;
        doc += ch;
    }
    thefile.close();
    return doc;
}

bool htmlcheck(string filename){
    string doc = stringify(filename);
    
    string tag_name = "";
    stack<string> tag_names;
    stack<string> tags;
    bool valid = true;//untuk exit loop utama
    bool kosong = true;//jika tidak ada tag sama sekali
    for(int i=0; i<doc.length(); i++){
        if(doc[i]=='<'){
            
            i++;
            if (doc[i]== '/'){//bila closing tag
                i++;
                while(true){
                    if (doc[i] == '>' && tag_name==tag_names.top()){//jika sesuai dengan stack
                        tag_names.pop();
                        tags.pop();
                        tag_name = "";
                        break;}
                    if (doc[i] == '>'){//jika tidak sesuai tag di stack teratas
                        valid = false;
                        break;}
                    if (doc[i] == '<'){//jika langsung ada '<' lagi
                        valid = false;
                        break;}
                    tag_name += doc[i];//collect tag name
                    i++;
                    if (i==doc.length())//jika file sudah terbaca semua namun tidak ada penutup tag '>'
                        return false;
                }
            }
            else{
                tags.push("<");//bila opening tag
                while(true){
                    if (doc[i] == '>'){
                        tag_names.push(tag_name);
                        tag_name = "";
                        kosong = false;
                        break;}
                    if (doc[i] == '<'){//jika langsung ada '<' lagi
                        valid = false;
                        break;}
                    tag_name += doc[i];//collect tag name
                    i++;
                    if (i==doc.length())//jika file sudah terbaca semua namun tidak ada penutup tag '>'
                        return false;
                } 
            }
        }
    }
    
    if (tags.empty() && valid && !kosong)
        return true;
    else
        return false;
}

int main(){
    string file = "html.html";
    bool validity = htmlcheck(file);

    if(validity)
        cout << "valid";
    else 
        cout << "invalid";

    return 0;
}