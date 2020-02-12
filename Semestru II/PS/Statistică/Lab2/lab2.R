# File -> New File -> R Script
# File -> New File -> Text File
# Session -> Set Working Directory -> To Source File Location/Choose Directory

## Ex I.1
x = scan ("sample1.txt")
stem(x)

## Ex I.2
x = read.csv ("unemploy2012.csv", header = T, sep = ';')
rate = x[['rate']]
hist(rate, breaks=c(0,4,6,8,10,12,14,30), right = T, freq = T, col = 'red')

## Ex I.3
x = read.csv ("life_expect.csv", header = T, sep = ',')
male = x[['male']]
female = x[['female']]
hist(male, breaks = 7, right = T, freq = T, col = 'red')
hist(female, breaks = 7, right = T, freq = T, col = 'blue')

## Ex II.1
x = scan("sample1.txt")
mean(x) #medie
median(x) #mediana

## Ex II.2
x = read.csv ("life_expect.csv", header = T, sep = ',')
male = x[['male']]
female = x[['female']]
mean(male) #medie
median(male) #mediana

## Ex III.1 Valori aberante a)
# x nu apartine [ M-2*s, M+2*s] -> x = valoarea aberanta
outliers_mean = function(x) {
  j = 0;
  m = mean(x)
  s = sd(x) # deviatia standard
  rez = vector()
  for(i in 1:length(x)) {
    if (x[i] <= m-2*s | x[i] >= m+2*s) {
      j = j+1
      rez[j] = x[i]
    }
  }
  rez
}

sample = scan("sample2.txt")
outliers_mean(sample)

## Ex III.1 Valori aberante b)
# IQR = Q3 - Q1 (interval interquartilic)
# x nu apartine [Q1 - 1,5*IQR, Q3+1,5*IQR] -> x valoare aberanta
x = scan("sample1.txt")
summary(x)

outliers_iqr = function(x) {
  j = 0
  y = summary(x)
  q1 = y[2]
  q3 = y[5]
  IQR = q3-q1
  rez = vector()
  for(i in 1:length(x)) {
    if (x[i] <= q1-1.5*IQR | x[i] >= q3+1.5*IQR) {
      j = j+1
      rez[j] = x[i]
    }
  }
  rez
}

sample = scan("sample2.txt")
outliers_iqr(sample)


