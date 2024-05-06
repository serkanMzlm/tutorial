import numpy as np
import pandas as pd

data = np.random.randint(1, 10, (5, 3))
weekly_sales = pd.DataFrame(data, 
                            index=["Mon", "Tues", "Wed", "Thurs", "Fri"],
                            columns=["Almond", "Peanut", "Canhew"])
print(weekly_sales)

prices = np.array([10, 23, 3])
butter_prices = pd.DataFrame(prices.reshape(1, 3),
                             index=["Price"],
                             columns=["Almond", "Peanut", "Canhew"])

print(butter_prices)

total_sales = prices.dot(data.T) 
print(total_sales)

weekly_sales["Total ($)"] = total_sales.T
print(weekly_sales)