import reboundrumble
from numpy import matrix
from numpy import array
import urllib

MATCH_URL = "http://www.thefirstalliance.org/api/api.json.php?action=event-matches&event-code="
TEAMLIST_URL = "http://www.thefirstalliance.org/api/api.json.php?action=event-details&event-code="

#Create Parse Object
p = reboundrumble.ParserRR()

#Get Team Data
teamJson = urllib.urlopen(TEAMLIST_URL + "OHC")

#Parse Team Data into list
p.ParseJsonTeams(teamJson)

#Create Match Array (dependent on number of teams)
p.InitMatchArray()

#Get Match Data
matchJson = urllib.urlopen(MATCH_URL + "OHC")

#Parse Match Data into Matrixes
p.ParseJsonMatches(matchJson)


matchArray = p.GetMatchArray()
scoreList = p.GetScoreList()
teamList = p.GetTeamList()

#Calculate OPR
opr = array(matchArray.I * scoreList).tolist()

for i in range(len(matchArray)):
    print "%4s: %s" % (teamList[i], opr[i][0])