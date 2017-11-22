#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu();
void sair();
void juros_futuro();
void juros_presente();
void valor_presente_liquido();
void payback();
void taxa_interna_retorno();

int main(){
  menu();
}


void menu(){

	int op = 0;

		printf("\n\t|------------------- MENU ------------------|");
		printf("\n\t| 1 - Calcular valor futuro                 |");
    printf("\n\t| 2 - Calcular valor presente               |");
		printf("\n\t| 3 - Calcular valor presente liquido (VPL) |");
    printf("\n\t| 4 - Calcular payback                      |");
		printf("\n\t| 5 - Calcular taxa interna de retorno (TIR)|");
		printf("\n\t| 9 - SAIR                                  |");
		printf("\n\t|-------------------------------------------|\n\n");

	printf("\n\t> Digite a opção desejada: ");
	scanf("%d", &op);

	switch (op){
		case 1:
			juros_futuro();

			break;
    case 2:
  		juros_presente();

  		break;
		case 3:
			valor_presente_liquido();
			break;
		case 4:
			payback();
			break;
    case 4:
  		taxa_interna_retorno();
  		break;


	}

// Enquanto o usuário não digitar "9"(parâmetro de saída), ele chama o menu.

	while(op != 9){
		menu();
	}

}

void juros_futuro(){

float capital, i, m;
int t;
  printf("\tInforme o valor do capital:\t\n");
  scanf("%f",&capital);
  printf("\tInforme o total de periodos:\t\n");
  scanf("%d",&t);
  printf("\tInforme o valor da taxa (%):\t\n");
  scanf("%f",&i);

  m = capital*pow(1+(i/100),t);
  printf("\tAo fim de %d periodos com taxa de %.2f o valor sera R$ %.2f\n",t,i,m);
}

void juros_presente(){
  float capital, i, m;
  int t;
    printf("\tInforme o valor do capital:\t\n");
    scanf("%f",&capital);
    printf("\tInforme o total de periodos:\t\n");
    scanf("%d",&t);
    printf("\tInforme o valor da taxa (%):\t\n");
    scanf("%f",&i);

    m = (capital/pow(1+(i/100),t));
    printf("\tAo fim de %d periodos com taxa de %.2f o valor sera R$ %.2f\t\n",t,i,m);

}

void valor_presente_liquido(){
  float in, tax, m, total =0;
  int t,i;
    printf("\tInforme o valor do capital:\t\n");
    scanf("%f",&in);
    in = in * (-1);
    printf("\tInforme o total de periodos:\t\n");
    scanf("%d",&t);
    printf("\tInforme o valor da taxa (%):\t\n");
    scanf("%f",&tax);

    t = t+1;
    float fc[t];
    fc[0] = in;
    total = fc[0];
    for (i=1; i < t; i++){
      printf("\tInforme o valor para o periodo %d: \t\n",i);
      scanf("%f",&fc[i]);
      total = total + fc[i]/pow(1+(tax/100),i);
    }
printf("Ao fim de %d periodos com taxa de %.2f o valor sera R$ %.2f \t\n",t-1,tax,total );

}


void payback(){


}

void taxa_interna_retorno(){
  float capital, in, m;
  int t,i;

  float tir =0, aux=0, fluxos;

    printf("\tInforme o valor investimento inicial:\t\n");
    scanf("%f",&in);
    in = in * (-1);

    printf("\tInforme o total de periodos:\t\n");
    scanf("%d",&t);
    t = t+1;
    float fc[t];
    fc[0] = in;

    for (i=1;i<t; i++){
      printf("\tInforme o valor para o periodo %d: \t\n",i);
      scanf("%f",&fc[i]);
    }

    do{
      aux = 0;
      tir += 0.01;
      for (i=0;i < t; i ++){
        aux += (fc[i]/pow(1+(tir/100),i));
      }
    }while(aux > 0);

    printf("\tA taxa interna de retorno e igual a: %.2f\t\n",tir);
}
