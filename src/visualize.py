import pandas as pd
import os
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import seaborn
seaborn.set() #make the plots look pretty



df = pd.read_csv(os.path.join(os.getcwd(),"src/test_result2.csv"), header=None)
data_3 = df.loc[df[1]==3][df[0] > 3]
data = data_3.groupby([0,1]).size()
data.plot.bar(x=0, y=2, rot=0)
print(data)
plt.show()