#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

class Alfabeto{
	public:
		int cont, flag, recebe;
		char *alfa;

		Alfabeto(){
			cont = 0;/*
			recebe = 0;*/
			flag = 1;
			alfa = this->alfa;
		};

		~Alfabeto();


		void verifAlfabeto(string alfabeto, int tamanho){
			alfa = (char*) malloc(tamanho*sizeof(char));
			/*alfa = new char [tamanho];*/
			for(int x = 0; x < tamanho; x++){
			    if(alfabeto[x] != '{' || alfabeto[x] != '}' || alfabeto[x] != ',' || alfabeto[x] != ' '){
			        if (isalnum (alfabeto[x])){
			            alfa[cont] = alfabeto[x]; 
			            cont++; //Quantidade de elementos válidos alfanuméricos
			        }
			    }
			}			
		};

		void mostarAlfabeto (string alfabeto){
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
				alfabeto = "{";
				for(int x = 0; x < cont; x++){ 
		            alfabeto = alfabeto + alfa[x];
		            if(flag != cont) {
		                alfabeto = alfabeto + ",";
	                    flag++;
	                }
				}
	            alfabeto = alfabeto + "}";
		        cout << "" << alfabeto << endl;
			}
			recebe = 0;
		};
					
};
