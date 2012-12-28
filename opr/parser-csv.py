#!/usr/bin/python

from numpy import matrix

def AddAllToMatchCount(a,b,c):
	AddToMatchCount(a,b)
	AddToMatchCount(a,c)
	AddToMatchCount(b,c)
	AddToMatchCount(a,a)
	AddToMatchCount(b,b)
	AddToMatchCount(c,c)
    	
def AddToMatchCount (a, b):
	a = teamMap.index(int(a))
	b = teamMap.index(int(b))
	matrixA[a][b] = matrixA[a][b] + 1
	if (a != b):
		matrixA[b][a] = matrixA[b][a] + 1

def AddToTeamScore (t, s):
	t = teamMap.index(int(t))
	teamScores[t][0] = teamScores[t][0] + int(s)

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

ParseTeams()

matrixA = []
for i in range(len(teamMap)):
	matrixRow = []
	for j in range(len(teamMap)):
		matrixRow.append(0)
	matrixA.append(matrixRow)
	teamScores.append([0])

print matrixA

file = open("MatchResults.csv")

for line in file:
	print line
	sLine = line.split(',')

	r1 = sLine[0]
	r2 = sLine[1]
	r3 = sLine[2]
	rs = sLine[3]

	#Red Team
	AddAllToMatchCount(r1,r2,r3)

	#Red Score
	AddAllTeamScore(r1,r2,r3,rs)

A = matrix(matrixA)
B = matrix(teamScores)
print matrixA
print teamScores
print len(A)
print len(B)
print "++++++++++++++++++"
print A.I
print A.I * B

