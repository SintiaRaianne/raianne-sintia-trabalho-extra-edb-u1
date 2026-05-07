#include <iostream>
#include <vector>
using namespace std;

double horner(vector<double> a, double x)
{
    int n = a.size();

    double resultado = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        resultado = resultado * x + a[i];
    }

    return resultado;
}

int main()
{
    vector<double> a;
    double coeficiente;

    cout << "Digite os coeficientes (-1 para parar):" << endl;

    while (true)
    {
        cin >> coeficiente;

        if (coeficiente == -1)
        {
            break;
        }

        a.push_back(coeficiente);
    }

    double x;

    cout << "Digite o valor de x: ";
    cin >> x;

    cout << "Resultado: " << horner(a, x) << endl;

    return 0;
}