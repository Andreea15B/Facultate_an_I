## B1
# (Las Vegas) Scrieti o functie care implementeaza algoritmul aleator Quick Sort. Functia va avea multimnea S ca 
# singur parametru (dat ca vector).

quicksort = function(S)
{
  if(length(S) > 1)
  {
    x = sample(1:length(S), 1);
    pivot = S[x];
    li = 1;
    ls = length(S);
    while(li <= ls)
    {
      while(S[li] < pivot) li = li + 1;
      while(S[ls] > pivot) ls = ls - 1;
      if(li <= ls)
      {
        aux = S[li];
        S[li] = S[ls];
        S[ls] = aux;
        li = li + 1;
        ls = ls - 1;
      }
    }
    return (c(quicksort(S[S<pivot]), pivot, quicksort(S[S>pivot])));
  }
  return (S);
}

x = c(10, 5, -8, 2, 12, 20, 1, -3)
quicksort(x)

## B2
# (Monte Carlo) Scrieti o functie care sa implementeze algoritmul lui Karger.
# Presupunem ca graful este dat cu matrice de adiacenta.

Rand_Min_Cut = function(G)
{
  while(nrow(G) > 2) 	## while there are more than 2 vertices
  {
    e = sample(1:nrow(G), 2, replace = T); 	## pick a random edge (u, v)
    while(G[e[1],e[2]] == 0) 	## while (u, v) it's not a vertex
    {
      e = sample(1:nrow(G), 2, replace = T); 	## pick a random edge (u, v)
    }
    for(j in 1:ncol(G))
    {
      if(G[e[2],j] > 0 & j != e[1]) 	## if node e[2] has another edge other than e[1]
      {
        G[e[1],j] = G[e[1],j] + G[e[2],j]; 	## Merge u and v into a single vertex
        G[j,e[1]] = G[e[1],j];
      }
    }
    G = G[-e[2],]; ## remove e[2] vertex
    G = G[,-e[2]];
  }
  return (G);
}

y = c(0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0)
M = matrix(y, 6, 6)
Rand_Min_Cut(M)