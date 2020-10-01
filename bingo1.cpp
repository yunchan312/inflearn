#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE
{
	AI_EASY = 1,
	AM_HARD = 2
};

int main(void)
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	// 1~25���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; i++)
	{
		iNumber[i]=i + 1;
		iAINumber[i] = i + 1;
	}

	//���ڸ� �����ش�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		//mix AI numbers
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	//AI ���̵��� �����Ѵ�.
	while (true) {
		system("cls");
		cout << "1. EASY" << endl;
		cout << "2. HARD" << endl;
		cout << "AI ��带 �����ϼ��� : ";


		cin >> iAIMode;

		if (iAIMode >= AI_EASY || iAIMode <= AM_HARD)
			break;
	}

	//���� �ȵ� ��� �迭�� �����.
	int iNoneSelect[25] = {};
	//���þȵ� ���� ������ ����
	int iNoneSelectCount = 0;


	while (true)
	{
		system("cls");

		//���ڸ� 5X5�� ����Ѵ�.
		cout << "===================Player=======================" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
				cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl << endl;

		// print AI Bingo board
		cout << "===================AI=======================" << endl;

		switch (iAIMode)
		{
		case AI_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
		
			cout << endl;
		}
		//print a number of AI lines
		cout << "AIBingo Line : " << iAIBingo << endl;


		//�ټ��� 5�̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
		{ 
			cout << "Player Win" << endl;
			break;
		}

		else if (iAIBingo >= 5)
		{
			cout << "AI Win" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		//����ó���� ���� �Ѵ� (�����Ȳ)
		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;

		//�ߺ� �Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٰ�
		// �ϱ����� true�� ����־���.
		bool bAcc = true;

		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ�
		//�ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i)
		{
			//���� ���ڰ� ���� ���
			if (iInput == iNumber[i])
			{
				//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				//bAcc ������ false�� ������ش�.
				bAcc = false;

				//���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�
				iNumber[i] = INT_MAX;
				//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
				//for���� ����������.
				break;
			}
		}

		//bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�
		if(bAcc)
			continue;

		//�ߺ��� �ƴ϶�� AI�� ���ڵ� ���� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;

				break;
			}
		}
		//AI�� ������ �Ѵ�.
		switch (iAIMode)
		{	/* AI EASY ���� ���� AI�� ���ڸ�� �� *�� �ٲ��� ���� ���� ����� ����
	�� ��� �� �ϳ��� �����ϰ� �Ѵ�.*/

		case AI_EASY:
			//���þȵ� ���ڸ���� ������ش�.
			//���� �ȵ� ���� ������ ����� ���� �� ī���� ���ش�.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i)
			{
				if (iAINumber[i] != INT_MAX)
				{
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			//for���� ���������� �Ǹ� ���þȵ� ����� ���������
			//���� �ȵ� ����� ������ ��������� �ȴ�.
			// ���� �ȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			break;
		}

		//AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		//AI  ���ڸ� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}


		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� �� ���� ó������
		//���� ī��Ʈ. �׷��Ƿ� iBingo������ 0���� �Ź� �ʱ�ȭ�ϰ� ���Ӱ�
		//�� ���� ���Ѵ�.
		iBingo = 0;
		iAIBingo = 0;

		//����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			// ������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				//���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1; 

				//���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				//AI��üũ
				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;
				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;


			}
			//(i�� ��, j�� ���� �����ϸ� ����)

			// j for���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStar1������ ���� �ȴ�. iStar1�� 5�� ������ ��� *�̶�� ��
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAIStar1 == 5)
				++iAIBingo;

			if (iAIStar2 == 5)
				++iAIBingo;

		}

		//���� ��� -> ������ �ϴ� �밢�� üũ
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		if (iAIStar1 == 5)
			++iAIBingo;
		
		//������ ��� -> ���� �ϴ� �밢�� üũ
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		if (iAIStar1 == 5)
			++iAIBingo;



	}

	return 0;
}