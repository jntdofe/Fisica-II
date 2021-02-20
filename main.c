#include <stdio.h>
#include <math.h>

#define M_PI_180 0.01745329251994329576923690768489

void find_potential_diff();

int main(void) {
  printf(
    "\n"
    "    Trabalho de Física II\n"
    "\n"
    " Resolva o problema de uma pequena carga de massa m\n"
    " pendurada por um fio isolante que se encontra entre\n"
    " duas placas paralelas afastadas de uma distância d. Ambas,\n"
    " possuem uma densidade superficial `+sigma` e `-sigma`. A carga\n"
    " da esfera é q e a diferença de potencial é V.\n"
    "\n"
    " Escolha uma das opções abaixo para encontrar a variável incógnita,\n"
    " a partir das outras informações dadas.\n"
    "\n"
    " 0. Sair.\n"
    " 1. Encontrar a Diferença de Potencial (DDP).\n"
    " 2. Encontrar a massa da carga.\n"
    " 3. Encontrar a distância das placas paralelas.\n"
    " 4. Encontrar a carga da partícula.\n"
    " 5. Encontrar a gravidade.\n"
    " 6. Encontrar o ângulo.\n"
    "\n"
  );
  
  unsigned int opcode;

  do {

    printf(" [Entrada] > ");
    scanf("%u", &opcode);

    switch (opcode) {
      case 0:
        break;
      case 1:
        find_potential_diff();
        break;
      default:
        printf("Código de Operação Inválido.\n");
        break;
    }

  } while (opcode != 0);


  return 0;
}

/* Essa função irá requisitar da entrada padrão as informações de massa, gravidade, distância entre placas paralelas, ângulo da partícula com a vertical a carga da partícula é irá fornecer a diferença de potencial necessária para isso. */
void find_potential_diff() {
  long double mass;
  long double gravity;
  long double dist;
  long double angle;
  long double charge;
  long double pdiff;

  printf("Insira a massa da partícula (kg): ");
  scanf("%Lf", &mass);

  printf("Insira a gravidade (m/s^2): ");
  scanf("%Lf", &gravity);
  
  printf("Insira a distância entre as placas paralelas (m): ");
  scanf("%Lf", &dist);

  printf("Insira o ângulo entre a partícula e a vertical (graus): ");
  scanf("%Lf", &angle);

  printf("Insira a carga da partícula (C): ");
  scanf("%Lf", &charge);

  /* Transforma o ângulo em radianos. */
  angle *= M_PI_180;

  pdiff = mass * gravity * dist * tan(angle) / charge;

  printf(
    "\n"
    " A diferença de potencial necessária para uma partícula\n"
    " da partícula %.4Lfkg em uma gravidade local de %.4Lfm/s^2,\n"
    " uma distância entre as placas de %.4Lfm com um ângulo com\n"
    " a vertical de %.4Lf° e com carga %.4LeC será de\n"
    "\n"
    " Diferença de Potencial: %.4LfV\n"
    "\n",
    mass, gravity, dist, angle * (1.0 / M_PI_180), charge, pdiff
  );
}
