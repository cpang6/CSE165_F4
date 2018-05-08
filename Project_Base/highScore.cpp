using namespace std;

int currHi = 0;
string strLine;
string userScoreStr;
string hiScoreWText;


highScore::highScore(int x){
while(getline (scoreFile, strLine)){
    //scoreFile << userScoreStr;
    ofstream myfile ("scoreList.txt");
    myfile << userScoreStr;
    strLine = userScoreStr;
  }
  hiScoreWText = "Highest Score: " + strLine + " | ";

  }
}
scoreFile.close();

}


string highScore::getScore(){
  return hiScoreWText;
}