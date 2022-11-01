#include <stdio.h>
#include <math.h>

void magnitude(double x1, double x2, double y1, double y2, char sign1, char sign2);        //Function declarations so int main can recognize
void phase(double x1, double x2, double y1, double y2, char sign1, char sign2);
void sum(double x1, double x2, double y1, double y2, char sign1, char sign2);
void difference(double x1, double x2, double y1, double y2, char sign1, char sign2);
void multiplication(double x1, double x2, double y1, double y2, char sign1, char sign2);
void division(double x1, double x2, double y1, double y2, char sign1, char sign2);

int main(){
    char sign1 = '+', sign2 = '+', j1, j2, repeat, discard;
    double num1, num2, x1, x2, y1, y2, phase1, phase2, sum1, diff1;
    
    do{ 
        printf("Enter first complex number");         //Prompts user to enter the 1st complex number
        scanf_s("%lf%c%c%lf",&x1,&sign1,&j1,&y1);       //Scans user input with character-type and double-type and assigns to appropriate variables
        discard = getchar();                           
        if (sign1 == '-')                             //If the user entered a negative sign for the imaginary number, change y-value to negative
            y1 = -y1;                                 //Otherwise leave positive (default)
        
        printf("Enter second complex number");       //Repeat for the 2nd complex number
        scanf_s("%lf%c%c%lf",&x2,&sign2,&j2,&y2);      
        discard = getchar(); 
        if (sign2 == '-')                            
            y2 = -y2;                                
        
        while(x1 == 0 && y1 == 0 || x2 == 0 && y2 == 0 || j1 != 'j' || j2 != 'j'){ //If x and y are 0 for the first or second number, or if the user did not enter 'j' before y:
            printf("\nIncorrect input(s). Real and imaginary numbers cannot be 0. Complex number has to include j. Reenter the numbers"); // Prompts the user to reenter a number in the right range 
            printf("\nEnter first complex number");          //This section is a repeat of earlier
            scanf_s("\n%lf%c%c%lf", &x1, &sign1, &j1, &y1);
            discard = getchar();
            printf("\nEnter second complex number");
            scanf_s("\n%lf%c%c%lf", &x2, &sign2, &j2, &y2);                                
            discard = getchar();                               
        }
        
        magnitude(x1, x2, y1, y2, sign1, sign2);             // This section calls all of the functions with the user-inputted values
        phase(x1, x2, y1, y2, sign1, sign2);
        sum(x1, x2, y1, y2, sign1, sign2);
        difference(x1, x2, y1, y2, sign1, sign2);
        multiplication(x1, x2, y1, y2, sign1, sign2);
        division(x1, x2, y1, y2, sign1, sign2);

        printf("\nPress y/Y to repeat, any other quits: ");           // Asks user if they want to repeat the program by pressing y or Y or quit
        scanf("%c", &repeat);                                         // Scans user input for y or Y or a different key
        discard = getchar();                                         
    } while (repeat=='y' || repeat=='Y');                             //If Y or y entered, repeat the do section
}

void magnitude(double x1, double x2, double y1, double y2, char sign1, char sign2){                //Function definitions below:
    double mag1, mag2;
    char j = 'j';
    
    mag1 = sqrt(pow(x1, 2) + pow(y1, 2));  //algorithm for magnitude
    mag2 = sqrt(pow(x2, 2) + pow(y2, 2));
    y1 = abs(y1);                          //If the y-values are not set to their absolute value, the output would be -j-y instead of the desired -jy
    y2 = abs(y2);

    printf("\nMagnitude of (%.1lf%c%c%.1lf) = %.2lf", x1, sign1, j, y1, mag1);
    printf("\nMagnitude of (%.1lf%c%c%.1lf) = %.2lf", x2, sign2, j, y2, mag2);
}

void phase(double x1, double x2, double y1, double y2, char sign1, char sign2){
    double phase1, phase2;
    char j = 'j';

    if(y1>0 && x1==0)            //special case if first complex number x is 0 and y is greater than 0
        phase1 = +(3.14159265)/2;
    else if(y1<0 && x1==0)       //special case if first complex number x is 0 and y is less than 0
        phase1 = -(3.14159265)/2;
    else                         //If no special case, use algorithm to calculate magnitude
        phase1 = atan(y1/x1)*(180/3.14159265); 
    if(y2>0 && x2==0)           //repeats previous section for second complex number
        phase2 = +(3.14159265)/2;
    else if(y2<0 && x2==0)
        phase2 = -(3.14159265)/2;
    else
        phase2 = atan(y2/x2)*(180/3.14159265);
    y1 = abs(y1);
    y2 = abs(y2);

    printf("\nPhase of (%.1lf%c%c%.1lf) = %.2lf°", x1, sign1, j, y1, phase1);  
    printf("\nPhase of (%.1lf%c%c%.1lf) = %.2lf°", x2, sign2, j, y2, phase2); 
}

void sum(double x1, double x2, double y1, double y2, char sign1, char sign2){
    double sum1, sum2;
    char sumSign = '+', j = 'j'; 
    
    sum1 = x1 + x2;         //Algorithms for sum of x's and y's
    sum2 = y1 + y2;
    if(sum2<0)              //if the sum of the y-values are less than 0 change sign to negative. Otherwise leave positive (default)
        sumSign = '-';     
    sum2 = abs(sum2);      //If the imaginary-values are not set to their absolute value, the output would be -j-y instead of the desired -jy
    y1 = abs(y1);          
    y2=abs(y2);

    printf("\nSum: (%.1lf%c%c%.1lf) + (%.1lf%c%c%.1lf) = %.2lf%c%c%.2lf", x1, sign1, j, y1, x2, sign2, j, y2, sum1, sumSign, j, sum2);
}

void difference(double x1, double x2, double y1, double y2, char sign1, char sign2){
    double diff1, diff2;
    char diffSign = '+', j= 'j';
    
    diff1 = (x1 - x2);         //Algorithms for difference of x's
    diff2 = (y1 - y2);         //Algorithms for difference of y's 
    if(diff2<0)
        diffSign = '-'; 
    diff2 = abs(diff2);
    y1 = abs(y1);
    y2=abs(y2);
    
    printf("\nDifference: (%.1lf%c%c%.1lf) - (%.1lf%c%c%.1lf) = %.2lf%c%c%.2lf", x1, sign1, j, y1, x2, sign2, j, y2, diff1, diffSign, j, diff2);
}

void multiplication(double x1, double x2, double y1, double y2, char sign1, char sign2){
    double product1, product2;
    char multSign = '+', j = 'j';  
    
    product1 = (x1*x2-y1*y2);      //Algorithm for multiplication of x's and y's = real value
    product2 = (x1*y2+x2*y1);      //Algorithm for multiplication of x's and y's = imaginary value
    if(product2<0)                 
        multSign = '-';
    product2 = abs(product2);
    y1 = abs(y1);
    y2=abs(y2);
    
    printf("\nMultiplication: (%.1lf%c%c%.1lf) * (%.1lf%c%c%.1lf) = %.2lf%c%c%.2lf", x1, sign1, j, y1, x2, sign2, j, y2, product1, multSign, j, product2);
}

void division(double x1, double x2, double y1, double y2, char sign1, char sign2){
    double division1, division2, denominator1;
    char divSign = '+', j = 'j';
    
    denominator1 = pow(x2,2)+pow(y2,2);      //Denominator to calculate real and imaginary value of division
    division1 = (x1*x2+y1*y2)/denominator1;  //Algorithm for division of x's and y's = real value
    division2 = (x2*y1-x1*y2)/denominator1;  //Algorithm for division of x's and y's = imaginary
    if(division2<0)
        divSign = '-';
    division2 = abs(division2);
    y1 = abs(y1);
    y2 = abs(y2);
    
    printf("\nDivision: (%.1lf%c%c%.1lf) / (%.1lf%c%c%.1lf) = %.2lf%c%c%.2lf", x1, sign1, j, y1, x2, sign2, j, y2, division1, divSign, j, division2);
}
