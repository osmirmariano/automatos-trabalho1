#include <iostream>
#include "Alfabeto.cpp"

using namespace std;

int main(){
    int op, recebe, tamanho = 0, verifica;
    string alfabeto;
    char *alfa;

    Alfabeto *alfabet = new Alfabeto();
    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t MENU DE OPCOES" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 -- INSERIR ALFABETO" << endl;
        cout << " 2 -- UNIR ALFABETOS" << endl;
        cout << " 3 -- PREFIXOS " << endl;
        cout << " 4 -- SUFIXOS" << endl;
        cout << " 5 -- SUBPALAVRAS" << endl;
        cout << " 6 -- LISTAR ALFABETOS" << endl;
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
                    alfabet->verifAlfabetoRepetido(alfabeto);
                }
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t UNIÃO DOS ALFABETOS" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 3:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t PREFIXOS" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 4:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t SUFIXOS" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 5:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t SUBPALAVRAS" << endl;
                cout << "---------------------------------------------" << endl;
                break;
            case 6:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t LISTA DE TODOS OS ALFABETOS" << endl;
                cout << "---------------------------------------------" << endl;
                alfabet->imprimeAlfabetos();
                break;
            case 0:
                cout << "PROGRAMA ENCERRADO COM SUCESSO!" << endl;
                break;
            default:
                cout << "OPÇÃO INVÁLIDA. POR FAVOR, INFORME UMA VÁLIDA" << endl;
        };

    }while(op != 0);
    return 0;
}
