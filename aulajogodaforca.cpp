#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;



string cadastropalavras(){

    //função para cadastrar as palavras a serem sorteadas no programa

    string palavras[6] = {"celular", "computador", "tela", "cereveja", "nariz", "boca"};

  
    int indiceAleatorio = rand() % 6;


    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    int cont = 0;
    string palavraComMascara;

    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

    cout << "\nPalavra:" << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;

    int cont;
    cout << "\nLetras arriscadas:";
    for(cont = 0; cont < letrasJaArriscadas.size();cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }

}

int jogar(int numeroDeJogadores){

    
    string palavra;

    
    if(numeroDeJogadores == 1){

    
        palavra = cadastropalavras();

    }else{

        cout << "\nDigite uma palavra:";
        cin >> palavra;
        system("cls");
    }

 
    int tamanhoDaPalavra = palavra.size();

 
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);


    int tentativas = 0, maximoDeTentativas = 10;            
    int cont = 0;                                           
    char letra;                                            
    int opcao;                                              
    string letrasJaArriscadas;                             
    string mensagem = "Bem vindo ao jogo!";                 
    string palavraArriscada;                                
    bool jaDigitouLetra = false, acertouLetra = false;     


    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){

        

      
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas,mensagem);

        
        cout << "\nDigite uma letra (Ou digite 1 para arriscar a palavra):";
        cin >> letra;

        
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                 palavraComMascara = palavraArriscada;
            }else{
                 tentativas = maximoDeTentativas;
            }
        }

        
        for(cont = 0; cont < tentativas; cont++){

           
            if(letrasJaArriscadas[cont] == letra){

                mensagem = "Essa letra ja foi digitada!";

                
                jaDigitouLetra = true;

            }
        }

       
        if(jaDigitouLetra == false){

           
            letrasJaArriscadas += tolower(letra);

            
            for(cont = 0; cont < tamanhoDaPalavra; cont++){

                
                if(palavra[cont] == tolower(letra)){

                   
                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;

                }
            }

            if(acertouLetra == false){

                mensagem = "Voce errou uma letra!";

            }else{

                mensagem = "Voce acertou uma letra!";

            }

       
            tentativas++;

        }

       
        jaDigitouLetra = false;
        acertouLetra = false;

    }

    if(palavra == palavraComMascara){

        ;
        cout << "Parabens, voce venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;

    }else{

        ;
        cout << "Voce perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
    }

}

void Menu(){

    
    int opcao = 0;

   
    while(opcao < 1 || opcao > 3){
        ;
        cout << "Jogo da forca!";
        cout << "\n1 - Jogar Sozinho";
        cout << "\n2 - Jogar em Dupla";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";

        
        cin >> opcao;

        
        switch(opcao){
            case 1:
              
                if(jogar(1) == 1){
                    Menu();
                }
                break;
            case 2:
               
                if(jogar(2) == 1){
                    Menu();
                }
                break;

                break;
            case 3:
                cout << "Saindo...";
                break;
        }
    }

}

int main(){

 
    srand( (unsigned)time(NULL));

    Menu();

    return 0;
}
