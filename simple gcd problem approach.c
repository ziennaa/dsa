simple gcd problem approach 

#include <stdio.h>

int main() {
    int num1, num2, gcd_val, i;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    for (i = 1; i <= num1 && i <= num2; ++i) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd_val = i;
        }
    }

    printf("GCD is: %d\n", gcd_val);

    return 0;
}


recursive
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD is: %d\n", gcd(num1, num2));

    return 0;
}

#include <stdio.h>

int main() {
    int num1, num2, remainder;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Ensure num1 is always the larger number for consistent subtraction
    if (num2 > num1) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    while (num2 != 0) {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    printf("GCD is: %d\n", num1);

    return 0;
}
