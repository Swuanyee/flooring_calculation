#include <stdio.h>

int choice;
float squareFoot;
float ton;
float raw_ton_without_wastage;
float raw_ton_with_wastage;
float width;
float thickness;
float l_mm;
float l_ft;
float raw_width;
float raw_thickness;
float sqmm;
char repeat_again;
float with_wastage_l_ft;
float without_wastage_l_ft;
float with_wastage_l_mm;
float without_wastage_l_mm;
float with_wastage_sqmm;
float without_wastage_sqmm;
float with_wastage_squareFoot;
float without_wastage_squareFoot;
float finished_squareFoot;
float finished_sqmm;


float calculation(int choice) {
    switch(choice) {
        case 1:
            printf("Please enter the square foot: \n");
            scanf("%f", &squareFoot);
            printf("Please enter the width in mm: \n");
            scanf("%f", &width);
            printf("Please enter the thickness in mm: \n");
            scanf("%f", &thickness);
            printf("Please enter the raw width in inches: \n");
            scanf("%f", &raw_width);
            printf("Please enter the raw thickness in inches: \n");
            scanf("%f", &raw_thickness);
            sqmm = squareFoot * 92903.04;
            l_mm = sqmm / width;
            l_ft = l_mm / 304.8;
            raw_ton_without_wastage = (l_ft * raw_width * raw_thickness) / 7200;
            raw_ton_with_wastage = 1.1 * raw_ton_without_wastage;
            ton = sqmm * thickness / 1415800000;
            printf("%f square foot is equal to %f square mm. \n", squareFoot, sqmm);
            printf("The length in mm is: %f \n", l_mm);
            printf("The length in ft is: %f \n\n", l_ft);
            printf("The raw ton required without considering wastage is: %.4f \n", raw_ton_without_wastage);
            printf("The raw ton required after considering wastage is: %.4f \n\n", raw_ton_with_wastage);
            printf("The finished ton required is: %f \n\n", ton);
            printf("Do you want to repeat the calculation? (y/n) \n");
            scanf("%s", &repeat_again);
            if (repeat_again == 'y') {
                printf("Please enter the corresponding number to the desired action: \n");
                printf("1. Convert square foot to ton. \n");
                printf("2. Convert ton to square foot. \n");
                printf("3. Exit. \n");
                scanf("%d", &choice);
                calculation(choice);
            } else {
                printf("Thank you for using the program. \n");
                return 0;
            }
            break;
        case 2:
            printf("Please enter the ton: \n");
            scanf("%f", &ton);
            printf("Please enter the width in mm: \n");
            scanf("%f", &width);
            printf("Please enter the thickness in mm: \n");
            scanf("%f", &thickness);
            printf("Please enter the raw width in inches: \n");
            scanf("%f", &raw_width);
            printf("Please enter the raw thickness in inches: \n");
            scanf("%f", &raw_thickness);
            raw_ton_with_wastage = ton / 1.1;
            raw_ton_without_wastage = ton;
            with_wastage_l_ft = (raw_ton_with_wastage * 7200) / (raw_width * raw_thickness);
            without_wastage_l_ft = (raw_ton_without_wastage * 7200) / (raw_width * raw_thickness);
            with_wastage_l_mm = with_wastage_l_ft * 304.8;
            without_wastage_l_mm = without_wastage_l_ft * 304.8;
            with_wastage_sqmm = with_wastage_l_mm * width;
            without_wastage_sqmm = without_wastage_l_mm * width;
            finished_sqmm = (ton*1415800000)/thickness;
            with_wastage_squareFoot = with_wastage_sqmm / 92903.04;
            without_wastage_squareFoot = without_wastage_sqmm / 92903.04;
            finished_squareFoot = finished_sqmm / 92903.04;

            printf("The square foot that can be secured without considering wastage is: %.0f \n", without_wastage_squareFoot);
            printf("The square foot that can be secured considering wastage is: %.0f \n\n", with_wastage_squareFoot);
            printf("The finished square foot is: %.0f \n\n", finished_squareFoot);
            printf("Do you want to repeat the calculation? (y/n) \n");
            scanf("%s", &repeat_again);
            if (repeat_again == 'y') {
                printf("Please enter the corresponding number to the desired action: \n");
                printf("1. Convert square foot to ton. \n");
                printf("2. Convert ton to square foot. \n");
                printf("3. Exit. \n");
                scanf("%d", &choice);
                calculation(choice);
            } else {
                printf("Thank you for using the program. \n");
                return 0;
            }
            break;
        case 3:
            printf("Thank you for using the program. \n");
            return 0;
        default:
            printf("Please enter the corresponding number to the desired action: \n");
            printf("1. Convert square foot to ton. \n");
            printf("2. Convert ton to square foot. \n");
            printf("3. Exit. \n");
            scanf("%d", &choice);
            calculation(choice);
            break;
    }
    return 0;
};


int main() {
    printf("Please enter the corresponding number to the desired action: \n");
    printf("1. Convert square foot to ton. \n");
    printf("2. Convert ton to square foot. \n");
    printf("3. Exit. \n");
    scanf("%d", &choice);
    calculation(choice);
}
