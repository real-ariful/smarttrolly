import pymongo
from pymongo import MongoClient
client = MongoClient()

#Dumping in mongodb
db = client.test_database
collection = db.test_collection
posts=db.table1


import pprint
x=2361989187150
for i in posts.find({"uid": x }):
    pprint.pprint(str(i['date']))
    pprint.pprint(i['item'])    
    pprint.pprint(i['price'])
    
    
for j in posts.find({"uid": x }):
    if posts.find({"uid": x }).count > 0:
        pprint.pprint("UID found: True")
    else:
        pprint.pprint("UID found: False")

#pprint.pprint("Counting is: " + str(posts.count()))

#Printing all data
#for post in posts.find():
#    pprint.pprint(post)    