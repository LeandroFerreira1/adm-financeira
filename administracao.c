#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu();
void valor_futuro();
void valor_presente();
void valor_presente_liquido();
void payback();
void taxa_interna_retorno();

int main(){
  menu();
}


void menu(){

	int op = 0;

		printf("\n\t|------------------- MENU ------------------|");
		printf("\n\t| 1 - Calcular valor presente               |");
    printf("\n\t| 2 - Calcular valor futuro                 |");
		printf("\n\t| 3 - Calcular valor presente liquido (VPL) |");
    printf("\n\t| 4 - Calcular payback                      |");
		printf("\n\t| 5 - Calcular taxa interna de retorno (TIR)|");
		printf("\n\t| 9 - SAIR                                  |");
		printf("\n\t|-------------------------------------------|\n\n");

	printf("\n\t> Digite a opção desejada: ");
	scanf("%d", &op);

	switch (op){
		case 1:
			valor_presente();
			break;
    case 2:
  		valor_futuro();
  		break;
		case 3:
			valor_presente_liquido();
			break;
		case 4:
			payback();
			break;
    case 5:
  		taxa_interna_retorno();
  		break;
	}
  
	while(op != 9){
		menu();
	}

}

void valor_futuro(){

float capital, i, m;
int t;
  printf("\n\nInforme o valor do capital:\n");
  scanf("%f",&capital);
  printf("Informe o total de periodos:\n");
  scanf("%d",&t);
  printf("Informe o valor da taxa (%):\n");
  scanf("%f",&i);

  m = capital*pow(1+(i/100),t);
  printf("\tAo fim de %d periodos com taxa de %.2f o valor sera R$ %.2f\n",t,i,m);
}

void valor_presente(){
  float capital, i, m;
  int t;
    printf("\n\nInforme o valor do capital:\n");
    scanf("%f",&capital);
    printf("Informe o total de periodos:\n");
    scanf("%d",&t);
    printf("Informe o valor da taxa (%):\n");
    scanf("%f",&i);

    m = (capital/pow(1+(i/100),t));
    printf("\tAo fim de %d periodos com taxa de %.2f o valor sera R$ %.2f\t\n",t,i,m);

}

void valor_presente_liquido(){
  float in, tax, m, total =0;
  int t,i;
    printf("\n\nInforme o valor do capital:\n");
    scanf("%f",&in);
    in = in * (-1);
    printf("Informe o total de periodos:\n");
    scanf("%d",&t);
    printf("Informe o valor da taxa (%):\n");
    scanf("%f",&tax);

    t = t+1;
    float fc[t];
    fc[0] = in;
    total = fc[0];
    for (i=1; i < t; i++){
      printf("Informe o valor para o periodo %d: \t\n",i);
      scanf("%f",&fc[i]);
      total = total + fc[i]/pow(1+(tax/100),i);
    }
printf("\tAo fim de %d periodos com taxa de %.2f o valor sera R$ %.2f \t\n",t-1,tax,total );

}


void payback(){
  float capital, in, m,tax,positivo,pbk;
  int t,i,p1,p2;

  float tir =0, aux=0, fluxos;

    printf("\n\nInforme o valor investimento inicial:\n");
    scanf("%f",&in);
    in = in * (-1);

    printf("Informe o valor da taxa (%): \n");
    scanf("%f",&tax);

    printf("Informe o total de periodos: \n");
    scanf("%d",&t);
    t = t+1;
    float fc[t], vpls[t], acumulados[t];
    fc[0] = in;

    vpls[0] = (fc[0]/pow(1+(tax/100),0));
    acumulados[0] = vpls[0];

    for (i=1;i<t; i++){
      printf("Informe o valor para o periodo %d: \n",i);
      scanf("%f",&fc[i]);
      vpls[i] = (fc[i]/pow(1+(tax/100),i));
    }

    for(i=0;i<t;i++){
      acumulados[i] = vpls [i] - acumulados[i-1] * (-1);
    }

    positivo = -1;

    for(i=0;i<t;i++){
      if(acumulados[i] > 0)
        positivo = i;
    }

    if (positivo != -1){
      p1 = positivo -1;
      p2 = positivo;
      pbk = ((positivo-1) + (acumulados[p1]*(-1)/vpls[p2]));
      printf("\tO PAYBACK sera de %.2f periodos.\n", pbk);
    }else
      printf("\tNao houve PAYBACK menor que %d periodos.\n",t);

}

void taxa_interna_retorno(){
  float capital, in, m;
  int t,i;

  float tir =0, aux=0, fluxos;

    printf("\n\nInforme o valor investimento inicial:\n");
    scanf("%f",&in);
    in = in * (-1);

    printf("Informe o total de periodos:\n");
    scanf("%d",&t);
    t = t+1;
    float fc[t];
    fc[0] = in;

    for (i=1;i<t; i++){
      printf("Informe o valor para o periodo %d: \n",i);
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
