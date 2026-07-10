#include <iostream>
#include <vector>
 
using namespace std;
 
// On définit "l'infini" avec une valeur très grande (2 * 10^18)
// Cela permet d'éviter les dépassements de mémoire (overflow) même avec des poids négatifs.
const long long INF = 2e18; 
 
// Une structure simple pour stocker nos arêtes
struct Edge {
    int u, v;
    long long w;
};
 
int main() {
    // Optimisation indispensable des entrées/sorties
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;
 
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
 
    // Tableau des distances initialisé à l'infini
    vector<long long> dist(n + 1, INF);
    dist[s] = 0; // La distance vers le point de départ est 0
 
    // Algorithme de Bellman-Ford (n - 1 itérations)
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        
        for (const auto& edge : edges) {
            // Si le sommet 'u' est accessible depuis 's' et qu'on trouve un chemin plus court vers 'v'
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                updated = true;
            }
        }
        
        // Optimisation : si aucun chemin n'a été amélioré durant cette boucle,
        // c'est qu'on a déjà trouvé le résultat final. Inutile de continuer.
        if (!updated) break; 
    }
 
    // Détection du cycle négatif (la n-ième itération)
    for (const auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
            // Si on peut encore améliorer un chemin, il y a un cycle négatif accessible
            cout << "Negative cycle\n";
            return 0; // On arrête l'exécution ici, comme demandé par l'énoncé
        }
    }
 
    // Affichage des distances finales
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "inf ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << "\n";
 
    return 0;
}
