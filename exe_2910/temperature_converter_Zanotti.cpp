#include <iostream>
#include <iomanip>  // to use setprecision()

using namespace std;

int main(){
    const int min_temperature = 0;
    const int max_temperature = 50000;

    float start_temperature, end_temperature, step, difference_temp, temp_celsius, temp_fahrenheit;
    int i = 0;

    cout << "     *****************************************" << endl;
    cout << "      Developed by Paolo Zanotti @ UniBg 2020 " << endl;
    cout << "     *****************************************" << endl;
    cout << endl;

    // Start temperature input validation
    do{
        cout << " # Insert the start temperature (" << min_temperature << " <= start < " << 
            max_temperature << "): " ; cin >> start_temperature;
        
        if(start_temperature < min_temperature || start_temperature >= max_temperature)
            cout << "     [x] Wrong temperature, try again...\n" << endl;

    }while(start_temperature < min_temperature || start_temperature >= max_temperature);

    // start_temperature can't be changed during the execution, so I work on temp_celsius
    temp_celsius = start_temperature;

    cout << endl;

    // End temperature input validation
    do{
        cout << " # Insert the end temperature (" << start_temperature << " < end <= " << 
            max_temperature << "): " ; cin >> end_temperature;

        if(end_temperature > max_temperature || end_temperature <= start_temperature)
            cout << "     [x] Wrong temperature, try again...\n" << endl;

    }while(end_temperature > max_temperature || end_temperature <= start_temperature);

    difference_temp = end_temperature - start_temperature;

    cout << endl;

    // Step size input validation
    do{
        cout << " # Insert the step size (0 < step <= " << difference_temp << "): " ; cin >> step;

        if(step > difference_temp || step <= 0)
            cout << "     [x] Wrong step size, try again...\n" << endl;
            
    }while(step > difference_temp || step <= 0);

    cout << endl;
    cout << endl;

    cout << "   +--------------------------------+" << endl;
    cout << "   |  CELSIUS     |     FAHRENHEIT  |" << endl;
    cout << "   +--------------------------------+" << endl;
    cout << endl;

    // Convert temperature from celsius to fahrenheit and print the values
    while(temp_celsius <= end_temperature){
        temp_fahrenheit = temp_celsius * 1.8 + 32;

        cout << i + 1<< ".    " << fixed << setprecision(5) << temp_celsius << "          " << 
            fixed << setprecision(5) << temp_fahrenheit << endl;

        temp_celsius += step;

        i++;
    }
    
    return 0;
}