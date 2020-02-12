## D1
# Nivelul de potasiu al unei persoane este masurat independent de 8 ori (aceste masuratori urmeaza o 
# distribuire normala cu deviatia standard sigma = 0.5). Media acestor masuratori este 2.75. 
# Determinati un interval de incredere de 99% pentru nivelul mediu de potasiu.

z_confidence_interval = function(n, sample_mean, alfa, sig)
{
  sigma = sqrt(sig);
  critical_z = qnorm(1-alfa/2, 0, 1);
  a = sample_mean - critical_z*sigma/sqrt(n);
  b = sample_mean + critical_z*sigma/sqrt(n);
  interval = c(a, b);
  return (interval);
}

z_confidence_interval(8, 2.75, 0.01, 0.25)

t_conf_interval = function(n, sample_mean, alfa, s)
{
  se = s/sqrt(n);
  critical_t = qt(1-alfa/2, n-1)
  a = sample_mean - critical_t*se;
  b = sample_mean + critical_t*se;
  interval = c(a,b);
  return (interval);
}

t_conf_interval(8, 2.75, 0.01, 0.5)

## D3
# O agentie imobiliara isi schimba managementul deoarece 10% dintre clienti declara ca sunt nemultumiti 
# de serviciile oferite. Dupa schimbarea managementului, dintr-un esantion de 112 clienti, 14 sunt 
# nemultumiti. Se poate trage concluzia ca schimbarea a fost inutila? (1% si 5% nivel de semnificatie.)

test_proportion = function(alfa, n, succese, p0)
{
  p_prim = succese/n;
  z_score = (p_prim-p0)/sqrt(p0*(1-p0)/n);
  return (z_score);
}

scorz = test_proportion(0.01, 112, 14, 0.1)
critz = qnorm(0.99, 0, 1)
scorz
critz

scorz = test_proportion(0.05, 112, 14, 0.1)
critz = qnorm(0.95, 0, 1)
scorz
critz
