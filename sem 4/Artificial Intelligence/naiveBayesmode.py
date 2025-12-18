#to implement naive bay's algo for training data
#predict class for x=(Overcast,Cool, High, Strong)

weather=    ['Sunny','Sunny','Overcast','Rainy','Rainy','Rainy','Rainy','Overcast','Sunny','Sunny','Rainy','Sunny','Overcast','Rainy']
temp=       ['Hot','Hot','Hot','Mild','Cool','Cool','Cool','Mild','Cool','Mild','Mild','Mild','Hot','Mild']
humidity=   ['High','High','High','High','Normal','Normal','Normal','High','Normal','Normal','Normal','High','Normal','High']
wind=       ['Weak','','Weak','Weak','Weak','Strong','Strong','Weak','Weak','Weak','Strong','Strong','Weak','']
play=       ['No','No','Yes','Yes','Yes','No','Yes','No','Yes','Yes','Yes','Yes','Yes','No']

from sklearn import preprocessing
le=preprocessing.LabelEncoder() #le vaneko random varaible ho

#data into number
we=le.fit_transform(weather)
#temp input  text data into number
t=le.fit_transform(temp)
#humidity input text data into number
h=le.fit_transform(humidity)
#for wind
wn=le.fit_transform(wind)
#for play
p=le.fit_transform(play)

print (we,t,h,wn,p)

#data
features=zip(we,t,h,wn)
inp=list(features)
print("input data:")
print(inp)
print("Actual Output:")
print(p)

from sklearn.naive_bayes import GaussianNB

model=GaussianNB()
model.fit(inp,p)

predicted=model.predict([[1,1,1,1]]) #ya chai change garnu parxa. for eg garmi hunxa ki hudaina or something like that. afno maan ley rakhe, random 1,0,2,0 whatever you like


#overcast
print("predicted value is : ",predicted)
if(predicted==1):
    print("play tennis: YEs")
else:
    print("play tennis: no")



