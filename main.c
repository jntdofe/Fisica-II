#include <stdio.h>
#include <math.h>

#define M_PI_180 0.01745329251994329576923690768489 /* (M_PI / 180.0) */
#define M_1_PI_180 57.295779513082320876798154814105 /* (180.0 / M_PI) */

void find_potential_diff();
void find_particle_mass();
void find_distance();
void find_particle_charge();
void find_gravity();
void find_angle();

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
    " 2. Encontrar a massa da partícula.\n"
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
      case 2:
        find_particle_mass();
        break;
      case 3:
        find_distance();
        break;
      case 4:
        find_particle_charge();
        break;
      case 5:
        find_gravity();
        break;
      case 6:
        find_angle();
        break;
      default:
        printf("Código de Operação Inválido.\n");
        break;
    }

  } while (opcode != 0);

  return 0;
}

/* Essa função irá requisitar da entrada padrão as informações de massa, gravidade, distância entre placas paralelas, ângulo da partícula com a vertical a carga da partícula e irá fornecer a diferença de potencial necessária para isso. */
void find_potential_diff() {
  long double mass;
  long double gravity;
  long double dist;
  long double angle;
  long double charge;
  long double pdiff;

  printf("Insira a massa da partícula (kg): ");
  scanf("%Lf", &mass);

  if (mass < 0) {
      printf("Você não pode inserir uma massa negativa.\n");
      return;
  }

  printf("Insira a gravidade (m/s^2): ");
  scanf("%Lf", &gravity);

  if (gravity < 0) { 
    printf("Você não pode inserir uma gravidade negativa");
    return;
  }

  printf("Insira a distância entre as placas paralelas (m): ");
  scanf("%Lf", &dist);

  if (dist < 0) {
    printf("Você não pode colocar uma distância entre as placas paralelas negativa.");
    return;
  }

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
    " de massa %.4Lfkg em uma gravidade local de %.4Lfm/s^2,\n"
    " uma distância entre as placas de %.4Lfm com um ângulo com\n"
    " a vertical de %.4Lf° e com carga %.4LeC será de\n"
    "\n"
    " Diferença de Potencial: %.4LfV\n"
    "\n",
    mass, gravity, dist, angle * M_1_PI_180, charge, pdiff
  );
}

/* Essa função irá requisitar da entrada padrão as informações de gravidade, distância entre placas paralelas, ângulo da partícula com a vertical, carga da partícula e diferença de potencal e irá fornecer a massa da partícula para isso. */
void find_particle_mass() {
  long double gravity;
  long double dist;
  long double angle;
  long double charge;
  long double pdiff;
  long double mass;

  printf("Insira a gravidade (m/s^2): ");
  scanf("%Lf", &gravity);

  if (gravity < 0) { 
    printf("Você não pode inserir uma gravidade negativa");
    return;
  }

  printf("Insira a distância entre as placas paralelas (m): ");
  scanf("%Lf", &dist);

  if (dist < 0) {
    printf("Você não pode colocar uma distância entre as placas paralelas negativa.");
    return;
  }

  printf("Insira o ângulo entre a partícula e a vertical (graus): ");
  scanf("%Lf", &angle);

  printf("Insira a carga da partícula (C): ");
  scanf("%Lf", &charge);
  
  printf("Insira a diferença de potencial (V): ");
  scanf("%Lf", &pdiff);

  /* Transforma o ângulo em radianos. */
  angle *= M_PI_180;

  mass = charge * pdiff / (gravity * dist * tan(angle));
  
  printf(
    "\n"
    " A massa da partícula necessária para uma gravidade\n"
    " local de %.4Lfm/s^2, uma distância entre as placas de %.4Lfm\n"
    " com um ângulo com a vertical de %.4Lf°, com carga %.4LeC e com\n"
    " uma diferença de potencial de %.4Lf será de \n"
    "\n"
    " Massa da Partícula: %.4Lfkg\n"
    "\n",
    gravity, dist, angle * M_1_PI_180, charge, pdiff, mass
  );
}

/* Essa função irá requisitar da entrada padrão as informações de massa da partícula, gravidade, ângulo da partícula com a vertical, carga da partícula e diferença de potencal e irá fornecer a distância entre as placas paralelas para isso. */
void find_distance() {
  long double mass;
  long double gravity;
  long double angle;
  long double charge;
  long double pdiff;
  long double dist;

  printf("Insira a massa da partícula (kg): ");
  scanf("%Lf", &mass);

  if (mass < 0) {
      printf("Você não pode inserir uma massa negativa.\n");
      return;
  }

  printf("Insira a gravidade (m/s^2): ");
  scanf("%Lf", &gravity);

  if (gravity < 0) { 
    printf("Você não pode inserir uma gravidade negativa");
    return;
  }
  
  printf("Insira o ângulo entre a partícula e a vertical (graus): ");
  scanf("%Lf", &angle);

  printf("Insira a carga da partícula (C): ");
  scanf("%Lf", &charge);
    
  printf("Insira a diferença de potencial (V): ");
  scanf("%Lf", &pdiff);

  /* Transforma o ângulo em radianos. */
  angle *= M_PI_180;

  dist = charge * pdiff / (gravity * mass * tan(angle));

  printf(
    "\n"
    " A distância das placas paralelas necessária para uma partícula\n"
    " de massa %.4Lfkg, gravidade local de %.4Lfm/s^2, ângulo com a vertical\n"
    " de %.4Lf°, com carga %.4LeC e com uma diferença de potencial %.4LfV será de\n"
    "\n"
    " Distância entre as placas paralelas: %.4Lfm\n"
    "\n",
    mass, gravity, angle * M_1_PI_180, charge, pdiff, dist    
  );
}

/* Essa função irá requisitar da entrada padrão as informações de massa da partícula, gravidade, ângulo da partícula com a vertical, distância entre as placas paralelas e diferença de potencal e irá fornecer a carga da partícula para isso. */
void find_particle_charge() {
  long double mass;
  long double gravity;
  long double dist;
  long double angle;
  long double pdiff;
  long double charge;

  printf("Insira a massa da partícula (kg): ");
  scanf("%Lf", &mass);

  if (mass < 0) {
      printf("Você não pode inserir uma massa negativa.\n");
      return;
  }

  printf("Insira a gravidade (m/s^2): ");
  scanf("%Lf", &gravity);

  if (gravity < 0) { 
    printf("Você não pode inserir uma gravidade negativa");
    return;
  }
  
  printf("Insira o ângulo entre a partícula e a vertical (graus): ");
  scanf("%Lf", &angle);

  printf("Insira a distância entre as placas paralelas (m): ");
  scanf("%Lf", &dist);

  if (dist < 0) {
    printf("Você não pode colocar uma distância entre as placas paralelas negativa.");
    return;
  }

  printf("Insira a diferença de potencial (V): ");
  scanf("%Lf", &pdiff);

  /* Transforma o ângulo em radianos. */
  angle *= M_PI_180;

  charge = mass * gravity * dist * tan(angle) / pdiff;

  printf(
    "\n"
    " A carga da partícula necessária para uma partícula de massa\n"
    " %.4Lfkg, gravidade local de %.4Lfm/s^2, angulo com a vertical %.4Lf°,\n"
    " distância entre as placas paralelas de %.4Lfm e com uma diferença de\n"
    " potencial de %.4LfV será de\n"
    "\n"
    " Carga da Partícula: %.4LeC"
    "\n",
    mass, gravity, angle * M_1_PI_180, dist, pdiff, charge
  );

}

/* Essa função irá requisitar da entrada padrão as informações de massa da partícula, carga da partícula, ângulo da partícula com a vertical, distância entre as placas paralelas e diferença de potencal e irá fornecer a gravidade local para isso. */
void find_gravity() {
  long double mass;
  long double dist;
  long double angle;
  long double charge;
  long double pdiff;
  long double gravity;

  printf("Insira a massa da partícula (kg): ");
  scanf("%Lf", &mass);

  if (mass < 0) {
      printf("Você não pode inserir uma massa negativa.\n");
      return;
  }

  printf("Insira o ângulo entre a partícula e a vertical (graus): ");
  scanf("%Lf", &angle);

  printf("Insira a distância entre as placas paralelas (m): ");
  scanf("%Lf", &dist);

  if (dist < 0) {
    printf("Você não pode colocar uma distância entre as placas paralelas negativa.");
    return;
  }

  printf("Insira a carga da partícula (C): ");
  scanf("%Lf", &charge);

  printf("Insira a diferença de potencial (V): ");
  scanf("%Lf", &pdiff);

  /* Transforma o ângulo em radianos. */
  angle *= M_PI_180;

  gravity = charge * pdiff / (mass * dist * tan(angle));

  printf(
    "\n"
    " A gravidade local necessária para uma partícula de massa\n"
    " %.4Lfkg, angulo com a vertical %.4Lf°, distância entre as placas\n"
    " paralelas de %.4Lfm, com uma carga de %.4LeC e diferença de potencial\n"
    " de %.4LfV será de\n"
    "\n"
    " Gravidade Local: %.4Lfm/s^2"
    "\n",
    mass, angle * M_1_PI_180, dist, charge, pdiff, gravity
  );
}

/* Essa função irá requisitar da entrada padrão as informações de massa da partícula, gravidade, carga da partícula, distância entre as placas paralelas e diferença de potencal e irá fornecer a ângulo da partícula com a vertical para isso. */
void find_angle() {
  long double mass;
  long double gravity;
  long double dist;
  long double charge;
  long double pdiff;
  long double angle;

  printf("Insira a massa da partícula (kg): ");
  scanf("%Lf", &mass);

  if (mass < 0) {
      printf("Você não pode inserir uma massa negativa.\n");
      return;
  }

  printf("Insira a gravidade (m/s^2): ");
  scanf("%Lf", &gravity);

  if (gravity < 0) { 
    printf("Você não pode inserir uma gravidade negativa");
    return;
  }

  printf("Insira a distância entre as placas paralelas (m): ");
  scanf("%Lf", &dist);

  if (dist < 0) {
    printf("Você não pode colocar uma distância entre as placas paralelas negativa.");
    return;
  }

  printf("Insira a carga da partícula (C): ");
  scanf("%Lf", &charge);

  printf("Insira a diferença de potencial (V): ");
  scanf("%Lf", &pdiff);

  angle = atan((charge * pdiff) / (mass * gravity * dist));

  printf(
    "\n"
    " O ângulo necessário para uma partícula de massa %.4Lfkg\n"
    " em uma gravidade de %.4Lfm/s^2, distância entre as placas paralelas\n"
    " de %.4Lfm, com uma carga de %.4LeC e diferença de potencial %.4LfV\n"
    " será de\n"
    "\n"
    " Ângulo: %.4Lf°\n"
    "\n",
    mass, gravity, dist, charge, pdiff, angle * M_1_PI_180
  );
}