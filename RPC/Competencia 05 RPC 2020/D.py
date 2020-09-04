
n = int(input())

for i in range(n):
    k = int(input())
    name = str(input())
    
    pancakes = 0
    peaSup = 0
    
    # reading restorant names
    for j in range(k):
        plate = str(input())
        if plate == "pea soup":
            peaSup = 1
        if plate == "pancakes":
            pancakes = 1
            
    if pancakes == 1 and peaSup == 1:
        print(name)
        exit()
        
        
print("Anywhere is fine I guess")
