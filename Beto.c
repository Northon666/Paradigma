/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                             RPG versão 0.5 alpha                          *
 *                                                                           *
 *        Criado por Gabriel, Felipe, João (não sei o nome de geral)         *
 *                                Um título original 2022                    *
 *                                                                           *
 *  Programa de Código Aberto com fins de aprendizado.     			 	     *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
     
     Sobre o Projeto:
       
            Desenvolvido com intuito de aprender mais rapidamente funções e
         comandos em C. Esse programa foi feito tentando atingir os requisitos
         dos parametros requeridos da linguagem solicitado pela professora:
                *
                *
                *
            O programa VAI ser recheado de comentários com as mais diversas explicações
         e pode servir como como um guia na iniciação no aprendizado
         por apresentar apenas comandos de fácil entendimento.
		             
            Bom Proveito.            

    obs: Cada função, dependendo de sua complexidade, vem antes com um comentario
           com explicações de sua função e seu funcionamento. A leitura desses
           comentarios é extremamente recomendada a todos os usuarios, pois facilita
           o entendimento do programa.     

    obs1: Mais comentarios ao final do programa.
*/

// Bibliotecas

#include <stdio.h>  // Biblioteca Padrão de C, tem comandos basicos de entrada e saida.
#include <stdlib.h> // Usada Para Comandos System(" ");
#include <string.h> // Biblioteca que contem operações com strings.
#include <time.h>  // Biblioteca Usada para gerar numeros aleatorios.
#include <locale.h> // Biblioteca Usada para funcionar caracters como ~´ etc.

//Funçoes com ponteiro
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(); // Funçao Principal: Chama as Outras Funções.
void Principal(int *forca1, int *forca2, int *escudo1, int *escudo2, int *vida2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes); // Funçao Principal: Chama as Outras Funções.
void classe(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes); // Funçao classe: Usada para definir a classe do jogador.
void sit0(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes); // Funçao situação 0: Apresenta a situação inicial do jogo.
void sit1(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes); // Funçao situação 1: Caso o jogador bata no avô.
void sit2(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes); // Funçao situação 2: Caso o jogador siga sozinho.
void sit3(int *vida, int *vida2, int *forca1, int *escudo1, int *forca2, int *escudo2, int *classes); // Funçao situação 3: Jogador encontra com o primeiro inimigo.
void sit4(int *vida, int *vida2, int *forca1, int *escudo1, int *forca2, int *escudo2, int *classes); // Funçao situação 4: Jogador se encontra com a fada.
void combate(int *vida, int *vida2, int *forca1, int *escudo1, int *forca2, int *escudo2, int x); // Funçao combate: Usada para situação de combate
void menu();
void tela();

/* Rápida explicação para int e void:
          
               Uma função qualquer pode ser definida como int ou void
          a diferença fundamental dessas definições é o retorno da função.
          Uma Função int tem um retoro inteiro, já uma função void nao tem 
          retorno.
          
               Portanto, ao final de uma função int é obrigatorio um retorno
          para que a função seja finalizada corretamente.

               Já uma função void pode ser finalizada sem retorno. 
               
   Rápida explicação para Comandos Incomuns Usados no Jogo:
          
         -system("cls");   Limpa a tela totalmente.
         -system("pause"); Pausa o programa até que alguma tecla seja pressionada.
         -sleep(...);      Espera o tempo em milésimos para executar a próxima linha de comando.
*/
//______________________________________________________________________________
// Variaveis Universais


//Struct para o personagem
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------	
struct personagem{
	
	char nome[40]; //variavel do nome do jogador
	char arma[3][11]; //variavel da arma do jogador
	
}; typedef struct personagem PERSONAGEM;
PERSONAGEM P;

//Struct para o inimigo
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------	
struct inimigo{
	
	char enemy[3][11]; //variavel do nome do inimigo
	
}; typedef struct inimigo INIMIGO;
INIMIGO I;

//Inicio do Programa
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
	
	// Armas de acordo com as classes
	//--------------------------------
	strcpy(P.arma[0],"sua espada");
	strcpy(P.arma[1],"seu cajado");
	strcpy(P.arma[2],"seu arco");
	// Inimigos
	//--------------------------------
	strcpy(I.enemy[0],"Duende");
	strcpy(I.enemy[1],"Fada");
	strcpy(I.enemy[2],"Ogro");	
	//--------------------------------
	
    system ("cls");//Limpar texto
    
    int vida=15, vida2=0, forca1=5, escudo1=5, forca2=0, escudo2=0, cavaleiro=10, mago=10, arqueiro1=7, arqueiro2=7, classes; //variaveis para dano, attk e classes
    Principal(&vida, &vida2, &forca1, &escudo1, &forca2, &escudo2, &cavaleiro, &mago, &arqueiro1, &arqueiro2, &classes); //Chamar função principal
}

//Função morte, sempre que houver risco de morte será chamada
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void morte(int *vida){
	if ((*vida) <= 0){
		system("cls");
		printf("\n\t*---------------*\n");
		printf("\t|                 |\n");
		printf("\t|    Game Over    |\n");
		printf("\t|                 |\n");
		printf("\t*-----------------*\n");
		system("pause");
		main();
	}
   return;
}
//Função para combate, sempre que houver um combate ela será chamada
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void combate(int *vida, int *vida2, int *forca1, int *escudo1, int *forca2, int *escudo2, int x){

	int f1, f2, round=1; //é atribuido ao valor força e escudo do jogador
	int maxvi=5, maxve=5, escolha; //maxi=vida maxima | maxive=veneno maximo do jogador
	int maxvi2=5, maxve2=5, escolha2; //maxi=vida maxima | maxive=veneno maximo do inimigo
	
    do{
    	
    //Tabela do combate
    //--------------------------------------------------------------------------
    system("cls");
    srand(time(NULL)); 
    f2=(rand() % *forca2)+1; //gerar dano aleatorio do inimigo
    srand(time(NULL));
    f1=(rand() % *forca1)+1; //gerar dano aleatorio do jogador
   do{
    printf("\t*=========================================================*\n");
	printf("\t| Rodada: %02d |  Sua Vida: %02d        Vida do Oponente: %02d  |\n", round, *vida, *vida2);
	printf("\t|                                                         |\n");
	printf("\t|  Escolha sua ação                                       |\n");
	printf("\t|                                                         |\n");
	printf("\t| 1- Atacar (Ataque basico)                               |\n");
	printf("\t| 2- Envenenar (Cause 1 de dano no inimigo por 4 rodadas) |\n");
	printf("\t| 3- Curar (Aumente 1 de vida por 4 rodadas)              |\n");
	printf("\t|                                                         |\n");
	printf("\t*=========================================================*\n");
	
    //Ação do jogador
    //--------------------------------------------------------------------------
	scanf("%d", &escolha);
	
	switch (escolha){
    case 1:
    	if(f1 <= (*escudo2)){
    		system("cls");
    		printf("\n\tO %s conseguiu defender seu ataque de %d de dano\n\t", I.enemy[x], f1);
    		printf("E não perdeu pontos de vida\n\t");
    		system("pause");
  	   }else {
			system("cls");
    		printf("\n\tSeu ataque foi de %d de dano ", f1);
    		f1 = f1 - (*escudo2);
    		(*vida2) = (*vida2) - f1;
    		printf("e seu inimigo usando o escudo recebeu apenas %d\n\t", f1);
			system("pause");
		}
		break;
	case 2:
    		system("cls");
    		printf("\n\tVocê envenenou o oponente causando 1 de dano por 4 rodadas\n\t");
    		system("pause");
    		maxve=0;
		break;	
	case 3:
    		system("cls");
    		printf("\n\tVocê está curando 1 ponto de vida por 4 rodadas\n\t");
    		system("pause");
    		maxvi=0;
		break;	
	default:
		   	system("cls");
    		printf("\n\tPor favor digite uma ação valida\n\t");
    		system("pause");
    		system("cls");
    	break;
}
   } while ((escolha != 1)&&(escolha != 2)&&(escolha != 3)); 
	
    	if ((maxvi<=4)&&((*vida)<15)){
    		(*vida)=(*vida)+1;
    		maxvi++;
	}
		if (maxve<=4){
    		(*vida2)--;
    		maxve++;
	}
	
	//ação do inimigo
	//--------------------------------------------------------------------------
	escolha2=(rand() %3)+1; //Gerar ação do inimigo
	
    switch (escolha2){
    case 1:
    	if(f2 <= (*escudo1)){
    		system("cls");
    		printf("\n\tVocê conseguiu defender o ataque do %s de %d de dano\n\t", I.enemy[x], f2);
    		printf("E não perdeu pontos de vida\n\t");
    		system("pause");
	  } else {
			system("cls");
    		printf("\n\tO ataque do %s foi de %d, ", I.enemy[x], f2);
    		f2 = f2 - (*escudo1);
    		(*vida) = (*vida) - f2;
    		printf("e usando seu escudo, você recebeu apenas %d\n\t", f2);
    		system("pause");
	}
		break;	
	case 2:
    		system("cls");
    		printf("\n\tO %s causou em você 2 de dano por 4 rodadas\n\t", I.enemy[x]);
    		system("pause");
    		maxve2=0;
		break;	
	case 3:
    		system("cls");
    		printf("\n\tO %s está curando 2 de vida por 4 rodadas\n\t", I.enemy[x]);
    		system("pause");
    		maxvi2=0;	
		break;	
	}	
	    if (maxvi2<=4){
    	   (*vida2)=(*vida2)+2;
    		maxvi2++;
	}
	    if (maxve2<=4){
    		(*vida)=(*vida)-2;
    		maxve2++;
	}
    round++;
   		 if ((*vida) <= 0){
    		system("cls");
			printf("\n\tA batalha terminou com %d rodadas\n\tVocê infelizmente foi derrotado!\n\t", round);
			system("pause");  
			morte(vida);
		}
    } while ((*vida2) > 0);
	system("cls");
	printf("\n\tA batalha terminou com %d rodadas\n\tParabéns você venceu!\n\t", round);
	system("pause");  
	system("cls");
}


//Função principal, usada para registrar nome do jogador
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Principal(int *forca1, int *forca2, int *escudo1, int *escudo2, int *vida2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes){
	
	(*vida)=15; //define vida do jogador = 15
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("\t*=========================================================*\n");
	printf("\t| Digite o nome do seu aventureiro para começarmos o jogo |\n");
	printf("\t*=========================================================*\n\t");
	scanf("%s", &P.nome);
	system("cls");
	classe(vida2, forca1, escudo1, forca2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes); //Chamar função
	}

//Função principal, usada para registrar a classe do jogador
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void classe(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes){
	
	int c;
	
	printf("\t*===========================*\n");
	printf("\t|Escolha sua classe         |\n\t|1 - Cavaleiro              |\n\t|2 - Mago                   |\n\t|3 - Arqueiro               |\n\t|4 - Explicação das classes |\n");
	printf("\t*===========================*\n\t");
	scanf("%d", classes);
	
	switch (*classes){ //escolher a classe e aplicar seus respectivos atributos
	case 1:
			(*forca1)=(*cavaleiro);
			(*escudo1)=5;
		break;
	case 2:
			(*escudo1)=(*mago);
			(*forca1)=5;
		break;
	case 3:
			(*forca1)=(*arqueiro1);
			(*escudo1)=(*arqueiro2);
		break;
	case 4:
			system("cls");
			printf("      *================================================================*\n");
			printf("      |Você já começa com 5 pontos de força, 5 de proteção e 15 de vida|\n");
			printf("      *================================================================*\n");
			printf("\t*=============================*\t*===========================*\n");
			printf("\t|Cavaleiro: Receba +5 de força|\t|Mago: Receba +5 de proteção|\n");
			printf("\t*=============================*\t*===========================*\n");
			printf("\t       *=============================================*\n");
			printf("\t       |Arqueiro: Receba +2 de força e +2 de proteção|\n");
			printf("\t       *=============================================*\n\n\n\n\t\t ");	
			system("pause");
			system("cls");
			classe(forca1, escudo1, forca2, vida2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes);
		break;
	default:
			system("cls");
			printf("\t    *============================*\n");
			printf("\t    |ERRO DIGITE UMA OPÇÃO VALIDA|\n");
			printf("\t    *============================*\n");
			system("pause");
			system("cls");
			classe(forca1, escudo1, forca2, vida2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes);
    	break;
	}
	system("cls");
	printf("%s está pronto para começar?\n", P.nome);
	system("pause");
	system("cls");
	printf("\t*============================================================================*\n");
	printf("\t| Tome cuidado aventureiro, sua jornada será perigosa, seu jogo começa em... |\n");
	printf("\t*============================================================================*\n\n\t\t\t\t\t     ");
	
	for(c=5; c>=1; c--){  //contagem do 5 ao 1
   		printf("%02d\n\t\t\t\t\t     ", c);
   	     Sleep(800); //timer 
	   }
	   
	system("cls"); 
	sit0(forca1, escudo1, forca2, vida2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes); //Chamar função
}  
	
//Função situação 0, historia inicial do personagem
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void sit0(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes){

    int op1;
    printf("Desconhecido: Acorda!\nDesconhecido: Acorda!\n");	
    Sleep(2000);
	printf("- Você ouve uma voz te chamar\n");
	Sleep(2000);
	printf("Desconhecido: Acorda %s!!!\n", P.nome);
	Sleep(2000);
	printf("- Você sente que essa pessoa que te chama está te tocando para acordar, o que você faz?\n\n");	
	Sleep(3000);
	
	do{ 
	printf("1- Acordar e bater na pessoa que esta te acordando\n2- Acordar tranquilamente e interrogar quem é\n");
	scanf("%d", &op1); 
	
	switch (op1){
    case 1:
    		system("cls"); 
    		sit1(forca1, escudo1, forca2, vida2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes);
    	break;
    case 2:
    		system("cls");	
    		sit2(forca1, escudo1, forca2, vida2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes);
    	break;
    default:
    		system("cls");
    		printf("Digite uma opção valida!\n");
    		system ("pause");
    		system("cls");
    	}
    	
	}while ((op1 != 1)&&(op1 != 2));
}
     
void sit1(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes){
	
    printf("Desconhecido: Aiiii, porque você fez isso %s?\n", P.nome);	
    Sleep(2000);
    sit2(forca1, escudo1, forca2, vida2, escudo2, vida, cavaleiro, mago, arqueiro1, arqueiro2, classes);
}
     
void sit2(int *forca1, int *escudo1, int *forca2, int *vida2, int *escudo2, int *vida, int *cavaleiro, int *mago, int *arqueiro1, int *arqueiro2, int *classes){
	
	int i=(*classes)-1;
	
    int op1;
    printf("- Você acorda e percebe que quem te acordava era seu avô Aurélio.\n"); 
    Sleep(2000);
    printf("Aurélio: Uma tempestade está acontecendo, toda nossa plantação foi devastada.\nAurélio: Pegue %s que está no andar de baixo e fuja imediatamente.\n", P.arma[i]);
    Sleep(5000);
    printf("%s: Mas avô e você??\n", P.nome);
    Sleep(2500);
    printf("Aurélio: Eu ja estou velho e cuido dessa casa a anos, eu preciso morrer aqui.\n");
    Sleep(3500);
    printf("- Enquanto seu avô falava você sente que a casa está desmoronando aos poucos.\n");
    Sleep(3500);
    printf("Aurélio: Vá logo!\n");
    Sleep(3500);
    printf("- Você e seu avô descem as escadas, você percebe que todo o seu quarto já está cheio de lama e que logo a casa será devastada.\n- No andar de baixo você pega %s no ármario.\n", P.arma[i]);
    Sleep(5000);
    printf("Aurélio: Vá logo %s!\n", P.nome);
    Sleep(3000);
    printf("%s: Eu não vou deixar voc---\n", P.nome);
    Sleep(3000);
    printf("- Antes que você pudesse terminar a frase, o teto começa a tremer. O que você faz?\n\n");
    Sleep(3000);
    do{
    printf("1- Tentar puxar seu avô para fora da casa junto com você\n2- Tentar destruir o teto com %s \n3- Receber a pancada no lugar dele\n", P.arma[i]);
	scanf("%d",&op1);
    
    switch (op1){
    	case 1:
    		system("cls");
    		printf("\n\tVocê não foi ágil, e seu avô foi soterrado, porém você saiu da casa sem danos\n\n");
    		sit3(vida, vida2, forca1, escudo1, forca2, escudo2, classes);
    		break;
    	case 2:
    		system("cls");
    		printf("\n\tVocê falhou e seu avô veio a falecer, você perdeu 3 pontos de vida | Vida atual: %d\n\n", (*vida)-3);
    		sit3(vida, vida2, forca1, escudo1, forca2, escudo2, classes);
    		break;
    	case 3:
    		system("cls");
    		printf("\n\tVocê morreu com a pancada e seu corpo esmagou o seu avô, e os 2 morreram\n\n");
    		(*vida)=(*vida)-15;
    		morte(vida);
    		break;
    	default:
    		system("cls");
    		printf("\n\tVocê desonrou seu avô, e os 2 morreram\n\n");
    		(*vida)=(*vida)-15;
    		morte(vida);
    		break;
    }
    }while ((op1 != 1)&&(op1 != 2)&&(op1 != 3));
}
	
void sit3(int *vida, int *vida2, int *forca1, int *escudo1, int *forca2, int *escudo2, int *classes){
	
	int op1;
	
	(*vida2) = 5;
	(*escudo2) = 2;
	(*forca2) = 5;
	
	system("pause");
	system("cls");
	printf("- Você vê sua casa junto com seu avô indo embora com a correnteza.\n"
	       "- Atrás de você há um caminho seguro, você corre por ele enquanto chora por não ter conseguido salvar o seu avô.\n");
	Sleep(5000);
	do{
	printf("- Após horas de caminhada você está com fome e avista uma árvore com frutos, o que você faz?\n\n"
    "1- Seguir seu caminho\n2- Ir até a árvore e se alimentar.\n");
    scanf("%d", &op1);
    switch (op1){
    case 1:
    		system("cls");
    		printf("\n\tVocê continua seu caminho com fome e perde 1 de vida | Vida atual: %d\n\t", (*vida)=(*vida)-3);
    		system("pause");
    		sit4(vida, vida2, forca1, escudo1, forca2, escudo2, classes);
    	break;
    case 2:
    		system("cls");
    		printf("\n\tVocê se aproxima da árvore e come um fruto, sua vida se regenera | Vida atual: %d\n\t", (*vida)=15);
    		system("pause");
    		system("cls");
    		printf("- Você achou um %s!\n"
    		       "%s: Estranho o que faz no meu habitat?\n"
   		           "%s: Essa árvore é MINHA\n", I.enemy[0], I.enemy[0], I.enemy[0]);
   		    Sleep(5000);
			printf("%s parte para cima!\n", I.enemy[0]);          
			system("pause");
    		combate(vida, vida2, forca1, escudo1, forca2, escudo2, 0);
    		system("cls");
    		printf("\n\tVocê recuperou sua vida e ganhou mais atributos\n\t"
				   "\n\tVocê adquiriu +1 de força e + 2 de vida\n\t");
         	system("pause");
         	system("cls");
    		(*vida)=17;
    		(*forca1)++;
    		printf("- Após a vitória contra o %s\n", I.enemy[0]);
    		sit4(vida, vida2, forca1, escudo1, forca2, escudo2, classes);
    	break;
    default:
    		system("cls");
    		printf("Digite uma opção valida!\n");
    		system ("pause");
    		system("cls");
    }
    }while ((op1 != 1)&&(op1 != 2));
	system("pause");
}

void sit4(int *vida, int *vida2, int *forca1, int *escudo1, int *forca2, int *escudo2, int *classes){
	
	int op1;
	int i=(*classes)-1;
	
	(*vida2) = 10;
	(*escudo2) = 3;
	(*forca2) = 7;
	
	printf("- Você segue ate um bosque encantado\n"	
		   "- Dentro dele voce sente um ar de calma e um cheiro forte de planta\n");
 	Sleep(5000);
	printf("- Mas o clima que antes parecia agitado agora ficou calmo e tranquilo\n"	
		   "- Com seu instinto você empunha %s mas nada acontece\n", P.arma[i]);
 	Sleep(5000);
	printf("- Você caminha mais um pouco, mas sente que está andando no mesmo lugar\n"	
		   "- Quando de repente um ser místico aparece\n", P.arma[i]);
	Sleep(5000);
	printf("- Você achou uma %s!\n"
    		"%s: O que voce faz na minha bosque seu mero humano??\n"
   		    "%s: Volte agora mesmo do lugar de onde veio\n"
   		    "%s: Ou eu mesma farei isso\n\n", I.enemy[1], I.enemy[1], I.enemy[1], I.enemy[1]);
    Sleep(5000);
   	printf("- A fada fica mais irritada a cada segundo que passa. "	
		   "O que voce faz?\n");
	 Sleep(5000);
	do{ 
	printf("1- Tentar conversar com a fada\n2- Sacar novamente %s\n", P.arma[i]);
	scanf("%d", &op1); 
	    switch (op1){
    	case 1:
    		system("cls");
			printf("%s: Eu não te dei permissão para se dirigir a mim\n"
   		    "%s: Cansei, perdi minha paciencia\n"
   		    "%s parte para cima!\n", I.enemy[1], I.enemy[1], I.enemy[1]);
   		    system("pause");
   		    combate(vida, vida2, forca1, escudo1, forca2, escudo2, 1);
   		    main();
    		break;
    	case 2:
    		system("cls");
			printf("%s: Como voce ousa me enfrentar\n"
   		    "%s: Vai se arrepender disso criatura ridicula\n"
   		    "%s parte para cima!\n\n", I.enemy[1], I.enemy[1], I.enemy[1]);
   		    system("pause");
   		    combate(vida, vida2, forca1, escudo1, forca2, escudo2, 1);
   		    main();
    		break;
    	default:
    		system("cls");
    		printf("Digite uma opção valida!\n");
    		system ("pause");
    		system("cls");
    		break;
    }
    }while ((op1 != 1)&&(op1 != 2));
 }    
