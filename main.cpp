#include <iostream>
#include "Alfabeto.cpp"

using namespace std;

int main(){
    int op, recebe, tamanho = 0, verifica, op2;
    string alfabeto, inseriAlfa, alfaUnir;
    char *alfa;

    Alfabeto *alfabet = new Alfabeto();
    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t PRINCIPAL MENU" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 -- INSERIR ALFABETO" << endl;
        cout << " 2 -- UNIAO DOS ALFABETOS" << endl;
        cout << " 3 -- PREFIXOS, SUFIXOS E SUBPALAVRAS " << endl;
        cout << " 4 -- LISTAR ALFABETOS" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> op;
        cout << "---------------------------------------------" << endl << endl;

        switch(op){
            case 1:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t INSERCAO DE ALFABETOS" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "INFORME UM ALFABETO: ";
                cin >> alfabeto;
                tamanho = alfabeto.length();

                if(alfabeto[0] != '{' || alfabeto[tamanho-1] != '}'){
                    cout << endl << "\t ALFABETO INFORMADO NAO ACEITO." << endl;
                    cout << "POR FAVOR, INFORME UM VALIDO DE ACORDO COM A TEORIA DE CONJUNTOS." << endl;
                }
                else{
                    alfabet->verifAlfabeto(alfabeto, tamanho);
                    alfabet->verifAlfabetoRepetido(alfabeto, tamanho);
                }
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t UNIAO DOS ALFABETOS" << endl;
                cout << "---------------------------------------------" << endl;
                alfabet->unirAlfabeto(alfabeto);
                break;
            case 3:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t PREFIXOS, SUFIXOS E SUBPALAVRAS" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "INFORME UM ALFABETO: ";
                cin >> inseriAlfa;
                do{
                    cout << endl << "   ---------------------------------------------" << endl;
                    cout << " \t   MENU SECUNDÁRIO" << endl;
                    cout << "   ---------------------------------------------" << endl;
                    cout << "   1 -- VERIFICAR SE PERTENCE AO ALFABETO" << endl;
                    cout << "   2 -- VISUALIZAR PREFIXOS" << endl;
                    cout << "   3 -- VISUALIZAR SUFIXOS" << endl;
                    cout << "   4 -- VISUALIZAR SUBPALAVRAS" << endl;
                    cout << "   0 -- VALTAR PARA O MENU PRINCIPAL" << endl;
                    cout << "   ---------------------------------------------" << endl;
                    cout << "   OPCAO: ";
                    cin >> op2;

                    switch(op2){
                        case 1:
                            cout << endl << "   ---------------------------------------------" << endl;
                            cout << "\t   VERIFICAÇÃO" << endl;
                            cout << "   ---------------------------------------------" << endl;
                            alfabet->verificaPercAlfa(alfabeto, inseriAlfa);
                            cout << endl << "   ---------------------------------------------" << endl << endl;
                            break;
                        case 2:
                            cout << endl << "---------------------------------------------" << endl;
                            cout << "\t PREFIXOS" << endl;
                            cout << "---------------------------------------------" << endl;
                            break;
                        case 3:
                            cout << endl << "---------------------------------------------" << endl;
                            cout << "\t SUFIXOS" << endl;
                            cout << "---------------------------------------------" << endl;
                            break;
                        case 4:
                            cout << endl << "---------------------------------------------" << endl;
                            cout << "\t SUBPALAVRAS" << endl;
                            cout << "---------------------------------------------" << endl;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\tOPÇÃO INVÁLIDA, INFORME UMA VÁLIDA" << endl;
                    }
                }while(op2 != 0);

                break;
            case 4:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t LISTA DE TODOS OS ALFABETOS" << endl;
                cout << "---------------------------------------------" << endl;
                alfabet->imprimeAlfabetos();
                break;
            case 0:
                cout << "PROGRAMA ENCERRADO COM SUCESSO!" << endl;
                break;
            default:
                cout << "\tOPÇÃO INVÁLIDA. POR FAVOR, INFORME UMA VÁLIDA" << endl;
        };

    }while(op != 0);
    return 0;
}
