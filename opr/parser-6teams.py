#!/usr/bin/python

def AddAllToMatchCount(a,b,c):
	AddToMatchCount(a,b)
	AddToMatchCount(a,c)
	AddToMatchCount(b,c)

def AddToMatchCount (a, b):
	a = teamMap.index(int(a))
	b = teamMap.index(int(b))
	matrix[a][b] = matrix[a][b] + 1
	matrix[b][a] = matrix[b][a] + 1

def AddToTeamScore (t, s):
	t = teamMap.index(int(t))
	teamScores[t] = teamScores[t] + int(s)

def AddAllTeamScore(a,b,c,s):
	AddToTeamScore(a,s)
	AddToTeamScore(b,s)
	AddToTeamScore(c,s)

def ParseTeams():
    file = open("TeamList.csv")
    for line in file:
        teamMap.append(int(line))

teamMap = []

teamScores = []

matrix = []
for i in range(len(teamMap)):
	matrixRow = []
	for j in range(len(teamMap)):
		matrixRow.append(0)
	matrix.append(matrixRow)
	teamScores.append(0)

print matrix

file = open("MatchResults.csv")

for line in file:
	print line
	sLine = line.split(',')

	r1 = sLine[0]
	r2 = sLine[1]
	r3 = sLine[2]
	b1 = sLine[3]
	b2 = sLine[4]
	b3 = sLine[5]
	rs = sLine[6]
	bs = sLine[7]

	#Red Team
	AddAllToMatchCount(r1,r2,r3)

	#Blue Team
	AddAllToMatchCount(b1,b2,b3)

	#Red Score
	AddAllTeamScore(r1,r2,r3,rs)

	#Blue Score
	AddAllTeamScore(b1,b2,b3,bs)

print matrix
print teamScores

