#include <iostream>
#include <string>
#include <fstream>


using namespace std ;

string Mettre_Min(string phrase){
	string copy_phrase ="" ;
	int ASCII=0 ;
	for (int i=0 ; i < phrase.length() ; i++){
		if ( 65 <= int(phrase[i]) &  int(phrase[i]) <= 90){
			ASCII= int(phrase[i]) + 32 ;
			copy_phrase += char(ASCII) ;
		}
		else if (97 <= int(phrase[i]) & int(phrase[i]) <= 122 ){
			ASCII = int(phrase[i]);
			copy_phrase += char(ASCII);
		}
		if (int(phrase[i])==32){
			ASCII= int(phrase[i]);
			copy_phrase += char(ASCII);
		}
		}
	
	return copy_phrase ; 
	}

string LireFichier(string nomfichier){
	ifstream fichier(nomfichier.c_str()) ;
	string ligne ;
	string texte="" ;
	if (fichier){
		while (getline(fichier , ligne )) {
			texte += ligne ;
		}
		fichier.close() ;
	}
	return texte ;
}
	

int main(){
	string nomfichier ;
	string texte ;
	cout << "Entrer le nom du fichier :" ;
	cin >> nomfichier ;
	texte = LireFichier(nomfichier) ;
	texte = Mettre_Min(texte) ;
	int j =97 ;
    int compteur[26][2] ;
    for (int i=0 ; i < 26 ; i++){
        compteur[i][0]=j ;
        j++ ;
    }
    for (int i=0 ; i < 26 ; i++){
    	compteur[i][1] = 0 ;
	}

	for (int i=0 ; i < texte.length() ; i++){
		for (int j=0 ; j < 26 ; j++){
			if ( int(texte[i]) == compteur[j][0] ){
				compteur[j][1] += 1 ;
			}
		}
	}
	cout << "Le nombre de chaque lettre est :" << endl ;
	for (int i=0 ; i < 26 ; i++){
		cout << char(compteur[i][0]) << "  :  " << compteur[i][1] << endl ;
	}
	return 0 ;	
}




