import math
d = list(map(int, input().split()))[:4]
v = [d[2]*d[3], d[0]*d[0]+d[1]*d[1], d[0]*d[1], d[2]*d[2]+d[3]*d[3]]

if(v[0]==0 or v[2]==0 or v[0]==v[2] or (v[0]*v[1] - v[2]*v[3])/(v[0]-v[2])<0):
  print('Impossible.')
else:
  print('Distance is', round(1000*math.sqrt((v[0]*v[1] - v[2]*v[3])/(v[0]-v[2]))), 'km.')
