#include<iostream>
#include<cstdlib>

using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hrad = 3,LMix=4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4,OMix=5 };


struct stGameResults {

	short NumberOfQuestions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfRightAnswer = 0;
	short NumberOfWrongAnser = 0;
	string QuestionLevelName;
	string OperationTypeName;

};


int RandomNumber(int From, int To) {

	int RanNum = rand() % (To - From + 1) + From;

	return RanNum;
}




string OperationTypeName(enOperationType OperationType) {

	string arrOperationName[5] = { "+","-","*","/","Mix" };

	return arrOperationName[OperationType - 1];
}
string QuestionLevelName(enQuestionLevel Level) {

	string arrOperationName[4] = { "Easy","Med","Hard","Mix" };

	return arrOperationName[Level - 1];
}


short NumberOfQuestions() {

	short NumberOfQuestions = 0;

	cout << "How Many Questions do you wan to Answer? ";
	cin >> NumberOfQuestions;


	return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel() {

	short QLevel = 0;

	do {

		cout << "Enter Question Level [1] Easy, [2] Med , [3] Hard, [4] Mix? ";
		cin >> QLevel;

	} while (QLevel < 1 || QLevel>4);

	return (enQuestionLevel)QLevel;
}

enOperationType ReadOperationType() {

	short OpType = 0;
	do {

		cout << "Enter Operations Type [1] Add, [2] Sub, [3] Mul, [4] Div ,[5] Mix ? ";
		cin >> OpType;
	} while (OpType < 1 || OpType>5);

	return (enOperationType)OpType;
}


int PrintQuestionStruct(int Num1, int Num2, enOperationType OpType) {

	int Answer;
	cout << Num1 << endl;
	cout << Num2 << "  " << OperationTypeName(OpType) << endl;
	cout << "______________\n";
	cin >> Answer;

	return Answer;
}


int Calculate(enOperationType OpType, int num1, int num2) {

	switch (OpType)
	{
	case enOperationType::Add:
	{
		return num1 + num2;
		break;
	}

	case enOperationType::Sub:
	{
		return num1 - num2;
		break;
	}
	case enOperationType::Mul:
	{
		return num1 * num2;
		break;
	}
	case enOperationType::Div:
	{
		return num1 / num2;
		break;
	}

	}


}
void  CheckAnswer(int AnswerFromCalcluate, int AnswerUser,stGameResults &GameResults) {

	
	
	if (AnswerFromCalcluate == AnswerUser) {
		cout << "Correct Anhsweer (-:\n";
		system("color 2F");
		GameResults.NumberOfRightAnswer++;
	}
	else {
		cout << "Wrong answer , the correct answer is   " << AnswerFromCalcluate << endl;
		system("color 4F");
		cout << "\a";
		GameResults.NumberOfWrongAnser+=1;
		cout << "\nCheck: "<<GameResults.NumberOfWrongAnser << endl;
		 
	}

}







void GenerateQuestions(enQuestionLevel QLevel, enOperationType Optype, stGameResults &GameResults) {

	switch (QLevel)
	{
	case enQuestionLevel::Easy:
	{
		if (Optype != enOperationType::OMix) {

        int Num1 = RandomNumber(1, 10);
		int Num2 = RandomNumber(1, 10);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype), GameResults);
		
		}
		else {
			int Num1 = RandomNumber(1, 10);
			int Num2 = RandomNumber(1, 10);
			int Op = RandomNumber(1, 4);
			CheckAnswer(Calculate((enOperationType)Op, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType)Op), GameResults);


		}
        break;
		
	}

	case enQuestionLevel::Med:
	{
		if (Optype != enOperationType::OMix) {

        int Num1 = RandomNumber(10, 30);
		int Num2 = RandomNumber(10, 30);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype), GameResults);
		
		}
		else {
			int Num1 = RandomNumber(10, 30);
			int Num2 = RandomNumber(10, 30);
			int Op = RandomNumber(1, 4);
			CheckAnswer(Calculate((enOperationType)Op, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType)Op), GameResults);
		}
		break;
	}

	case enQuestionLevel::Hrad:
	{
		if (Optype != enOperationType::OMix) {

			int Num1 = RandomNumber(30, 100);
			int Num2 = RandomNumber(30, 100);
			CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype), GameResults);

		}
		else {
			int Num1 = RandomNumber(30, 100);
			int Num2 = RandomNumber(30, 100);
			int Op = RandomNumber(1, 4);
			CheckAnswer(Calculate((enOperationType)Op, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType)Op), GameResults);
		}
		break;

	}
	case enQuestionLevel::LMix:
	{
		/*int Num1 = RandomNumber(1, 100);
		int Num2 = RandomNumber(1, 100);
		int OOp = RandomNumber(1, 4);
		CheckAnswer(Calculate((enOperationType)OOp, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType) OOp));*/
		if (Optype == enOperationType::OMix) {

		int Num1 = RandomNumber(1, 3);
		int OOp = RandomNumber(1, 4);
		GenerateQuestions((enQuestionLevel)Num1, (enOperationType)OOp, GameResults);
		
		
		}
		else if (Optype != enOperationType::OMix) {
			int Num1 = RandomNumber(1, 3);
			GenerateQuestions((enQuestionLevel)Num1, Optype, GameResults);
		}

		break;
	}
	}

}


void PlayGame(short HowManyQuestions,stGameResults &GameResults) {


	enQuestionLevel Qlevel = ReadQuestionLevel();
	enOperationType OpType = ReadOperationType();
	short RightAnswerCount = 0, WrongAnswer = 0;
	for (short Question = 1; Question <= HowManyQuestions; Question++) {

		cout << "\n\nQuestions [" << Question << "/" << HowManyQuestions << "]\n";
		GameResults.NumberOfQuestions = HowManyQuestions;
		GameResults.OperationType = OpType;
		GameResults.QuestionLevel = Qlevel;
		GenerateQuestions(Qlevel, OpType,GameResults);
		

		


	}

	
}


void  PrintGameResults(stGameResults &GameResults) {

	cout << "Number of Questions are : " << GameResults.NumberOfQuestions << endl;
	cout << "Questions Level: " << QuestionLevelName(GameResults.QuestionLevel) << endl;
	cout << "OpType: " << OperationTypeName(GameResults.OperationType) << endl;
	cout << "Number of right answers: " << GameResults.NumberOfRightAnswer << endl;
	cout << "Number of wrong answers: " << GameResults.NumberOfWrongAnser << endl;
	cout << "\n\n__________________________________________\n\n";


}

void showFinalResults(stGameResults &GameResults) {

	if (GameResults.NumberOfRightAnswer >= GameResults.NumberOfWrongAnser ) {
		cout << "\n\n__________________________\n\n";
		cout << "Final Results is PASS (-:";
		cout << "\n\n__________________________\n\n";
	
	}
	else {
		cout << "\n\n__________________________\n\n";
		cout << "Final Results is Fail (-:";
		cout << "\n\n__________________________\n\n";
		

	}

}

void ResstScreen() {
	system("cls");
	system("color 0F");
}
void StartGame(stGameResults &GameResults) {
	
	char PlayAgain = 'Y';
	do {
		ResstScreen();
		GameResults.NumberOfRightAnswer = 0;
		GameResults.NumberOfWrongAnser = 0;
		PlayGame(NumberOfQuestions(),GameResults);
		showFinalResults(GameResults);
		PrintGameResults(GameResults);
		cout << "Do want to paly again? Y/N ?";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');


}

int main() {
	srand((unsigned)time(NULL));
	stGameResults GameResults;
	StartGame(GameResults);
	
	return 0;
}