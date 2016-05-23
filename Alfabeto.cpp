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
        string unirAlfa;
        vector<char> alfaUnir;
        vector<char> inseriAlfa;

    public:
		Alfabeto(){
			cont = 0;
			flag = 1;
            contando = 0;
            alfabetos = this->alfabetos;
            alfa = this->alfa;
            unirAlfa = this->unirAlfa;
            alfaUnir = this->alfaUnir;
            inseriAlfa = this->inseriAlfa;
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
		void guardaAlfabeto(string alfabeto, int tamanho){
            alfabetos.push_back(alfabeto);
            contando++;
            for(int x = 0; x < tamanho; x++){
			    if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                    unirAlfa += alfabeto[x];
			    }
			}
        };

		/*----------------------FUNÇÃO VERIFICA ALFABETO REPETIDOS-------------------------*/
		void verifAlfabetoRepetido (string alfabeto, int tamanho){ // verifica repetições de elementos no alfabeto
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
		        guardaAlfabeto(alfabeto,tamanho);
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

		/*-------------------------------FUNÇÃO UNIR ALFABETO---------------------------------*/
        void unirAlfabeto(string alfabeto){
        	flag = 0;
            int tam = unirAlfa.length();
            int cont = 1;
            cout << "{";
            for(int x = 0; x < tam; x++){
            	for(int y = x+1; y < tam; y++){
            		if(unirAlfa[x] == unirAlfa[y]){
            			while(y <= tam){
            				unirAlfa[y] = unirAlfa[y+1];
            				y++;
            			}
            			cont++;
            		}

            	}
            	int virgula = tam-cont;
            	cout << unirAlfa[x];
            	if(flag < virgula){
            		cout << ",";
            		flag++;
            	}
            }
            cout << "}";
        }

        /*---------------------------FUNÇÃO VERIFICA ALFABETO PERTENCE -------------------------*/
        void verificaPercAlfa(string alfabeto, string inseriPalavra){
        	int pertence = 0;
        	int tam = unirAlfa.length();
        	int tam2 = inseriPalavra.length();
        	if(tam == 0)
        		cout << "   \tNÃO EXISTE NENHUM ALFABETO REGISTRADO" << endl;
        	else{
        		for(int x = 0; x < tam; x++){
	        		for(int y = 0; y < tam2; y++){
	        			if(unirAlfa[x] == inseriPalavra[y]){
	        				pertence++;
	        			}
	        		}
	        	}
	        	if(pertence > 0){
	        		cout << "\tA PALAVRA '" << inseriPalavra << "' PERTENCE AO ALFABETO ";
	        		unirAlfabeto(alfabeto);
	        	}
	        	else{
	        		cout << "\tA PALAVRA '" << inseriPalavra << "' NÃO PERTENCE AO ALFABETO ";
	        		unirAlfabeto(alfabeto);
	        	}
        	}
        };

        /*---------------------------------FUNÇÃO PREFIXO---------------------------------------*/
        void prefixo(string alfabeto, string inseriPalavra){
        	string armazena;
        	int x = 0, cont = 0;
        	int tam = inseriPalavra.length();
            cout << "   \t&" << endl;
            while(x < tam){
                armazena += inseriPalavra[x];
                cout << "   \t" << armazena << endl;
                x++;
                cont++;
            }
            cout << endl << "\tTOTAL: " << cont+1;
        }

        /*---------------------------------FUNÇÃO SUFIXO---------------------------------------*/
        void sufixo(string alfabeto, string inseriPalavra){
        	string armazena;
        	int tam = inseriPalavra.length();
        	int x = tam,cont = 0;
            cout << "   \t&" << endl;
            while(x != 0){
                if(x != tam)
                    armazena = inseriPalavra[x-1] + armazena;
                else
                    armazena += inseriPalavra[x-1];
                cout << "   \t" << armazena << endl;
                x--;
                cont++;
            }
            cout << endl << "   \tTOTAL: " << cont+1;
        }

        /*---------------------------------FUNÇÃO SUBPALAVRA-----------------------------------*/
        void subpalavra(string alfabeto, string inseriPalavra){
        	string armazena;
        	int tam = inseriPalavra.length();
        	int x = 0, flag = 0;
            cout << "   &" << endl;

            for(int x = 0; x < tam; x++){
                for(int y = x; y < tam+1; y++){
                    armazena += inseriPalavra[y];
                    cout << "   " << armazena << endl;
                    flag++;
                    if(flag == tam){
                        y = flag;
                        armazena = "";
                        flag = 0;
                    }
                }
            }
        };

};