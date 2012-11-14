#!/usr/bin/env python

def P(gc):
  """
  Returns the chance that two randomly chosen letters are equal, taken from
  two strings with equal GC-content.
  """
  CG = gc/2.0;
  AT = (1.0-gc)/2.0;
  return 2.0 * (CG*CG + AT*AT)

def E(gc,m,n):
  """
  Given two strings of lengths m and n, m<n, returns the expected number of
  substring matches where m is found inside n.
  """
  pm = P(gc)**m # small string
  s = 0.0
  for i in xrange(0,n-m+1):
    s += pm
  return s

if __name__ == "__main__":
  line = raw_input().split()
  m = int(line[0])
  n = int(line[1])
  A = [float(f) for f in raw_input().split()]

  for gc in A:
    print E(gc, m, n),
