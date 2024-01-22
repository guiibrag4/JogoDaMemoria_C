#include <stdio.h> /* Para fun��es b�sicas como printf() */
#include <stdlib.h> /* Para usar  srand e rand(), que geram n�meros alet�rios */
#include <locale.h> /* Para usar acentos e caracteres como � no c�digo */
#include <time.h> /* Para inicializar a semente com n�meros diferentes a cada execu��o do programa */
#include <unistd.h> /* Para usar a fun��o sleep() */

/* Indicando ao compilador qual � o cabe�alho da fun��o, fazendo a declara��o de seu tipo da mesma forma que se declara as vari�veis. A de-
clara��o da fun��o consiste na escrita do seu cabe�alho seguida de um ponto e v�rgula. Isso ir� evitar erros de duplica��o de fun��es no
c�digo e consequentemente erro de compila��o, j� que em C n�o se pode exibir duas fun��es com o mesmo nome */
void Menu_Jogo();
void Desenho_Menu();
void Instrucoes();
void Escolha_Dificuldade();
void Asterisco_Revelacoes();
void Cartas_Facil();
void Cartas_Medio();
void Cartas_Dificil();
void Embaralhar();
void Imprime_Cartas_Facil();
void Jogar();

/* Struct que cont�m uma vari�vel que ser� utilizada para conferir se um par de cartas foi virada e deixar esse par impresso na tela */
typedef struct sJogo_memoria {
  int Cartas_corretas_F[4][4];
}J;

int Cartas_F [4][4] = {{14,21,15,16},{15,20,19,14},{21,16,17,18},{18,19,20,17}};
J acertadas;

typedef struct sJogo {
	int x;
	int y;
}Coordenadas; /* Struct que cont�m as vari�veis das coordenadas que ser�o usadas no c�digo */

Coordenadas primeira; /* Vari�veis globais */
Coordenadas segunda;

void Desenho_Menu() {
  /* Criada para fins est�ticos no jogo. */
  int Carinha = 4, Carinha2 = 2, Carinha3 = 5;
  printf("-----------------------------------------------------------------------------------------------------------------------");
  puts("\n\n");
  printf("\t\t\t|--------------------------------------------------------------------|\n");
  printf("\t\t\t|--------------------------------------------------------------------|\n");
  printf("\t\t\t|--------------------------------------------------------------------|\n");
  printf("\t\t\t|   %c      %c      %c	    JOGO DA MEM�RIA	   %c      %c      %c   |\n", (char) Carinha, (char) Carinha2, (char) Carinha3, (char) Carinha3, (char) Carinha2, (char) Carinha);
  printf("\t\t\t|--------------------------------------------------------------------|\n");
  printf("\t\t\t|--------------------------------------------------------------------|\n");
  printf("\t\t\t|--------------------------------------------------------------------|\n");
  printf("\n\n-----------------------------------------------------------------------------------------------------------------------");
}

void Instrucoes() {
  int i = 26, j, a = 24, b = 25, c = 26; //Vari�veis definidos s� para fins est�ticos no jogo.
  char caracter;
  printf("\t\t\t\t");for (j = 0; j < 61; j++) {
    printf("%c", (char) i);
  }
  printf("\n");
  for (j = 0; j < 2; j++) {
    printf("				%c							    %c\n", (char) a, (char) b);
  }
  printf("				%c Nesse jogo, uma determinada quantidade de cartas escondi- %c\n", (char) a, (char) b);
  printf("				%c das aparecer� na sua tela por um breve momento. Voc� ter� %c\n", (char) a, (char) b);
  printf("				%c  que adivinhar a posi��o de duas cartas iguais para con-  %c\n", (char) a, (char) b);
  printf("				%c  seguir um acerto. Um n�mero de tentativas � determinado  %c\n", (char) a, (char) b);
  printf("				%c para cada n�vel de dificuldade no jogo, o jogador dever�  %c\n", (char) a, (char) b);
  printf("				%c  achar todos os pares de cartas antes do n�mero de tenta- %c\n", (char) a, (char) b);
  printf("				%c      tivas acabar para que ele ganhe.Caso contr�rio,      %c\n", (char) a, (char) b);
  printf("				%c                        ele perde.                         %c\n", (char) a, (char) b);
  printf("				%c                                                           %c\n", (char) a, (char) b);
  printf("				%c                                                           %c\n", (char) a, (char) b);
  printf("				%c                       Boa sorte!!!!                       %c\n", (char) a, (char) b);
  for (j = 0; j < 1; j++) {
    printf("				%c							    %c\n", (char) a, (char) b);
  }
  printf("\t\t\t\t");
  for (j = 0; j < 61; j++) {
    printf("%c", (char) c);
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Pressione enter para voltar...");

  /*O uso de getchar(); � feito para ter uma pausa no sistema, de forma que o usu�rio precisar� apertar alguma tecla para que o c�digo ten-
  ha continuidade.*/
  getchar(); //Esse getchar descarta o caractere que ainda estiver no buffer, se tiver;
  caracter = getchar(); //j� esse, aguarda a entrada do usu�rio, s�o colocados 2 getchar() para que o programa funciona corretamente
}

void Menu_Jogo() {
  char opcao;
  Desenho_Menu();
  do {
    printf("\n\n\n\t\t\tSELECIONE UMA OP��O: \n");
    printf("\t\t\t1- Jogar\n");
    printf("\t\t\t2- Instru��es\n");
    printf("\t\t\t3- Sair\n");
    printf("\t\t\tOp��o escolhida: ", opcao);
    scanf(" %c", & opcao);
    system("cls");
    switch (opcao) {
    case '1':
      Escolha_Dificuldade(); /* Caso queira jogar, a fun��o Escolha_Dificuldade ser� chamada */
      break;
    case '2':
      Instrucoes(); /* Chama a fun��o que demonstra as instru��es do jogo */
      system("cls");
      Desenho_Menu();
      break;
    case '3':
      system("cls");
      char certeza;
      printf("Voc� tem certeza que deseja sair do jogo? Caso sim, dever� ser iniciado novamente para jogar...\n\n");
      do {
        printf("(1)Voltar para o jogo\n(2)Sair msm\n\nOp��o: ");
        scanf(" %c", &certeza);
        system("cls");
      } while (certeza != '1' && certeza != '2');
      if (certeza == '1') {
        Menu_Jogo(); 
      } else if (certeza == '2') {
        printf("End Game.\n");
      }
      break;
    	default:
      printf("Op��o inv�lida, escolha novamente.\n");
      Desenho_Menu();
      break;
    }
  } while (opcao != '1' && opcao != '3');
}

/* Essa Matriz � respons�vel por imprimir uma matriz de asteriscos, que ser� utilizada diversas vezes para imprimir as cartas escondidas no
jogo, ela recebe como par�metro linha e coluna para poder ser modificada de acordo com as dificuldades "F�cil", "M�dia" e "D�ficil". */
void Asterisco_Revelacoes(int *teste1, int *teste2){
  
  int i, j;
  printf("(x)\n\n"); /* formata��o para aparecer o x como horinzontal */
  for (i = 0; i < *teste1; i++) {
    printf(" %d ", i);
    for (j = 0; j < *teste2; j++) {
    	if(acertadas.Cartas_corretas_F[i][j] == 1){
    		printf(" [%c] ", (char) Cartas_F[i][j] + 5);
		}
		else{
        printf(" [*] ");
    	}
    }
    printf("\n\n");
  }
  printf("     0    1    2    3  (y)  \n\n"); /* y na vertical */
}

void Escolha_Dificuldade() {
  char nivel;
  int Design = 16;
  do {
    puts("Escolha o n�vel de dificuldade do jogo: \n\n(F)F�cil  \n(M)M�dia \n(D)D�ficil ");
    scanf(" %c", & nivel);
    system("cls");
    if (nivel == 'f' || nivel == 'F') {
      printf("Voc� escolheu o n�vel de dificuldade f�cil, as cartas aparecer�o na sua tela por 10 segundos.\n");
      printf("\n%c Lembrando que voc� ter� 14 tentativas e ter� que obter 8 acertos antes de acaba-las para ganhar o jogo!\n\n", (char) Design);
      int Cartas_F [4][4] = {{14,21,15,16},{15,20,19,14},{21,16,17,18},{18,19,20,17}};
      printf("Pressione enter para continuar...");
      getchar();
      getchar();
      Jogar();
    } else if (nivel == 'm' || nivel == 'M') {
      Cartas_Medio();
    } else if (nivel == 'd' || nivel == 'D') {
      Cartas_Dificil();
    } else {
      system("cls");
      printf("Caractere inv�lido, digite um dos caracteres sugeridos.\n\n");
    }
  } while (nivel != 'f' && nivel != 'F');
}

void Cartas_Facil(int Cartas[4][4]) {
  int i, j;
  srand(time(NULL)); /* inicializa o gerador de n�meros aleat�rios */
  Embaralhar(Cartas, 4, 4); /* embaralha a matriz */
}

/* Fun��o respons�vel por imprimir as Cartas que j� estavam definidas na fun��o Jogar em posi��es aleat�rias da matriz, para que toda vez o
algu�m for jogar, o jogo seja diferente da �ltima. */
void Imprime_Cartas_Facil(int Cartas[][4]) {
  int i, j;
  printf("(x)\n\n");
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (j == 0) {
        printf(" %d", i);
      }
      printf("  [%c]", (char) Cartas[i][j] + 5); /* Casting para imprimir caracteres da tabela ASCII */
    }
    printf("\n\n");
  }
  printf("     0    1    2    3  (y)  \n\n");
}

void Embaralhar(int Cartas[][4], int linhas, int colunas) { 
  int i, j;											   //Ex 1:											|Ex2:
  for (i = linhas - 1; i >= 0; i--) { 			       //i = 3  										|i = 3
    for (j = colunas - 1; j >= 0; j--) { 			   //j = 3											|j = 2
      int aleatorio = rand() % (i * colunas + j + 1);  // nmr 12                 				   		|      nmr 11
      int linha_aleatoria = aleatorio / colunas;       // 12/4 = linha 3        					    |    11/4 = 2,75  arrendodado --> linha 3
      int coluna_aleatoria = aleatorio % colunas;      // 12 % 4 = coluna 0         					|  		     11%4 = coluna 3 
      int temp = Cartas[i][j];                         // temp = Cartas[3][3]	      					|		     temp = Cartas[3][2]
      Cartas[i][j] = Cartas[linha_aleatoria][coluna_aleatoria]; // Cartas[3][3] =  Cartas[3][0]	        |     Cartas[2]
      Cartas[linha_aleatoria][coluna_aleatoria] = temp;         // Cartas[3][0] = Cartas[3][3]			|
    }
  }
}

void Jogar() {
  int i = 10;
  int teste1 = 4, teste2 = 4;
  Cartas_Facil(Cartas_F);
  /* chama a fun��o Cartas_Facil e define como argumento da fun��o a matriz Cartas_F, onde ser� embaralhada
   								as cartas do jogo em posi��es aleat�rias. */
  do {
    system("cls");
    printf("Memorize as cartas!!");
    printf("\n\nTempo: %d\n\n\n", i);
    i--;
    Imprime_Cartas_Facil(Cartas_F);
    sleep(1); /* Suspende a execu��o do programa pela quantidade de segundos dentro do argumento (1 segundo) */
  } while (i > 0); /* Esse La�o far� a contagem regressiva para que as cartas expostas sejam escondidas. */
  system("cls");
  Asterisco_Revelacoes(&teste1, &teste2);
  /* Passando o argumento 4,4 para a fun��o asterisco receber como par�metro da fun��o esses n�meros de linhas e colunas
   					em sua matriz, respectivamente. */
   					
  int aux1, aux2;
  
  /* aux 1 e aux 2 s�o usadas para armazenar o valor da carta contida nas coordenadas digitadas pelo usu�-
rio, n�o seriam necess�rias mas ajudam muito na legibilidade e entendimento do programa. */
  int cont_tentativas = 14, cont_acertos = 0;
  char c;

  do {
    /* La�o para que o jogador entre com as cartas at� vencer ou perder o jogo. */
    printf("Entre com as coordenadas da 1� carta (x,y): ");
    do {
      /* Caso o jogador entre com coordenadas inv�lidas, ele ter� que digita-las novamente. */
      scanf("%d %d", &primeira.x, &primeira.y);
      system("cls");
     
      Asterisco_Revelacoes(&teste1, &teste2); /* Fun��o que ir� imprimir os asteriscos e caso um par seja encontrado, imprimi-r� o par e os asteriscos.*/
      if (primeira.x < 0 || primeira.x > 3 || primeira.y < 0 || primeira.y > 3) {
        system("cls");
        Asterisco_Revelacoes(&teste1,&teste2);
        printf("\nCoordenadas inv�lidas. Entre com coordenadas para a 1� carta dentro do intervalo [0,3]: \n\n");
      }
    } while (primeira.x < 0 || primeira.x > 3 || primeira.y < 0 || primeira.y > 3);
    aux1 = Cartas_F[primeira.x][primeira.y]; /* aux 1 recebendo a carta que est� contida nas coordenas digitas pelo jogador. */
    printf("Carta 1: %c\n", (char) aux1 + 5); 
    printf("\nEntre com as coordenadas da 2� carta (x,y): ");
    do {
      scanf("%d %d", &segunda.x, &segunda.y);
      system("cls");
      Asterisco_Revelacoes(&teste1, &teste2);
      if (segunda.x < 0 || segunda.x > 3 || segunda.y < 0 || segunda.y > 3) {
        system("cls");
        Asterisco_Revelacoes(&teste1, &teste2);
        printf("\nCarta 1: %c\n", (char) aux1 + 5);
        printf("Coordenadas inv�lidas. Entre com coordenadas para a 2� carta dentro do intervalo [0,3]: \n\n");
      } else if (segunda.x == primeira.x && segunda.y == primeira.y) {
        /* Verifica se o jogador acabou de entrar com as mesmas coordenadas, para que o jogo n�o d� um
	  erro l�gico e contabilize como acerto caso o jogador digite a mesma carta. Ent�o o jogador dever� inserir coordenadas diferentes. */
        system("cls");
        printf("Voc� acabou de usar essas coordenadas para a  1� carta, entre com uma coordenada diferente para a 2� carta.\n\n");
        Asterisco_Revelacoes(&teste1, &teste2);
        printf("Carta 2: ");
      }
    } while (segunda.x < 0 || segunda.x > 3 || segunda.y < 0 || segunda.y > 3 || (segunda.x == primeira.x && segunda.y == primeira.y));
    /* O c�digo ir� se repetir enquanto as coordenadas ou forem
	maiores que as permitidas no escopo ou se forem iguais as coordenadas inseridas anteriormente. */

    aux2 = Cartas_F[segunda.x][segunda.y]; /* aux 2 recebendo a carta que est� contida nas coordenas digitas pelo jogador. */
    printf("Carta 1: %c\n", (char) aux1 + 5);
    printf("Carta 2: %c\n", (char) aux2 + 5);
    sleep(2); /* Mostra a carta escolhida pelo usu�rio por dois segundos, justamente para ele memorizar sua	posi��o. */

    if (aux1 == aux2) {
      system("cls");
      acertadas.Cartas_corretas_F[primeira.x][primeira.y] = 1;
      acertadas.Cartas_corretas_F[segunda.x][segunda.y] = 1;
      Asterisco_Revelacoes(&teste1, &teste2);
      printf("\nParab�ns, voc� acertou!!\n");
      cont_acertos++;
      printf("\nAcertos: %d\nTentativas: %d\n\n", cont_acertos, cont_tentativas); 
      if (cont_acertos == 2) {
        /* Caso o usu�rio acerte 2 cartas, as posi��es das cartas ser�o reveladas rapidamente. */
        printf("\nQuanto mais se tem, mais se recebe! As cartas aparecer�o na tela por 3 segundos, fique atento!\n\n");
        printf("Pressione enter para continuar...\n");
        getchar();
        getchar();
        system("cls");
        Imprime_Cartas_Facil(Cartas_F);
        sleep(3);
        system("cls");
        Asterisco_Revelacoes(&teste1, &teste2);
      } else if (cont_acertos == 4) {
        /* Caso o usu�rio acerte 4 cartas, as posi��es das cartas ser�o reveladas rapidamente. */
        printf("\nQuanto mais se tem, mais se recebe! As cartas aparecer�o na tela por 3 segundos, fique atento!\n\n");
        printf("Pressione enter para continuar...\n");
        getchar();
        getchar();
        system("cls");
        Imprime_Cartas_Facil(Cartas_F);
        sleep(3);
        system("cls");
        Asterisco_Revelacoes(&teste1, &teste2);
      } else if (cont_acertos == 6) {
        /* Caso o usu�rio acerte 6 cartas, as posi��es das cartas ser�o reveladas rapidamente. */
        printf("\nQuanto mais se tem, mais se recebe! As cartas aparecer�o na tela por 2 segundos, fique atento!\n\n");
        printf("Pressione enter para continuar...\n");
        getchar();
        getchar();
        system("cls");
        Imprime_Cartas_Facil(Cartas_F);
        sleep(2);
        system("cls");
        Asterisco_Revelacoes(&teste1, &teste2);
      }
    } else {
      system("cls");
      Asterisco_Revelacoes(&teste1, &teste2);
      printf("\nVoc� errou, tente novamente!\n");
      cont_tentativas--;
      if (cont_tentativas == 7) { /* O jogador j� usou metade de suas tentitivas e n�o ganhou, ent�o receber� uma ajuda. */
      	system("cls");
      	Asterisco_Revelacoes(&teste1, &teste2);
        printf("\nVoc� errou, tente novamente!\n");
        printf("\nAs suas tentativas est�o acabando! Para lhe ajudar, as cartas aparecer�o na tela por 4 segundos, fique atento!\n\n");
        printf("Pressione enter para continuar...\n");
        getchar();
        getchar();
        system("cls");
        Imprime_Cartas_Facil(Cartas_F);
        sleep(4);
        system("cls");
        Asterisco_Revelacoes(&teste1, &teste2);
      } else if (cont_tentativas == 2) {
        /* O jogador est� para perder o jogo, ent�o ele receber� uma ajuda. */
        system("cls");
      	Asterisco_Revelacoes(&teste1, &teste2);
      	printf("\nVoc� errou, tente novamente!\n");
        printf("\nAs suas tentativas est�o acabando! Para lhe ajudar, as cartas aparecer�o na tela por 5 segundos, fique atento!\n\n");
        printf("Pressione enter para continuar...\n");
        getchar();
        getchar();
        system("cls");
        Imprime_Cartas_Facil(Cartas_F);
        sleep(5);
        system("cls");
        Asterisco_Revelacoes(&teste1, &teste2);
      }

      printf("\nAcerto: %d\nTentativas: %d\n\n", cont_acertos, cont_tentativas); /* Para o usu�ria ficar consciente de suas condi��es. */
    }
  } while (cont_tentativas != 0 && cont_acertos != 8); /* La�o ser� feito at� que tentativas sejam iguais a 0 e acertos iguais a 8. */
  char novamente;
  if (cont_tentativas == 0) {
    system("cls");
    Asterisco_Revelacoes(&teste1, &teste2);
    printf("\nAs suas tentativas se esgostaram, lamento mas voc� perdeu D:\n\n");
    printf("Voc� deseja jogar novamente?\n\n");
    do {
      printf("(1)Jogar novamente\n(2)Sair do jogo\n\n");
      printf("Op��o: ");
      scanf(" %c", & novamente);
      if (novamente == '1') {
        system("cls");
        Menu_Jogo();
      } else if (novamente == '2') {
        system("Cls");
        printf("Obrigado por ter jogado meu jogo XD\n\n");
      }
      if (novamente != '1' && novamente != '2') {
        system("cls");
        printf("Caractere inv�lido\n\n");
      }
    } while (novamente != '1' && novamente != '2');
  } else if (cont_acertos == 8) {
    system("cls");
    Asterisco_Revelacoes(&teste1,&teste2);
    printf("\nVoc� ganhou o jogo, G�enio!\n\n"); /* Cara � um G�nio. */
    printf("Voc� deseja jogar novamente?\n\n");
    do {
      printf("(1)Jogar novamente\n(2)Sair do jogo\n\n"); 
      printf("Op��o: ");
      scanf(" %c", & novamente);
      if (novamente == '1') {
        system("cls");
        Menu_Jogo();
      } else if (novamente == '2') {
        system("cls");
        printf("Obrigado por ter jogado meu jogo XD\n\n");
      }
      if (novamente != '1' && novamente != '2') {
        system("cls");
        printf("Caractere inv�lido\n\n");
      }
    } while (novamente != '1' && novamente != '2');
  }
}

void Cartas_Medio(int Cartas[4][6]) {
  int i = 3, j = 16, k = 5;
  printf("%cA equipe ficou sem dinheiro para completar o jogo D:, por enquanto jogue no n�vel f�cil!\n\n", (char) j);
  printf("%cGostou do jogo? Fa�a um pix para ajudar a equipe a finaliza-lo %c %c\n", (char) k, (char) i, (char) i);
  printf("%cE-mail e chave pix da equipe: Xx20CodificarxX@gmail.com\n", (char) j);
  printf("\n\nPressione enter para voltar...");
  getchar();
  getchar();
  system("cls");
}

void Cartas_Dificil(int Cartas[5][5]) {
  int i = 3, j = 16, k = 5;
  printf("%cA equipe ficou sem dinheiro para completar o jogo D:, por enquanto jogue no n�vel f�cil!\n\n", (char) j);
  printf("%cGostou do jogo? Fa�a um pix para ajudar a equipe a finaliza-lo %c %c\n", (char) k, (char) i, (char) i);
  printf("%cE-mail e chave-pix da equipe: Xx20CodificarxX@gmail.com\n", (char) j);
  printf("\n\nPressione enter para voltar...");
  getchar();
  getchar();	
  system("cls");
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  Menu_Jogo();
  return 0;
}
