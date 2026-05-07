#include <iostream>
#include <vector>

long long mergeAndCount(std::vector<int>& arr, int esq, int meio, int dir) {
    std::vector<int> esquerda, direita;
    for (int i = esq; i <= meio; i++) esquerda.push_back(arr[i]);
    for (int i = meio + 1; i <= dir; i++) direita.push_back(arr[i]);

    long long inversoes = 0;
    int i = 0, j = 0, k = esq;

    while (i < esquerda.size() && j < direita.size()) {
        if (esquerda[i] <= direita[j]) {
            arr[k++] = esquerda[i++];
        } else {
            arr[k++] = direita[j++];
            inversoes += (esquerda.size() - i);
        }
    }
    while (i < esquerda.size()) arr[k++] = esquerda[i++];
    while (j < direita.size()) arr[k++] = direita[j++];

    return inversoes;
}

long long contagemInversoes(std::vector<int>& arr, int esq, int dir) {
    long long cont = 0;
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        cont += contagemInversoes(arr, esq, meio);
        cont += contagemInversoes(arr, meio + 1, dir);
        cont += mergeAndCount(arr, esq, meio, dir);
    }
    return cont;
}

int main() {
    std::vector<int> A = {2, 3, 8, 6, 1};
    std::cout << "Total de inversoes: " << contagemInversoes(A, 0, A.size() - 1) << std::endl;
    return 0;
}
