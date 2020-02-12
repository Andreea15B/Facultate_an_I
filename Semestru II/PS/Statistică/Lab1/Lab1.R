## Ex 1
x = c(46, 33, 39, 37, 46, 30, 48, 32, 48, 35, 30, 48)
max(x)
min(x)
sum(x)
length(x)
length(x[x>40])
length(x[x<35]) / length(x)*100

## Ex 2
log_nat = function(x) {
  v = log(x)
  return(v)
}

maxim = function(x) {
  return (x-max(x))/(min(x))
}

log_nat(c(1:5))

## Ex 3
x = scan("test.txt")
log_nat(x)

## Ex 4
densitate = function(n, p, colour) {
  return (barplot(dbinom(0:n, n, p), main = 'grafic', col = colour))
}

densitate(25, 0.3, 'red')
densitate(50, 0.7, 'green')
densitate(35, 0.5, 'yellow')

## Ex 5
pmax = function(n, p) {
  return(max(dbinom(0:n, n, p)))
}

pmax(50, 0.3)

## Ex 6
poisson = function(lambda, n) {
  return (dpois(0:n, lambda))
}

poisson(1, 20)

## Ex 7
exf = function(fd) {
  fd = read.table('teest.csv', header = T)
  x = fd[['AA']]
  y = fd[['BB']]
  plot(x, y, type = 'h', col = 'green', main = 'grafic', lwd = '10')
}

exf()





