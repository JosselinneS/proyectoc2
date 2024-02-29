#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot_i.h"

#define MAX_INPUT_LENGTH 100

// Funciones de cálculo de las ecuaciones
double k(double x, double a, double b, double c) {
    return a * pow(x, 2) + b * x + c;
}

double p(double z, double d, double e, double f) {
    return d * pow(z, 2) + e * z + f;
}

int main() {
    double a, b, c, d, e, f, error_usuario;
    double g, h, i, discriminante, x1, x2;
    char input[MAX_INPUT_LENGTH];

    printf("Ingrese a: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    a = atof(input);

    printf("Ingrese b: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    b = atof(input);

    printf("Ingrese c: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    c = atof(input);

    printf("Ingrese d: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    d = atof(input);

    printf("Ingrese e: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    e = atof(input);

    printf("Ingrese f: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    f = atof(input);

    printf("Ingrese un porcentaje de error: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    error_usuario = atof(input);

    if (error_usuario >= 0 && error_usuario <= 100) {
        g = a - d;
        h = b - e;
        i = c - f;
        discriminante = pow(h, 2) - 4 * g * i;

        if (discriminante == 0) {
            if (h != 0) {
                x1 = -i / h;
                // Código para encontrar los subdominios y graficarlos
            } else {
                printf("No hay intersección\n");
            }
        } else if (discriminante > 0) {
            // Código para encontrar los subdominios y graficarlos
        } else {
            printf("No hay intersección\n");
        }

        // Inicializar gnuplot
        gnuplot_ctrl *h1;
        h1 = gnuplot_init();
        gnuplot_cmd(h1, "set xrange [-30:30]");
        gnuplot_cmd(h1, "set yrange [-30:30]");
        gnuplot_cmd(h1, "plot NaN title ''");

        // Graficar las ecuaciones
        double x, z;
        for (x = -100; x <= 50 + M_PI; x += 0.01) {
            gnuplot_cmd(h1, "set object circle at %lf,%lf size 0.1 fillcolor 'blue' lw 1", x, k(x, a, b, c));
        }
        for (z = -100; z <= 50 + M_PI; z += 0.01) {
            gnuplot_cmd(h1, "set object circle at %lf,%lf size 0.1 fillcolor 'red' lw 1", z, p(z, d, e, f));
        }

        // Refrescar el gráfico
        gnuplot_cmd(h1, "replot");
        getchar(); // Espera la entrada del usuario para cerrar gnuplot
        gnuplot_close(h1);
    } else {
        printf("El porcentaje está fuera del rango, debe ser entre 0 y 100\n");
    }

    return 0;
}
