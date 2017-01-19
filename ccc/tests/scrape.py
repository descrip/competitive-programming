import urllib
import requests
import os

#cemc is unorganised, cemc doesnt care

# 2007 has .exp
# 2004 has .data
# 1996-2003 has nothing, because i can't find anything for 2001-2003 and 1996-2000 have crap naming

#url = "https://cemc.math.uwaterloo.ca/contests/computing/2014/Stage1Data/WINDOWS.zip"
#url = "https://cemc.math.uwaterloo.ca/contests/computing/2011/stage1/Stage1Data/WINDOWS.zip"
#url = "https://cemc.math.uwaterloo.ca/contests/computing/2009/stage1/data/WINDOWS.zip" 

url = "https://cemc.math.uwaterloo.ca/contests/computing/%i/stage1/data.zip"
for i in range(1996,2008+1):
    try:
        os.system("mkdir %i"%i)
        urllib.request.urlretrieve(url%i, "%i/compressed.zip"%i)
        os.system("unzip %i/compressed.zip -d %i"%(i,i))
    except:
        continue
