import pandas as pd
df = pd.DataFrame({'A': [10, 20, 30], 'B': [40, 50, 60]})
print(df.loc[0, 'A'])  # Output: 10 (by label)
print(df.iloc[0, 0])   # Output: 10 (by index position)