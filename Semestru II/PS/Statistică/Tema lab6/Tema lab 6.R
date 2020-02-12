## E1
# Se masoara nivelul de magneziu (care urmeaza o lege normala) din sangele unui pacient:
# 1.64 1.54 1.56 1.57 1.44 1.48 1.56 (mg=dl)
# Putem trage concluzia ca acest nivel este mai mic decat maximum posibil, 1:6 mg/dl? (1%)

t_test = function(esantion, miu0, alfa, tip)
{
  n = length(esantion);
  sample_mean = mean(esantion);
  s = sd(esantion);
  se = s/sqrt(n);
  t_score = (sample_mean - miu0)/se;
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
 #  print(critical_t);
 #  print(t_score);
}

t_test(c(1.64, 1.54, 1.56, 1.57, 1.44, 1.48, 1.56), 1.6, 0.01, -1)

## E4
# Pentru doua esantioane provenind din doua populatii normale distincte A si B se determina urmatoarele valori
# (A) sigma1 = 0.75; n1 = 155; x(n1) barat = 15
# (B) sigma2 = 0.78; n2 = 150; x(n2) barat = 14.5
# Sa se testeze diferenta mediilor celor doua populatii cu 1% si cu 5% nivel de semnificatie.

z_test_means = function(n1, n2, sample_mean1, sample_mean2, sigma1, sigma2, alfa, miu0, tip)
{
  combined_sigma = sqrt(sigma1^2/n1 + sigma2^2/n2);
  critical_z = qnorm(1-alfa/2);
  score_z = (sample_mean1 - sample_mean2 - miu0)/combined_sigma;
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
  # print(critical_z);
  # print(z_score);
}

z_test_means(155, 150, 15, 14.5, 0.75, 0.78, 0.01, 0, -1)
z_test_means(155, 150, 15, 14.5, 0.75, 0.78, 0.05, 0, -1)

## E5
# Pentru doua esantioane aleatoare simple provenind din doua populatii normale se obtin urmatoarele date
# n1 = 66; x(n1) barat = 21; s1 = 1.2
# n2 = 68; x(n2) barat = 20; s2 = 1.1
# Sa se testeze diferenta mediilor ceor doua populatii (5%).

T_test_means = function(n1, n2, sample1_mean, sample2_mean, s1, s2, alfa, m0, tip)
{
  critical_F_s = qf(alfa/2, n1-1, n2-1);
  critical_F_d = qf(1-alfa/2, n1-1, n2-1);
  F_score = s1^2/s2^2;
  if(F_score < critical_F_s | F_score > critical_F_d)
  {
    df = min(n1-1, n2-1);
    combined_s = sqrt(s1^2/n1 + s2^2/n2);
  }
  else
  {
    df = n1 + n2 - 2;
    combined_s = sqrt(((n1-1)*s1^2 + (n2-1)*s2^2)/df)*sqrt(1/n1+1/n2);
  }
  # critical_t = qt(1-alfa/2, df);
  t_score = (sample1_mean - sample2_mean - m0)/combined_s;
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
  print(critical_t);
  print(t_score);
}

T_test_means(66, 68, 21, 20, 1.2, 1.1, 0.05, 0, -1)

