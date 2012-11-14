#!/usr/bin/env python

def kmp_preprocess(p):
  m = len(p)
  b = [0]*(1+len(p))
  i=0
  j=-1
  b[i]=j
  while i < m:
    while j>=0 and p[i]!=p[j]:
      j = b[j]
    i += 1
    j += 1
    b[i] = j
  return b[1:]

if __name__ == "__main__":
  s = raw_input().strip()

  for n in kmp_preprocess(s):
    print n,
