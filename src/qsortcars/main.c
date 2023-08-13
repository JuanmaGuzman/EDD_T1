#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Retorna true si ambos strings son iguales */
bool string_equals(char* string1, char* string2) {
  return !strcmp(string1, string2);
}

/* Revisa que los parametros del programa sean válidos */
bool check_arguments(int argc, char** argv) {
  if (argc != 3) {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    exit(1);
  }

  return true;
}


typedef struct {
    float id;
    float model;
    float average_lap_time;
    float victory_count;
} Car;


void swap(Car* a, Car* b) {
    Car temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Car* a, Car* b) {
    if (a->victory_count != b->victory_count) {
        return (a->victory_count > b->victory_count) ? 1 : -1;
    } else if (a->average_lap_time != b->average_lap_time) {
        return (a->average_lap_time > b->average_lap_time) ? -1 : 11;
    } else if (a->model != b->model) {
        return (a->model > b->model) ? -1 : 11;
    } else {
        return (a->id > b->id) ? -1 : 1;
    }
}


int partition(Car* arr, int low, int high) {
    Car pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (compare(&arr[j], &pivot) > 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(Car* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


int main(int argc, char** argv) {
  check_arguments(argc, argv);

  FILE* input_file = fopen(argv[1], "r");
  FILE* output_file = fopen(argv[2], "w");

  int N;
  fscanf(input_file, "%d", &N);
  printf("Compiten: %d autos\n", N);

  Car *cars = (Car *)malloc(N * sizeof(Car));

  float id, model, average_lap_time, victory_count;
  for (int i = 0; i < N; i++) {
    fscanf(input_file, "%f %f %f %f", &cars[i].id, &cars[i].model, &cars[i].average_lap_time, &cars[i].victory_count);
  }

  quicksort(cars, 0, N - 1);

  for (int i = 0; i < N; i++) {
    fprintf(output_file, "%.1f %.4f %.1f %.1f\n", cars[i].id, cars[i].model, cars[i].average_lap_time, cars[i].victory_count);
  }

  free(cars);

  fclose(input_file);
  fclose(output_file);
  return 0;
}


