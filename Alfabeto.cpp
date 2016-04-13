#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

class Alfabeto{
	public:
		int cont, repete, encontra, flag, recebe;

		Alfabeto(){
			cont = 0;
			repete = 0;
			encontra = 0;
			flag = 1;
		};

		~Alfabeto();

		void verifAlfabeto(string alfabeto, int tamanho){
			char *alfa = new char [tamanho];
			
			for(int x = 0; x < tamanho; x++){
			    if(alfabeto[x] != '{' || alfabeto[x] != '}' || alfabeto[x] != ',' || alfabeto[x] != ' '){
			        if (isalnum (alfabeto[x])) {
			            alfa[cont] = alfabeto[x]; 
			            cont++; //Quantidade de elementos válidos alfanuméricos
			        }
			    }
			}

			//Verificar elementos repetidos
			for(int x = 0; x < cont; x++){
			    for(int y = x+1; y < cont; y++){
				   	if(alfa[x] == alfa[y]){
				   		recebe = 1;
				   	}
				   	else
				   		recebe = 0;
				}
			}


			if(recebe == 1){
				cout << endl << "\t ALFABETO INVÁLIDO." << endl;
                cout << "NÃO É PERMITIDO ALFABETO COM REPETIÇÕES." << endl;
			}
			else{
				cout << "ALFABETO INFORMADO: ";
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
		};

			/*for(int x = 0; x < tamanho; x++){
		        if(alfabeto[x] != '{' || alfabeto[x] != '}' || alfabeto[x] != ',' || alfabeto[x] != ' '){
		            if (isalnum (alfabeto[x])) {
		                alfa[cont] = alfabeto[x]; 
		                cont++; //Quantidade de elementos válidos alfanuméricos
		            }
		        }
		    }
		    cout << "QUANTIDADE E ALFANÚMERICOS VÁLIDOS: " << cont << endl;
		    cout << "ALFABETO INFORMADO:";
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
            recebe = alfa;

		};

		int verifRepetido(string alfabeto, int tamanho, char *recebe){
			for(int x = 0; x < cont; x++){
			    for(int y = x+1; y < cont; y++){
				   	if(recebe[x] == recebe[y]){ 
				    	return 0;
				    }
				    else
				    	return 1;
				}
			}
		};*/
		
};
