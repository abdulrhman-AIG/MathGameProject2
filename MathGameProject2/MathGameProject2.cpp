#include<iostream>
#include<cstdlib>

using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hrad = 3 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4 };
enum enOperationTypeSign { sAdd = '+', sSub = '-', sMul = '*', sDiv = '/', sMix = '#' };

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
void CheckAnswer(int AnswerFromCalcluate, int AnswerUser) {

	if (AnswerFromCalcluate == AnswerUser) {
		cout << "Correct Anhsweer (-:\n";
		system("color 2F");

	}
	else {
		cout << "Wrong answer , the correct answer is   " << AnswerFromCalcluate << endl;
		system("color 4F");
	}

}



void GenerateQuestions(enQuestionLevel QLevel, enOperationType Optype) {

	switch (QLevel)
	{
	case enQuestionLevel::Easy:
	{
		int Num1 = RandomNumber(1, 10);
		int Num2 = RandomNumber(1, 10);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype));
		break;
	}

	case enQuestionLevel::Med:
	{
		int Num1 = RandomNumber(11, 30);
		int Num2 = RandomNumber(11, 30);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype));
		break;
	}

	case enQuestionLevel::Hrad:
	{
		int Num1 = RandomNumber(30, 100);
		int Num2 = RandomNumber(30, 100);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype));
		break;

	}
	}

}

int PlayGame(short HowManyQuestions) {
	enQuestionLevel Qlevel = ReadQuestionLevel();
	enOperationType OpType = ReadOperationType();
	short RightAnswerCount = 0, WrongAnswer = 0;
	for (short Question = 1; Question <= HowManyQuestions; Question++) {

		cout << "\n\nQuestions [" << Question << "/" << HowManyQuestions << "]\n";
		GenerateQuestions(Qlevel, OpType);



	}

	return 1;
}



int main() {
	srand((unsigned)time(NULL));

	PlayGame(NumberOfQuestions());

	return 0;
}