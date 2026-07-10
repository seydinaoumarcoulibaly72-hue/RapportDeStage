#include <iostream>
 
using namespace std;
 
int main() {
    // Optimisation classique des entrées/sorties
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
 
    // On affiche simplement les nombres en ordre décroissant
    // Cela garantit que la plus longue sous-séquence croissante a une taille de 1.
    for (int i = n; i >= 1; i--) {
        cout << i << (i == 1 ? "" : " ");
    }
    cout << "\n";
 
    return 0;
}
