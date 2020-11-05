#include <stdio.h>
#include <string.h>

#define LOWER_LIMIT 0
#define HIGHER_LIMIT 50000

float celToFahr (double cel, int limit_high, int step) {
    double fahr;
    while(cel <= limit_high) {
        fahr = (9.0 * cel) / 5.0 + 32.0;
        printf("%.2f\t\t%.2f\n", cel, fahr);
        cel += step;
    }
    return 0;
}

float fahrToCel (double fahr, int limit_high, int step) {
    double cel;
    while(fahr <= limit_high) {
        cel = (fahr - 32.0) * 5.0 / 9.0;
        printf("%.2f\t\t%.2f\n", fahr, cel);
        fahr += step;
    }
    return 0;
}

int main() {
    int limit_low = -1, limit_high = -1;
    int step, max_step_size;
    char choice[5];

    printf("Please select your temperature type (cel or fahr): ");
    scanf("%s", &choice);

    while(limit_low < (int) LOWER_LIMIT) {
        printf("Please give in a lower limit, limit >= %d: ", (int) LOWER_LIMIT);
        scanf("%d", &limit_low);
    }
    while((limit_high <= limit_low) || (limit_high > (int) HIGHER_LIMIT)) {
        printf("Please give in a higher limit, %d < limit <= %d: ", limit_low, (int) HIGHER_LIMIT);
        scanf("%d", &limit_high);
    }
    max_step_size = limit_high - limit_low;
    while((step <= 0) || (step > max_step_size)) {
        printf("Please give in a step, 0 < step >= %d: ", max_step_size);
        scanf("%d", &step);
    }


    if (strcmp(choice, "cel") == 0) {
        printf("\nCelsius\t\tFahrenheit");
        printf("\n-------\t\t----------\n");
        celToFahr (limit_low, limit_high, step);
    }

    else {
        printf("\nFahrenheit\tCelsius");
        printf("\n----------\t-------\n");
        fahrToCel (limit_low, limit_high, step);
    }

    printf("\n");

    return 0;
}










