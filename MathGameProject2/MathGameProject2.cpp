#include<iostream>
#include<cstdlib>

using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hrad = 3,LMix=4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4,OMix=5 };
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
		if (Optype != enOperationType::OMix) {

        int Num1 = RandomNumber(1, 10);
		int Num2 = RandomNumber(1, 10);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype));
		
		}
		else {
			int Num1 = RandomNumber(1, 10);
			int Num2 = RandomNumber(1, 10);
			int Op = RandomNumber(1, 4);
			CheckAnswer(Calculate((enOperationType)Op, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType)Op));


		}
        break;
		
	}

	case enQuestionLevel::Med:
	{
		if (Optype != enOperationType::OMix) {

        int Num1 = RandomNumber(1, 10);
		int Num2 = RandomNumber(1, 10);
		CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype));
		
		}
		else {
			int Num1 = RandomNumber(1, 10);
			int Num2 = RandomNumber(1, 10);
			int Op = RandomNumber(1, 4);
			CheckAnswer(Calculate((enOperationType)Op, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType)Op));
		}
		break;
	}

	case enQuestionLevel::Hrad:
	{
		if (Optype != enOperationType::OMix) {

			int Num1 = RandomNumber(30, 100);
			int Num2 = RandomNumber(30, 100);
			CheckAnswer(Calculate(Optype, Num1, Num2), PrintQuestionStruct(Num1, Num2, Optype));

		}
		else {
			int Num1 = RandomNumber(30, 100);
			int Num2 = RandomNumber(30, 100);
			int Op = RandomNumber(1, 4);
			CheckAnswer(Calculate((enOperationType)Op, Num1, Num2), PrintQuestionStruct(Num1, Num2, (enOperationType)Op));
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
		GenerateQuestions((enQuestionLevel)Num1, (enOperationType)OOp);
		
		
		}
		else if (Optype != enOperationType::OMix) {
			int Num1 = RandomNumber(1, 3);
			GenerateQuestions((enQuestionLevel)Num1, Optype);
		}

		break;
	}
	}

}
//
//void MixFunction() {
//	int Num1 = RandomNumber(1, 3);
//	int OOp = RandomNumber(1, 4);
//	GenerateQuestions((enQuestionLevel)Num1, (enOperationType)OOp);
//
//
//}

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