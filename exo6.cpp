#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main() {
    // Optimisation indispensable des entrées/sorties
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
 
    // Création de la liste d'adjacence.
    // On utilise n + 1 pour que les sommets soient directement indexés de 1 à n.
    vector<vector<int>> adj(n + 1);
    
    // Lecture minutieuse des m arêtes
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // u est connecté à v
        adj[v].push_back(u); // v est connecté à u (le graphe est non orienté)
    }
 
    // Tableau pour stocker les distances. 
    // On l'initialise entièrement à -1. Ainsi, si un sommet est inaccessible, 
    // il gardera la valeur -1 demandée par l'énoncé.
    vector<int> dist(n + 1, -1);
    
    // File (queue) utilisée pour le BFS
    queue<int> q;
 
    // Le point de départ est le sommet k. La distance vers lui-même est 0.
    dist[k] = 0;
    q.push(k);
 
    // Début du Parcours en Largeur (BFS)
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        // On parcourt tous les voisins du sommet actuel 'u'
        for (int v : adj[u]) {
            // Si le voisin 'v' n'a pas encore été visité (distance == -1)
            if (dist[v] == -1) {
                // Sa distance est celle du sommet précédent + 1
                dist[v] = dist[u] + 1;
                // On l'ajoute dans la file pour explorer ses propres voisins plus tard
                q.push(v);
            }
        }
    }
 
    // Affichage de la distance de chaque sommet (de 1 à n)
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
 
    return 0;
}
