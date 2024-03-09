#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<string>
using namespace std;

//��ͼ��
class Game
{
public:
	int myLen;
	int myMap[230][230]; //����ͼ
	int canGo[25000][2]; //��¼���ߵ�·
	int canGoNum = 0; //��¼���ߵĲ���
	int myXY[2]; //�ҵ�XY����

	//��ʼ����ͼ
	Game(int myMapSize)
	{
		myLen = myMapSize;
		//����ҵĵ�ͼ
		for (int a = 0; a < 130; a++)
		{
			for (int b = 0; b < 130; b++)
			{
				myMap[a][b] = 0;
			}
		}

		//�����������·
		//�����ŵ�λ��
		canGo[0][0] = 30 + rand() % myMapSize - 30;
		canGo[0][1] = 30 + rand() % myMapSize - 30;
		myMap[canGo[0][0]][canGo[0][1]] = 1;
		for (int c = 0; c < (myMapSize*myMapSize / 100); c++)
		{
			//�������һ���µķ�֧
			if (canGoNum != 0) {
				int FenZhi = 0 + rand() % canGoNum;
				myXY[0] = canGo[FenZhi][0];
				myXY[1] = canGo[FenZhi][1];
			}
			else
			{
				myXY[0] = canGo[0][0];
				myXY[1] = canGo[0][1];
			}
			//��ʼ�������
			for (int d = 0; d < (myMapSize*myMapSize/50); d++)
			{
				//ѡ��һ���������
				int FangXiang = 1 + rand() % 4;
				if ((FangXiang == 1 && !(myXY[0] - 1 == 30) && (myMap[myXY[0] - 2][myXY[1]]) != 1) || 
					(FangXiang == 2 && !(myXY[0] + 1 == myMapSize - 30) && (myMap[myXY[0] + 2][myXY[1]]) != 1) ||
					(FangXiang == 3 && !(myXY[1] - 1 == 30) && (myMap[myXY[0]][myXY[1] - 2]) != 1) ||
					(FangXiang == 4 && !(myXY[1] + 1 == myMapSize - 30) && (myMap[myXY[0]][myXY[1] + 2]) != 1))
				{
					switch(FangXiang)
					{
					case 1:
						--myXY[0];
						myMap[myXY[0]][myXY[1]] = 1;
						++canGoNum;
						canGo[canGoNum][0] = myXY[0];
						canGo[canGoNum][1] = myXY[1];
						break;
					case 2:
						++myXY[0];
						myMap[myXY[0]][myXY[1]] = 1;
						++canGoNum;
						canGo[canGoNum][0] = myXY[0];
						canGo[canGoNum][1] = myXY[1];
						break;
					case 3:
						--myXY[1];
						myMap[myXY[0]][myXY[1]] = 1;
						++canGoNum;
						canGo[canGoNum][0] = myXY[0];
						canGo[canGoNum][1] = myXY[1];
						break;
					case 4:
						++myXY[1];
						myMap[myXY[0]][myXY[1]] = 1;
						++canGoNum;
						canGo[canGoNum][0] = myXY[0];
						canGo[canGoNum][1] = myXY[1];
						break;
					}
				}
			}
		}
		
		////��canGo��������
		//int writeCanGoOnes[2] = {0,0};
		//for (int h = 0; h < canGoNum; h++)
		//{
		//	for (int g = 0; g < canGoNum + 1 - h; g++)
		//	{
		//		if ((canGo[g + 1][0] + canGo[g + 1][1]) < (canGo[g][0] + canGo[g][0]))
		//		{
		//			writeCanGoOnes[0] = canGo[g][0];
		//			writeCanGoOnes[1] = canGo[g][1];
		//			canGo[g][0] = canGo[g + 1][0];
		//			canGo[g][1] = canGo[g + 1][1];
		//			canGo[g + 1][0] = writeCanGoOnes[0];
		//			canGo[g + 1][1] = writeCanGoOnes[1];
		//		}

		//	}
		//}

		//�����ҵ�����
		myXY[0] = canGo[canGoNum/15][0];
		myXY[1] = canGo[canGoNum/15][1];
	}


	//��ʾ��ͼ
	void lookAtTheMap()
	{
		for (int a = myXY[0]-10; a < myXY[0] + 11; a++)
		{
			for (int b = myXY[1]-15; b < myXY[1]+16; b++)
			{
				if (a == myXY[0]-10 || b == myXY[1]-15 || b == myXY[1] + 15 || a == myXY[0] + 10)
				{
					cout << "��";
				}
				else if (myMap[a][b]==0)
				{
					cout << "ǽ";
				}
				else if (a==myXY[0] && b==myXY[1])
				{
					cout << "��";
				}
				else if (a == canGo[0][0] && b == canGo[0][1])
				{
					cout << "��";
				}
				else if(myMap[a][b]==1)
				{
					cout << "  ";
				}
				else
				{
					cout << "ǽ";
				}
			}
		cout << endl;
		}
	}

	//���ơ��ҡ����ж�
	void inputMyWalk()
	{
		//��ȡ�ҵ�����
		int a = 0;
		if (_kbhit()) 
		{
			a = _getch();
			//cout << a << endl;
		}
		//�ж�ǰ������,���Ƿ����ǰ��
		if ((a == 119) && ((myMap[myXY[0] - 1][myXY[1]]) != 0) && !(myXY[0] == 5))
		{
			--myXY[0];
		}
		else if ((a == 115) && ((myMap[myXY[0] + 1][myXY[1]]) != 0) && !(myXY[0] == myLen-5))
		{
			++myXY[0];
		}
		else if ((a == 97) && ((myMap[myXY[0]][myXY[1]-1]) != 0) && !(myXY[1] == 5))
		{
			--myXY[1];
		}
		else if ((a == 100) && ((myMap[myXY[0]][myXY[1] + 1]) != 0) && !(myXY[1] == myLen - 5))
		{
			++myXY[1];
		}
		
	}
	
	~Game() {};
};

int yourKey(const string  bus[],int run[], int len)
{
	int num = 0;
	for (int i = 0; 1;)
	{
		i = 0;
		if (_kbhit())
		{
			i = _getch();
		}
		if (i == 119 && num - 1 != -1)
		{
			--num;
		}else if (i == 115 && num + 1 != len)
		{
			++num;
		}
		else if (i == 13)
		{
			return run[num];
		}
		cout << "����W���ϣ�S���£��س�ȷ��\n" << "________________________\n";
		for (int r = 0; r < len; r++)
		{
			if (r == num)
			{
				cout << "->\t" << bus[r] << endl;
			}
			else
			{
				cout << "\t" << bus[r] << endl;
			}
			
		}
		Sleep(50);
		system("cls");
	}
}

int running()
{
	cout << "W��S��A��D�ң�\n";
	system("pause");
	string txt1[] = { "�򵥣�32*32��","һ�㣨50*50��","���ѣ�100*100��","������200*200��" };
	int ret[] = { 32,50,100,200 };
	srand((unsigned int)time(NULL));

	Game a(yourKey(txt1,ret,4));
	for(int i = 0;1;i++)
	{
		a.lookAtTheMap();
		a.inputMyWalk();
		Sleep(40);
		system("cls");
		if (a.myXY[0] == a.canGo[0][0] && a.myXY[1] == a.canGo[0][1])
		{
			return 0;
		}

	}
	
}

int main() 
{
	string txt2[] = { "������һ��","���˳�" };
	int ret2[] = {0,1};
	for (int h = 0; 1;) {
		running();
		cout << "��ϲ�㣬�������յ㣡\n";
		Sleep(2000);
		system("pause");
		
		if(yourKey(txt2, ret2, 2))
		{
			system("pause");
			return 0;
		}
	}
	
	
	
}