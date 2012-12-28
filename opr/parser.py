from numpy import matrix

class Parser (object):
    
    mTeamList = []
    mMatchArray = []
    mScoreList = []
    
    def __init__ (self):
        self.mTeamList = []
        self.mMatchArray = []
        self.mScoreList = []
    
    def InitMatchArray(self):
        for i in range(len(self.mTeamList)):
            matrixRow = []
            for j in range(len(self.mTeamList)):
                matrixRow.append(0)
            self.mMatchArray.append(matrixRow)
    
    def AddAlliance(self, a, b, c, s):
        self.AddToMatchCount(a,b)
        self.AddToMatchCount(a,c)
        self.AddToMatchCount(b,c)
        self.AddToMatchCount(a,a)
        self.AddToMatchCount(b,b)
        self.AddToMatchCount(c,c)
        self.AddToTeamScore(a,s)
        self.AddToTeamScore(b,s)
        self.AddToTeamScore(c,s)
            
    def AddToMatchCount (self, a, b):
        a = self.mTeamList.index(int(a))
        b = self.mTeamList.index(int(b))
        self.mMatchArray[a][b] = self.mMatchArray[a][b] + 1
        if (a != b):
            self.mMatchArray[b][a] = self.mMatchArray[b][a] + 1
    
    def AddToTeamScore (self, t, s):
        t = self.mTeamList.index(int(t))
        self.mScoreList[t][0] = self.mScoreList[t][0] + int(s)
        
    def GetTeamList(self):
        return self.mTeamList
    
    def GetMatchArray(self):
        return matrix(self.mMatchArray)
    
    def GetScoreList(self):
        return matrix(self.mScoreList)



