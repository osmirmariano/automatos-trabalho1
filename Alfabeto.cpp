#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <vector>

using namespace std;


class Alfabeto{
	public:
		int cont, flag, recebe, contando;
		vector<string> alfabetos;
        vector<char> alfa;

    public:
		Alfabeto(){
			cont = 0;
			flag = 1;
			alfa = this->alfa;
			contando=0;
		};

		~Alfabeto();

		/*---------------------------FUNÇÃO VERIFICA ALFABETO------------------------------*/
		void verifAlfabeto(string alfabeto, int tamanho){ //pega cada elemento da string alfabeto e coloca em um vetor
			for(int x = 0; x < tamanho; x++){
			    if(alfabeto[x] != '{' || alfabeto[x] != '}' || alfabeto[x] != ',' || alfabeto[x] != ' '){
			        if (isalnum (alfabeto[x])){
			            alfa.push_back(alfabeto[x]);
			            cont++; //Quantidade de elementos válidos alfanuméricos
			        }
			    }
			}
		};

		/*-----------------------------FUNÇÃO GUARDA ALFABETO------------------------------*/
		void guardaAlfabeto(string alfabeto){
            alfabetos.push_back(alfabeto);
            contando++;
		};

		/*----------------------FUNÇÃO VERIFICA ALFABETO REPETIDOS-------------------------*/
		void verifAlfabetoRepetido (string alfabeto){ // verifica repetições de elementos no alfabeto
			for(int x = 0; x < cont; x++){
			    for(int y = x+1; y < cont; y++){
				   	if(alfa[x] == alfa[y]){
				   		recebe = 1;
				   		break;
				   	}
				}
			}
			if(recebe == 1){
				cout << endl << "ALFABETO INFORMADO NÃO ACEITO!" << endl;
                cout << "NÃO É PERMITIDO ALFABETO COM REPETIÇÕES." << endl;
			}
			else{
				cout << endl << "\tALFABETO INFORMADO ACEITO - ";
		        cout << "" << alfabeto << endl;
		        guardaAlfabeto(alfabeto);
			}
			recebe = 0;
			destrutor();
            cont=0;
		};

		/*-----------------------FUNÇÃO IMPRIMIR TODOS ALFABETOS VÁLIDOS-----------------------*/
		void imprimeAlfabetos(){
			for(int x = 0; x < contando; x++){
                cout << x+1 << " -" << " " << alfabetos[x] << endl;
            }
		}

		/*---------------------------FUNÇÃO DESTRUTOR DE ALFABETO-----------------------------*/
		void destrutor(){
            alfa.clear();
		}

};