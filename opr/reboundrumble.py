import parser
from numpy import matrix
import simplejson

class ParserRR (parser.Parser):
    
    def __init__ (self):
        super(parser.Parser,self).__init__(self)
        
    def ParseJsonTeams(self, teams):
        jDict = simplejson.load(teams)
        data = jDict['data']
        data = data['rankings']
        for team in data:
            self.mTeamList.append(int(team['Team']))
            self.mScoreList.append([ int(team['CP']) * 5 ])    #Adjust OPR
    
    def ParseJsonMatches(self, matches):
        jDict = simplejson.load(matches)
        data = jDict['data']
        for team in data:    
            
            """ Do not include elimination matches """
            if team['match_type'] == '2':
                continue
            
            #Red Alliance
            self.AddAlliance(team['red_1_num'],team['red_2_num'],team['red_3_num'],team['red_score'])   
            
            #Blue Alliance
            self.AddAlliance(team['blue_1_num'],team['blue_2_num'],team['blue_3_num'],team['blue_score'])
