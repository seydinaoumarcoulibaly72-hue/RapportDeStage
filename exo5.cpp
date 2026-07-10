#include <iostream>
#include <vector>
#include <numeric> // Indispensable pour la fonction std::gcd
 
using namespace std;
 
int main() {
    // Optimisation de la lecture pour les plateformes de compétition
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
 
    // Utilisation de long long pour éviter le débordement
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
 
    // Le PPCM initial est simplement la période de la première planète
    long long ans = t[0];
 
    // On calcule le PPCM cumulé avec le reste des planètes
    for (int i = 1; i < n; i++) {
        // Formule sécurisée : (a / PGCD(a,b)) * b
        ans = (ans / std::gcd(ans, t[i])) * t[i];
    }
 
    // Affichage du résultat final
    cout << ans << "\n";
 
    return 0;
}
