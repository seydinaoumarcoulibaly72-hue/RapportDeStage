#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort
 
using namespace std;
 
int main() {
    // Optimisation des entrées/sorties pour la vitesse
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
 
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
 
    // 1. On trie le jeu de cartes par ordre croissant
    sort(c.begin(), c.end());
 
    // 2. On vérifie si les nombres se suivent strictement
    bool is_good = true;
    for (int i = 1; i < n; i++) {
        // Si la carte actuelle n'est pas égale à la carte précédente + 1, le jeu est truqué
        if (c[i] != c[i - 1] + 1) {
            is_good = false;
            break; // Inutile de vérifier le reste, on a trouvé une erreur
        }
    }
 
    // 3. Affichage du résultat exactement comme demandé
    if (is_good) {
        cout << "Deck looks good\n";
    } else {
        cout << "Scammed\n";
    }
 
    return 0;
}
