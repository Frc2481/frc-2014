#!/usr/bin/python

from numpy import matrix
from numpy import array
import urllib
import simplejson

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

def AddAllTeamScore(a,b,c,s):
	AddToTeamScore(a,s)
	AddToTeamScore(b,s)
	AddToTeamScore(c,s)

def AddToTeamScore (t, s):
	t = teamMap.index(int(t))
	teamScores[t][0] = teamScores[t][0] + int(s)

def ParseTeams():
    file = open("TeamList.csv")
    for line in file:
        teamMap.append(int(line))
        
def BuildMatchURL(e):
	baseUrl = "http://www.thefirstalliance.org/api/api.json.php?action=event-matches&event-code="
	return baseUrl + e

def BuildTeamListURL(e):
	baseUrl = "http://www.thefirstalliance.org/api/api.json.php?action=event-details&event-code="
	return baseUrl + e

def ParseJsonTeams(e):
	jData = urllib.urlopen(BuildTeamListURL(e))
	jDict = simplejson.load(jData)
	data = jDict['data']
	data = data['rankings']
	for team in data:
		teamMap.append(int(team['Team']))
		teamScores.append([ int(team['CP']) * 5 ])	#Adjust OPR

def ParseJsonMatches(matches):
	jDict = simplejson.load(matches)
	data = jDict['data']
	for team in data:	
		if team['match_type'] == '2':
			continue
		AddAllToMatchCount(team['red_1_num'],team['red_2_num'],team['red_3_num'])					#Red Team
		AddAllTeamScore(team['red_1_num'],team['red_2_num'],team['red_3_num'],team['red_score'])	#Red Score
		AddAllToMatchCount(team['blue_1_num'],team['blue_2_num'],team['blue_3_num'])				#Blue Team
		AddAllTeamScore(team['blue_1_num'],team['blue_2_num'],team['blue_3_num'],team['blue_score'])#Blue Score

teamMap = []

teamScores = []

ParseJsonTeams("WI")

matrixA = []
for i in range(len(teamMap)):
	matrixRow = []
	for j in range(len(teamMap)):
		matrixRow.append(0)
	matrixA.append(matrixRow)

#file = open("MatchResults.csv")

matchJson = urllib.urlopen(BuildMatchURL("WI"))
ParseJsonMatches(matchJson)

A = matrix(matrixA)
B = matrix(teamScores)
C = array(A.I * B).tolist()
for i in range(len(A)):
	print "%4s: %s" % (teamMap[i], C[i][0])



