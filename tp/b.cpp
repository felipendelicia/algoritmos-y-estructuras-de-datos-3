#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int exitosas = 0;  // Cantidad de formas que llegan al objetivo
int total = 0;     // Cantidad total de combinaciones posibles

// Calcula la posición final que se debería alcanzar
int calcularObjetivo(const string& s1) {
    int pos = 0;
    for (char c : s1) {
        if (c == '+') pos++;
        else pos--;
    }
    return pos;
}

void backtrack(const string& s2, int idx, int actual, int objetivo) {
    if (idx == s2.size()) {
        if (actual == objetivo) exitosas++;
        total++;
        return;
    }

    if (s2[idx] == '+') {
        backtrack(s2, idx + 1, actual + 1, objetivo);
    } else if (s2[idx] == '-') {
        backtrack(s2, idx + 1, actual - 1, objetivo);
    } else { // '?'
        backtrack(s2, idx + 1, actual + 1, objetivo);
        backtrack(s2, idx + 1, actual - 1, objetivo);
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int objetivo = calcularObjetivo(s1);

    backtrack(s2, 0, 0, objetivo);

    cout << fixed << setprecision(12) << (double)exitosas / total << endl;

    return 0;
}
