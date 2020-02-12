## Testul Z pt medie (se cunoaste sigma^2 a intregii populatii)

# I.2 sigma^2 = 144, n = 49, x barat = 88, miu0 = 90
# 1) H0: miu = miu0 = 90 (ipoteza nula)
# 2) Ha: miu < miu0 (asimetrica stanga)
# 3: alfa = {0.01, 0.05}
# 4) scorul testului (valoarea calculata): z = (x barat - miu0)/(sigma/sqrt(miu)) = -1.16
# 5) criticul (valoarea teoretica): z* = qnorm(alfa) = -1.64
# 6) decizia: z = -1.16 > z* = -1.64 --> Se accepta H0 la alfa = 0.05

# I.3 miu0 = 75, sigma^2 = 17, n = 36, x barat = 85, alfa = 0.01
# 1) H0: miu = miu0 = 75
# 2) Ha: miu != miu0 (simetric)
# 3) alfa = 0.01
# 4) scorul z = 14.55
# 5) criticul z* = qnorm(1-alfa/2) = 2.57
# 6) decizia: |z| = 14.55 : |z*| = 2.57 --> Se respinge H0 la alfa = 0.01


## Testul t pt medie (nu se cunoaste sigma^2 si n<30)

# II.3 miu0 = 11.4, n = 100, x barat = 11.9, s = 0.25
# 1) H0: miu = miu0 = 11.4
# 2) Ha: miu > miu0 = 11.4 (asimetric dreapta)
# 3) alfa = {0.01, 0.05}
# 4) scorul t = (x barat - miu0)/(s/sqrt(miu)) = 20
# 5) t* = qt(1-alfa, n-1) = 2.36
# 6) decizia: t = 20 > t* 2.36 --> Se respinde H0 la alfa = 0.01

## Testul Z pt diferenta mediilor a 2 populatiei (dispersiile populatiilor de cunosc)

# III.2 n1 = 80, n2 = 70, x1 barat = 160, x2 barat = 155, sigma1 = 3.24, sigma2 = 2.25
# 1) H0: miu1 = miu2
# 2) Ha: miu1 != miu2 (simetrica)
# 3) alfa = {0.01, 0.05}
# 4) scorul z = (x1 barat - x2 barat)/sqrt(sigma1^2/miu1+sigma2^2/miu2)
# 5) z* = qnorm(1-alfa/2) = 2.57
# 6) decizia: |z| = 11.08 > |z*| = 2.57 --> Se respinge H0 la alfa = 0.01

## Testul F pt raportul dispersiilor

# Problema rezolvata din laborator:
# n1 = 120, s1 = 5.05, n2 = 135, s2 = 5.44, alfa = 0.01
# 1) H0: sigma1^2 = sigma2^2
# 2) Ha: sigma1^2 != sigma2^2 (simetrica)
# 3) alfa = 0/01
# 4) scorul F = (s1^2)/(s2^2) = 0.86
# 5) Fs* = qf(alfa/2, n1-1, n2-1) = 0.62, Fd* = qf(1-alfa/2, n1-1, n2-1) = 1.58
# 6) decizia: F = 0.86 apartine [0.62, 1.58] --> dispersii egale

## Testul t pt diferenta mediilor a 2 populatii (dispersiile populatiilor nu se cunosc)

# Problema rezolvata:
# n1 = 110, x1 barat = 25.84, s1 = 4.25, n2 = 105, x2 barat = 21.53, s2 = 3.85, alfa = 0.01
# F = (s1^2)/(s2^2) = 1.21
# Fs* = 0.60, Fd* = 1.65 --> dispersii egale
# 1) H0: miu1 = miu2
# 2) Ha: miu1 != miu2
# 3) alfa = 0.01
# 4) t = (x1 barat - x2 barat)/sqrt(s1^2/n1+s2^2/n2) = 7.78
#    s = ((n1-1)*(s^2) + (n2-1)*(s2^2)) / (n1+n2-2) = 31.06
# 5) t* = qt(1-alfa/2, df) = 2.62, unde df = n1+n2-2
# 6) decizia: |t| = 7.78 > |t*| = 2.62 --> Se respinge H0


## I.1

med_pop_disp_cunosc = function(alfa, population_mean, sample_mean, n, sigma, tip)
{
  z_score = (sample_mean - population_mean)/(sigma/sqrt(n))
  if(tip == -1)
  {
    critical_z = qnorm(alfa)
    print("Ipoteza este asimetrica la stanga !")
    if(z_score < critical_z)
      print("Ipoteza nula este respinsa !")
    else
      print("Ipoteza nula poate fi respinsa, se accepta ipoteza initiala !")
  }
  else if(tip == 0)
  {
    critical_z = qnorm(1-alfa)
    print("Ipoteza este asimetrica la dreapta !")
    if(z_score > critical_z)
      print("Ipoteza nula este respinsa !")
    else
      print("Ipoteza nula poate fi respinsa, se accepta ipoteza initiala !")
  }
  else {
    critical_z = qnorm(1-alfa/2)
    print("Ipoteza este simetrica !")
    if(abs(z_score) > abs(critical_z))
      print("Ipoteza nula este respinsa !")
    else
      print("Ipoteza nula poate fi respinsa, se accepta ipoteza initiala !")
  }
  print(critical_z)
  z_score
}

med_pop_disp_cunosc(0.05, 810, 816, 200, 50, -1)

# I.2

med_pop_disp_cunosc(0.05,90,88,49,sqrt(144), -1)

# I.3

med_pop_disp_cunosc(0.01,85,75,36,17, -1)

# II.1

t_test1 = function(file)
{
  x = scan(file);
  return(x)
}

med_pop_disp_nec = function(alfa, n, population_mean, sample_mean, x, file, tip)
{
  if(length(x) == 1) x = t_test1(file);
  s = sd(x);
  se = s/sqrt(n);
  t_score = (sample_mean - population_mean)/se;
  if(tip == -1)
  {
    critical_t = qt(alfa, n - 1)
    if(t_score < critical_t)
      print("Ipoteza nula este respinsa")
    else
      print("Ipoteza nula nu poate fi respinsa!")
  }
  else if(tip == 0)
  {
    critical_t = qt(1 - alfa, n - 1);
    if(t_score > critical_t)
      print("Ipoteza nula este respinsa")
    else
      print("Ipoteza nula nu poate fi respinsa!")
  }
  else
  {
    critical_t = qt(1-alfa/2, n-1)
    if(abs(t_score) > abs(critical_t))
      print("Ipoteza nula este respinsa")
    else
      print("Ipoteza nula nu poate fi respinsa!")
  }
}

# II.2 

x = c(36, 32, 28, 33, 41, 28, 31, 26, 29, 34);
med_pop_disp_nec(0.01, length(x), 34, mean(x), x, -1)

# II.4

x = t_test1("history.txt")
med_pop_disp_nec(0.01, length(x), 80, mean(x), x, -1)

# III.1

diferenta_mediilor_disp_cunosc = function(alfa, sample1_mean, sample2_mean, n1, n2, sigma1, sigma2, tip)
{
  m0=0
  combined_sigma = sqrt(sigma1^2/n1 + sigma2^2/n2)
  score_z = (sample1_mean - sample2_mean-m0)/combined_sigma
  if(tip == -1)
  {
    print("Avem: Ipoteza asimetrica la stanga!")
    critical_z = qnorm(alfa, 0, 1);
    if(score_z < critical_z)
      print("Ipoteza nula este respinsa!")
    else
      print("Ipoteza nula este acceptata!")
  }
  else if(tip == 0)
  {
    print("Avem: Ipoteza asimetrica la dreapta!")
    critical_z = qnorm(1-alfa, 0, 1);
    if(score_z > critical_z)
      print("Ipoteza nula este respinsa!")
    else
      print("Ipoteza nula este acceptata!")
  }
  else
  {
    print("Avem: Ipoteza simetrica!")
    critical_z = qnorm(1-alfa/2, 0, 1);
    if(abs(score_z) > abs(critical_z))
      print("Ipoteza nula este respinsa!")
    else
      print("Ipoteza nula este acceptata!")
  }
}

diferenta_mediilor_disp_cunosc(0.05, 48, 47, 100, 100, 4, 3, -1)

# III.2

diferenta_mediilor_disp_cunosc(0.01, 160, 155, 80, 70, 3.24, 2.25, -1)

# III.3

diferenta_mediilor_disp_cunosc(0.01, 22.8, 23.3, 100, 100, 1.3, 1.9, -1)

# IV.1

Inferenta_asupra_disp = function(alfa, n1, n2, s1, s2)
{
  critical_F_s = qf(alfa/2, n1-1, n2-1)
  critical_F_d = qf(1-alfa/2, n1-2, n2-1)
  score_F = sqrt(s1)/sqrt(s2)
  if(score_F < critical_F_s || score_F > critical_F_d)
    print("Ipoteza nula este respinsa!")
  else
    print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
}

Inferenta_asupra_disp(0.01, 120, 135, 5.05, 5.44)

# IV.2

x1 = read.table("program.txt", header = T)[['A']]
x2 = read.table("program.txt", header = T)[['B']]

Inferenta_asupra_disp(0.01, length(x1), length(x2), sd(x1), sd(x2))
Inferenta_asupra_disp(0.05, length(x1), length(x2), sd(x1), sd(x2))

# IV.3

drogati = c(12.512, 12.869, 19.098, 15.350, 13.297, 15.589)
normali = c(11.074, 9.686, 12.164, 8.351, 12.182, 11.489)

Inferenta_asupra_disp(0.05, length(drogati), length(normali), sd(drogati), sd(normali))

# V.1

Dif_mediilor_dips_nec = function(alfa, sample1_mean, sample2_mean, n1, n2, s1, s2, tip)
{
  m0=0
  critical_F_s = qf(alfa/2, n1 - 1, n2 - 1)
  critical_F_d = qf(1 - alfa/2, n1 - 1, n2 - 1)
  F_score = s1^2/ s2^2
  if(F_score < critical_F_s || F_score > critical_F_d)
  {
    df = min(n1 - 1, n2 - 1);
    combined_s = sqrt(s1^2/n1 + s2^2/n2);
  }
  else
  {
    df = n1 + n2 - 2;
    combined_s = sqrt(((n1 - 1)*s1^2 + (n2 - 1)*s2^2)/df)*sqrt(1/n1 + 1/n2);
  }
  # critical_t = qt(1 - alfa/2, df)
  t_score = (sample1_mean - sample2_mean - m0)/combined_s
  if(tip == -1)
  {
    critical_t = qt(alfa, df)
    print("Ipoteza asimetrica la stanga!")
    if(t_score < critical_t)
      print("Ipoteza nula este respinsa!")
    else
      print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
  }
  else if(tip == 0)
  {
    critical_t = qt(1 - alfa, df)
    print("Ipoteza asimetrica la dreapta!")
    if(t_score > critical_t)
      print("Ipoteza nula este respinsa!")
    else
      print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
  }
  else
  {
    critical_t = qt(1 - alfa/2, df)
    print("Ipoteza simetrica!")
    if(abs(t_score) > abs(critical_t))
      print("Ipoteza nula este respinsa!")
    else
      print("Nu exista suficiente dovezi pentru a respinge ipoteza nula!")
  }
  print(critical_t)
  t_score
}

# V.2

x1 = read.table("program.txt", header=T)[['A']]
x2 = read.table("program.txt", header=T)[['B']]

Dif_mediilor_dips_nec(0.01, mean(x1), mean(x2), length(x1), length(x2), sd(x1), sd(x2), -1)
Dif_mediilor_dips_nec(0.05, mean(x1), mean(x2), length(x1), length(x2), sd(x1), sd(x2), -1)

# V.3

drogati = c(12.512, 12.869, 19.098, 15.350, 13.297, 15.589)
normali = c(11.074, 9.686, 12.164, 8.351, 12.182, 11.489)

Dif_mediilor_dips_nec(0.01, mean(drogati), mean(normali), length(drogati), length(normali), sd(drogati), sd(normali), -1)




