#include <iostream>
#include <vector>
#include <algorithm> // Indispensable pour utiliser std::reverse
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    // On lit la taille du tableau
    if (!(cin >> n)) return 0; 
 
    // On crée un vecteur (un tableau dynamique) de taille n
    vector<int> a(n);
    
    // On remplit le vecteur avec les données de l'énoncé
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int l, r;
    // On lit les requêtes en boucle
    while (cin >> l >> r) {
        // Condition d'arrêt de l'énoncé : si on reçoit 0 et 0, on stoppe tout
        if (l == 0 && r == 0) {
            break; 
        }
        
        // On applique l'inversion sur la bonne portion (attention au l-1 et r)
        std::reverse(a.begin() + l - 1, a.begin() + r);
    }
 
    // On affiche le tableau final, avec des espaces entre les nombres
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
 
    return 0;
}
