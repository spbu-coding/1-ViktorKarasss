#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define errprintf(...) fprintf(stderr, __VA_ARGS__)

double left_border, right_border;

void input(){
    printf("Insert left border: ");
    scanf("%lf", &left_border);
    printf("Insert right border: ");
    scanf("%lf", &right_border);

    if (left_border < 0 || right_border > M_PI){
        errprintf("Borders must be in [0;Pi].");
        exit(EXIT_FAILURE);
    }
    if(left_border > right_border){
        errprintf("Left border must be less than right border.");
        exit(EXIT_FAILURE);
    }
}


double calc_simpson_method(int part) {
    double result = 0;
    double step = (right_border - left_border) / part;

    for(int i = 0; i < part; i++){
        double active_left_border = left_border + step * i;
        double active_right_border = active_left_border + step;
        result += (active_right_border - active_left_border) / 6 * (sin(active_left_border) +
                4 * sin((active_left_border + active_right_border) / 2) + sin(active_right_border));
    }
    return result;
}

double calc_rectangle_method(int part){
    double result = 0;
    double step = (right_border - left_border) / part;

    for(int i = 0; i < part; i++){
        double active_left_border = left_border + step * i;
        double active_right_border = active_left_border + step;
        result += step * sin((active_left_border + active_right_border) / 2);
    }
    return result;
}

void calculate(){
    int partition[] = {6, 10, 20, 100, 500, 1000};
    int partition_size = sizeof(partition) / sizeof(partition[0]);
    for(int i = 0; i < partition_size; i++){
        printf("%d %.5lf %.5lf\n",
               partition[i], calc_rectangle_method(partition[i]), calc_simpson_method(partition[i]));
    }
}

int main() {
    input();
    calculate();
    return 0;
}
