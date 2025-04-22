// Asks the user to input weight (in pounds) and height (in inches)
// Prints the weight status

#include <iostream>
using namespace std;

int main()
{
    double weight, height;
    double BMI;

    cout << "Please enter weight in pounds: ";
    cin >> weight;
    weight = weight * 0.453592;

    cout << "Please enter height in inches: ";
    cin >> height;
    height = height * 0.0254; 
    
    BMI = weight / (height * height);

    if (BMI < 18.5)
        cout << "The weight status is: Underweight \n";
    else if ((BMI >= 18.5) && (BMI <= 25))
        cout << "The weight status is: Normal \n";
    else if ((BMI >= 25) && (BMI <= 30))
        cout << "The weight status is: Overweight \n";
    else if (BMI >= 30)
        cout << "The weight status is: Obese \n";
    return 0;
}