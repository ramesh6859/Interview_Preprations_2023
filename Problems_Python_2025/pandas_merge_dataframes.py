import pandas as pd
df1 = pd.DataFrame({'ID': [1, 2, 3], 'Name': ['Alice', 'Bob', 'Charlie']})
df2 = pd.DataFrame({'ID': [1, 2, 4], 'Score': [85, 92, 88]})
result = pd.merge(df1, df2, on='ID', how='inner')
print(result)  # Output: merged DataFrame with common ‘ID’