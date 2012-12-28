from numpy import matrix

class Parser2012 (Parser):
    
    def __init__ (self):
        Parser.__init__(self)
        #self.mTeamList = []
        #self.mMatchList = []
        #self.mTotalScoreList = []
        
    def ParseJsonTeams(self, teams):
        jDict = simplejson.load(jData)
        data = jDict['data']
        data = data['rankings']
        for team in data:
            Pet.mTeamList.append(int(team['Team']))
            #teamScores.append([ int(team['CP']) * 5 ])    #Adjust OPR
    
    def ParseJsonMatches(self, matches):
        jDict = simplejson.load(matches)
        data = jDict['data']
        for team in data:    
            
            """ Do not include elimination matches """
            if team['match_type'] == '2':
                continue
            
            #Red Alliance
            Parser.AddAlliance(team['red_1_num'],team['red_2_num'],team['red_3_num'],team['red_score'])   
            
            #Blue Alliance
            Parser.AddAlliance(team['blue_1_num'],team['blue_2_num'],team['blue_3_num'],team['blue_score'])
