## Ex 1
# Reprezentati functie de masa de probabilitate a distributiei binomiale B(n, p), si apoi functiile de 
# masa de probabilitate Poisson(lambda) si Geometric(p) - doar primele k valori, k fiind un parametru dat.

binom = function(n, p) {
  return (barplot(dbinom(1:n, n, p), main = 'grafic', col = 'red'))
}
binom(20, 0.4)


poisson = function(lambda, k) {
  return (barplot(dpois(1:k, lambda), col = 'blue'))
}
poisson(12, 20)


geometric = function(p, k) {
  return (barplot(dgeom(k, p), col = 'yellow'))
}
geometric(0.4, 0:20)

## Ex 2
# Determinati mediana, media, deviatia standard, cvartilele si valorile aberante (daca exista).

x = scan("ex2.txt")
mediana = median(x)
cat("Mediana =", mediana, "\n")
media = mean(x)
cat("Media =", media, "\n")
deviatia = sd(x)
cat ("Deviatia standard =", deviatia, "\n")
y = summary(x)
y
Q1 = y[2]
Q1
Q3 = y[5]
Q3

valori_aberante = function(x) {
  j = 0;
  m = mean(x)
  s = sd(x)
  rez = vector()
  for(i in 1:length(x)) {
    if (x[i] < m-2*s | x[i] > m+2*s) {
      j = j+1
      rez[j] = x[i]
    }
  }
  rez
}
valori_aberante(x)

## Ex 3
# Sa se determine media, mediana, deviatia standard, quartilele si sa se afle (daca exista) valorile
# aberante ale esantionului.

note_admitere = c(6.50, 8.60, 9.60, 7.25, 8.50, 9.95, 6.66, 6.40, 7.75, 7.66, 8.60, 9.33, 7.80, 9.85, 9.50, 5.50, 7.60, 7.25, 8.50, 9.70, 9.50, 8.25, 7.50, 8.66, 7.50, 9.00, 8.50, 9.33, 8.33, 9.90, 8.75, 5.60, 6.50, 6.75, 8.20, 8.33, 9.50, 8.66, 6.50, 7.25, 9.50, 9.33)

mean(note_admitere)
mediana = median(note_admitere)
cat("Mediana =", mediana, "\n")
media = mean(note_admitere)
cat("Media =", media, "\n")
deviatia = sd(note_admitere)
cat ("Deviatia standard =", deviatia, "\n")
y = summary(note_admitere)
y
Q1 = y[2]
Q1
Q3 = y[5]
Q3

valori_aberante = function(x) {
  j = 0;
  m = mean(x)
  s = sd(x)
  rez = vector()
  for(i in 1:length(x)) {
    if (x[i] < m-2*s | x[i] > m+2*s) {
      j = j+1
      rez[j] = x[i]
    }
  }
  rez
}
valori_aberante(note_admitere)





