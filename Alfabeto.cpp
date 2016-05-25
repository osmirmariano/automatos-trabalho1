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
        string unirAlfa, alfabetor;
        vector<char> alfaUnir;
        vector<char> inseriAlfa;
        vector<string> subpalavras;


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
            subpalavras = this->subpalavras;
		};

		~Alfabeto();

		/*---------------------------FUNÇÃO VERIFICA ALFABETO------------------------------*/
		void verifAlfabetoAlfanumerico(string alfabeto, int tamanho){ //pega cada elemento da string alfabeto e coloca em um vetor
			for(int x = 0; x < tamanho; x++){
			    if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                    if (isalnum (alfabeto[x])){
			            alfa.push_back(alfabeto[x]);
			            cont++;
			        }
			        else{
			            recebe = 1;
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
			}
			else{
				cout << endl << "\tALFABETO INFORMADO ACEITO - ";
		        function(alfabeto, tamanho);
		        cout << endl;
		        guardaAlfabeto(alfabeto,tamanho);
			}
			recebe = 0;
			destrutor();
            cont = 0;
		};

		/*-----------------------FUNÇÃO IMPRIMIR TODOS ALFABETOS VÁLIDOS-----------------------*/
		void imprimeAlfabetos(string alfabeto, int tamanho){
			for(int x = 0; x < contando; x++){
                cout << x+1 << " - ";
                function(alfabeto, tamanho);
                cout << endl;
            }  
		};

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
        	int x = 0, flag = 0, cont = 0, tam2 = 0;
            cout << "   &" << endl;

            for(int x = 0; x < tam; x++){
                for(int y = cont; y < tam; y++){
                    armazena += inseriPalavra[y];
                    subpalavras.push_back(armazena);
                    cout << "   " << armazena << endl;
                    flag++;
                    if(flag == tam-x){
                        //y = tam;
                        armazena = ""; //cout << "n" << flag << tam-x << endl;
                        flag = 0;
                        cont++;
                        break;
                    }
                }
            }

            tam2 = subpalavras.size();
            cout << tam2 << endl;

            for(int x = 0; x < tam2; x++){ // ELIMINAR SUBPALAVRAS REPETIDAS
                for(int y = x+1; y < tam2; y++){
                    if(subpalavras[x] == subpalavras[y]){
                        cout << subpalavras[x] << " igual " << subpalavras[y] << endl;
                        if(y+1 != tam2){
                            while(y <= tam2){
                                //cout << "   foi "<< y << tam2 << endl;
                                subpalavras[y] = subpalavras[y+1];
                                y++;
                            }
                        }
                        tam2--;
                    }

                }
            }

            cout << "\n   IMPRIMI "<< endl;
            for(int x = 0; x < tam2; x++){
                cout << "   " << subpalavras[x] << endl;
            }

            int n=0,m=0;
            string aux;
            for(int i = 0; i < tam2; i++){ //ORDENAR
                for(int j = i+1; j < tam2; j++){
                    if((n = subpalavras[i].size()) > (m = subpalavras[j].size())){
                        aux = subpalavras[i];
                        subpalavras[i] = subpalavras[j];
                        subpalavras[j] = aux;
                    }
                }
            }

            cout << "\n   ORDENADO "<< endl;
            for(int x = 0; x < tam2; x++){
                cout << "   " << subpalavras[x] << endl;
            }
        };

        //Função para mostrar bonitinho
        void function(string alfabeto, int tamanho){
        	int cont = 0;
                for(int x = 0; x < tamanho; x++){
                    if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                        if (isalnum (alfabeto[x])){
                            alfa.push_back(alfabeto[x]);
                            cont++;
                        }
                    }
                }

                alfabetos.push_back(alfabeto);
                for(int x = 0; x < tamanho; x++){
                    if(alfabeto[x] != '{' && alfabeto[x] != '}' && alfabeto[x] != ',' && alfabeto[x] != ' '){
                        alfabetor += alfabeto[x];
                    }
                }
                
                cout << "{";
                int flag = 0;
                for (int x = 0; x < cont; x++){
                    cout << alfabetor[x];
                    if(flag < cont-1){
                        cout << ",";
                        flag++;
                    }
                }
                cout << "}";	
        }
};