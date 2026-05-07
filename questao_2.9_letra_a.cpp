#include <iostream>
#include <vector>
using namespace std;

double polinomio(vector<double> a, double x)
{
    int n = a.size();
    double resultado = 0;

    for (int i = 0; i < n; i++)
    {
        double potencia = 1;

        // calcula x^i
        for (int j = 0; j < i; j++)
        {
            potencia *= x;
        }

        resultado += a[i] * potencia;
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

    cout << "Resultado: " << polinomio(a, x) << endl;

    return 0;
}
