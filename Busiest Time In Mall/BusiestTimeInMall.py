def find_busiest_period(data):
  
  shoppers = 0
  max_shoppers = 0
  for i in range(len(data)):
    if data[i][2] == 1:
      shoppers += data[i][1]
    else:
      shoppers -= data[i][1]    
      
    if i == len(data) - 1 or data[i][0] != data[i+1][0]:                   
      if max_shoppers < shoppers:
        max_shoppers = shoppers
        busiest_time = data[i][0]
  return busiest_time
