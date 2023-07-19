import pymysql
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime

# create connection to the database
db = pymysql.connect(host='192.168.18.8', port=3306, user='ESMicaiah', password='121303', db='Personal')

# create cursor
cursor = db.cursor()

# SQL query to fetch data
query = "SELECT * FROM bp"

# execute SQL query
cursor.execute(query)

# fetch all rows
rows = cursor.fetchall()

# convert the rows into a dataframe
df = pd.DataFrame(list(rows), columns=['side', 'sbp', 'dbp', 'hr', 'timestamp'])

# close database connection
db.close()

# convert timestamp to datetime object and set as index
df['timestamp'] = pd.to_datetime(df['timestamp'])
df.set_index('timestamp', inplace=True)

# sort by datetime index
df = df.sort_index()

# draw line chart
plt.figure(figsize=(10,6))
plt.plot(df.index, df['sbp'], color='red', label='SBP')
plt.plot(df.index, df['dbp'], color='blue', label='DBP')
plt.xlabel('Date')
plt.ylabel('Value')
plt.title('SBP and DBP over time')
plt.legend()
plt.grid(True)
plt.show()

