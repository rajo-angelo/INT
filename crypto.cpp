#include<iostream>
#include<vector>
using namespace std;
string cryptee(string message,vector<char>);
string decryptee(string message,vector<char>);

int main()
{
    vector<char> DICO {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','X','Y','Z'};
    string mot,motCryptee,motDecryptee;
    cout<<"Entrez un mot :";
    cin>>mot;         
    motCryptee = cryptee(mot,DICO);
    motDecryptee = decryptee(motCryptee,DICO);
    cout<<"\n\n==========RESULTAT==============\n\n";
    cout<<"Originale : "<<mot<<endl;
    cout<<"Cryptee : "<<motCryptee<<endl;
    cout<<"deCryptee : "<<motDecryptee<<endl;
}

string cryptee(string message,vector<char> DICO)
{
    string resultat;
    for (auto &&c : message)
    {
        for (int i=0;i<DICO.size();i++)
        {
            if (c==DICO[i])
            {
                int index = (i+3)%25;
                resultat += DICO[index];
                break;
            }           
        }       
    }
    return resultat;
}

string decryptee(string message,vector<char> DICO)
{
    string resultat;
    for (auto &&c : message)
    {
        for (int i=0;i<DICO.size();i++)
        {
            if (c==DICO[i])
            {
                int index = (i-3)%25;
                resultat += DICO[index];
                break;
            }           
        }       
    }
    return resultat;
}