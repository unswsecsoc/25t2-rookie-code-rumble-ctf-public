import csv
rows = []

with open('aec-senate-formalpreferences-31496-TAS.csv', newline='') as csvfile:
    csvreader = csv.reader(csvfile, delimiter=',', quotechar='"')
    for row in csvreader:
        rows.append(row)

prefs = ["K:Australian Labor Party", "B:Liberal", "F:The Greens", "G:Jacqui Lambie Network", "I:Pauline Hanson's One Nation", "D:Legalise Cannabis Party", "L:Shooters, Fishers and Farmers Party"]

for row in rows:
    for i in range(1,min(8, len(prefs)+1)):
        try:
            j = rows[0].index(prefs[i-1])
        except:
            break
        try:
            if row[j] != str(i):
                break
        except:
            break
    else:
        print(row)
        print("Vote collection point is third entry")