#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct punto{
    float x,y;
};

int main(){
    punto p1, p2, p3;
    float lato_ab, lato_bc, lato_ac;
    float perimetro;

    cout << "Primo punto" << endl;
    cout << "Inserisci la coordinata x: "; cin >> p1.x;
    cout << "Inserisci la coordinata y: "; cin >> p1.y;
   
    cout << endl;

    cout << "Secondo punto" << endl;
    cout << "Inserisci la coordinata x: "; cin >> p2.x;
    cout << "Inserisci la coordinata y: "; cin >> p2.y;

    cout << endl;

    cout << "Terzo punto" << endl;
    cout << "Inserisci la coordinata x: "; cin >> p3.x;
    cout << "Inserisci la coordinata y: "; cin >> p3.y;

    //Side calculation
    lato_ab = sqrt(((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y))); 
    lato_ac = sqrt(((p1.x-p3.x) * (p1.x-p3.x) + (p1.y-p3.y) * (p1.y-p3.y)));
    lato_bc = sqrt(((p2.x-p3.x) * (p2.x-p3.x) + (p2.y-p3.y) * (p2.y-p3.y)));

    // Check degenerate triangle
    if(!(lato_ab < lato_ac + lato_bc && lato_ac < lato_ab + lato_bc && lato_bc < lato_ab + lato_ac))
        cout << "\nTriangolo degenere\n" << endl;
    else{

        // Check equilateral triangle
        if(lato_ab == lato_ac && lato_ac == lato_bc)
            cout << "\nTriangolo equilatero";

        // Check isosceles triangle
        else if ((lato_ab == lato_ac) || (lato_ab == lato_bc) || (lato_ac == lato_bc))
            cout << "\nTriangolo isoscele";

        // Check scalene triangle
        else
            cout << "\nTriangolo scaleno";
        
        // Check right triangle
        if ((lato_ab*lato_ab == lato_ac*lato_ac+lato_bc*lato_bc) ||
         (lato_ac*lato_ac == lato_ab*lato_ab+lato_bc*lato_bc) ||
         (lato_bc*lato_bc == lato_ab*lato_ab+lato_ac*lato_ac))
            cout << " - Triangolo rettangolo";
    }

    perimetro = lato_ab + lato_bc + lato_ac;
    cout << "\nIl perimetro è: " << setw(5) <<  setprecision(4) << perimetro << endl;

    return 0;
}