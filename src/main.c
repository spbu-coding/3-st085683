#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void var_double_count(char var_char) {
    double true_var_dble_t = 1.0, true_var_dble_d = 1.0, t, d, delta = 0.0001;
    int evaluate = 0;
    double var_dble_error = 0.000001;
    switch(var_char){
        case '1':
            while (evaluate < 22){
                d = (2.0001 + delta - 2.0) / 0.0001;
                t = 2.0 - d;
                fprintf(stdout, "%d\t%lf\t%lf\n", evaluate, t, d);
                evaluate++;
                delta = delta / 2.0f;
            }
            break;
        case '5':
            while (evaluate >= 0){
                delta = 0.0001;
                evaluate = 0;
                while (evaluate >= 0){
                    d = (2.0001 + delta - 2.0) / 0.0001;
                    t = 2.0 - d;
                    if (sqrt(pow(fabs(t - true_var_dble_t), 2) + pow(fabs(d - true_var_dble_d), 2)) <= var_dble_error)
                        break;
                    evaluate++;
                    delta = delta / 2.0;
                }
                printf("%d\t\t %0.20lf\n", evaluate, var_dble_error);
                var_dble_error /= 10;
            }
            break;
        default:
            while (evaluate >= 0){
                d = (2.0001 + delta - 2.0f) / 0.0001;
                t = 2.0 - d;

                if (sqrtf(powf(fabsf(t - true_var_dble_t), 2) + powf(fabsf(d - true_var_dble_d), 2)) <= 0.000001)
                    break;
                evaluate++;
                delta = delta / 2.0;
            }
            fprintf(stdout, "%d\n", evaluate > 0? evaluate : -1);
            break;
    }
}

float var_float_error(float y, float z){
    float t, d, var_float_err_y, var_float_err_z, var_float_z, var_float_y;
    t = y + z;
    var_float_err_z = t - y;
    var_float_err_y = t - var_float_err_z;
    var_float_z = z - var_float_err_z;
    var_float_y = y - var_float_err_y;
    y = var_float_y + var_float_z;
    return y;
}



void var_float_count(char var_char) {
    float true_var_dble_t = 1.0f, true_var_dble_d = 1.0f, t, d, delta = 0.0001f;
    int evaluate = 0;
    switch(var_char){
        case '1':
            while (evaluate < 22){
                t = (2.0001f + delta - 2.0f) / 0.0001f;
                d = 2.0f - d;
                fprintf(stdout, "%d\t%f\t%f\n", evaluate, t, d);
                evaluate++;
                delta = delta / 2.0f;
            }
            break;
        case '2':
            while (evaluate < 22){
                d = (2.0001f + delta - 2.0f) / 0.0001f;
                t = 2.0f - d;
                fprintf(stdout, "%d\t%.20f\t%.20f\n", evaluate, t, d);
                evaluate++;
                delta = delta / 2.0f;
            }
            break;
        case '3':
            while (evaluate < 12){
                d = (2.0001f + delta - 2.0f) / 0.0001f;
                t = 2.0f - d;
                fprintf(stdout, "%d\t%.20f\t%.20f\t%.20f\n", evaluate, 2.0001f + delta, 2.0001f + delta - 2.0f, d);
                evaluate++;
                delta = delta / 2.0f;
            }
            break;
        case '4':
            while (evaluate < 16){
                d = (2.0001f + delta - 2.0f) / 0.0001f;
                t = 2.0f - d;
                float var_dble_error = var_float_error(2.0001f, delta);
                printf("%d\t%.20f\t%.20f\t  %d\n", evaluate, fabsf(var_dble_error), delta, fabsf(var_dble_error) == delta);
                evaluate++;
                delta = delta / 2.0f;
            }
            break;
        default:
            while (evaluate >= 0){
                d = (2.0001f + delta - 2.0f) / 0.0001f;
                t = 2.0f - d;

                if (sqrtf(powf(fabsf(t - true_var_dble_t), 2) + powf(fabsf(d - true_var_dble_d), 2)) <= 0.000001f)
                    break;
                evaluate++;
                delta = delta / 2.0f;
            }
            fprintf(stdout, "%d\n", evaluate > 0? evaluate : -1);
            break;
    }
}

void calculation(char var_char){
    switch(var_char){
        case '1':
            fprintf(stdout, "evaluate\t t_double \t d_double\n\n");
            var_double_count('1');
            fprintf(stdout, "\ncount\t t_float \t d_float\n\n");
            var_float_count('1');
            break;
        case '2':
            fprintf(stdout, "evaluate\t t_float \t\t d_double\n\n");
            var_float_count('2');
            break;
        case '3':
            fprintf(stdout, "evaluate\tsum     \t\tsub     \t\tdiv\n\n");
            var_float_count('3');
            break;
        case '4':
            fprintf(stdout, "evaluate\terror\t\t\tdelta\t\t\t  equal\n\n");
            var_float_count('4');
            break;
        case '5':
            fprintf(stdout, "return evaluate\tallowable var_dble_error\n\n");
            var_double_count('5');
            break;
        default:
            fprintf(stdout, "return evaluate double \t");
            var_double_count('0');
            fprintf(stdout, "return evaluate float \t");
            var_float_count('0');
            break;
    }
}

int main(int param1, char **char_param2){
    if (param1 <= 1)
        calculation('0');
    else
        calculation(char_param2[1][0]);
    return 0 ;
}
