#include <stdio.h>
#include <math.h>

double left_border, right_border;
int partition[] = {6, 10, 20, 100, 500, 1000};
int partition_size = sizeof(partition) / sizeof(partition[0]);

void input(){
    printf("Insert left border: ");
    scanf("%lf", &left_border);
    printf("Insert right border: ");
    scanf("%lf", &right_border);


}

double simpson_method(int part) {
    double result = 0;
    double step = (right_border - left_border) / part;

    for(int i = 0; i < part; i++){
        double active_left_border = left_border + step * i;
        double active_right_border = active_left_border + step;
        result += (active_right_border - active_left_border) / 6 * (sin(active_left_border) + 4 * sin((active_left_border + active_right_border) / 2) + sin(active_right_border));
    }
    return result;
}

double rectangle_method(int part){
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
    for(int i = 0; i < partition_size; i++){
        printf("%d %.5lf %.5lf\n",partition[i],rectangle_method(partition[i]),simpson_method(partition[i]));
    }
}

int main() {
    input();
    calculate();
    return 0;
}
