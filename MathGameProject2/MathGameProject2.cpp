#include<iostream>
#include<cstdlib>

using namespace std;


enum enQuestionLevel{Easy=1,Med=2,Hrad=3,Mix=4};
enum enOperationType{Add=1,Sub=2,Mul=3,Div=4,Mix=5};


struct stGameResults {

	short NumberOfQuestions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfRightAnswer = 0;
	short NumberOfWrongAnser = 0;
	string QuestionLevelName;
	string OperationTypeName;

};






int main() {






	return 0;
}